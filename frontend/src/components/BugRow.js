import React, { Component, PropTypes } from 'react';
import { Link } from 'react-router';

class BugRow extends Component {
    render() {
        return (
            <tr>
                <td>{this.props.id}</td>
                <td><Link to={`/bug/id/${this.props.id}`}>{this.props.title}</Link></td>
                <td>{this.props.product}</td>
                <td>{this.props.status}</td>
                <td>{this.props.priority}</td>
            </tr>
        );
    }
}


BugRow.propTypes = {
    id: PropTypes.number.isRequired,
    title: PropTypes.string.isRequired,
    product: PropTypes.string.isRequired,
    status: PropTypes.string.isRequired,
    priority: PropTypes.number.isRequired,
}

export default BugRow;
