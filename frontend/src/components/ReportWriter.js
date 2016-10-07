import React, { Component, PropTypes } from 'react';
import { Link } from 'react-router';
import { Field, reduxForm } from 'redux-form';
import TinyMCE from 'react-tinymce';

class ReportWriter extends Component {
    render() {
        let fields = this.FormFields();

        return (
            <div id="report-form" className="ReportContainer">
                <h2>Reporting Tool</h2>

                <h3>Bug Details</h3>
                <div id="details" className="ReportDetails">
                    {fields}
                </div>
                <h3>Bug Notes</h3>
                <div id="description">
                    <TinyMCE
                        content="<p>Please enter any further details of the bug here.</p>"
                        config={{
                            plugins: 'print preview fullscreen spellchecker code autosave',
                            menubar: false,
                            statusbar: false,
                            toolbar_items_size: 'large',
                            toolbar: 'newdocument | undo redo | bold italic | print preview fullscreen | spellchecker ',
                            height: 300,
                            width: "50%",
                        }}
                        onChange={this.handleEditorChange}
                    />
                </div>
            </div>
        )
    }

    FormFields() {
        const handleSubmit = this.props.dispatch;

        return (
            <form className="aui" method="post" onSubmit={handleSubmit}>
                <div className="field-group">
                    <label htmlFor="title">Title<span class="aui-icon icon-required">(required)</span></label>
                    <Field className="text full-width-field" name="title" component="input" type="text" placeholder="Short title describing bug."/>
                </div>
                <div className="field-group">
                    <label htmlFor="project">Project</label>
                    <Field className="text full-width-field" name="project" component="input" type="text" placeholder="Software project where bug was found."/>
                </div>
                <div className="field-group">
                    <label htmlFor="component">Component</label>
                    <Field className="text full-width-field" name="component" component="input" type="text" placeholder="Module / component of project that the bug was found in."/>
                </div>
                <div className="field-group">
                    <label htmlFor="os">OS</label>
                    <Field className="text full-width-field" name="os" component="input" type="text" placeholder="Operating system(s) where bug has been found."/>
                </div>
                <div className="field-group">
                    <label htmlFor="milestone">Milestone</label>
                    <Field className="text full-width-field" name="milestone" component="input" type="text" placeholder="Milestone / version that bug is to be fixed by"/>
                </div>
                <div className="field-group">
                    <label htmlFor="flocation">Location</label>
                    <Field className="text full-width-field" name="flocation" component="input" type="text" placeholder="Location of bug"/>
                </div>
            </form>
        )
    }

    handleEditorChange(e) {
        console.log(e.target.getContent());
    }
}


export default ReportWriter = reduxForm({
    form: 'report-writer'
})(ReportWriter)
