import React from "react";
import { PersistGate } from 'redux-persist/integration/react';
import { Switch, HashRouter, Route, BrowserRouter } from "react-router-dom";
import { Provider } from 'react-redux';
import { store, persistor } from "../store/configStore";
import Home from "./Home";
import Game from "./Game";
import Loader from '../components/Loader';
import NotFound from "./NotFound";
import { createMuiTheme, ThemeProvider } from '@material-ui/core/styles';

const theme = createMuiTheme({
  palette: {
    primary: {
      main: '#d50000',
      light: '#ff5131',
      dark: '#9b0000',
      contrastText: '#ffffff',
    },
    secondary: {
      main: '#f44336',
      light: '#ff7961',
      dark: '#ba000d',
      contrastText: '#ffffff',
    },
  },
});


function App() {
  return (
    <Provider store={store}>
      <PersistGate loading={<Loader />} persistor={persistor}>
        <ThemeProvider theme={theme}>
          <BrowserRouter>
            <Switch>
              <Route exact path="/">
                <HashRouter hashType="noslash">
                  <Switch>
                    <Route strict exact path="/" component={Home} />
                    <Route exact path="/:room[:playerName]" component={Game} />
                    <Route path="*">
                      <NotFound />
                    </Route>
                  </Switch>
                </HashRouter>
              </Route>
              <Route path="*">
                <NotFound />
              </Route>
            </Switch>
          </BrowserRouter>
        </ThemeProvider>
      </PersistGate>
    </Provider >
  );
}

export default App;
