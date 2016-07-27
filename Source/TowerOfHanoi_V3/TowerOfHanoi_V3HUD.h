// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.
#pragma once 
#include "GameFramework/HUD.h"
#include "TowerOfHanoi_V3HUD.generated.h"

UCLASS()
class ATowerOfHanoi_V3HUD : public AHUD
{
	GENERATED_BODY()

public:
	ATowerOfHanoi_V3HUD();

	/** Primary draw call for the HUD */
	virtual void DrawHUD() override;

private:
	/** Crosshair asset pointer */
	class UTexture2D* CrosshairTex;

};

