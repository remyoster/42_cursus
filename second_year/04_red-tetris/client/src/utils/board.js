import { offsetPiece } from './tetrimino';
/*
** Boolean function to check if the board is fillable with the new tetri shape.
*/

export function isBoardFillable(board, oldShape, newShape) {
  let points;
  if (!newShape)
    return (false);
  if (oldShape)
    points = newShape.filter(e =>
      (oldShape.findIndex(f =>
        (f.x === e.x && f.y === e.y)) > -1) ? false : true);
  else
    points = newShape;
  for (const i in points) {
    if (!board[`${points[i].x},${points[i].y}`]
      || board[`${points[i].x},${points[i].y}`].occuped)
      return (false);
  }
  return (true);
}

/*
** Fill the board with the newShape of the tetri and "delete" the old one.
** Then return the newBoard. Does the same with ghostMode for the ghostTetri
*/

export function fillBoard(board, oldShape, newShape, color, ghost = false) {
  if (!ghost) {
    if (oldShape)
      oldShape.forEach(e => {
        board[`${e.x},${e.y}`] = { occuped: false, color: null }
      });
    newShape.forEach(e => {
      board[`${e.x},${e.y}`] = { occuped: true, color: color }
    });
  }
  else {
    if (oldShape)
      oldShape.forEach(e => {
        board[`${e.x},${e.y}`].ghost = false;
      });
    newShape.forEach(e => {
      board[`${e.x},${e.y}`].ghost = true;
      board[`${e.x},${e.y}`].color = color;
    });
  }
  return (board);
}

/*
** Return a object with entries x,y (width, height) based on a 10x axis and
** inifite y. Each entry receive two props : occuped (boolean) and
** color (hex val or string)
*/

export function createBoard(width, height) {
  return (Array.from({
    length: width * height
  }, (v, k) => k)
    .reduce((o, key) => ({
      ...o, [`${key % width},${parseInt(key / width)}`]: {
        occuped: false,
        color: null
      }
    }), {}));
}

/*
** Check the board "around" the last tetri droped. If the board has one or more 
** (4 max) line completed, it "delete" them by putting the cell state to not
** occuped. Then it rolls down every cell upper the y-max cleared line by the
** number of line cleared (or by the ecart if any, with the correct offset). 
** Returns a tmpBoard and the length of full line, if any
*/

export function checkAndPopCompleteLine(board, tetri) {
  let tmpBoard = null;
  let yMax = Math.max(...tetri.shape.map(e => e.y));
  let fullLine = [];
  let full;
  for (let y = yMax; y >= 0 && yMax - y < 4; y--) {
    full = 0;
    for (let x = 0; x < 10; x++) {
      if (board[`${x},${y}`].occuped)
        full += 1;
    }
    if (full === 10)
      fullLine.push(y);
  }
  if (fullLine.length) {
    tmpBoard = { ...board };
    fullLine.forEach(y => {
      for (let x = 0; x < 10; x++)
        tmpBoard[`${x},${y}`] = { occuped: false, color: null };
    });
    yMax = Math.max(...fullLine) - 1;
    let ecart = findEcartInArray(fullLine);
    for (let y = yMax; y >= 0; y--) {
      if (ecart && ecart.lines.includes(y)) {
        for (let x = 0; x < 10; x++) {
          if (tmpBoard[`${x},${y}`].occuped) {
            tmpBoard[`${x},${y}`].occuped = false;
            tmpBoard[`${x},${(y + fullLine.length - ecart.offset)}`] = {
              occuped: true,
              color: tmpBoard[`${x},${y}`].color
            };
          }
        }
      }
      else {
        for (let x = 0; x < 10; x++) {
          if (tmpBoard[`${x},${y}`].occuped) {
            tmpBoard[`${x},${y}`].occuped = false;
            tmpBoard[`${x},${(y + fullLine.length)}`] = {
              occuped: true,
              color: tmpBoard[`${x},${y}`].color
            };
          }
        }
      }
    }
  }
  return ({ tmpBoard: tmpBoard, fullLine: fullLine.length });
}

/*
** Find the first ecart in an array of consecutive number and return an array of
** each consecutive number in the ecart interval (if any) and an offset of 
** 1 if the ecart interval is 2, else 2.
** The array must be in reverse order
*/

export function findEcartInArray(arr) {
  let ecart = null;
  if (arr.length > 1) {
    let ecartIdx = arr.findIndex((e, idx) => arr[idx + 1] && e - arr[idx + 1] !== 1);
    if (ecartIdx > -1) {
      let nbLines = arr[ecartIdx] - arr[ecartIdx + 1];
      if (ecartIdx === 0)
        ecart = {
          lines: Array.from({ length: nbLines }, (v, k) => arr[ecartIdx] - (k + 1)),
          offset: arr.length === 2 ? 1 : 2
        }
      else
        ecart = { lines: [arr[ecartIdx] - 1], offset: 1 };
    }
  }
  return (ecart);
}

/*
** Add penaltyLines into the board. If there is a tetri falling down it moves it
** from penaltyLines.length upper
*/

export function addPenaltyLinesToBoard(board, tetri, penaltyLines) {
  let tmpBoard = fillBoard(board, tetri.shape, [], tetri.color);
  for (let y = 0; y < 20; y++) {
    for (let x = 0; x < 10; x++) {
      if (tmpBoard[`${x},${y}`].occuped) {
        tmpBoard[`${x},${y}`].occuped = false;
        tmpBoard[`${x},${(y - penaltyLines.length)}`] = {
          occuped: true,
          color: tmpBoard[`${x},${y}`].color
        };
      }
    }
  }
  for (let y = 20 - penaltyLines.length; y < 20; y++) {
    for (let x = 0; x < 10; x++) {
      if (x !== penaltyLines[19 - y])
        tmpBoard[`${x},${y}`] = { occuped: true, color: 'firebrick' };
    }
  }
  let idx = 0;
  let newShape;
  while (idx < 4) {
    newShape = offsetPiece(tetri.shape, { x: 0, y: -idx });
    if (isBoardFillable(tmpBoard, null, newShape))
      break;
    idx++;
  }
  tmpBoard = fillBoard(tmpBoard, null, newShape, tetri.color);
  return ({ tmpBoard, newShape });
}
