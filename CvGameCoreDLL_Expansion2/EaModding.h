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
#define EA_GP_OTHER_CHANGES					// Pass over GPs for disbanding (they are combat units now so would be considered)
#define EA_PERSISTENT_SETTABLE_INVISIBILITY
#define EA_INVISIBILITY_YOU_CANT_SEE

//#define EA_GP_MAX_HIT_POINTS

// Combat
#define EA_COMBAT_EVENTS_METHODS			// Adds some of Gedemon's GameEvents, modifies CanSaveUnit to provide bDelayed, and adds Game.GetUnitPower(unitTypeID) and unit:GetPower()


// Civ & Leader changing:
#define EA_CIVILIZATION_TRAITS				// Traits can be from Leader OR Civilization [Requires new Civilization_Traits table]
#define EA_CIV_LEADER_CHANGING				// Adds player:ChangeCivilizationType() and player:ChangeLeaderType() with trait resets
// Civ contact
#define EA_EVENT_CAN_MEET_TEAM				// GameEvents.CanMeetTeam; prevents all contact including war state change, but can still start/end war via Lua
#define EA_EVENT_CAN_CONTACT_MAJOR_TEAM		// GameEvents.CanContactMajorTeam; prevents UI and AI interaction after meeting
// Animal player support					! Mod must add CIVILIZATION_ANIMALS in Civilizations and ANIMALS_CIVILIZATION in PostDefines !
#define EA_ANIMAL_PLAYER					// Add as player 62 (define ANIMAL_PLAYER, ANIMAL_TEAM enums); all spawning logic on Lua side	
#define EA_ANIMAL_BEHAVIOR					// Don't enter enemy borders; don't pillage trade route
#define EA_ANIMAL_THREAT_ADJUSTMENTS		// NOT IMPLEMENTED YET! AI don't worry about animals if inside borders
// Gods
#define EA_RELIGIOUS_MINORS_DONT_DIE		// These are gods in Ea and don't have cities
// Policy, Tech counting
#define EA_POLICY_COUNTING					// Can get real number (excluding utility) and this is used for score
#define EA_TECH_COUNTING					// ls612: Utility Tech stuff	--Paz modified to get non-utility count for Lua
// Plots and yields
#define EA_NEW_BUILD_REQUIREMENTS			//ls612: We can now limit available builds for plots in so many ways!
#define EA_BUILD_AI_CHANGES					// Swap blight for fallout; allow for mulitple Builds for same improvement 
#define EA_YIELD_FROM_SPECIAL_PLOTS_ONLY	// For Pantheistic restriction on plot yields
#define EA_EXTENDED_YIELD_METHODS			//ls612: SetLeaderYieldBoost, SetCityResidentYieldBoost, GetFaithPerTurnFromSpecialists (and used it!)
// Buildings
#define EA_NEGATIVE_BUILDING_HAPPINESS		// Allow negative values
// Units
#define EA_GENERIC_WORKERS					//ls612: Remove hardcoded references to UNIT_WORKER
#define EA_UNIT_UPGRADE_TECHS				// Added upgrade test for additional techs (added in Unit_TechTypes table)
// Natural Wonders
#define EA_NATURAL_WONDER_HAPPINESS			//ls612: Moving that out of lua into the DLL

// Disables
#define EA_HIDDEN_CIVS_DISABLES				// Skip useless code for hidden civs that have no cities
#define EA_DISABLE_TOURISM					// Not used by mod so don't calculate
#define EA_DISABLE_UNIT_TURN_EXP_COSTS		// Handicap and Gamespeed xml tags disabled in dll, so I killed it here instead
#define EA_DISABLE_EXPENSIVE_EVENTS			// GameCoreUpdateBegin and other expensive but unneeded GameEvents

// Misc Changes
#define EA_NO_BARB_CITIES

// Strategies
#define EA_STRATEGY_CHANGES

// Diplo Trade Items
#define EA_RENOUNCE_MALEFICIUM_TRADE		// Support for "Reounouce Maleficium" trade item
#define EA_RENOUNCE_MALEFICIUM_VALUE_DEFINES // Defines so we can balance on Lua/SQL side

