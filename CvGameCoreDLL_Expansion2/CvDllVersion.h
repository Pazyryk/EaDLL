/*	-------------------------------------------------------------------------------------------------------
	© 1991-2012 Take-Two Interactive Software and its subsidiaries.  Developed by Firaxis Games.  
	Sid Meier's Civilization V, Civ, Civilization, 2K Games, Firaxis Games, Take-Two Interactive Software 
	and their respective logos are all trademarks of Take-Two interactive Software, Inc.  
	All other marks and trademarks are the property of their respective owners.  
	All rights reserved. 
	------------------------------------------------------------------------------------------------------- */
#pragma once

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
// WARNING! This must be unique for each DLL!
// If you are a modder and you are creating your own DLL from the original source, this must be changed to a unique GUID.
// Use the Visual Studio Create GUID option in the Tools menu to create a new GUID.
// {C3B2B6B3-439C-480b-8536-1CF39FCFC682}
// {83F34FF0-3D60-43e7-AEDB-82C79867EE3F}

// Paz new GUID is
// {3DDA56DC-4652-45B3-A5F7-745D0D1791D4}	- The No More Civilian Traffic Jams Mod
// {6A2F4607-03F2-4059-B891-99609BE82884}	- Ea mod

static const GUID CIV5_XP2_DLL_GUID = 
#ifdef EA_CIVILIAN_MOD_ONLY
	{ 0x3dda56dc, 0x4652, 0x45b3, { 0xa5, 0xf7, 0x74, 0x5d, 0xd, 0x17, 0x91, 0xd4 } };
#elif defined (EA_DLL_VERSION)
	{ 0x6a2f4607, 0x3f2, 0x4059, { 0xb8, 0x91, 0x99, 0x60, 0x9b, 0xe8, 0x28, 0x84 } };
#else
	{ 0x83f34ff0, 0x3d60, 0x43e7, { 0xae, 0xdb, 0x82, 0xc7, 0x98, 0x67, 0xee, 0x3f } };
#endif
static const char* CIV5_XP2_DLL_VERSION = "1.0.0";
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
