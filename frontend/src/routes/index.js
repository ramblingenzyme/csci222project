import App from '../components/App.js';
import Login from '../components/Login.js';
import SidebarSearch from '../components/SidebarSearch.js';
import SidebarAnalysis from '../components/SidebarAnalysis.js';
import SidebarAssign from '../components/SidebarAssign.js';
import ProfilePage from '../components/ProfilePage.js';
import ReportPage from '../components/ReportPage.js';

import LoginPageContainer from '../containers/LoginPageContainer.js';

export default {
    path: '/',
    component: App,
    indexRoute: {
        components: {
            main: Login,
            sidebar: SidebarSearch
        }
    },
    childRoutes: [
        {
            path: 'login',
            component: LoginPageContainer
        },
        {
            path: 'test/:username',
            components: {
                main: Login,
                sidebar: SidebarSearch
            }
        },
        {
            path: '/Report/',
            component: ReportPage,
        },
        {
            path: '/Analysis/',
            components: {
                main: Login,
                sidebar: SidebarAnalysis
            }
        },
        {
            path: '/Assign/',
            components: {
                main: Login,
                sidebar: SidebarAssign
            }
        },
        {
            path: '/Review/',
            component: Login,
        },
        {
            path: '/Search/',
            components: {
                main: Login,
                sidebar: SidebarSearch
            }
        },
        {
            path: '/Profile/',
            component: ProfilePage
        }
    ]
}
