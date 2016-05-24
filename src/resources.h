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

#ifndef __RESOURCES_H__
#define __RESOURCES_H__

#include <stdlib.h>
#include <map>
#include "types.h"
#include "zone.h"
#include "cards/gravecrawler.h"
#include "cards/vengevine.h"
#include "cards/forest.h"

#define TheGame Resources::Instance()

class Resources
{
    public:
        static Resources* Instance();
        static void DestroyInstance();

        void play();
        Zone* getLibrary();
        Zone* getHand();
        Zone* getBattlefield();
        Zone* getGraveyard();
        Zone* getExile();
        void drawCards( int numOfCards );

    private:
        static Resources* instance;
        Resources();
        ~Resources();
        Resources( Resources const& ) {};

        Zone* getZoneByType( ZoneType::ZoneType zoneType );
        void evaluateCards();
        bool playTurn();
        bool playMana();

        std::map< ZoneType::ZoneType, Zone* > zones;
        int currentTurn;
        Steps::Steps currentStep;
        bool playedMana;
        int opponentLife;
        int playerLife;
        Zone *library;
        Zone *hand;
        Zone *battlefield;
        Zone *graveyard;
        Zone *exile;
};

#endif
