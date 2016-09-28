import React, { Component, PropTypes } from 'react';

class BugPage extends Component {
    render() {
        return (
            <div class="bugPage">
            </div>
        );
    }
}

BugPage.propTypes = {
    cclist:       PropTypes.array.isRequired,
    comments:     PropTypes.array.isRequired,
    component:    PropTypes.string.isRequired,
    createdAt:    PropTypes.string.isRequired,
    description:  PropTypes.string.isRequired,
    lastModified: PropTypes.string.isRequired,
    os:           PropTypes.string.isRequired,
    product:      PropTypes.string.isRequired,
    status:       PropTypes.string.isRequired,
    title:        PropTypes.string.isRequired,
    version:      PropTypes.string.isRequired,
    id:           PropTypes.integer.isRequired,
    priority:     PropTypes.integer.isRequired,
};

export default BugPage;
