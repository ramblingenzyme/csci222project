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
        if (this.props.loggedIn) {
            return (
                <div>
                    Hello {this.props.username}
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
