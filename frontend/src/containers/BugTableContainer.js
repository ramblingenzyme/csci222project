import { connect } from 'react-redux';
import BugTable from '../components/BugTable';

const mapStateToProps = state => ({bugTable: state.bugList});

const mapDispatchToProps = dispatch => ({})

const BugTableContainer = connect(
    mapStateToProps,
    mapDispatchToProps
)(BugTable);

export default BugTableContainer;
