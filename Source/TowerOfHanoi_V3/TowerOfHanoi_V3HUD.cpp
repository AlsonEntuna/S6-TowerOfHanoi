// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.

#include "TowerOfHanoi_V3.h"
#include "TowerOfHanoi_V3HUD.h"
#include "Engine/Canvas.h"
#include "TextureResource.h"
#include "CanvasItem.h"

ATowerOfHanoi_V3HUD::ATowerOfHanoi_V3HUD()
{
	// Set the crosshair texture
	static ConstructorHelpers::FObjectFinder<UTexture2D> CrosshiarTexObj(TEXT("/Game/FirstPerson/Textures/Aim"));
	CrosshairTex = CrosshiarTexObj.Object;
}


void ATowerOfHanoi_V3HUD::DrawHUD()
{
	Super::DrawHUD();

	// Draw very simple crosshair

	// find center of the Canvas
	const FVector2D Center(Canvas->ClipX * 0.5f, Canvas->ClipY * 0.5f);

	// offset by half the texture's dimensions so that the center of the texture aligns with the center of the Canvas
	const FVector2D CrosshairDrawPosition( (Center.X),
										   (Center.Y));

	// draw the crosshair
	FCanvasTileItem TileItem( CrosshairDrawPosition, CrosshairTex->Resource, FLinearColor::White);
	TileItem.BlendMode = SE_BLEND_Translucent;
	//Canvas->DrawItem( TileItem );
}

