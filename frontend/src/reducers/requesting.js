import { REQUEST } from '../const/';

export default function requesting(state = false, action) {
    switch (action.type) {
        case REQUEST:
            return action.requesting;
        default:
            return state
    }
}
