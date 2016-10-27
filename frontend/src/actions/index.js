import {
    REQUEST,
    RECEIVE_BUG_INFO,
    RECEIVE_BUG_LIST,
    RECEIVE_AUTH_STATUS,
    RECEIVE_PROFILE_INFO,
    RECEIVE_PROFILE_LIST
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

export function receiveProfileList(profileList) {
    return {
        type: RECEIVE_PROFILE_LIST,
        profileList
    }
}

export function logout() {
    return {
        type: LOGOUT,
        authStatus: {
            authed: false,
            role: "guest"
        }
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
        return genericApiRequest(dispatch, receiveAuthStatus, endpoint, params);
    }
}

export function fetchBugPage(id, cb) {
    return function(dispatch) {
        let endpoint = `bug?id=${id}`;
        return genericApiRequest(dispatch, receiveBugInfo, endpoint)
            .then(() => {
                if (cb) {
                    cb();
                }
            })
    }

}

export function fetchSearchResults(query, cb) {
    return function (dispatch) {
        let endpoint = 'search';
        let params = {
            method: 'POST',
            headers: {
                'Content-Type': 'application/json'
            },
            body: JSON.stringify(query)
        }

        genericApiRequest(dispatch, receiveBugList, endpoint, params)
            .then(() => {
                if (cb) {
                    cb();
                }
            });
    }
}

export function fetchBugTable(page, cb) {
    return function (dispatch) {
        let endpoint = `get_normal_search`;
        let params = {
            method: 'POST',
            headers: {
                'Content-Type': 'application/json'
            },
            body: JSON.stringify({ page, query: '' })
        }

        return genericApiRequest(dispatch, receiveBugList, endpoint, params)
            .then(() => {
                if (cb) {
                    cb();
                }
            });
    }
}

export function fetchProfile(username) {
    return function (dispatch) {
        let endpoint = `profile/${username}`

        return genericApiRequest(dispatch, receiveProfileInfo, endpoint);
    }
}

export function fetchProfileList() {
    return function (dispatch) {
        let endpoint = `profiles`

        return genericApiRequest(dispatch, receiveProfileList, endpoint);
    }
}
