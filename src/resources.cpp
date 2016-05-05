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
    :   hand( NULL ),
        library( NULL )
{
}

Resources::~Resources()
{
    if ( hand != NULL ) {
        delete hand;
    }

    if ( library != NULL ) {
        delete library;
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

Zone* Resources::getHand()
{
    if ( hand == NULL ) {
        hand = new Zone();
    }
    return hand;
}

Zone* Resources::getLibrary()
{
    if ( library == NULL ) {
        library = new Zone();
    }
    return library;
}
