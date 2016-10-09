import React, { Component, PropTypes } from 'react';
import { Field, reduxForm } from 'redux-form';

class InputField extends Component {
    render() {
        return (
            <form className="aui">
                <div className="field-group">
                    <label htmlFor={this.props.id}>{this.props.label}<span className="aui-icon icon-required">required</span></label>
                    <Field className="text" type="text" id={this.props.id} name={this.props.id} title={this.props.title} />
                    <div className="description">{this.props.description}</div>
                </div>
            </form>
        )
    }
}

InputField.defaultProps = {
    description: "",
    title: "Text Input",
    id: "text-input",
    label: "Search"
};

export default InputField;
