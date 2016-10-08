import React, { Component } from 'react';
import Search from './Search.js'

import '../css/App.css';

// This is the default sidebar; for sort bugs
class SidebarSearch extends Component {

    render() {
        return (
            <div className="aui-page-panel-nav">
                <nav className="aui-navgroup aui-navgroup-vertical">
                    <div className="aui-navgroup-inner">
                        <div className="aui-sidebar-group aui-sidebar-group-tier-one">
                            <div className="aui-nav-heading" title="bug-page-search">
                                <strong>Search Bugs In Project</strong>
                            </div>
                            <ul className="aui-nav" title="Page actions">
                                <li>
                                    <a className="aui-nav-item" href="#" title="Edit">Edit</a>
                                </li>
                            </ul>
                        </div>
                    </div>
                </nav>
            </div>
        );
    }
}

export default SidebarSearch;
