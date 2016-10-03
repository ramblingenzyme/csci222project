import React, { Component, PropTypes } from 'react';
import { Link } from 'react-router';

class ProfilePage extends Component {
    render() {
        let content = this._getContent();
        return (
            <div>
                {content}
            </div>
        )
    }

    _getContent() {
        if (this.props.loggedIn) {
            return (
                <section className="ProfileInfo">
                    <div id="username">
                        <strong>Username:</strong>
                        <span>James</span>
                        /* <span>{this.props.username}</span> */
                    </div>
                    <div id="email">
                        <strong>Email:</strong>
                        <span>stub@gmail.com</span>
                        /* <span>{this.props.email}</span> */
                    </div>
                </section>
            )
        } else {
            return (
                <p>
                    You must <Link to="/login">login</Link> to view this page
                </p>
            )
        }
    }
}

export default ProfilePage;