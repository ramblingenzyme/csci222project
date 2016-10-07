import React, { Component, PropTypes } from 'react';
import { Link } from 'react-router';
import ReportWriter from './ReportWriter.js'

class ReportPage extends Component {
    render() {
        const handleSubmit = this.props.dispatch;

        return (
            <form className="aui" method="post" onSubmit={handleSubmit}>
                <ReportWriter />
                <div className="buttons-container">
                    <div className="buttons">
                        <button type="submit">Submit</button>
                    </div>
                </div>
            </form>
        )
    }

    handleEditorChange(e) {
        console.log(e.target.getContent());
    }
}

export default ReportPage;
