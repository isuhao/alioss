/*-----------------------------------------------------------------
File	: strutil
Author	: twofei <anhbk@qq.com>
Date	: Thu, Nov 13 2014
Desc	: String manipulation
-----------------------------------------------------------------*/

#ifndef __alioss_strutil_h__
#define __alioss_strutil_h__

#include <string>
#include <vector>

namespace alioss{
	namespace strutil{

		std::string strip(const std::string& s);
		std::string strip(const char* s, int len=-1);

	}
}


#endif //!__alioss_strutil_h__

