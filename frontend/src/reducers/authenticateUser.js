import { RECEIVE_AUTH_STATUS } from '../const';

export default function authenticateUser(state = { authed: false, role: 'guest' }, action) {
    switch (action.type) {
        case RECEIVE_AUTH_STATUS:
            return action.authStatus;
        default:
            return state;
    }
}
