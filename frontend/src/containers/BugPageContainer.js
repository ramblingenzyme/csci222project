import { connect } from 'react-redux';
import BugPage from '../components/BugPage';

const mapStateToProps = state => ({bugPage: state.bugPage});

const mapDispatchToProps = dispatch => ({})

const BugPageContainer = connect(
    mapStateToProps,
    mapDispatchToProps
)(BugPage);

export default BugPageContainer;
