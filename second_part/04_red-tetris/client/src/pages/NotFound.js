import React, { useState } from "react";
import { Redirect } from "react-router-dom";
import Button from "@material-ui/core/Button";
import ExitToAppIcon from '@material-ui/icons/ExitToApp';

function NotFound() {
    const [redirectUrl, setredirectUrl] = useState(false);

    function backToGoodUrl() {
        return setredirectUrl(true);
    }

    function displayPage404() {
        if (redirectUrl) {
            return <Redirect to="/" />;
        }
        return (
            <>
                <h1>GAME OVER</h1>
                <h2>404- Page not found</h2>
                <Button onClick={backToGoodUrl} variant='contained' color='primary'
                    startIcon={<ExitToAppIcon />}>
                    Back
                </Button>
            </>
            );
    }
    return (
        <div className="dark-backGround retro-border formforname-container">
            {displayPage404()}
        </div>
    );
}
export default NotFound;
