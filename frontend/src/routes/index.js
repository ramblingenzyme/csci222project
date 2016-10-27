import App from '../components/App.js';
import SidebarSearch from '../components/SidebarSearch.js';
import SidebarAnalysis from '../components/SidebarAnalysis.js';
import SidebarAssign from '../components/SidebarAssign.js';
import ProfilePage from '../components/ProfilePage.js';
import ReportPage from '../components/ReportPage.js';
import SearchPage from '../components/SearchPage.js';

import BugTableContainer from '../containers/BugTableContainer';
import BugPageContainer from '../containers/BugPageContainer';

import LoginContainer from '../containers/LoginContainer';
import LoginPageContainer from '../containers/LoginPageContainer';

import { fetchSearchResults, fetchBugPage, fetchBugTable } from '../actions/'

export default function routes(store) {
    const getSearchResults = (nextState, replace, callback) => {
        store.dispatch(fetchSearchResults({
            query: nextState.query.searchTerm,
            page: nextState.params.page
        }, callback))
    };

    const getBugPage = (nextState, replace, callback) => {
        store.dispatch(fetchBugPage(nextState.params.id, callback));
    }

    const getBugTable = (nextState, replace, callback) => {
        store.dispatch(fetchBugTable(nextState.params.page || 0, callback));
    }

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
                path: 'report',
                component: ReportPage,
            },
            {
                path: 'analysis',
                components: {
                    main: LoginContainer,
                    sidebar: SidebarAnalysis
                }
            },
            {
                path: 'assign',
                components: {
                    main: LoginContainer,
                    sidebar: SidebarAssign
                }
            },
            {
                path: 'review',
                component: LoginContainer,
            },
            {
                path: 'search',
                indexRoute: {
                    components: {
                        main: SearchPage,
                        sidebar: SidebarSearch
                    }
                },
                childRoutes: [
                    {
                        path: 'page/:page',
                        component: BugTableContainer,
                        onEnter: getBugTable
                    }
                ]
            },
            {
                path: 'profile',
                indexRoute: {
                    component: ProfilePage
                },
                childRoutes: [
                    {
                        path: 'id/:id',
                        component: ProfilePage
                    }
                ]

            },
            {
                path: 'bugs',
                indexRoute: {
                    component: BugTableContainer,
                    onEnter: getBugTable
                },
                childRoutes: [
                    {
                        path: 'id/:id',
                        component: BugPageContainer,
                        onEnter: getBugPage
                    }
                ]
            }
        ]
    }
}
