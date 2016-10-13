import { connect } from 'react-redux';
import LoginPage from '../components/LoginPage.js';
import { fetchAuthStatus } from '../actions';

const mapStateToProps = state => ({});

const mapDispatchToProps = dispatch => ({
    handleSubmit: (username, password) => {
        dispatch(fetchAuthStatus(username, password))
    }
});

const LoginPageContainer = connect(
    mapStateToProps,
    mapDispatchToProps
)(LoginPage);

export default LoginPageContainer
