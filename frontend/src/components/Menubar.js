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
                        <Link to={'/Report/'}>Report </Link>
                    </li>
                    <li>
                        <Link to={'/Analysis/'}>Analysis </Link>
                    </li>
                    <li>
                        <Link to={'/Assign/'}>Assign </Link>
                    </li>
                    <li>
                        <Link to={'/Review/'}>Review </Link>
                    </li>
                    <li>
                        <Link to={'/Search/'}>Search </Link>
                    </li>
                    <li>
                        <Link to={'/Profile/'}>Profile </Link>
                    </li>
                </ul>
            </div>
        )
    }
}

export default Menubar;
