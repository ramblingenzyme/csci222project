import React, { Component } from 'react';
import { Control, Form, Errors } from 'react-redux-form';

class LoginForm extends Component {
    _required(val) {
        return val && val.length;
    }

    _handleLogin(user) {
        return this.props.fetchAuthStatus(user.username, user.password)
            .then(response => {
                if (response.authed === false) {
                    return alert("Incorrect username/password");
                } else {
                    return Promise.resolve(true);
                }
            });
    }

    render() {
        return (
            <Form className="aui field-group" model="forms.user" onSubmit={(user) => this._handleLogin(user)}>
                <div className="field-group">
                    <label htmlFor="username">
                        Username
                    </label>
                    <Control.text
                        model="forms.user.username"
                        id="username"
                        validators={{
                            required: this._required
                        }}
                        className="text"
                    />
                    <Errors
                        className="error"
                        model="forms.user.username"
                        show="touched"
                        messages={{
                            required: 'Required'
                        }}
                    />
                </div>
                <div className="field-group">
                    <label htmlFor="password">Password</label>
                    <Control.text
                        type="password"
                        model="forms.user.password"
                        id="password"
                        validators={{
                            required: this._required
                        }}
                        className="text"
                    />
                    <Errors
                        className="error"
                        model="forms.user.password"
                        show="touched"
                        messages={{
                            required: 'Required'
                        }}
                    />
                </div>
                <div className="buttons-container">
                    <button type="submit">Submit</button>
                </div>
            </Form>
        )
    }

}

export default LoginForm;
