import {
    RECEIVE_AUTH_STATUS,
    REQUEST
} from '../const';

import fetchFromBackend from '../helpers/fetch';

export function requestData(requesting) {
    return {
        type: REQUEST,
        requesting
    };
}

export function recieveAuthStatus(authStatus) {
    return {
        type: RECEIVE_AUTH_STATUS,
        authStatus
    };
}

export function fetchAuthStatus(username, password) {
    return function(dispatch) {
        dispatch(requestData(true));

        return fetchFromBackend(`authenticate`, {
            method: 'POST',
            headers: {
                'Content-Type': 'application/json'
            },
            body: {
                username,
                password
            }
        }).then(response => {
            dispatch(recieveAuthStatus(response));
            return dispatch(requestData(false));
        });
    };
}
