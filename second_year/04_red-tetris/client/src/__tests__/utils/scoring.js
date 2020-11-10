import { displayScoreLevel, displayScoreLine, displayScorePoints,
	scoreDispatcher, updateScore } from '../../utils/scoring';

it('displayScoreLevel function', () => {
	expect(displayScoreLevel(0)).toBe('00');
	expect(displayScoreLevel(5)).toBe('05');
	expect(displayScoreLevel(15)).toBe('15');
});

it('displayScoreLine function', () => {
	expect(displayScoreLine(2)).toBe('002');
	expect(displayScoreLine(42)).toBe('042');
	expect(displayScoreLine(420)).toBe('420');
	expect(displayScoreLine(1420)).toBe('1420');
})

it('displayScorePoints funtion', () => {
	expect(displayScorePoints(37)).toBe('000037');
	expect(displayScorePoints(57837)).toBe('057837');
	expect(displayScorePoints(15478541)).toBe('15478541');
	expect(displayScorePoints(142)).toBe('000142');
})

it('scoreDispatcher function', () => {
	expect(scoreDispatcher(0, 0, 0, 0)).toBe(0);
	expect(scoreDispatcher(0, 1, 1, 0)).toBe(3);
	expect(scoreDispatcher(0, 2, 2, 0)).toBe(6);
	expect(scoreDispatcher(0, 0, 0, 4)).toBe(1200);
	expect(scoreDispatcher(4, 4, 5, 3)).toBe(1513);
});

it('updateScore function', () => {
	let prev = {
		line: 7,
		level: 0,
		points: 0
	};
	let downMove = { hard: 2, soft : 2};
	let fullLine = 2;
	expect(updateScore(prev, fullLine, downMove)).toEqual({
		line: 9,
		level: 0,
		points: 106
	});
	fullLine = 4;
	expect(updateScore(prev, fullLine, downMove)).toEqual({
		line: 11,
		level: 1,
		points: 1206
	});
});