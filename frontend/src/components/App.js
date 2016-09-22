import React, { Component } from 'react';

import logo from '../assets/logo.svg';
import '../css/App.css';

// this is where the persistent UI will be defined. This will be wrapped in a Router to change the main page content shown
class App extends Component {
    render() {
        return (
          <div className="App">
            <div className="App-header">
              <img src={logo} className="App-logo" alt="logo" />
              <h2>Welcome to React</h2>
            </div>
            <p className="App-intro">
              To get started, edit <code>src/App.js</code> and save to reload.
            </p>
            {this.props.children}
          </div>
        );
    }
}

export default App;
