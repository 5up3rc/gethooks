/*
Copyright (C) 2011 Jay Satiro <raysatiro@yahoo.com>
All rights reserved.

This file is part of GetHooks.

GetHooks is free software: you can redistribute it and/or modify 
it under the terms of the GNU General Public License as published by 
the Free Software Foundation, either version 3 of the License, or 
(at your option) any later version.

GetHooks is distributed in the hope that it will be useful, 
but WITHOUT ANY WARRANTY; without even the implied warranty of 
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the 
GNU General Public License for more details.

You should have received a copy of the GNU General Public License 
along with GetHooks.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef _TEST_H
#define _TEST_H

#include <windows.h>

/* snapshot store (system process info, gui threads, desktop hooks) */
#include "snapshot.h"

/* desktop hook store (linked list of desktop and hook information) */
#include "desktop_hook.h"



#ifdef __cplusplus
extern "C" {
#endif


/* the diff types */
enum difftype
{ 
	/* every HOOK in the initial snapshot is "found" */
	HOOK_FOUND = 1, 
	
	/* a HOOK that is present in the current snapshot but not in the previous */
	HOOK_ADDED, 
	
	/* a HOOK that is present in both the previous and current snapshots but has changed */
	HOOK_MODIFIED, 
	
	/* a HOOK that is present in the previous snapshot but not in the current */
	HOOK_REMOVED
};


/* thread info as it pertains to a HOOK */
enum threadtype
{
	/* the thread that owns the HOOK */
	THREAD_OWNER = 1, 
	
	/* the thread that the HOOK originated from */
	THREAD_ORIGIN, 
	
	/* the thread that is hooked */
	THREAD_TARGET 
};



/** 
these functions are documented in the comment block above their definitions in test.c
*/
void poll_handle_count(
	int seconds   // in
);

void testmode( void );


#ifdef __cplusplus
}
#endif

#endif // _TEST_H