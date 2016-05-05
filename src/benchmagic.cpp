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

#include "benchmagic.h"
#include "card.h"
#include "resources.h"
#include "version.h"

void printVersion()
{
    std::string version = Version::getLongVersion();
    std::cout << "benchmagic " << version << std::endl;
    std::cout << "Copyright (C) 2016  Tobias Eliasson <arnestig@gmail.com" << std::endl;
    std::cout << "Licencse GPLv3+: GNU GPL version 3 or later <http://gnu.org/licenses/gpl.html>" << std::endl;
    std::cout << "This is free software: you are free to change and redistribute it." << std::endl;
    std::cout << "There is NO WARRANTY, to the extent permitted by law." << std::endl;
    exit( 0 );
}

void printUsage()
{
    std::cout << "Usage: benchmagic [option(s)]" << std::endl;
    std::cout << " -h  --help                Display this information" << std::endl;
    std::cout << " -v  --version             Print benchmagic version" << std::endl;
    exit( 0 );
}

void parseArguments( int argc, char *argv[] )
{
    int c;
    while ( 1 ) {
        static struct option long_options[] = {
        { "help",       no_argument,        NULL,           'h' },
        { "version",    no_argument,        NULL,           'v' },
        { 0,            0,                  0,              0 } };

        int option_index = 0;
        c = getopt_long( argc, argv, "hv", long_options, &option_index );
        
        // are we at the end of our options? break in that case
        if ( c == -1 ) {
            break;
        }

        int comma = 0;
        std::string filterArg;
        switch ( c ) {
            case 0:
                if ( long_options[ option_index ].flag != 0 ) {
                    break;
                }
            case 'v':
                printVersion();
                break;
            case 'h':
            case '?':
                printUsage();
                break;
            default:
                abort();
        }
    }
}

void mulligan()
{
    //...
}

void drawCard( int numOfCards )
{
   Zone *hand = Resources::Instance()->getHand();
   Zone *library = Resources::Instance()->getLibrary();
   for ( int i = 0; i < numOfCards; i++ ) {
       hand->addCard( library->takeTopCard() ); 
   }
}

