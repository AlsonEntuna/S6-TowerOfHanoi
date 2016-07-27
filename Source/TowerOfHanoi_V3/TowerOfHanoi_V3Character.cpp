// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.

#include "TowerOfHanoi_V3.h"
#include "TowerOfHanoi_V3Character.h"
#include "TowerOfHanoi_V3Projectile.h"
#include "Animation/AnimInstance.h"
#include "GameFramework/InputSettings.h"

DEFINE_LOG_CATEGORY_STATIC(LogFPChar, Warning, All);

//////////////////////////////////////////////////////////////////////////
// ATowerOfHanoi_V3Character

ATowerOfHanoi_V3Character::ATowerOfHanoi_V3Character()
{
	// Set size for collision capsule
	GetCapsuleComponent()->InitCapsuleSize(55.f, 96.0f);

	// set our turn rates for input
	BaseTurnRate = 45.f;
	BaseLookUpRate = 45.f;

	// Create a CameraComponent	
	FirstPersonCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("FirstPersonCamera"));
	FirstPersonCameraComponent->SetupAttachment(GetCapsuleComponent());
	FirstPersonCameraComponent->RelativeLocation = FVector(-39.56f, 1.75f, 64.f); // Position the camera
	FirstPersonCameraComponent->bUsePawnControlRotation = true;

	

	

	// Default offset from the character location for projectiles to spawn
	GunOffset = FVector(100.0f, 30.0f, 10.0f);

	// Note: The ProjectileClass and the skeletal mesh/anim blueprints for Mesh1P are set in the
	// derived blueprint asset named MyCharacter (to avoid direct content references in C++)
}

void ATowerOfHanoi_V3Character::BeginPlay()
{
	// Call the base class  
	Super::BeginPlay();

	CanMove = true;
}

//////////////////////////////////////////////////////////////////////////
// Input

void ATowerOfHanoi_V3Character::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	// set up gameplay key bindings
	check(InputComponent);

	InputComponent->BindAction("Fire", IE_Pressed, this, &ATowerOfHanoi_V3Character::EnableIsDragging);
	InputComponent->BindAction("Fire", IE_Released, this, &ATowerOfHanoi_V3Character::DisableIsDragging);

	InputComponent->BindAxis("MoveForward", this, &ATowerOfHanoi_V3Character::MoveForward);
	InputComponent->BindAxis("MoveRight", this, &ATowerOfHanoi_V3Character::MoveRight);

	// We have 2 versions of the rotation bindings to handle different kinds of devices differently
	// "turn" handles devices that provide an absolute delta, such as a mouse.
	// "turnrate" is for devices that we choose to treat as a rate of change, such as an analog joystick
	InputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
	InputComponent->BindAxis("TurnRate", this, &ATowerOfHanoi_V3Character::TurnAtRate);
	InputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput);
	InputComponent->BindAxis("LookUpRate", this, &ATowerOfHanoi_V3Character::LookUpAtRate);
}

void ATowerOfHanoi_V3Character::EnableIsDragging() { IsDragging = true; }
void ATowerOfHanoi_V3Character::DisableIsDragging()
{
	IsDragging = false; 
	DropEvent.Broadcast();
}


void ATowerOfHanoi_V3Character::BeginTouch(const ETouchIndex::Type FingerIndex, const FVector Location)
{
	if (TouchItem.bIsPressed == true)
	{
		return;
	}
	TouchItem.bIsPressed = true;
	TouchItem.FingerIndex = FingerIndex;
	TouchItem.Location = Location;
	TouchItem.bMoved = false;
}

void ATowerOfHanoi_V3Character::EndTouch(const ETouchIndex::Type FingerIndex, const FVector Location)
{
	if (TouchItem.bIsPressed == false)
	{
		return;
	}

	TouchItem.bIsPressed = false;
}

void ATowerOfHanoi_V3Character::TouchUpdate(const ETouchIndex::Type FingerIndex, const FVector Location)
{
	if ((TouchItem.bIsPressed == true) && (TouchItem.FingerIndex == FingerIndex))
	{
		if (TouchItem.bIsPressed)
		{
			if (GetWorld() != nullptr)
			{
				UGameViewportClient* ViewportClient = GetWorld()->GetGameViewport();
				if (ViewportClient != nullptr)
				{
					FVector MoveDelta = Location - TouchItem.Location;
					FVector2D ScreenSize;
					ViewportClient->GetViewportSize(ScreenSize);
					FVector2D ScaledDelta = FVector2D(MoveDelta.X, MoveDelta.Y) / ScreenSize;
					if (FMath::Abs(ScaledDelta.X) >= 4.0 / ScreenSize.X)
					{
						TouchItem.bMoved = true;
						float Value = ScaledDelta.X * BaseTurnRate;
						AddControllerYawInput(Value);
					}
					if (FMath::Abs(ScaledDelta.Y) >= 4.0 / ScreenSize.Y)
					{
						TouchItem.bMoved = true;
						float Value = ScaledDelta.Y * BaseTurnRate;
						AddControllerPitchInput(Value);
					}
					TouchItem.Location = Location;
				}
				TouchItem.Location = Location;
			}
		}
	}
}

void ATowerOfHanoi_V3Character::MoveForward(float Value)
{
	if (Value != 0.0f)
	{
		// add movement in that direction
		if (CanMove)
			AddMovementInput(GetActorForwardVector(), Value);
	}
}

void ATowerOfHanoi_V3Character::MoveRight(float Value)
{
	if (Value != 0.0f)
	{
		// add movement in that direction
		if (CanMove)
			AddMovementInput(GetActorRightVector(), Value);
	}
}

void ATowerOfHanoi_V3Character::TurnAtRate(float Rate)
{
	// calculate delta for this frame from the rate information
	AddControllerYawInput(Rate * BaseTurnRate * GetWorld()->GetDeltaSeconds());
}

void ATowerOfHanoi_V3Character::LookUpAtRate(float Rate)
{
	// calculate delta for this frame from the rate information
	AddControllerPitchInput(Rate * BaseLookUpRate * GetWorld()->GetDeltaSeconds());
}

bool ATowerOfHanoi_V3Character::EnableTouchscreenMovement(class UInputComponent* InputComponent)
{
	bool bResult = false;
	if (FPlatformMisc::GetUseVirtualJoysticks() || GetDefault<UInputSettings>()->bUseMouseForTouch)
	{
		bResult = true;
		InputComponent->BindTouch(EInputEvent::IE_Pressed, this, &ATowerOfHanoi_V3Character::BeginTouch);
		InputComponent->BindTouch(EInputEvent::IE_Released, this, &ATowerOfHanoi_V3Character::EndTouch);
		InputComponent->BindTouch(EInputEvent::IE_Repeat, this, &ATowerOfHanoi_V3Character::TouchUpdate);
	}
	return bResult;
}
