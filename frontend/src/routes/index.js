import App from '../components/App.js';
import SidebarSearch from '../components/SidebarSearch.js';
import SidebarAnalysis from '../components/SidebarAnalysis.js';
import SidebarAssign from '../components/SidebarAssign.js';
import ProfilePage from '../components/ProfilePage.js';
import ReportPage from '../components/ReportPage.js';
import SearchPage from '../components/SearchPage.js';

import LoginContainer from '../containers/LoginContainer'
import LoginPageContainer from '../containers/LoginPageContainer';

import { fetchSearchResults } from '../actions/'

export default function routes(store) {
    const getSearchResults = (nextState, replace, callback) => {
        store.dispatch(fetchSearchResults(nextState.params.search), callback)
    };

    return {
        path: '/',
        component: App,
        indexRoute: {
            components: {
                main: LoginContainer,
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
                    main: LoginContainer,
                    sidebar: SidebarSearch
                }
            },
            {
                path: '/report/',
                component: ReportPage,
            },
            {
                path: '/analysis/',
                components: {
                    main: LoginContainer,
                    sidebar: SidebarAnalysis
                }
            },
            {
                path: '/assign/',
                components: {
                    main: LoginContainer,
                    sidebar: SidebarAssign
                }
            },
            {
                path: '/review/',
                component: LoginContainer,
            },
            {
                path: '/search/',
                components: {
                    main: SearchPage,
                    sidebar: SidebarSearch
                },
            },
            {
                path: '/profile/',
                component: ProfilePage
            },
        ]
    }
}
