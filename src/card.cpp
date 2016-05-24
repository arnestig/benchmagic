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

#include "card.h"

Card::Card( std::string name )
    :   name( name ),
        tapped( false )
{
}

Card::~Card()
{
}

std::string Card::getName() const
{
    return name;
}

CardInfo::CardType Card::getCardType() const
{
    return cardType;
}

CardInfo::SuperType Card::getCardSuperType() const
{
    return superType;
}

CardInfo::Ability Card::getCardAbility() const
{
   return cardAbility;
}

ZoneType::ZoneType Card::getCurrentZone() const
{
    return currentZoneType;
}

bool Card::tap()
{
    if ( tapped == true ) {
        return false;
    }
    std::cout << "Tapping " << getName() << std::endl;
    return (tapped = true);
}

bool Card::untap()
{
    /** perhaps check condition here based on active effects **/
    if ( 0 /** ableToUntap() == false **/ ) {
        return false;
    }

    if ( tapped == true ) {
        std::cout << "Untapping " << getName() << std::endl;
    }

    return ! (tapped = false);
}

Land::Land( std::string name, CardInfo::Mana manaType )
    :   Card( name ),
        manaType( manaType )
{
    cardType = static_cast< CardInfo::CardType >( cardType | CardInfo::LAND );
}

Land::~Land()
{
}