int main( int argc, char *argv[] )
{
    // parse command line arguments
    parseArguments( argc, argv );

    Zone *library = Resources::Instance()->getLibrary();
    Zone *hand = Resources::Instance()->getHand();
    /** dredgevine **/
    library->addCard( new Card( "Insolent Neonate", CardInfo::CREATURE, "R" ) );
    library->addCard( new Card( "Insolent Neonate", CardInfo::CREATURE, "R" ) );
    library->addCard( new Card( "Insolent Neonate", CardInfo::CREATURE, "R" ) );
    library->addCard( new Card( "Insolent Neonate", CardInfo::CREATURE, "R" ) );
    library->addCard( new Card( "Vengevine", CardInfo::CREATURE, "2GG" ) );
    library->addCard( new Card( "Vengevine", CardInfo::CREATURE, "2GG" ) );
    library->addCard( new Card( "Vengevine", CardInfo::CREATURE, "2GG" ) );
    library->addCard( new Card( "Vengevine", CardInfo::CREATURE, "2GG" ) );
    library->addCard( new Card( "Lotleth Troll", CardInfo::CREATURE, "BG" ) );
    library->addCard( new Card( "Lotleth Troll", CardInfo::CREATURE, "BG" ) );
    library->addCard( new Card( "Lotleth Troll", CardInfo::CREATURE, "BG" ) );
    library->addCard( new Card( "Lotleth Troll", CardInfo::CREATURE, "BG" ) );
    library->addCard( new Card( "Bloodghast", CardInfo::CREATURE, "BB" ) );
    library->addCard( new Card( "Bloodghast", CardInfo::CREATURE, "BB" ) );
    library->addCard( new Card( "Bloodghast", CardInfo::CREATURE, "BB" ) );
    library->addCard( new Card( "Bloodghast", CardInfo::CREATURE, "BB" ) );
    library->addCard( new Card( "Satyr Wayfinder", CardInfo::CREATURE, "1G" ) );
    library->addCard( new Card( "Satyr Wayfinder", CardInfo::CREATURE, "1G" ) );
    library->addCard( new Card( "Satyr Wayfinder", CardInfo::CREATURE, "1G" ) );
    library->addCard( new Card( "Golgari Grave-Troll", CardInfo::CREATURE, "4G" ) );
    library->addCard( new Card( "Golgari Grave-Troll", CardInfo::CREATURE, "4G" ) );
    library->addCard( new Card( "Golgari Grave-Troll", CardInfo::CREATURE, "4G" ) );
    library->addCard( new Card( "Golgari Grave-Troll", CardInfo::CREATURE, "4G" ) );
    library->addCard( new Card( "Prized Amalgam", CardInfo::CREATURE, "1UB" ) );
    library->addCard( new Card( "Prized Amalgam", CardInfo::CREATURE, "1UB" ) );
    library->addCard( new Card( "Prized Amalgam", CardInfo::CREATURE, "1UB" ) );
    library->addCard( new Card( "Prized Amalgam", CardInfo::CREATURE, "1UB" ) );
    library->addCard( new Card( "Gurmag Angler", CardInfo::CREATURE, "6B" ) );
    library->addCard( new Card( "Gurmag Angler", CardInfo::CREATURE, "6B" ) );
    library->addCard( new Card( "Gurmag Angler", CardInfo::CREATURE, "6B" ) );
    library->addCard( new Card( "Gurmag Angler", CardInfo::CREATURE, "6B" ) );
    library->addCard( new Card( "Murderous Cut", CardInfo::INSTANT, "4B" ) );
    library->addCard( new Card( "Murderous Cut", CardInfo::INSTANT, "4B" ) );
    library->addCard( new Card( "Murderous Cut", CardInfo::INSTANT, "4B" ) );
    library->addCard( new Card( "Abrupt Decay", CardInfo::INSTANT, "BG" ) );
    library->addCard( new Card( "Abrupt Decay", CardInfo::INSTANT, "BG" ) );
    library->addCard( new Card( "Abrupt Decay", CardInfo::INSTANT, "BG" ) );
    library->addCard( new Card( "Faithless Looting", CardInfo::SORCERY, "R" ) );
    library->addCard( new Card( "Faithless Looting", CardInfo::SORCERY, "R" ) );
    library->addCard( new Card( "Faithless Looting", CardInfo::SORCERY, "R" ) );
    library->addCard( new Card( "Faithless Looting", CardInfo::SORCERY, "R" ) );
    library->addCard( new Card( "Forest", CardInfo::BASIC_LAND, "" ) );
    library->addCard( new Card( "Swamp", CardInfo::BASIC_LAND, "" ) );
    library->addCard( new Card( "Blackcleave Cliffs", CardInfo::LAND, "" ) );
    library->addCard( new Card( "Blackcleave Cliffs", CardInfo::LAND, "" ) );
    library->addCard( new Card( "Blackcleave Cliffs", CardInfo::LAND, "" ) );
    library->addCard( new Card( "Blackcleave Cliffs", CardInfo::LAND, "" ) );
    library->addCard( new Card( "Bloodstained Mire", CardInfo::LAND, "" ) );
    library->addCard( new Card( "Bloodstained Mire", CardInfo::LAND, "" ) );
    library->addCard( new Card( "Bloodstained Mire", CardInfo::LAND, "" ) );
    library->addCard( new Card( "Bloodstained Mire", CardInfo::LAND, "" ) );
    library->addCard( new Card( "Wooded Foothills", CardInfo::LAND, "" ) );
    library->addCard( new Card( "Wooded Foothills", CardInfo::LAND, "" ) );
    library->addCard( new Card( "Wooded Foothills", CardInfo::LAND, "" ) );
    library->addCard( new Card( "Wooded Foothills", CardInfo::LAND, "" ) );
    library->addCard( new Card( "Overgrown Tomb", CardInfo::LAND, "" ) );
    library->addCard( new Card( "Overgrown Tomb", CardInfo::LAND, "" ) );
    library->addCard( new Card( "Overgrown Tomb", CardInfo::LAND, "" ) );
    library->addCard( new Card( "Overgrown Tomb", CardInfo::LAND, "" ) );
    library->addCard( new Card( "Blood Crypt", CardInfo::LAND, "" ) );
    library->addCard( new Card( "Blood Crypt", CardInfo::LAND, "" ) );
    library->shuffle();

    drawCard( 7 );
    hand->printCards();

    Zone lands;
    hand->getCardsByType( lands, CardInfo::CardType(CardInfo::BASIC_LAND | CardInfo::LAND ) );
    std::cout << " -- Lands -- " << std::endl;
    lands.printCards();

    return 0;
}

