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

int main( int argc, char *argv[] )
{
    // parse command line arguments
    parseArguments( argc, argv );

    return 0;
}

