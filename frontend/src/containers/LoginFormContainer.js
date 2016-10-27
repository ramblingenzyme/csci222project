import { connect } from 'react-redux';
import { bindActionCreators } from 'redux';
import LoginForm from '../components/LoginForm.js';

import { fetchAuthStatus } from '../actions'

const mapStateToProps = state => ({})

function mapDispatchToProps(dispatch) {
    return bindActionCreators({
       fetchAuthStatus
    }, dispatch);
}

const LoginFormContainer = connect(
    mapStateToProps,
    mapDispatchToProps
)(LoginForm);

export default LoginFormContainer;
