import React, { Component, PropTypes } from 'react';

class BugPage extends Component {
    _getComments() {
        return this.props.comments.map(comment => (
            <div className="comment">
                {comment.content}
            </div>
        ))
    }

    _getCcList() {
        return this.props.cclist.map(email => (
            <li>email</li>
        ))
    }

    render() {
        let comments = this._getComments();
        let cclist = this._getCcList();

        return (
            <div class="bugPage">
                <h1>{this.props.id} - {this.props.title}</h1>
                <p>{this.props.description}</p>
                <table>
                    <tr>
                        <th>Status:</th>
                        <td>{this.props.status}</td>
                    </tr>
                    <tr>
                        <th>Product:</th>
                        <td>{this.props.product}</td>
                    </tr>
                    <tr>
                        <th>Version:</th>
                        <td>{this.props.version}</td>
                    </tr>
                    <tr>
                        <th>Created at:</th>
                        <td>{this.props.createdAt}</td>
                    </tr>
                    <tr>
                        <th>Last Modified:</th>
                        <td>{this.props.lastModified}</td>
                    </tr>
                    <tr>
                        <th>OS:</th>
                        <td>{this.props.os}</td>
                    </tr>
                    <tr>
                        <th>Component:</th>
                        <td>{this.props.component}</td>
                    </tr>
                </table>
                <h2>CC List</h2>
                <ul>
                    {cclist}
                </ul>
                <h2>Comments</h2>
                {comments}
            </div>
        );
    }
}

BugPage.propTypes = {
    bug_id:           PropTypes.integer.isRequired,
    creation_time:    PropTypes.string.isRequired,
    delta_time:       PropTypes.string.isRequired,
    title:            PropTypes.string.isRequired,
    description:      PropTypes.string.isRequired,
    product:          PropTypes.string.isRequired,
    component:        PropTypes.string.isRequired,
    version:          PropTypes.string.isRequired,
    operating_system: PropTypes.string.isRequired,
    target_milestone: PropTypes.string.isRequired,
    status:           PropTypes.string.isRequired,
    priority:         PropTypes.integer.isRequired,
    severity:         PropTypes.integer.isRequired,
    reporter:         PropTypes.string.isRequired,
    assigned_to:      PropTypes.string.isRequired,
    project_id:       PropTypes.string.isRequired,
    cclist:           PropTypes.array.isRequired,
    comments:         PropTypes.array.isRequired,
};

export default BugPage;
