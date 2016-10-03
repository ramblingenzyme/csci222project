import { combineReducers } from 'redux';

import requesting from './requesting.js';
import { reducer as formReducer } from 'redux-form';
import authenticateUser from './authenticateUser.js';

const baseReducer = combineReducers({
    requesting,
    authenticateUser,
    form: formReducer
});

export default baseReducer;
