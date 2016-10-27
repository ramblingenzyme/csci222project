import React, { Component } from 'react';

import LoginForm from '../containers/LoginFormContainer';
import RegisterForm from '../containers/RegisterFormContainer';

class LoginPage extends Component {
    _logout() {
        this.props.logout();
        return false;
    }

    render() {
        if (this.props.authenticateUser.authed) {
            return (
                <div>
                    <form onSubmit={this._logout}>
                        <div className="buttons-container">
                            <div className="buttons">
                                <button type="submit">Logout</button>
                            </div>
                        </div>
                    </form>
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
