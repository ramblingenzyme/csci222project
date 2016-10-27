import React, { Component } from 'react';
import { Control, Form, Errors } from 'react-redux-form';
import Fetch from '../helpers/fetch.js'

class RegisterForm extends Component {
    _passwordsMatch({ password, confirmPassword }) {
        return password === confirmPassword;
    }

    _required(val) {
        return val && val.length;
    }

    _handleRegister(user) {
        return Fetch('add_user', {
            method: "POST",
            headers: {
                'Content-Type': 'application/json'
            },
            body: JSON.stringify({
                user_info: {
                    username: user.username,
                    email: user.email,
                    password: user.password,
                    privilege_level: "Reporter"
                }
            })
        }).then(response => {
            if (response) {
                return alert("You have been registered");
            } else {
                alert("Error, could not register, PEBKAC probably.")
                return false;
            }
        })
    }

    render() {
        return (
            <Form
                className="aui"
                model="forms.register"
                onSubmit={(user) => this._handleRegister(user)}
            >
                <div className="field-group">
                    <label htmlFor="username">
                        Username
                    </label>
                    <Control.text
                        model="forms.register.username"
                        id="username"
                        validators={{
                            required: this._required
                        }}
                        className="text"
                    />
                    <Errors
                        className="error"
                        model="forms.register.username"
                        show="touched"
                        messages={{
                            required: 'Required'
                        }}
                    />
                </div>
                <div className="field-group">
                    <label htmlFor="email">
                        Email
                    </label>
                    <Control.text
                        model="forms.register.email"
                        id="email"
                        validators={{
                            required: this._required
                        }}
                        className="text"
                    />
                    <Errors
                        className="error"
                        model="forms.register.email"
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
                        model="forms.register.password"
                        id="password"
                        validators={{
                            required: this._required
                        }}
                        className="text"
                    />
                    <Errors
                        className="error"
                        model="forms.register.password"
                        show="touched"
                        messages={{
                            required: 'Required'
                        }}
                    />
                </div>
                <div className="field-group">
                    <label htmlFor="password">Confirm Password</label>
                    <Control.text
                        type="password"
                        model="forms.register.confirmPassword"
                        id="confirmPassword"
                        validators={{
                            required: this._required
                        }}
                        className="text"
                    />
                    <Errors
                        className="error"
                        model="forms.register.confirmPassword"
                        show="touched"
                        messages={{
                            required: 'Required',
                        }}
                    />
                </div>
                <div className="buttons-container">
                    <button type="submit">Register</button>
                </div>
            </Form>
        )
    }
}

export default RegisterForm;
