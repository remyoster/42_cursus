import React from 'react';
import { render, customRender, fireEvent } from '../../test-utils';
import OptionsForm, {
	CustomSwitcher, StartingLevelSlider, DropTimeRefSlider,
	SlideTransition
} from '../../components/OptionsForm';
import { requestChangeOption } from '../../actions/socket';
import Snackbar from '@material-ui/core/Snackbar';
import { initialState } from '../../reducers/gameReducer';

it('Renders the connected optionsForm with initial store state', () => {
	const { container, queryByLabelText} = customRender(
	<OptionsForm />, { initialState : {game:{...initialState, type: 'multi'}}});
	expect(container.querySelectorAll('div.option-container')).toHaveLength(5);
	expect(queryByLabelText('fullSpectrum')).toBeInTheDocument();
});

it('renders the <SlideTransition /> transition componenent inside a snackbar', () => {
	render(
		<Snackbar open={true} TransitionComponent={SlideTransition}>
			<div>test</div>
		</Snackbar>);
});

it('renders the <CustomSwitcher /> component', () => {
	const dispatch = jest.fn();
	const { rerender, getByLabelText } = render(
		<CustomSwitcher
			option={'ghostMode'} value={true} dispatch={dispatch} room='test' leader />);
	expect(getByLabelText('ghostMode').disabled).toBeFalsy();
	fireEvent.click(getByLabelText('ghostMode'));
	expect(dispatch.mock.calls.length).toBe(1);
	expect(dispatch).toHaveBeenCalledWith(
		requestChangeOption({ option: 'ghostMode', value: false, room: 'test' }));
	rerender(
		<CustomSwitcher
			option={'ghostMode'} value={false} dispatch={dispatch} room='test' leader />);
	fireEvent.click(getByLabelText('ghostMode'));
	expect(dispatch.mock.calls.length).toBe(2);
	expect(dispatch).toHaveBeenCalledWith(
		requestChangeOption({ option: 'ghostMode', value: true, room: 'test' }));
	rerender(
		<CustomSwitcher
			option={'ghostMode'} value={false} dispatch={dispatch} room='test' leader={false} />);
	expect(getByLabelText('ghostMode').disabled).toBeTruthy();
});

it('renders the <StartingLevelSlider /> component', () => {
	const dispatch = jest.fn();
	const { getByTestId } = render(
		<StartingLevelSlider
			value={5} dispatch={dispatch} room='test' leader />);
	fireEvent.mouseDown(getByTestId('startingLevelSlider'), { clientX: 100, clientY: 302 });
	fireEvent.mouseMove(getByTestId('startingLevelSlider'), { clientX: 162, clientY: 302 });
	fireEvent.mouseUp(getByTestId('startingLevelSlider'));
	expect(dispatch.mock.calls.length).toBe(1);
});

it('renders the <DropTimeRefSlider /> component', () => {
	const dispatch = jest.fn();
	const { getByTestId } = render(
		<DropTimeRefSlider
			value={1000} dispatch={dispatch} room='test' leader />);
	fireEvent.mouseDown(getByTestId('dropTimeRefSlider'), { clientX: 100, clientY: 302 });
	fireEvent.mouseMove(getByTestId('dropTimeRefSlider'), { clientX: 162, clientY: 302 });
	fireEvent.mouseUp(getByTestId('dropTimeRefSlider'));
	expect(dispatch.mock.calls.length).toBe(1);
});
