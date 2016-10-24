import React, { Component } from 'react';
import { Field, reduxForm } from 'redux-form';
import DropdownIndividual from './DropdownIndividual.js'
import InputField from './InputField.js'

import '../css/App.css';

// This is the default sidebar for searching bugs

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
                <nav className="aui-navgroup aui-navgroup-vertical">
                    <div className="aui-navgroup-inner">
                        <div className="aui-nav-heading">
                            Search Bugs In Project
                        </div>
                        <strong> </strong>
                        <ul className="aui-nav field-group top-label inputField">
                            <li>
                                <InputField id="search-keywords" title="Keyword(s)" className="text long-field" />
                            </li>
                            <li>
                                <InputField id="version-lower" title="Operating System(s)" placeholder="e.g. ios, mac" />
                            </li>
                            <li>
                                <InputField id="version-lower" title="Version(s)" placeholder="e.g. 1.4.5 - 1.4.7" />
                            </li>
                            <li>
                                <DropdownIndividual id="bug-age" options={timeline_options} title="Bug Age"
                                                    auiClass="aui top-label" />
                            </li>
                            <li>
                                <DropdownIndividual id="bug-status" options={status_options}title="Bug Status"
                                                    auiClass="aui top-label" />
                            </li>
                            <li>
                                <DropdownIndividual id="bug-priority" options={magnitudal_options} title="Bug Priority"
                                                    auiClass="aui top-label" />
                            </li>
                            <li>
                                <DropdownIndividual id="bug-severity" options={magnitudal_options} title="Bug Severity"
                                                    auiClass="aui top-label" />
                            </li>
                        </ul>
                    </div>
                </nav>
            </div>
        );
    }
}

SidebarSearch = reduxForm({
    form: 'sidebar-search'
})(SidebarSearch)

export default SidebarSearch;
