import React, { Component, PropTypes } from 'react';
import { Link } from 'react-router';

class Login extends Component {
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
                <p>
                    Hello {this.props.username}
                </p>
            )
        } else {
            return (
                <p>
                    <Link to="/login">Login</Link>
                </p>
            )
        }
    }
}

export default Login;
