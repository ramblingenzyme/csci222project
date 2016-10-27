import React, { Component, PropTypes } from 'react';
import { Control } from 'react-redux-form';

class InputField extends Component {
    render() {
        let input_field = this._getContent();
        let req = this._required();

        return (
            <div className={this.props.auiClass}>
                <label htmlFor={this.props.id}>
                    {this.props.title}
                    {required}
                </label>
                <div className="field-group">
                    {input_field}
                </div>
                <div className="description">
                    {this.props.description}
                </div>
            </div>
        );
    }

    _getContent() {
        if (this.props.disabled) {
            return (
                <Control.text className="text" model={this.props.model} type={this.props.type}
                       id={this.props.id} name={this.props.id}
                       placeholder={this.props.placeholder} component="input" disabled />
            )
        } else {
            return (
                <Control.text className="text" model={this.props.model} type={this.props.type}
                       id={this.props.id} name={this.props.id}
                       placeholder={this.props.placeholder} component="input" />
            )
        }
    }

    _required() {
        if (this.props.required) {
            return (
                <span className="aui-icon icon-required">(required)</span>
            )
        }
    }
}

InputField.defaultProps = {
    title: "Input",
    type: "text",
    disabled: false,
    description: "",
    id: "input-field" ,
    placeholder: "",
    className: "text",
    auiClass: "aui field-group top-label",
    required: false
};

export default InputField;
