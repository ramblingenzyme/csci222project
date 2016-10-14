import { connect } from 'react-redux';
import { bindActionCreators } from 'redux';
import LoginPage from '../components/LoginPage.js';

import { fetchAuthStatus } from '../actions'

const mapStateToProps = state => ({});

function mapDispatchToProps(dispatch) {
    return bindActionCreators({
       fetchAuthStatus
    }, dispatch);
}

const LoginPageContainer = connect(
    mapStateToProps,
    mapDispatchToProps
)(LoginPage);

export default LoginPageContainer
