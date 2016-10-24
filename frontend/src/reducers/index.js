import { combineReducers } from 'redux';

import requesting from './requesting.js';
import { reducer as formReducer } from 'redux-form';
import authenticateUser from './authenticateUser.js';
import { combineForms } from 'react-redux-form'

const initialUser = {
    username: '',
    password: '',
};

const baseReducer = combineReducers({
    requesting,
    authenticateUser,
    form: formReducer,
    forms: combineForms({
        user: initialUser
    }, 'forms')
});

export default baseReducer;
