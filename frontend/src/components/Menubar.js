import React, { Component, PropTypes } from 'react';
import { Link } from 'react-router';

class Menubar extends Component {
    render() {
        return (
            <div className="aui-primary-header">
                <h1 id="logo" className="aui-header-logo aui-header-logo-aui">
                </h1>
                <ul className="aui-nav">
                    <li>
                        <Link to={'/bugs'}>Bugs</Link>
                    </li>
                    <li>
                        <Link to={'/report/'}>Report</Link>
                    </li>
                    <li>
                        <Link to={'/analysis/'}>Analysis</Link>
                    </li>
                    <li>
                        <Link to={'/search/'}>Search</Link>
                    </li>
                    <li>
                        <Link to={'/profile/'}>Profile</Link>
                    </li>
                </ul>
            </div>
        );
    }
}

/* TODO: Stretch Goals
 <li>
 <Link to={'/assign/'}>Assign</Link>
 </li>
 <li>
 <Link to={'/review/'}>Review</Link>
 </li>
 */

export default Menubar;
