/*
 * Logger.cpp
 *
 *  Created on: 2012-5-15
 *      Author: michael
 */

#include "Logger.h"
#include <sstream>
#include <iomanip>

std::string Logger::toHex(const std::string& s, bool upper_case)
{
	std::cout << "size: " << s.size() << std::endl;

    std::ostringstream ret;

    for (std::string::size_type i = 0; i < s.length(); ++i)
    {
        int z = s[i]&0xff;
        ret << std::hex << std::setfill('0') << std::setw(2) << (upper_case ? std::uppercase : std::nouppercase) << z;
    }

    return ret.str();
}
