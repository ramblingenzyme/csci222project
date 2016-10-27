import { connect } from 'react-redux';
import LoginPage from '../components/LoginPage.js';

const mapStateToProps = state => ({
    authenticateUser: state.authenticateUser
});

const mapDispatchToProps = dispatch => ({});

const LoginPageContainer = connect(
    mapStateToProps,
    mapDispatchToProps
)(LoginPage);

export default LoginPageContainer;
