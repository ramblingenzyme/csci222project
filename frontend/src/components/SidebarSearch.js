import React, { Component } from 'react';
import Search from './Search.js'
import { Field, reduxForm } from 'redux-form';
import DropdownSelector from './DropdownSelector.js'

import '../css/App.css';

// This is the default sidebar; for sort bugs
class SidebarSearch extends Component {
    render() {
        var timeline_options = [
            "Day",
            "Week",
            "Month",
            "Year"
        ];
        var status_options = [
            "Unassigned",
            "Assigned",
            "Patch Submitted",
            "Resolved"
        ];
        var magnitudal_options = [
            "Low",
            "Medium",
            "High",
            "Extreme"
        ];
        return (
            <div className="aui-page-panel-nav">
                <nav className="aui-navgroup-vertical">

                    <div className="aui-nav-heading" title="bug-page-search">
                        <strong>Search Bugs In Project</strong>
                    </div>

                    <DropdownSelector id="bug-age" options={timeline_options} title="Age"/>
                    <DropdownSelector id="bug-status" options={status_options} title="Status"/>
                    <DropdownSelector id="bug-priority" options={magnitudal_options} title="Priority"/>
                    <DropdownSelector id="bug-severity" options={magnitudal_options} title="Severity"/>

                </nav>
            </div>
        );
    }
}

SidebarSearch = reduxForm({
    form: 'sidebar-search'
})(SidebarSearch)
export default SidebarSearch;
