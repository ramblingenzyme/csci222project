import { combineReducers } from 'redux';

import { reducer as formReducer } from 'redux-form';
import { combineForms } from 'react-redux-form'

import bugList from './bugList';
import bugPage from './bugPage';
import profile from './profile';
import requesting from './requesting';
import profileList from './profileList';
import authenticateUser from './authenticateUser';

const user = {
    username: '',
    password: '',
};

const searchBox = {
    searchTerm: ''
}

const baseReducer = combineReducers({
    bugList,
    bugPage,
    profile,
    requesting,
    profileList,
    authenticateUser,
    form: formReducer,
    forms: combineForms({
        user,
        searchBox
    }, 'forms')
});

export default baseReducer;
