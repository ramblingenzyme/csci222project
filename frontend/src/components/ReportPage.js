import React, { Component, PropTypes } from 'react';
import { Link } from 'react-router';
import ReportWriter from './ReportWriter.js'

class ReportPage extends Component {
    render() {
        return (
            <div>
                <ReportWriter />

            </div>
        )
    }

    handleEditorChange(e) {
        console.log(e.target.getContent());
    }
}

export default ReportPage;
