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
};

class Card
{
    public:
        Card( std::string name, CardInfo::CardType cardType, std::string manaCost );
        ~Card();

        std::string getName() const;
        CardInfo::CardType getCardType() const;
        int evaluateScore() const;

    private:
        std::string name;
        CardInfo::CardType cardType;
        std::string manaCost;
};

#endif
