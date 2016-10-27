import { connect } from 'react-redux';
import ReportPage from '../components/ReportPage.js';

const mapStateToProps = state => ({
    authenticateUser: state.authenticateUser
});

const mapDispatchToProps = dispatch => ({});

const ReportPageContainer = connect(
    mapStateToProps,
    mapDispatchToProps
)(ReportPage);

export default ReportPageContainer;
