import React, { Component } from 'react';
import { Field, reduxForm } from 'redux-form';

class SearchPage extends Component {
    render() {
        var timeline_options = [
            "Day",
            "Week",
            "Month",
            "Year"
        ];
        var status_options = [
            "Unassigned",
            "Assigned",
            "Patch Submitted",
            "Resolved"
        ];
        var magnitudal_options = [
            "Low",
            "Medium",
            "High",
            "Extreme"
        ];

        return(
            <div id="search-page">
            </div>
        )
    }
}

SearchPage = reduxForm({
    form: 'login'
})(SearchPage);

export default SearchPage;
