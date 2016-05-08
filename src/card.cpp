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

Card::Card( std::string name, CardInfo::CardType cardType, std::string manaCost )
    :   name( name ),
        cardType( cardType ),
        manaCost( manaCost )
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

int Card::evaluateScore() const
{
    /**
        calculate score here based on:
        - What zone this card sits in
        - How the other zones looks like
        - How the mana situation is on the battlefield zone
        **/
    
}
