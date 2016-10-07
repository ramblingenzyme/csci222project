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
            <form className="aui" method="post" onSubmit={handleSubmit}>
                <div className="field-group">
                    <label htmlFor="username">
                        Username
                    </label>
                    <Field name="username" className="text medium-field"  component="input" type="text" />
                </div>
                <div className="field-group">
                    <label htmlFor="password">Password</label>
                    <Field name="password" className="text medium-field"  component="input" type="password" />
                </div>
                <div className="buttons-container">
                    <div className="buttons">
                        <button type="submit">Submit</button>
                    </div>
                </div>
            </form>
        )
    }
}

LoginPage = reduxForm({
    form: 'login'
})(LoginPage)

export default LoginPage;
