import { RECEIVE_AUTH_STATUS } from '../const';

export default function authenticateUser(state={logged_in: false, role: null}, action) {
    switch (action.type) {
        case RECEIVE_AUTH_STATUS:
            return action.authStatus;
        default:
            return state;
    }
}
