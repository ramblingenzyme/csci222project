import React, { Component } from 'react';

import '../css/App.css';

// This is the default sidebar; for sort bugs
class SidebarSearch extends Component {

    render() {
        return (
            <div className="aui-page-panel-nav">
                <nav className="aui-navgroup aui-navgroup-vertical">
                    <div className="aui-navgroup-inner">
                        <ul className="aui-nav __skate">
                            <li>
                                Search
                            </li>
                        </ul>
                    </div>
                </nav>
            </div>
        );
    }
}

export default SidebarSearch;
