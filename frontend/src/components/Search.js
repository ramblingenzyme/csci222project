import React, { Component, PropTypes } from 'react';
import { Link } from 'react-router';
import Form from 'react-router-form';

class Search extends Component {
    render() {
        return (
            <Form className="aui-quicksearch" to={`/search/page/1/`}  method="POST">
                <label className="assistive" htmlFor="search">Search</label>
                <input className="text large-width-field" name="search" type="text" placeholder="Search Bugs"/>
            </Form>
        );
    }
}

export default Search;
