import React, { Component } from 'react';
import { Form } from 'react-redux-form';
import DropdownIndividual from './DropdownIndividual.js'
import InputField from './InputField.js'

import '../css/App.css';

// This is the default sidebar for searching bugs

class SidebarSearch extends Component {
    _handleSubmit(sideBar) {

    };

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
                    <div className="aui-navgroup-inner padField">
                        <div className="aui-nav-heading">
                            Search Bugs In Project
                        </div>
                        <strong> </strong>
                        <Form className="aui top-label padField" method="post" model="forms.user" onSubmit={(user) => this._handleSubmit(user)}>
                            <InputField id="search-keywords" title="Keyword(s)" placeholder="keyword1, keyword2"
                                model="forms.searchPageSidebar.keyword" className="text" need={true} />

                            <InputField id="operating-system" title="Operating System(s)" placeholder="e.g. ios, mac"
                                model="forms.searchPageSidebar.os" />

                            <InputField id="version" title="Version" placeholder="e.g. 1.4.5 - 1.4.7"
                                model="forms.searchPageSidebar.version" />

                            <DropdownIndividual id="bug-age" options={timeline_options} title="Bug Age"
                                                auiClass="aui top-label" model="forms.searchPageSidebar.age" />

                            <DropdownIndividual id="bug-status" options={status_options}title="Bug Status"
                                                auiClass="aui top-label" model="forms.searchPageSidebar.status" />

                            <DropdownIndividual id="bug-priority" options={magnitudal_options} title="Bug Priority"
                                                auiClass="aui top-label" model="forms.searchPageSidebar.priority" />

                            <DropdownIndividual id="bug-severity" options={magnitudal_options} title="Bug Severity"
                                                auiClass="aui top-label" model="forms.searchPageSidebar.severity" />
                        </Form>
                    </div>
                </nav>
            </div>
        );

    }
}

export default SidebarSearch;
