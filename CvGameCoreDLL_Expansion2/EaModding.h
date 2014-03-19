// EaModding.h
// Precompiler instructions for adding Ea mod code
// Comment-out any blocks of code you don't want
//
// Paz: Welcome to my universe!

// All dll modifications are marked by pre-compiler defines below or by "Paz Bug Fix"

#pragma once

#define EA_DLL_VERSION 1

#define EA_CONFIGURATION 3		// 0, Compiles as unomdded dll
								// 1, Compiles Isolation Code only
								// 2, Compiles with civilian rules only - NMCTJs Mod
								// 3, Compiles for Ea

//ls612: Ea Debug needs to undefine Final Release and a few other things
#ifdef EA_DEBUG_BUILD
#undef FINAL_RELEASE
#endif

#if (EA_CONFIGURATION > 0)
// Isolation Code - move define here and set EA_CONFIGURATION to 1 to test a change in isolation



#endif
#if (EA_CONFIGURATION > 1)					// This is the No More Civilians Traffic Jams (NMCTJs) Mod!
// Civilian rules:
#define EA_BREAK_CIVILIAN_1UPT
#define EA_BREAK_CIVILIAN_OTHER_RESTRICTIONS	// Can move into foreign units or cities if not at war
#endif
#if (EA_CONFIGURATION > 2)

// Ea GP Support
#define EA_PERSISTENT_SETTABLE_COMBAT		//
#define EA_BREAK_GP_1UPT
#define EA_BREAK_GP_OTHER_RESTRICTIONS
#define EA_GP_SPECIAL_ATTACK_CONTROL		// Modifies CvUnit::canMoveInto and CvUnit::isBetterDefenderThan [and CvDangerPlots::ShouldIgnoreUnit?] to handle special GP attack rules
#define EA_PERSISTENT_SETTABLE_INVISIBILITY
#define EA_INVISIBILITY_YOU_CANT_SEE

//#define EA_GP_MAX_HIT_POINTS

// Some of Gedemon's Combat Events
#define EA_COMBAT_EVENTS


// Civ & Leader changing:
#define EA_CIVILIZATION_TRAITS				// Traits can be from Leader OR Civilization [Requires new Civilization_Traits table]
#define EA_CIV_LEADER_CHANGING				// Adds player:ChangeCivilizationType() and player:ChangeLeaderType() with trait resets
// Civ contact:
#define EA_EVENT_CAN_MEET_TEAM				// GameEvents.CanMeetTeam; prevents all contact including war state change, but can still start/end war via Lua
#define EA_EVENT_CAN_CONTACT_MAJOR_TEAM		// GameEvents.CanContactMajorTeam; prevents UI and AI interaction after meeting
// Animal player support:
#define EA_ANIMAL_PLAYER					// Add as player 62 (define ANIMAL_PLAYER, ANIMAL_TEAM enums); all spawning logic on Lua side						
#define EA_ANIMAL_BEHAVIOR					// Don't enter enemy borders; don't pillage trade route
#define EA_ANIMAL_THREAT_ADJUSTMENTS		// NOT IMPLEMENTED YET! AI don't worry about animals if inside borders
// Gods
#define EA_RELIGIOUS_MINORS_DONT_DIE		// These are gods in Ea and don't have cities
// Policy, Tech counting
#define EA_DONT_COUNT_UTILITY_POLICIES
#define EA_DONT_COUNT_UTILITY_TECHS			//ls612: Utility Tech stuff

// New Tags
#define EA_NATURAL_WONDER_HAPPINESS			//ls612: Moving that out of lua into the DLL

// Misc extended Lua support:
// Game Events
#define EA_EVENT_CANAUTOSAVE				// GameEvents.CanAutoSave(bInitial, bPostTurn) CallTestAll
#define EA_UNIT_TAKING_PROMOTION			// GameEvents.UnitTakingPromotion(iPlayer, iUnit, promotionID) CallTestAll

#define EA_EVENT_TECH_COST_MOD				// GameEvents.PlayerTechCostMod(techID, iPlayer); CallAccumulator that uses return integer as percent cost modifier
#define EA_EVENT_MINOR_FRIENDSHIP			// GameEvents.PlayerMinorFriendshipAnchor(eMajor, eMinor); CallAccumulator

#define EA_EVENT_ACQUIRE_PLOT				// GameEvents.CityCanAcquirePlot(iPlayer, iCity, x, y)

#define EA_PLOTS							// Persisted plot data for Ea's Living Terrain and plot methods

#define EA_UNIT_MORALE						// Set of Lua methods and persisted unit int for Ea's Morale system (needs UI Lua/XML support to show in unit panel)
#define EA_UNIT_PERSON_INFO					// Just a persisted unit int used for GPs, with Get, Set Lua methods
#define EA_TEST_PROMOTION_READY				// unit:TestPromotionReady()
#define EA_PATHFINDING						// unit:TurnsToReachTarget(CvPlot* pTarget, bool bReusePaths, bool bIgnoreUnits, bool bIgnoreStacking)

// Macros
#define SHOW_PLOT_FLOATUP(pPlot, ePlayer, szMessage, fDelay)  if (pPlot->isVisible(GET_PLAYER(ePlayer).getTeam())) DLLUI->AddPopupText(pPlot->getX(), pPlot->getY(), szMessage, fDelay)


// Work in progress:
//#define EA_LEADER_SCENE_BYPASS	// This is insane!  (needs support LeaderHead and related xml/lua)
//#define EA_PLAYER_DEAL_API		// Needed for EA_LEADER_SCENE_BYPASS to work
#endif

// Depreciated, but should work if we ever need it again:
//#define EA_COMBAT_EVENTS_EXTRA
//#define EA_ALLOW_REDUNDANT_BARB_PLAYER_COLOR	// DEPRECIATED
//#define EA_SET_FOUNDED_FIRST_CITY				// Added but never tested



// Doesn't work or dangerous code
//#define EA_FOUND_RELIGION_NO_FOUNDER		// Found religion without fouder or holy city or notification








