import React, { Component, PropTypes } from 'react';
import { Field, reduxForm } from 'redux-form';

class InputField extends Component {
    render() {
        let input_field = this._getContent();

        return (
            <form className={this.props.auiClass}>
                <div className={this.props.auiClass}>
                    <label htmlFor={this.props.id}>
                        {this.props.title}
                    </label>
                    {input_field}
                    <div className="description">
                        {this.props.description}
                    </div>
                </div>
            </form>
        )
    }

    _getContent() {
        if (this.props.disabled) {
            return (
                <Field className={this.props.className} type={this.props.type}
                       id={this.props.id} name={this.props.id}
                       placeholder={this.props.placeholder} component="input" disabled />
            )
        } else {
            return (
                <Field className={this.props.className} type={this.props.type}
                       id={this.props.id} name={this.props.id}
                       placeholder={this.props.placeholder} component="input" />
            )
        }
    }
}

InputField.defaultProps = {
    title: "Input",
    type: "text",
    className: "text medium-field",
    disabled: false,
    description: "",
    id: "input-field" ,
    placeholder: "",
    auiClass: "aui"
};

export default InputField;
