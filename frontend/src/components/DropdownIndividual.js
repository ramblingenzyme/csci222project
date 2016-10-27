import React, { Component, PropTypes } from 'react';
import { Control } from 'react-redux-form';

class DropdownIndividual extends Component {
    render() {
        return (
            <div className={this.props.className}>
                <label htmlFor={this.props.id}>
                    {this.props.title}
                </label>
                <Control.select className="select" component="select" id={this.props.id} name={this.props.id}
                    model={this.props.model}>
                    <option>{this.props.defaultOption}</option>
                    {this.props.options.map((result) => (
                        <option key={result}>{result}</option>
                    ))}
                </Control.select>
            </div>
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
