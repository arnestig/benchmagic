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

#ifndef __ZONE_H__
#define __ZONE_H__

#include "card.h"
#include "types.h"
#include <vector>
#include <sys/time.h>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <stdio.h>

class Zone
{
    public:
        Zone( ZoneType::ZoneType zoneType = ZoneType::TEMPORARY );
        ~Zone();

        void addCard( Card* card );
        std::vector< Card* > getCards();
        void shuffle();
        Card* takeTopCard();
        void printCards();
        void getCardsByType( Zone &zone, CardInfo::CardType cardType );
        void getCardsBySuperType( Zone &zone, CardInfo::SuperType superType );
        void getCardsByAbility( Zone &zone, CardInfo::Ability cardAbility );

    private:
        std::string getZoneName();
        ZoneType::ZoneType zoneType;
        std::vector< Card* > cards;
};

#endif
