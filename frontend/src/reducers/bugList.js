import { RECEIVE_BUG_LIST } from '../const';

export default function bugList(state = {}, action) {
    switch (action.type) {
        case RECEIVE_BUG_LIST:
            return action.bugList;
        default:
            return state;
    }
}
