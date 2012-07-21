/* ScummVM - Graphic Adventure Engine
 *
 * ScummVM is the legal property of its developers, whose names
 * are too numerous to list here. Please refer to the COPYRIGHT
 * file distributed with this source distribution.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.

 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 *
 */

/*
 * This file is based on WME Lite.
 * http://dead-code.org/redir.php?target=wmelite
 * Copyright (c) 2011 Jan Nedoma
 */

#ifndef WINTERMUTE_PLATFORMSDL_H
#define WINTERMUTE_PLATFORMSDL_H

#include "engines/wintermute/dctypes.h"
#include "engines/wintermute/math/rect32.h"
#include "engines/wintermute/wintypes.h"
#include "common/events.h"

namespace WinterMute {

class CBGame;

//////////////////////////////////////////////////////////////////////////
class CBPlatform {
public:
	static int initialize(CBGame *inGame, int argc, char *argv[]);
	static void handleEvent(Common::Event *event);

	static AnsiString getSystemFontPath();
	static AnsiString getPlatformName();

	// Win32 API bindings
	static void outputDebugString(const char *lpOutputString);
	static uint32 getTime();
	static bool getCursorPos(Point32 *lpPoint);
	static bool setCursorPos(int X, int Y);
	static bool showWindow(int nCmdShow);
	static bool deleteFile(const char *lpFileName);
	static bool copyFile(const char *from, const char *to, bool failIfExists);
	static void setCapture();
	static bool releaseCapture();
	static bool setForegroundWindow();

	static bool setRectEmpty(Rect32 *lprc);
	static bool isRectEmpty(const Rect32 *lprc);
	static bool ptInRect(Rect32 *lprc, Point32 p);
	static bool setRect(Rect32 *lprc, int left, int top, int right, int bottom);
	static bool intersectRect(Rect32 *lprcDst, const Rect32 *lprcSrc1, const Rect32 *lprcSrc2);
	static bool unionRect(Rect32 *lprcDst, Rect32 *lprcSrc1, Rect32 *lprcSrc2);
	static bool copyRect(Rect32 *lprcDst, Rect32 *lprcSrc);
	static bool offsetRect(Rect32 *lprc, int dx, int dy);
	static bool equalRect(Rect32 *rect1, Rect32 *rect2);


	// string functions
//	static int stricmp(const char *str1, const char *str2);
//	static int strnicmp(const char *str1, const char *str2, size_t maxCount);
	static char *strupr(char *string);
	static char *strlwr(char *string);

	// sdl event callback
	static int SDLEventWatcher(void *userdata, Common::Event *event);

private:
	static CBGame *_gameRef;
};

} // end of namespace WinterMute

#endif
