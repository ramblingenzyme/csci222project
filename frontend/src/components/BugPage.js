import React, { Component, PropTypes } from 'react';
import { Link } from 'react-router';

class BugPage extends Component {
    _getComments() {
        return this.props.bugPage.comments.map(comment => (
            <div className="comment">
                {comment.content}
            </div>
        ))
    }

    _getCcList() {
        return this.props.bugPage.cclist.map(email => (
            <li>email</li>
        ))
    }

    render() {
        let comments = this._getComments();
        let cclist = this._getCcList();

        return (
            <div className="bugPage">
                <h1>{this.props.bugPage.id} - {this.props.bugPage.title}</h1>
                <p>{this.props.bugPage.description}</p>
                <div className="aui-group">
                    <div className="aui-item">
                        <table className="aui">
                            <tr>
                                <th>Status:</th>
                                <td>{this.props.bugPage.status}</td>
                            </tr>
                            <tr>
                                <th>Severity:</th>
                                <td>{this.props.bugPage.severity}</td>
                            </tr>
                            <tr>
                                <th>Project ID:</th>
                                <td>{this.props.bugPage.project_id}</td>
                            </tr>
                            <tr>
                                <th>Product:</th>
                                <td>{this.props.bugPage.product}</td>
                            </tr>
                            <tr>
                                <th>Component:</th>
                                <td>{this.props.bugPage.component}</td>
                            </tr>
                            <tr>
                                <th>Version:</th>
                                <td>{this.props.bugPage.version}</td>
                            </tr>
                            <tr>
                                <th>OS:</th>
                                <td>{this.props.bugPage.operating_system}</td>
                            </tr>
                        </table>
                    </div>
                    <div className="aui-item">
                        <table className="aui">
                            <tr>
                                <th>Reporter:</th>
                                <td>
                                    <Link to={`/profile/user${this.props.bugPage.reporter}`}>
                                        {this.props.bugPage.reporter}
                                    </Link>
                                </td>
                            </tr>
                            <tr>
                                <th>Assigned to:</th>
                                <td>
                                    <Link to={`/profile/user${this.props.bugPage.assigned_to}`}>
                                        {this.props.bugPage.assigned_to}
                                    </Link>
                                </td>
                            </tr>
                            <tr>
                                <th>Created at:</th>
                                <td>{this.props.bugPage.creation_time}</td>
                            </tr>
                            <tr>
                                <th>Last Modified:</th>
                                <td>{this.props.bugPage.delta_time}</td>
                            </tr>
                            <tr>
                                <th>Target Milestone:</th>
                                <td>{this.props.bugPage.target_milestone}</td>
                            </tr>
                            <tr>
                                <th>Status:</th>
                                <td>{this.props.bugPage.status}</td>
                            </tr>
                            <tr>
                                <th>Votes:</th>
                                <td>{this.props.bugPage.votes}</td>
                            </tr>
                        </table>
                    </div>
                </div>
                <h2>Description</h2>
                {this.props.bugPage.description}
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
    bugPage:    PropTypes.array.isRequired
};

export default BugPage;
