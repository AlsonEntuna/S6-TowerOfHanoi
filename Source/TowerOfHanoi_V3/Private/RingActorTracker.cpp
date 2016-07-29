// Fill out your copyright notice in the Description page of Project Settings.

#include "TowerOfHanoi_V3.h"
#include "RingActorTracker.h"


// Sets default values
ARingActorTracker::ARingActorTracker()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ARingActorTracker::BeginPlay()
{
	Super::BeginPlay();
	
	for (int i = 0; i < ActiveRingActors.Num(); i++)
		ActiveRingActors[i]->RingActorTrackerRef = this;
}

// Called every frame
void ARingActorTracker::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

bool ARingActorTracker::canMoveRingActor_Implementation()
{
	for (int i = 0; i < ActiveRingActors.Num(); i++)
	{
		if (ActiveRingActors[i]->IsBeingDragged)
		{
			return false;
			break;
		}
	}
	return true;
}

