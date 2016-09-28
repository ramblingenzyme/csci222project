import App from '../components/App.js';
import Login from '../components/Login.js';
import SidebarSearch from '../components/SidebarSearch.js';
import SidebarAnalysis from '../components/SidebarAnalysis.js';
import SidebarAssign from '../components/SidebarAssign.js';

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
            path: 'test/:username',
            components: {
                main: Login,
                sidebar: SidebarSearch
            }
        },
        {
            path: '/Report/',
            component: {
                main: Login,
            }
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
            component: {
                main: Login,
            }
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
            component: {
                main: Login,
            } 
        }
         
        
    ]
}
