import React, { Component } from 'react';
import { Control, Form } from 'react-redux-form';

class LoginPage extends Component {
    _handleSubmit(user) {
        console.log(user);
        this.props.fetchAuthStatus(user.username, user.password);
    }

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
                    <Form className="aui" model="forms.user" onSubmit={(user) => this._handleSubmit(user)}>
                        <div className="field-group">
                            <label htmlFor="username">
                                Username
                            </label>
                            <Control.text model="forms.user.username" id="username" />
                        </div>
                        <div className="field-group">
                            <label htmlFor="password">Password</label>
                            <Control.text type="password" model="forms.user.password" id="password" />
                        </div>
                        <div className="buttons-container">
                            <div className="buttons">
                                <button type="submit">Submit</button>
                            </div>
                        </div>
                    </Form>
                </div>
                <div className="aui-item">
                    <h3>Register User</h3>
                    form for registering user
                </div>

            </div>
        )
    }
}

export default LoginPage;
