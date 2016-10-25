import {
    REQUEST,
    RECEIVE_BUG_INFO,
    RECEIVE_BUG_LIST,
    RECEIVE_AUTH_STATUS,
    RECEIVE_PROFILE_INFO
} from '../const';

import genericApiRequest from './genericApiRequest';

// PURE ACTIONS
export function requestData(requesting) {
    return {
        type: REQUEST,
        requesting
    };
}

export function receiveAuthStatus(authStatus) {
    return {
        type: RECEIVE_AUTH_STATUS,
        authStatus
    };
}

export function receiveBugInfo(bugInfo) {
    return {
        type: RECEIVE_BUG_INFO,
        bugInfo
    };
}

export function receiveBugList(bugList) {
    return {
        type: RECEIVE_BUG_LIST,
        bugList
    };
}

export function receiveProfileInfo(profileInfo) {
    return {
        type: RECEIVE_PROFILE_INFO,
        profileInfo
    }
}

// THUNKS
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
        genericApiRequest(dispatch, receiveAuthStatus, endpoint, params);
    }
}

export function fetchBugPage(id) {
    return function(dispatch) {
        let endpoint = `bugs/${id}`;
        genericApiRequest(dispatch, receiveBugInfo, endpoint);
    }

}

export function fetchSearchResults(query) {
    return function (dispatch) {
        let endpoint = 'search';
        let params = {
            method: 'POST',
            headers: {
                'Content-Type': 'application/json'
            },
            body: JSON.stringify(query)
        }

        genericApiRequest(dispatch, receiveBugList, endpoint, params);
    }
}

export function fetchBugtable(page) {
    return function (dispatch) {
        let endpoint = `bugpage/${page}`;

        genericApiRequest(dispatch, receiveBugList, endpoint);
    }
}

export function fetchProfile(id) {
    return function (dispatch) {
        let endpoint = `profile/${id}`

        genericApiRequest(dispatch, receiveProfileInfo, endpoint);
    }
}
