import React, { Component } from 'react';
import {Link} from 'react-router';

import Login from "./Login.js";
import Menubar from './Menubar.js';
import '../css/App.css';

// this is where the persistent UI will be defined. This will be wrapped in a Router to change the main page content shown
class App extends Component {
    render() {
        return (
            <div>
                <div className="aui-header">
                    <div className="aui-header-primary">
                        <h2>Bug Management System</h2>
                        <Menubar />
                    </div>
                    <div className="aui-header-secondary">
                        <ul className="aui-nav">
                            <Login />
                        </ul>
                    </div>
                </div>

                <div className="aui-page-panel">
                    <div className="aui-page-panel-inner">
                        {this.props.sidebar}
                        <div className="aui-page-panel-item">
                            {this.props.children}
                            {this.props.main}
                        </div>
                    </div>
                </div>
            </div>
        );
    }
}

export default App;
