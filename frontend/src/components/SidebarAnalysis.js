import React, { Component } from 'react';

// This is the sidebar for analysis
class SidebarSortBugs extends Component {
    render() {
        return (
            <div className="aui-page-panel-nav">
                <nav className="aui-navgroup aui-navgroup-vertical">
                    <div className="aui-navgroup-inner">
                        <ul className="aui-nav __skate">
                            <li>
                                Analysis
                            </li>
                        </ul>
                    </div>
                </nav>
            </div>
        );
    }
}

export default SidebarSortBugs;
