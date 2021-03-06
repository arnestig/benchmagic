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

#ifndef __TYPES_H__
#define __TYPES_H__

#include <string>

namespace CardInfo
{
    enum CardType
    {
        BASIC_LAND  = 1,
        LAND        = 2,
        CREATURE    = 4,
        ENCHANTMENT = 8,
        INSTANT     = 16,
        SORCERY     = 32
    };

    enum SuperType
    {
        ZOMBIE      = 1
    };

    enum Mana
    {
        SWAMP,
        PLAINS,
        MOUNTAIN,
        ISLAND,
        FOREST,
        COLORLESS,
        PHYREXIAN
    };

    enum Ability
    {
        RETURN_FROM_GY_ON_LANDFALL                  = 1,
        RETURN_FROM_GY_ON_TWO_CREATURES_PLAYED      = 2,
        RETURN_FROM_GY_ON_CREATURE_ENTERED_FROM_GY  = 4,
        CAST_FROM_GY_IF_ZOMBIE_ON_BATTLEFIELD       = 8
     };
};

namespace Action
{
    enum Action
    {
        DRAW,
        DISCARD
    };

};

namespace Steps
{
    enum Steps
    {
        UNTAP = 0,
        UPKEEP,
        DRAW,
        MAIN_PHASE_ONE,
        BEGIN_COMBAT,
        DECLARE_ATTACKERS,
        DECLARE_BLOCKERS,
        COMBAT_DAMAGE,
        END_COMBAT,
        MAIN_PHASE_TWO,
        END_STEP,
        CLEAN_UP
    };

    static inline std::string getStepsAsString( Steps::Steps step )
    {
        switch( step ) {
            default:
            case Steps::UNTAP:
                return "Untap";
                break;
            case Steps::UPKEEP:
                return "Upkeep";
                break;
            case Steps::DRAW:
                return "Draw";
                break;
            case Steps::MAIN_PHASE_ONE:
                return "Main phase 1";
                break;
            case Steps::BEGIN_COMBAT:
                return "Begin combat";
                break;
            case Steps::DECLARE_ATTACKERS:
                return "Declare attackers";
                break;
            case Steps::DECLARE_BLOCKERS:
                return "Declare blockers";
                break;
            case Steps::COMBAT_DAMAGE:
                return "Combat damage";
                break;
            case Steps::END_COMBAT:
                return "End combat";
                break;
            case Steps::MAIN_PHASE_TWO:
                return "Main phase 2";
                break;
            case Steps::END_STEP:
                return "End step";
                break;
            case Steps::CLEAN_UP:
                return "Cleanup";
                break;
        }
    };
};

namespace ZoneType
{
    enum ZoneType
    {
        TEMPORARY,
        LIBRARY,
        HAND,
        BATTLEFIELD,
        GRAVEYARD,
        EXILE
    };
};

#endif
