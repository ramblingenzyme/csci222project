import { combineReducers } from 'redux';

import requesting from './requesting.js';
import authenticateUser from './authenticateUser.js';

const baseReducer = combineReducers({
    requesting,
    authenticateUser
});

export default baseReducer;
