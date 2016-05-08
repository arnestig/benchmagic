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

#include "zone.h"

Zone::Zone( ZoneType::ZoneType zoneType )
    :   zoneType( zoneType )
{
    struct timeval time; 
    gettimeofday(&time,NULL);
    std::srand( unsigned( (time.tv_sec * 1000 ) + (time.tv_usec / 1000 ) ) );
}

Zone::~Zone()
{
}

void Zone::addCard( Card* card )
{
    cards.push_back( card );
}

std::vector< Card* > Zone::getCards()
{
    return cards;
}

void Zone::shuffle()
{
    std::random_shuffle( cards.begin(), cards.end() );
}

Card* Zone::takeTopCard()
{
    Card *card = cards.back();
    cards.pop_back();
    return card;
}

void Zone::printCards()
{
    for ( std::vector< Card* >::iterator it = cards.begin(); it != cards.end(); ++it ) {
        std::cout << (*it)->getName() << std::endl;
    }
}

void Zone::getCardsByType( Zone &zone, CardInfo::CardType cardType )
{
    for ( std::vector< Card* >::iterator it = cards.begin(); it != cards.end(); ++it ) {
        if ( ( (*it)->getCardType() & cardType ) ) {
            zone.addCard( (*it ) );
        }
    }
}

