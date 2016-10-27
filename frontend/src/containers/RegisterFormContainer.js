import { connect } from 'react-redux';
import { bindActionCreators } from 'redux';
import RegisterForm from '../components/RegisterForm.js';

import { fetchAuthStatus } from '../actions'

const mapStateToProps = state => ({})

function mapDispatchToProps(dispatch) {
    return bindActionCreators({
       fetchAuthStatus
    }, dispatch);
}

const RegisterFormContainer = connect(
    mapStateToProps,
    mapDispatchToProps
)(RegisterForm);

export default RegisterFormContainer;
