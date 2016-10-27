import { connect } from 'react-redux';
import { bindActionCreators } from 'redux';
import LoginPage from '../components/LoginPage.js';

import { logout } from '../actions';

const mapStateToProps = state => ({
    authenticateUser: state.authenticateUser
});

function mapDispatchToProps(dispatch) {
    return bindActionCreators({
       logout
    }, dispatch);
}

const LoginPageContainer = connect(
    mapStateToProps,
    mapDispatchToProps
)(LoginPage);

export default LoginPageContainer;
