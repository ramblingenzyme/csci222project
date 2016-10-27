import { RECEIVE_PROFILE_INFO } from '../const';

export default function profile(state = {}, action) {
    switch (action.type) {
        case RECEIVE_PROFILE_INFO:
            return action.profileInfo;
        default:
            return state;
    }
}
