import { RECEIVE_PROFILE_LIST } from '../const';

export default function profileList(state = {}, action) {
    switch(action.type) {
        case RECEIVE_PROFILE_LIST:
            return action.profileList;
        default:
            return state;
    }
}
