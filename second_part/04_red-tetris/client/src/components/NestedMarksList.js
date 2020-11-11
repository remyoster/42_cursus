import React, { useState } from 'react';
import {
  List, ListItem, ListItemText, Collapse,
  Typography, Divider
} from '@material-ui/core';
import ExpandLess from '@material-ui/icons/ExpandLess';
import ExpandMore from '@material-ui/icons/ExpandMore';
import { withStyles } from '@material-ui/core/styles';
import { gameOptionsToText } from './Menu';

/*
** Display a nested list from best scores
*/

export default function NestedMarksList({ items, gameType }) {
  const [open, setOpen] = useState({});

  /*
  ** Create an object with each entry === one element
  */

  function handleClick(idx) {
    let tmpOpen = { ...open };
    tmpOpen[idx] = tmpOpen[idx] ? !tmpOpen[idx] : true;
    setOpen(tmpOpen);
  };

  /*
  ** If there are no marks yey
  */

  function displayEmptyItems() {
    if (items.length === 0)
      return (
        <div className='margin-10'>
          <Typography variant='body1'>
            No best scores yet
        </Typography>
        </div>
      );
  }

  return (
    <CustomList
      className="retro-border"
      aria-labelledby={"nested-list-subheader-" + gameType}
      subheader={
        <div>
          <Typography align="center" variant='h6'>
            {gameType.toUpperCase()}
          </Typography>
          <Divider style={{ backgroundColor: 'white' }} />
        </div>
      }
    >
      {displayEmptyItems()}
      {items.map((e, idx) =>
        <div key={e.pseudo + idx}>
          <ListItem button onClick={() => handleClick(idx)}>
            <ListItemText primaryTypographyProps={{ variant: 'h6' }}
              primary={`${idx + 1}. ${e.pseudo} - ${e.score.points}`} />
            {open[idx] ? <ExpandLess /> : <ExpandMore />}
          </ListItem>
          {open[idx] && <Collapse in timeout="auto" unmountOnExit>
            <List disablePadding>
              <CustomListItem>
                <Typography variant='body1' component='p'>
                  Level : {e.score.level} - Line: {e.score.line}
                </Typography>
              </CustomListItem>
              <CustomListItem>
                <div className='game-available-options'>
                  {gameOptionsToText(e.options)}
                </div>
              </CustomListItem>
            </List>
          </Collapse>}
        </div>
      )}
    </CustomList>
  );
}

const CustomList = withStyles({
  root: {
    color: 'white',
    height: 'fit-content',
    width: '250px',
  },
})(List);


const CustomListItem = withStyles({
  root: {
    padding: '0 0 0 16px',
    margin: 0,
    backgroundColor: 'rgba(213, 0, 0, 0.39)',
  }
})(ListItem);