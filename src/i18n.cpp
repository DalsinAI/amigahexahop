// (c) 2007 Miriam Ruiz <little_miry@yahoo.es>
//
// This library is free software; you can redistribute it and/or
// modify it under the terms of the GNU Library General Public
// License as published by the Free Software Foundation; either
// version 2 of the License, or (at your option) any later version.
//
// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// Library General Public License for more details.
//
// You should have received a copy of the GNU Library General Public
// License along with this library; if not, write to the Free Software
// Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301
// USA.

#include "i18n.h"
#include "system-relative.h"
#include <string>
#include <cstdlib>
#ifdef ENABLE_NLS
#include <locale.h>
#include <langinfo.h>
#endif

#ifdef ENABLE_NLS
static std::string GetLocalePath()
{
#ifdef RELATIVE_PATHS
	std::string locale_path;
	char* exedir = lisys_relative_exedir();
	if (exedir != NULL)
	{
		locale_path = exedir;
		locale_path += "/share/locale";
		free(exedir);
	}
	else
		locale_path = "./share/locale/";
	return locale_path;
#else
	return std::string(LOCALEDIR);
#endif
}
#endif

GetTextInit::GetTextInit()
{
	if  (!IsInit)
	{
		IsInit = true;
#ifdef ENABLE_NLS
		setlocale (LC_MESSAGES, "");
		setlocale (LC_CTYPE, "");
		setlocale (LC_COLLATE, "");
		textdomain ("hex-a-hop");
		bindtextdomain ("hex-a-hop", GetLocalePath().c_str());
#endif
	}
}

bool GetTextInit::IsInit = false;

#ifdef ENABLE_NLS
const char *GetTextInit::GetEncoding() const
{
	// See http://svn.xiph.org/trunk/vorbis-tools/intl/localcharset.c
	// if nl_langinfo isn't found
	char *locale_enc = nl_langinfo(CODESET);
	return locale_enc;
}
#endif
