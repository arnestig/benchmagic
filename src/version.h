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

#ifndef __VERSION_H__
#define __VERSION_H__

#include <string>

#ifndef GIT_HASH
#define GIT_HASH ""
#endif

namespace Version {
	static std::string name = "benchmagic";
	static std::string version = "1.0";

	inline std::string getNumericVersion()
	{
	    return version;
	}

	inline std::string getShortVersion()
	{
	    return name + " " + version;
	}

	inline std::string getLongVersion()
	{
	    std::string retval = version;
        std::string gitHash = GIT_HASH;
        if ( gitHash.length() > 0 ) {
            retval.append( "-" + gitHash );
        }
	    return retval;
	}
};

#endif
