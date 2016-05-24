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
    std::cout << "Added " << card->getName() << " to " << getZoneName() << std::endl;
    cards.push_back( card );
}

void Zone::playCard( Card* card, Zone* battlefield )
{
    for ( std::vector< Card* >::iterator it = cards.begin(); it != cards.end(); ) {
        if ( (*it) == card ) {
            it = cards.erase( it );
        } else {
            ++it;
        }
    }
    std::cout << "Playing " << card->getName() << std::endl;
    battlefield->addCard( card );
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
    if ( cards.empty() == true ) {
        return NULL;
    }

    Card *card = cards.back();
    cards.pop_back();
    return card;
}

void Zone::printCards()
{
    std::cout << " - Cards in " << getZoneName() << std::endl;
    for ( std::vector< Card* >::iterator it = cards.begin(); it != cards.end(); ++it ) {
        std::cout << (*it)->getName() << std::endl;
    }
}

std::string Zone::getZoneName()
{
    switch( zoneType ) {
        default:
        case ZoneType::TEMPORARY:
            return "Temporary";
            break;
        case ZoneType::LIBRARY:
            return "Library";
            break;
        case ZoneType::HAND:
            return "Hand";
            break;
        case ZoneType::BATTLEFIELD:
            return "Battlefield";
            break;
        case ZoneType::GRAVEYARD:
            return "Graveyard";
            break;
        case ZoneType::EXILE:
            return "Exile";
            break;
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

void Zone::getCardsBySuperType( Zone &zone, CardInfo::SuperType superType )
{
    for ( std::vector< Card* >::iterator it = cards.begin(); it != cards.end(); ++it ) {
        if ( ( (*it)->getCardSuperType() & superType ) ) {
            zone.addCard( (*it ) );
        }
    }
}

void Zone::getCardsByAbility( Zone &zone, CardInfo::Ability cardAbility )
{
    for ( std::vector< Card* >::iterator it = cards.begin(); it != cards.end(); ++it ) {
        if ( ( (*it)->getCardAbility() & cardAbility ) ) {
            zone.addCard( (*it ) );
        }
    }
}

