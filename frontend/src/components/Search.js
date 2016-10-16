import React, { Component, PropTypes } from 'react';
import { Link } from 'react-router';
import { Field, reduxForm } from 'redux-form';

class Search extends Component {
    render() {
        return (
            <form className="aui-quicksearch" method="post">
                <label className="assistive" htmlFor={this.props.field}>Search</label>
                <Field className="text large-width-field" name={this.props.field} component="input" type="text" placeholder="Search Bugs"/>
            </form>
        );
    }
}

Search = reduxForm({
    form: 'Search'
})(Search);

export default Search;
