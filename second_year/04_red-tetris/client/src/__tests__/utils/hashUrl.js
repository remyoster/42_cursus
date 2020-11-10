import { checkHashUrl } from '../../utils/hashUrl';

it('should handle window location hash to check if a user is connected', () => {
	let playerName = 'roster';
	const room = 'testroom'
	expect(checkHashUrl(room, playerName)).toBeTruthy();
	delete global.window.location;
	global.window = Object.create(window);
	global.window.location = {
			hash: '#testroom[roster]'
	};
	expect(checkHashUrl(room, playerName)).toBeTruthy();
	expect(checkHashUrl(room, playerName + 's')).toBeFalsy();
});