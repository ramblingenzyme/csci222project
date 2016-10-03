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
        const handleSubmit = this.props.dispatch;

        return(
            <form method="post" onSubmit={handleSubmit}>
                <div>
                    <label htmlFor="username">
                        Username
                    </label>
                    <Field name="username" component="input" type="text" />
                </div>
                <div>
                    <label htmlFor="password">Password</label>
                    <Field name ="password" component="input" type="password" />
                </div>
                <button type="submit">Submit</button>
            </form>
        )
    }
}

LoginPage = reduxForm({
    form: 'login'
})(LoginPage)

export default LoginPage;
