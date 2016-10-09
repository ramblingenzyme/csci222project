import React, { Component, PropTypes } from 'react';
import { Field, reduxForm } from 'redux-form';

class RadioField extends Component {
    render() {
        return (
            <div className="radio">
                <Field className="radio" type="radio" name="radiobuttons" checked={this.props.checked}
                       id={this.props.id} component="input"/>
                <label htmlFor={this.props.id}>{this.props.title}</label>
            </div>
        )
    }
}

RadioField.defaultProps = {
    checked: "",
    id: "radio-button"
};

export default RadioField;
