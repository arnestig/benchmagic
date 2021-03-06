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

#ifndef __CARD_H__
#define __CARD_H__

#include <string>
#include <iostream>
#include "types.h"

class Land;

class Card
{
    friend class Land;
    public:
        Card( std::string name );
        ~Card();

        std::string getName() const;
        CardInfo::CardType getCardType() const;
        CardInfo::SuperType getCardSuperType() const;
        CardInfo::Ability getCardAbility() const;
        ZoneType::ZoneType getCurrentZone() const;
        bool tap();
        bool untap();

    private:
        ZoneType::ZoneType currentZoneType;
        std::string name;
        bool tapped;
        CardInfo::CardType cardType;
        CardInfo::SuperType superType;
        CardInfo::Ability cardAbility;;
        std::string manaCost;
};

class Land : public Card
{
    public:
        Land( std::string name, CardInfo::Mana manaType );
        ~Land();

    private:
        CardInfo::Mana manaType;
};

#endif
