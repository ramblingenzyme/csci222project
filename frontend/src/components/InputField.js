import React, { Component, PropTypes } from 'react';
import { Control, Errors } from 'react-redux-form';

class InputField extends Component {
    render() {
        let input_field = this._getContent();
        let req = this._required();

        return (
            <div className={this.props.auiClass}>
                <label htmlFor={this.props.id}>
                    {this.props.title}
                    {req}
                </label>
                {input_field}
                <Errors
                    className="error"
                    model={this.props.model}
                    show="touched"
                    messages={{
                        required: 'Required'
                    }}
                />
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
            if (this.props.require) {
                return (
                    <Control.text className="text" model={this.props.model} type={this.props.type}
                                  id={this.props.id} name={this.props.id}
                                  placeholder={this.props.placeholder} component="input" validators={{required: this._required}} />
                )
            } else {
                return (
                    <Control.text className="text" model={this.props.model} type={this.props.type}
                                  id={this.props.id} name={this.props.id}
                                  placeholder={this.props.placeholder} component="input"/>
                )
            }
        }
    }

    _required() {
        if (this.props.require) {
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
    need: false
};

export default InputField;
