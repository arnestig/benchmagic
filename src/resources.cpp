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
    :   currentTurn( 1 ),
        opponentLife( 20 ),
        playerLife( 20 )
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

void Resources::play()
{
    getLibrary()->shuffle();
    drawCards( 7 );
    while ( playTurn() == true ) {

    }
}

bool Resources::playMana()
{
    Zone lands;
    getHand()->getCardsByType( lands, CardInfo::LAND );
    Card *landToPlay = lands.takeTopCard();
    if ( landToPlay != NULL ) {
        getHand()->playCard( landToPlay, getBattlefield() );
    }
}

bool Resources::playTurn()
{
    playedMana = false;
    currentStep = Steps::UNTAP;
    for ( int i = 0; i < Steps::CLEAN_UP; i++ ) {
        currentStep = static_cast< Steps::Steps >( i );
        std::cout << " = Current step " << Steps::getStepsAsString( currentStep ) << std::endl; 
        switch( currentStep ) {
            case Steps::UNTAP:
            {
                std::vector< Card* > cards = getBattlefield()->getCards();
                for( std::vector< Card* >::iterator it = cards.begin(); it != cards.end(); ++it ) {
                    (*it)->untap();
                }
            }
            break;
            case Steps::UPKEEP:
                // nothing for now
                break;
            case Steps::DRAW:
            {
                // here we have to decide if we want to dredge or not
                drawCards( 1 );
            }
            break;
            case Steps::MAIN_PHASE_ONE:
                // should we play mana?
                playMana();
                // should we play a spell?
                break;
            case Steps::BEGIN_COMBAT:
                break;
            case Steps::DECLARE_ATTACKERS:
                break;
            case Steps::DECLARE_BLOCKERS:
                break;
            case Steps::COMBAT_DAMAGE:
                break;
            case Steps::END_COMBAT:
                break;
            case Steps::MAIN_PHASE_TWO:
                break;
            case Steps::END_STEP:
                break;
            case Steps::CLEAN_UP:
                break;
        }
    }

    /** check if all players are alive **/
    if ( playerLife <= 0 ) {
        std::cout << "We're dead at turn " << currentTurn << std::endl;
        return false;
    }

    if ( opponentLife <= 0 ) {
        std::cout << "Opponent dead at turn " << currentTurn << std::endl;
        return false;
    }

    playerLife -= 5;

    currentTurn++;
    return true;
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

void Resources::drawCards( int numOfCards )
{
   Zone *hand = Resources::Instance()->getHand();
   Zone *library = Resources::Instance()->getLibrary();
   for ( int i = 0; i < numOfCards; i++ ) {
       hand->addCard( library->takeTopCard() ); 
   }
}
