import React, { Component } from 'react';
import { Field, reduxForm } from 'redux-form';

class LoginPage extends Component {
    constructor() {
        super();
        this.state = {
            username: '',
            password: ''
        }
    }

    render() {
        return(
            <Form method="post" to={`/test/${this.state.username}`}>
                <div>
                    <label htmlFor="username">
                        Username
                    </label>
                    <input type="text"
                        placeholder="Username"
                        value={this.state.username}
                        onChange={event => this.setState({username: event.target.value})}
                    />
                </div>
                <div htmlFor="password">
                    <label>
                    <input
                        type="password"
                        placeholder="Password"
                        onChange={event => this.setState({password: event.target.value})}
                    />
                </div>
                <input
                    type="submit"
                />
            </Form>
        )
    }
}

export default LoginPage;
