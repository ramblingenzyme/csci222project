import React, { Component, PropTypes } from 'react';
import { Field, reduxForm } from 'redux-form';

class DropdownIndividual extends Component {
    render() {
        return (
            <form key={this.props.title} className={this.props.auiClass}>
                <div className={this.props.className}>
                    <label htmlFor={this.props.id}>
                        {this.props.title}
                    </label>
                    <select className="select" id={this.props.id} name={this.props.id}>
                        <option>{this.props.defaultOption}</option>
                        {this.props.options.map((result) => (
                            <option key={result}>{result}</option>
                        ))}
                    </select>
                </div>
            </form>
        )
    }
}

DropdownIndividual.defaultProps = {
    defaultOption: "None Selected",
    id: "dropdown-selector",
    className: "field-group",
    auiClass: "aui"
};

export default DropdownIndividual;
