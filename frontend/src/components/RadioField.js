import React, { Component, PropTypes } from 'react';
import { Field, reduxForm } from 'redux-form';
import { Control } from 'react-redux-form';

class RadioField extends Component {
    render() {
        let buttons = this._getButtons();

        return (
            <fieldset className="group">
                {buttons}
            </fieldset>

        );
    }

    _getButtons() {
        return options.map((option, i) => (
            <div className="radio">
                <Control.radio className="radio" name={this.props.name} id={`${this.props.name}-${i}`} value={option.value} />
                <label for={`${this.props.name}-${i}`}>{option.label}</label>
            </div>
        ))
    }
}

RadioField.defaultProps = {
    options: [
        {
            value: 'a'
            label: 'Option A'
        },
        {
            value: 'b'
            label: 'Option A'
        },
        {
            value: 'c'
            label: 'Option C'
        },
    ],
    name: 'default-radio'
};

export default RadioField;
