import React, { Component } from 'react';

import LoginForm from '../containers/LoginFormContainer';
import RegisterForm from './RegisterForm';

class LoginPage extends Component {

    render() {
        if (this.props.authenticateUser.authed) {
            return (
                <div>
                    Logout here
                </div>
            )
        }

        return (
            <div className="aui-group">
                <div className="aui-item">
                    <h3>Login</h3>
                    <LoginForm />
                </div>
                <div className="aui-item">
                    <h3>Register User</h3>
                    <RegisterForm />
                </div>
            </div>
        )
    }
}

export default LoginPage;
