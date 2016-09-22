import App from '../components/App.js';
import Login from '../components/Login.js';

export default {
    path: '/',
    component: App,
    indexRoute: {
        component: Login
    },
    childRoutes: [
        {
            path: 'test/:username',
            component: Login
        }
    ]
}
