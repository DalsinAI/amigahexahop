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

#ifndef _I18N_H
#define _I18N_H

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#ifdef ENABLE_NLS
#include "gettext.h"
#define _(String) gettext (String)
#else
#define _(String) String
#define ngettext(a,b,n) ((n)?(b):(a))
#endif  // ENABLE_NLS

class GetTextInit
{
	protected:
		static bool IsInit;
	public:
		GetTextInit();
#ifdef ENABLE_NLS
		const char *GetEncoding() const;
#endif
};

static GetTextInit gettext_init;

#endif
