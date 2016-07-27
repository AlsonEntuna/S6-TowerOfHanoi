// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.

#include "TowerOfHanoi_V3.h"
#include "TowerOfHanoi_V3GameMode.h"
#include "TowerOfHanoi_V3HUD.h"
#include "TowerOfHanoi_V3Character.h"

ATowerOfHanoi_V3GameMode::ATowerOfHanoi_V3GameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = ATowerOfHanoi_V3HUD::StaticClass();
}
