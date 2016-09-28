import React, { Component, PropTypes } from 'react';
import { Link } from 'react-router';

class Menubar extends Component {
    render() {
        return (
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
        )
    }
}

export default Menubar;
