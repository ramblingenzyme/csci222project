import React, { Component, PropTypes } from 'react';
import { Form } from 'react-redux-form';
import InputField from './InputField.js';

class ReportPage extends Component {
    render() {
        const handleSubmit = this.props.dispatch;

        return (
            <div id="Reporting" className="aui">
                <h3>Bug Report Submission</h3>
                <Form className="aui top-label padField" method="post" model="forms.reportWriter">
                    <InputField id="report-writer-title" title="Title" model = "forms.reportWriter.title" require />
                    <InputField id="report-writer-project" title="Project" model = "forms.reportWriter.project" require/>
                    <InputField id="report-writer-component" title="Component" model = "forms.reportWriter.component" />
                    <InputField id="report-writer-os" title="Operating System" model = "forms.reportWriter.os" />
                    <InputField id="report-writer-description" title="Description" model = "forms.reportWriter.description" require />
                    <div className="buttons-container">
                        <button type="submit">Submit</button>
                    </div>
                </Form>
            </div>
        )
    }
}

export default ReportPage;
