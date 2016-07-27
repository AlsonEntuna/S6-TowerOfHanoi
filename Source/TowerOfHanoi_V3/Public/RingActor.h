// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "RingActor.generated.h"

UCLASS()
class TOWEROFHANOI_V3_API ARingActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ARingActor();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	// Variables
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "-- RingActor Public Attributes --")
		int32 RingID;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "-- RingActor Public Attributes --")
		bool CanBeMoved;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "-- RingActor Public Attributes --")
		FVector LastLocation;

	// Functions
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "-- RingActor Public Functions --")
		bool IsLowerRingID(int32 otherRingID);
	
};
