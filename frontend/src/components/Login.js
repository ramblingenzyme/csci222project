import React, { Component, PropTypes } from 'react';
import { Link } from 'react-router';

class Login extends Component {
    render() {
        let content = this._getContent();
        return (
            <div>
                {content}
            </div>
        );
    }

    _getContent() {
        if (this.props.authenticateUser.authed) {
            return (
                <div>
                    Hello {this.props.authenticateUser.username}
                </div>
            );
        } else {
            return (
                <div>
                    <Link to="/login">Login</Link>
                </div>
            );
        }
    }
}

export default Login;
