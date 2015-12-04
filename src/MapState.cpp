//
//  MapState.cpp
//  Final-Mystic-Quest
//
//  Created by Sandoche on 03/12/15.
//  Copyright © 2015 My Organisation Name. All rights reserved.
//

#include <stdio.h>
#include "MapState.hpp"

/*MapState::MapState()
{
    tail=0;
    head=0;
}


MapState::~MapState()
{
    while(tail)
    {
        popMap();
    }
}

void MapState::pushMap(Map *map)
{
    if(tail)
    {
        tail->pauseMap();
        tail->setNext(map);
    }
    map->setPrev(tail);
    tail=map;
    tail->init(player, &input, this);
}

void MapState::popMap()
{
    if(tail)
    {
        Map *toPop =tail;
        tail=tail->getPrev();
        if(tail)
        {
            tail->unpauseMap();
        }
        delete toPop;
        toPop=0;
    }
}

void MapState::changeMap(Map *map)
{
    popMap();
    pushMap(map);
}

void MapState::update()
{
    tail->updateMap();
}

/*void MapState::render()
{
    tail->re
}

void MapState::pause() {
    if (tail) {
        tail->pauseMap();
    }
}

void MapState::unpause() {
    if (tail) {
        tail->unpauseMap();
    }
}*/



