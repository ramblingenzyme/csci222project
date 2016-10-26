import { connect } from 'react-redux';
import Login from '../components/Login';

const mapStateToProps = state => ({
    authenticateUser: state.authenticateUser
});

const mapDispatchToProps = dispatch => ({})

const LoginContainer = connect(
    mapStateToProps,
    mapDispatchToProps
)(Login);

export default LoginContainer;
