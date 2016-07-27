// Fill out your copyright notice in the Description page of Project Settings.

#include "TowerOfHanoi_V3.h"
#include "RingActor.h"


// Sets default values
ARingActor::ARingActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ARingActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ARingActor::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}


bool ARingActor::IsLowerRingID(int32 otherRingID)
{
	return this->RingID < otherRingID;
}
