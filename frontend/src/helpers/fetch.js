import fetch from 'isomorphic-fetch';

export default function (url, params = { method: "GET", headers:{} }) {
    if (!params.headers) {
        params.headers = {};
    }

    return fetch(`/backend${url}`, params).then(response => {
        if (!response.ok) {
            return Promise.reject(response);
        } else if (response.headers.get('Content-Type').indexOf('application/json') > -1) {
            return response.json();
        } else {
            return response.text();
        }
    })

}
