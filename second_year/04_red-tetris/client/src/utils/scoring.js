
/*
** Display the level with format 00
*/

export function displayScoreLevel(level) {
  return (level < 10 ? '0' + level : level.toString());
}

/*
** Display the line score with format 000
*/

export function displayScoreLine(line) {
  return (line < 10 ? '00' + line : line < 100 ? '0' + line : line.toString());
}

/*
** Display the total score with format 000000
*/

export function displayScorePoints(points) {
  return (points.toString().padStart(6, '0'));
}

/*
** Original Nintendo scoring system + hard and soft drop bonuses
** https://tetris.wiki/Scoring#Original_Nintendo_scoring_system
*/

export function scoreDispatcher(level, hardDrop, softDrop, lineCleared) {
  const scoreRef = [40, 100, 300, 1200];
  let score = 0;
  if (lineCleared)
    score += scoreRef[lineCleared - 1] * (level + 1);
  score += softDrop + hardDrop * 2;
  return (score);
}

/*
** Return the new score state. It calculates points when the tetri hit the stack
** by calling scoreDispatcher. Then if the tetri break some lines it add it 
** to the total lines counter. Level can be inscreased if total line passed a 10
*/

export function updateScore(prev, fullLine, downMove) {
  let totalLine = prev.line + fullLine;
  let points = scoreDispatcher(
    prev.level,
    downMove.hard,
    downMove.soft,
    fullLine
  );
  if (fullLine && (prev.line % 10) + fullLine >= 10)
    return ({
      points: prev.points + points,
      line: totalLine,
      level: prev.level + 1,
    });
  else
    return ({ ...prev, points: prev.points + points, line: totalLine });
}
