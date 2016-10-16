import React, { Component, PropTypes } from 'react';
import { Link } from 'react-router';

import BugRow from './BugRow';

class BugTable extends Component {
    render() {
        let bugs = this._getBugs();
        let navigation = this._getNavigation();

        return (
            <div>
                {bugs}
                {navigation}
            </div>
        );
    }

    _getBugs() {
        return this.props.bugs.map(bug => <BugRow {... bug} />);
    }

    _getNavigation() {
        let previous = undefined;
        if (this.props.page > 1) {
            previous = (
                <li className="">
                    <Link to={`bugs/page/${this.props.page - 1}`}>
                        Previous
                    </Link>
                </li>
            );
        }

        let next = (
            <li className="">
                <Link to={`bugs/page/${this.props.page + 1}`}>
                    Next
                </Link>
            </li>
        );

        let pageRangeStart = this.props.page - (this.props.page % 10) + 1;

        let pages = [];
        for (i=pageRangeStart; i < pageRangeStart + 10; i++) {
            pages.push(
                <li className="">
                    <Link to={`bugs/page/${i}`}>
                        {i}
                    </Link>
                </li>
            );
        }

        return (
            <ul className="">
                {previous}
                {pages}
                {next}
            </ul>
        );
    }
}

BugRow.propTypes = {
    bugs: PropTypes.array.isRequired,
    page: PropTypes.number.isRequired
}

export default BugTable;
