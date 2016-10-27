import React, { Component } from 'react';
import { Link } from 'react-router';

class ProfilePage extends Component {
    render() {
        let content = this._getContent();
        return (
            <div>
                {content}
            </div>
        );
    }

    _getContent() {
        return (
            <section className="ProfileInfo">
                <div id="username">
                    <strong>Username:</strong>
                    <span>{this.props.profilePage.username}</span>
                </div>
                <div id="email">
                    <strong>Email: </strong>
                    <span>{this.props.profilePage.email}</span>
                </div>
                <div id="role">
                    <strong>Role: </strong>
                    <span>{this.props.profilePage.privilege_level}</span>
                </div>
           </section>
        );
    }
}

export default ProfilePage;
