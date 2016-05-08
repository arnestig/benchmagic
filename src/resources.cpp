/**
    Copyright (C) 2016 benchmagic - Benchmarking Magic: The Gathering decks

    Written by Tobias Eliasson <arnestig@gmail.com>.

    This file is part of benchmagic https://github.com/arnestig/benchmagic

    benchmagic is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    benchmagic is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with benchmagic.  If not, see <http://www.gnu.org/licenses/>.
**/

#include "resources.h"

Resources* Resources::instance = NULL;

Resources::Resources()
{
}

Resources::~Resources()
{
    for( std::map< ZoneType::ZoneType, Zone* >::iterator it = zones.begin(); it != zones.end(); ++it ) {
        if ( (*it).second != NULL ) {
            delete (*it).second;
        }
    }
}

void Resources::DestroyInstance()
{
    delete instance;
    instance = NULL;
}

Resources* Resources::Instance()
{
    if ( instance == NULL ) {
        instance = new Resources();
    }
    return instance;
}

Zone* Resources::getZoneByType( ZoneType::ZoneType zoneType )
{
    if ( zones[ zoneType ] == NULL ) {
        zones[ zoneType ] = new Zone( zoneType );
    }
    return zones[ zoneType ];
}

Zone* Resources::getHand()
{
    return getZoneByType( ZoneType::HAND );
}

Zone* Resources::getLibrary()
{
    return getZoneByType( ZoneType::LIBRARY );
}

Zone* Resources::getBattlefield()
{
    return getZoneByType( ZoneType::BATTLEFIELD );
}

Zone* Resources::getGraveyard()
{
    return getZoneByType( ZoneType::GRAVEYARD );
}

Zone* Resources::getExile()
{
    return getZoneByType( ZoneType::EXILE );
}

