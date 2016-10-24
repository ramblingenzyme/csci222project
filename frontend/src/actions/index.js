import {
    REQUEST,
    RECEIVE_BUG_INFO,
    RECEIVE_AUTH_STATUS,
    RECEIVE_SEARCH_RESULTS,
} from '../const';

import fetchFromBackend from '../helpers/fetch';

function genericApiRequest(dispatch, action, endpoint, params = { method: 'GET', headers: {} }) {
    return fetchFromBackend(endpoint, params)
        .then(response => {
            dispatch(action(response));
            return dispatch(requestData(false));
        });
}

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

export function recieveBugInfo(bugInfo) {
    return {
        type: RECEIVE_BUG_INFO,
        bugInfo
    };
}

export function recieveSearchResults(searchResults) {
    return {
        type: RECEIVE_SEARCH_RESULTS,
        searchResults
    };
}

export function fetchAuthStatus(username, password) {
    return function(dispatch) {
        let endpoint = 'authenticate';
        let params = {
            method: 'POST',
            headers: {
                'Content-Type': 'application/json',
                "Accept": 'application/json'
            },
            body: JSON.stringify({
                username,
                password
            })
        };
        genericApiRequest(dispatch, recieveAuthStatus, endpoint, params);
    }
}

export function fetchBugPage(id) {
    return function(dispatch) {
        let endpoint = `bugs/${id}`;
        genericApiRequest(dispatch, recieveBugInfo, endpoint);
    }

}

export function fetchSearchResults(query) {
    return function (dispatch) {
        console.log(query);
        let endpoint = 'search';
        let params = {
            method: 'POST',
            headers: {
                'Content-Type': 'application/json'
            },
            body: JSON.stringify(query)
        }

        genericApiRequest(dispatch, recieveSearchResults, endpoint, params);
    }
}
