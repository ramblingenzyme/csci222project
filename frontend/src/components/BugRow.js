import React, { Component, PropTypes } from 'react';
import { Link } from 'react-router';

class BugRow extends Component {
    render() {
        let keywords = this.props.keywords.map(keyword => <li>{keyword}</li>);
        return (
            <div className="bug">>
                <ul>
                    <li><Link to={`/bug/id/${this.props.id}`}>Title: {this.props.title}</Link></li>
                    <li>Product: {this.props.product}</li>
                    <li>Status: {this.props.status}</li>
                    <li>Priority: {this.props.priority}</li>
                    <li>
                        <ul>
                            {keywords}
                        </ul>
                    </li>
                </ul>
            </div>
        );
    }
}


BugRow.propTypes = {
    id: PropTypes.integer.isRequired,
    title: PropTypes.string.isRequired,
    product: PropTypes.string.isRequired,
    status: PropTypes.string.isRequired,
    priority: PropTypes.integer.isRequired,
    keywords: PropTypes.array.isRequired
}

export default BugRow;
