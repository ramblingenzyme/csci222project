import {
    RECEIVE_AUTH_STATUS,
    REQUEST
} from '../const';

import fetch from '../helpers/fetch';

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

export function fetchAuthStatus(username, password, cb) {
    return function(dispatch) {
        dispatch(requestData(true));

        fetch(`/authenticate?username=${username}&password=${password}`, { method: "POST" })
        .then(response => {
            dispatch(recieveAuthStatus(response));
            dispatch(requestData(false));

            if (cb) {
                cb();
            }
        });
    };
}
