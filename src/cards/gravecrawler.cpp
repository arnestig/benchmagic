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

#include "gravecrawler.h"

Gravecrawler::Gravecrawler() : Card( "Gravecrawler", CardInfo::CREATURE, CardInfo::ZOMBIE, CardInfo::CAST_FROM_GY_IF_ZOMBIE_ON_BATTLEFIELD, "B" )
{
}

Gravecrawler::~Gravecrawler()
{
}

int Gravecrawler::evaluateScore() 
{
    int score;
    //Zone returnCreatures;
    /**Resources::Instance()->getHand()->getCardsByType( returnCreatures, CardInfo::CardType( CardInfo::BASIC_LAND | CardInfo::LAND ) );
    if ( getCurrentZone() == ZoneType::GRAVEYARD ) {
       score += 10; 
    }**/
    return 0;
}

