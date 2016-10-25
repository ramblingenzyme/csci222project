import { RECEIVE_BUG_INFO } from '../const';

export default function bugPage(state = {}, action) {
    switch (action.type) {
        case RECEIVE_BUG_INFO:
            return action.bugInfo;
        default:
            return state;
    }
}
