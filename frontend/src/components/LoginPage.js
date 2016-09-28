import React, { Component } from 'react';
import Form from 'react-router-form';

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
                <input type="text"
                    placeholder="Username"
                    value={this.state.username}
                    onChange={event => this.setState({username: event.target.value})}
                />
                <input
                    type="text"
                    placeholder="Password"
                    onChange={event => this.setState({password: event.target.value})}
                />
                <input
                    type="submit"
                />
            </Form>
        )
    }
}

export default LoginPage;