// Trade
#define EA_TRADE_YIELD_CHANGES				// Science based on total known rather than difference
#define EA_TRADE_EVENTS_METHODS				// GameEvents.CanCreateTradeRoute(iOriginPlot, iDestPlot, iDestPlayer, eDomain, eConnectionType) CallTestAll and Game.CanCreateTradeRoute
#define EA_WH_EVENTS_CITY_CONNECTIONS		// Whoward's City Connections code: 
											// GameEvents.CityConnections.Add(function(iPlayer, bDomestic) return false end)
											// GameEvents.CityConnected.Add(function(iPlayer, iCityX, iCityY, iToCityX, iToCityY, bDomestic) return false end)
// GameEvents
#define EA_EVENT_GAME_SAVE					// GameEvents.GameSave() CallHook
#define EA_EVENT_CHANGE_EXPERIENCE			// GameEvents.CanChangeExperience(iPlayer, iUnit, iSummoner, iExperience, iMax, bFromCombat, bInBorders, bUpdateGlobal) CallTestAll
											// GameEvents.BarbExperienceDenied(iPlayer, iUnit, iSummoner, iExperience) CallHook
#define EA_UNIT_TAKING_PROMOTION			// GameEvents.UnitTakingPromotion(iPlayer, iUnit, promotionID) CallTestAll
#define EA_EVENT_TECH_COST_MOD				// GameEvents.PlayerTechCostMod(techID, iPlayer); CallAccumulator that uses return integer as percent cost modifier
#define EA_EVENT_MINOR_FRIENDSHIP			// GameEvents.PlayerMinorFriendshipAnchor(eMajor, eMinor); CallAccumulator
#define EA_EVENT_ACQUIRE_PLOT				// GameEvents.CityCanAcquirePlot(iPlayer, iCity, x, y) CallTestAll
#define EA_EVENT_CAN_CAPTURE_CIVILIAN		// GameEvents.CanCaptureCivilian(iPlayer, iUnit) CallTestAll
#define EA_EVENT_UNIT_CAPTURED				// GameEvents.UnitCaptured(iPlayer, iUnit) CallHook
#define EA_EVENT_POLICY_FINISHER			// GameEvents.FinisherPolicy(iPlayer, policyID) CallHook
#define EA_EVENT_CITY_KILLED				// GameEvents.CityKilled(iPlayer, iCity, iPlot, bCapital) CallHook


// Misc extended Lua support:
#define EA_PLOTS							// Persisted plot data and methods for Ea's Living Terrain and plot effects (Glyphs, Runes and Wards)
#define EA_UNIT_MORALE						// Set of Lua methods and persisted unit int for Ea's Morale system (needs UI Lua/XML support to show in unit panel)
#define EA_UNIT_PERSON_INFO					// 2 persisted ints used for GPs, with Get, Set Lua methods
#define EA_UNIT_METHODS						// TestPromotionReady, SetTurnProcessed
#define EA_PATHFINDING						// unit:TurnsToReachTarget(CvPlot* pTarget, bool bReusePaths, bool bIgnoreUnits, bool bIgnoreStacking)
#define EA_CITY_METHODS						// just SetNumFreeBuilding for now
#define EA_UNHAPPINESS						//ls612: Allow unhappiness from miscallaneous sources provided by lua
#define EA_NO_WARMONGER_PENALTY				//ls612: Allow lua to specify a reduction to warmonger penalty for actions against specific players




// Macros
#define SHOW_PLOT_FLOATUP(pPlot, ePlayer, szMessage, fDelay)  if (pPlot->isVisible(GET_PLAYER(ePlayer).getTeam())) DLLUI->AddPopupText(pPlot->getX(), pPlot->getY(), szMessage, fDelay)

// Miscallaneous Junk
#define EA_NO_FIRST_TURN_NOTIFICATIONS		//ls612: Fixes notifications caused by Ea mechanics which shouldn't be shown.

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


// Obsolete stuff that was removed from code
//#define EA_EVENT_CANAUTOSAVE				// GameEvents.CanAutoSave(bInitial, bPostTurn) CallTestAll








