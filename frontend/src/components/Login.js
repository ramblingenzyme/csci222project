import React, { Component } from 'react';
import Form from 'react-router-form';

class Login extends Component {
    componentWillUpdate(nextProps, nextState) {
    }

    render() {
        return(
            <Form method="post">
                <input type="text" value={this.state.username} onChange={event => this.setState({username: event.target.username})} />
                <input type="text" value={this.state.password} onChange={event => this.setState({password: event.target.password})} />
            </Form>
        )
    }
}

export default Login;
