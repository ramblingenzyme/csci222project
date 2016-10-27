import fetchFromBackend from '../helpers/fetch';
import { requestData } from './index'

export default function genericApiRequest(dispatch, action, endpoint, params = { method: 'GET', headers: {} }) {
    return fetchFromBackend(endpoint, params)
        .then(response => {
            dispatch(action(response));
            dispatch(requestData(false));

            return response;
        });
}
