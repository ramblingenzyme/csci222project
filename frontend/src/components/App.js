import React, { Component } from 'react';
import {Link} from 'react-router';

import Login from "./Login.js";
import '../css/App.css';

// this is where the persistent UI will be defined. This will be wrapped in a Router to change the main page content shown
class App extends Component { 

    render() {
        return (
            <div className="App">
                <div className="App-header">
            	   {/* <img src={bug} className="Bug-logo" alt="bug"/>*/}
                    <h2>Bug Management System</h2>
                    <div className="LoginContainer">
                        Login: <Login />
                    </div>
                    <div className="TopMenu">
                        <Link to={'/Report/'}>Report </Link>
                         | |
                        <Link to={'/Analysis/'}>Analysis </Link>
                         | |
                        <Link to={'/Assign/'}>Assign </Link>
                         | |
                        <Link to={'/Review/'}>Review </Link>
                         | |
                        <Link to={'/Search/'}>Search </Link>
                         | | 
                        <Link to={'/Profile/'}>Profile </Link>

                    </div>
                </div>
           
                {this.props.sidebar}

                <div className="DisplayWindow">
                    <p className="App-intro">
                        To get started, edit <code>src/App.js</code> 
                    </p>
                </div>
            {/* middle bit will be shown and rest hidden then change as buttons are*/}
            {this.props.children}
            {this.props.main}
            
          </div>
        );
    }
}

export default App;
