import App from '../components/App.js';
import Login from '../components/Login.js';
import LoginPage from '../components/LoginPage.js';

export default {
    path: '/',
    component: App,
    indexRoute: {
        component: Login
    },
    childRoutes: [
        {
            path: 'login',
            component: LoginPage
        }
    ]
}
