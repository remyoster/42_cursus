import React from "react";
import CircularProgress from "@material-ui/core/CircularProgress";

function Loader() {
    return (
        <div className='loader-component flex-container'>
            <CircularProgress color="secondary" />
        </div>
    );
}

export default Loader;