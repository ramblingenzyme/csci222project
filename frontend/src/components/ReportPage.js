import React, { Component, PropTypes } from 'react';
import { Form } from 'react-redux-form';

import InputField from './InputField.js';
import Fetch from '../helpers/fetch.js'

class ReportPage extends Component {
    _handleAdd(bugInfo) {
        if (!this.props.authenticateUser.authed) {
            return alert("You must login/register to report a bug!");
        }

        return Fetch('add_bug', {
            method: "POST",
            headers: {
                'Content-Type': 'application/json'
            },
            body: JSON.stringify({
                bug: {
                    title: bugInfo.title,
                    project: bugInfo.project,
                    component: bugInfo.component,
                    operating_system: bugInfo.os,
                    description: bugInfo.description,
                    reporter: this.props.authenticateUser.username
                }
            })
        }).then(response => {
            if (response) {
                 return alert("You have submitted a bug");
            } else {
                alert("Error, could not submit bug, PEBKAC probably.")
                return false;
            }
        })
    }

    render() {
        return (
            <div id="Reporting" className="aui">
                <h3>Bug Report Submission</h3>
                <Form
                    className="aui top-label padField"
                    method="post"
                    model="forms.reportWriter"
                    onSubmit={(bug) => this._handleAdd(bug)}
                >
                    <InputField
                        id="report-writer-title"
                        title="Title"
                        model="forms.reportWriter.title"
                        require
                    />
                    <InputField
                        id="report-writer-project"
                        title="Project"
                        model="forms.reportWriter.project"
                        require
                    />
                    <InputField
                        id="report-writer-component"
                        title="Component"
                        model="forms.reportWriter.component"
                    />
                    <InputField
                        id="report-writer-os"
                        title="Operating System"
                        model="forms.reportWriter.os"
                    />
                    <InputField
                        id="report-writer-description"
                        title="Description"
                        model="forms.reportWriter.description"
                        require
                    />
                    <div className="buttons-container">
                        <div className="buttons">
                            <button type="submit">Submit</button>
                        </div>
                    </div>
                </Form>
            </div>
        )
    }
}

export default ReportPage;
