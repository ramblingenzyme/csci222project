import React, { Component, PropTypes } from 'react';
import { Link } from 'react-router';
import { Field, reduxForm } from 'redux-form';
import TinyMCE from 'react-tinymce';

class ReportWriter extends Component {
    render() {
        let fields = this.FormFields();

        return (
            <div id="report-form">
                <h3>Bug Details</h3>
                {fields}
            </div>
        );
    }

    FormFields() {
        let req = <span className="aui-icon icon-required">(required)</span>;
        return (
            <div id="details" className="ReportDetails">
                <div className="field-group">
                    <label htmlFor="title">Title{req}</label>
                    <Field className="text large-width-field" name="title" component="input" type="text" placeholder="Short title describing bug."/>
                </div>
                <div className="field-group">
                    <label htmlFor="project">Project{req}</label>
                    <Field className="text large-width-field" name="project" component="input" type="text" placeholder="Software project where bug found."/>
                </div>
                <div className="field-group">
                    <label htmlFor="component">Component</label>
                    <Field className="text large-width-field" name="component" component="input" type="text" placeholder="Bug source module."/>
                </div>
                <div className="field-group">
                    <label htmlFor="os">OS</label>
                    <Field className="text large-width-field" name="os" component="input" type="text" placeholder="Operating system with bug."/>
                </div>
                <div className="field-group">
                    <label htmlFor="milestone">Milestone{req}</label>
                    <Field className="text large-width-field" name="milestone" component="input" type="text" placeholder="Goal resolution date"/>
                </div>
                <div className="field-group">
                    <label htmlFor="flocation">Location</label>
                    <Field className="text large-width-field" name="flocation" component="input" type="text" placeholder="Source file location"/>
                </div>
                <div className="field-group">
                    <label htmlFor="description">Description</label>
                    <textarea className="textarea large-width-field" name="description" type="text" placeholder="Bug description"/>
                </div>
            </div>
        );
    }

    handleEditorChange(e) {
        console.log(e.target.getContent());
    }
}


/* TODO Use for bug comments
 <TinyMCE
    content="<p>Please enter any further details of the bug here.</p>"
    config={{
        plugins: 'print preview fullscreen spellchecker code autosave',
        menubar: false,
        statusbar: false,
        toolbar_items_size: 'large',
        toolbar: 'newdocument | undo redo | bold italic | print preview fullscreen | spellchecker ',
        height: 300,
        width: "100%",
    }}
    onChange={this.handleEditorChange}
 />
 */

export default ReportWriter = reduxForm({
    form: 'report-writer'
})(ReportWriter);
