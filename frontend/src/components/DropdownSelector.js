import React, { Component, PropTypes } from 'react';
import { Field, reduxForm } from 'redux-form';

class DropdownSelector extends Component {
    render() {
        return (
            <form key={this.props.title} className="aui">
                <div className="field-group">
                    <label htmlFor={this.props.id}>
                        {this.props.title}
                    </label>
                    <select className="select" id={this.props.id} name={this.props.id}>
                        {this.props.options.map((result) => (
                            <option key={result.id}>{result.text}</option>
                        ))}
                    </select>
                </div>
            </form>
        )
    }
}

DropdownSelector.defaultProps = {
    id: "dropdown-selector"
};

export default DropdownSelector;
