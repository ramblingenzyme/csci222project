import { connect } from 'react-redux';
import ProfilePage from '../components/ProfilePage';

const mapStateToProps = state => ({
    authenticateUser: state.authenticateUser,
    profilePage: state.profile
});

const mapDispatchToProps = dispatch => ({})

const ProfilePageContainer = connect(
    mapStateToProps,
    mapDispatchToProps
)(ProfilePage);

export default ProfilePageContainer;
