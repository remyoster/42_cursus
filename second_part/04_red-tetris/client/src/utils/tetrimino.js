import { isBoardFillable, fillBoard } from './board';
import { moveTetri, moveTetriAndLock, updateGhost } from '../actions/board';

/*
** Move a shape by the offset coordinates
*/

export function offsetPiece(shape, offset) {
  if (offset.x !== 0 || offset.y !== 0)
    return (shape.map(e => ({
      ...e,
      x: e.x + offset.x,
      y: e.y + offset.y
    })));
  return (shape);
}

/*
** Rotate each point of a tetrimino shape by finding his center and passing
** each point to the rotate_point function
*/

export function rotateTetri(shape, clockwise = true) {
  let center = shape.find(e => e.center);
  return (shape.map(e => {
    if (!e.center)
      return (rotatePoint(e, center, clockwise));
    return (e);
  }));
}

/* 
** Rotate M point on center O by 90 degree following orthonormal coordinate
** system (x from left to right, y from top to bottom)
*/

export function rotatePoint(M, O, clockwise = true) {
  let xM = M.x - O.x;
  let yM = M.y - O.y;
  if (clockwise)
    return ({ x: -yM + O.x, y: xM + O.y });
  return ({ x: yM + O.x, y: -xM + O.y });
}

/*
** Apply the correct offset to a piece after it's rotation based on the old pos
** of the piece, the new pos, the letter and the offset test number.
** Our board is from top to bottom so y values are reverse.
** https://tetris.wiki/Super_Rotation_System
*/

export function offsetDispatcher(oldPos, newPos, letter, offset) {
  const O_offset = [
    [{ x: 0, y: 0 }],
    [{ x: 0, y: 1 }],
    [{ x: -1, y: 1 }],
    [{ x: -1, y: 0 }]
  ];
  const I_offset = [
    [{ x: 0, y: 0 }, { x: -1, y: 0 }, { x: 2, y: 0 }, { x: -1, y: 0 }, { x: 2, y: 0 }],
    [{ x: -1, y: 0 }, { x: 0, y: 0 }, { x: 0, y: 0 }, { x: 0, y: -1 }, { x: 0, y: 2 }],
    [{ x: -1, y: -1 }, { x: 1, y: -1 }, { x: -2, y: -1 }, { x: 1, y: 0 }, { x: -2, y: 0 }],
    [{ x: 0, y: -1 }, { x: 0, y: -1 }, { x: 0, y: -1 }, { x: 0, y: 1 }, { x: 0, y: -2 }],
  ];
  const other_offset = [
    [{ x: 0, y: 0 }, { x: 0, y: 0 }, { x: 0, y: 0 }, { x: 0, y: 0 }, { x: 0, y: 0 }],
    [{ x: 0, y: 0 }, { x: 1, y: 0 }, { x: 1, y: 1 }, { x: 0, y: -2 }, { x: 1, y: -2 }],
    [{ x: 0, y: 0 }, { x: 0, y: 0 }, { x: 0, y: 0 }, { x: 0, y: 0 }, { x: 0, y: 0 }],
    [{ x: 0, y: 0 }, { x: -1, y: 0 }, { x: -1, y: 1 }, { x: 0, y: -2 }, { x: -1, y: -2 }],
  ];
  const dispatcher = { 'I': I_offset, 'O': O_offset };
  let oldOffset = dispatcher[letter] ? dispatcher[letter][oldPos][offset]
    || dispatcher[letter][oldPos][0] : other_offset[oldPos][offset];
  let newOffset = dispatcher[letter] ? dispatcher[letter][newPos][offset]
    || dispatcher[letter][newPos][0] : other_offset[newPos][offset];
  return ({ x: oldOffset.x - newOffset.x, y: oldOffset.y - newOffset.y });
}

/*
 ** Return the action to dispatch when the rotation is done if there is one.
 ** That includes the new shape of the tetri and the new board already filled.
 */

export function toggleRotationOffset(key, tetri, board) {
  let rot = key === 38 ? { dir: true, pos: 1 } : { dir: false, pos: -1 };
  let newShape = rotateTetri(tetri.shape, rot.dir);
  let pos = tetri.pos + rot.pos;
  pos = pos > 3 ? 0 : pos < 0 ? 3 : pos;
  let offset = 0;
  while (offset < 5) {
    newShape = offsetPiece(
      newShape,
      offsetDispatcher(tetri.pos, pos, tetri.letter, offset)
    );
    if (isBoardFillable(board, tetri.shape, newShape))
      break;
    offset += 1;
  }
  if (offset < 5)
    return (moveTetri({
      tetri: { ...tetri, shape: newShape, pos: pos },
      board: fillBoard(board, tetri.shape, newShape, tetri.color),
    }));
  return (null);
}

/*
 ** Return the action to dispatch after a simple move or null if the move isn't
 ** possible.
 ** That includes the new shape of the tetri and the new board already filled
 */

export function toggleSimpleOffset(key, tetri, board) {
  let newShape;
  if (key === 39)
    newShape = offsetPiece(tetri.shape, { x: 1, y: 0 });
  else if (key === 37)
    newShape = offsetPiece(tetri.shape, { x: -1, y: 0 });
  else if (key === 40)
    newShape = offsetPiece(tetri.shape, { x: 0, y: 1 });
  if (isBoardFillable(board, tetri.shape, newShape))
    return (moveTetri({
      tetri: { ...tetri, shape: newShape },
      board: fillBoard(board, tetri.shape, newShape, tetri.color),
    }));
  return (null);
}

/*
** Return the action to dispatch after a hard drop.
** That includes the new shape of the tetri, the new board already filled and
** the number of lines droped (to scoring purpose)
*/

export function toggleHardDrop(tetri, board) {
  let y = 1;
  while (
    isBoardFillable(
      board,
      tetri.shape,
      offsetPiece(tetri.shape, { x: 0, y: y })
    )
  )
    y += 1;
  let newShape = offsetPiece(tetri.shape, { x: 0, y: y - 1 });
  return (moveTetriAndLock({
    tetri: { ...tetri, shape: newShape },
    board: fillBoard(board, tetri.shape, newShape, tetri.color),
    dropedLines: y - 1
  }));
}

/*
** Return the action to dispatch after a tetri move.
** That includes the new shape of the ghost and the new board already filled
*/

export function toggleGhost(ghostShape, tetri, board) {
  let y = 1;
  while (
    isBoardFillable(
      board,
      tetri.shape,
      offsetPiece(tetri.shape, { x: 0, y: y })
    )
  )
    y += 1;
  let newShape = offsetPiece(tetri.shape, { x: 0, y: y - 1 });
  return (updateGhost({
    ghostShape: newShape,
    board: fillBoard(board, ghostShape, newShape, tetri.color, true),
  }))
}
