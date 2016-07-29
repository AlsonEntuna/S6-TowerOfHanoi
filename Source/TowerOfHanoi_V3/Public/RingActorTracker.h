// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "RingActor.h"
#include "GameFramework/Actor.h"
#include "RingActorTracker.generated.h"

class ARingActor;
UCLASS()
class TOWEROFHANOI_V3_API ARingActorTracker : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ARingActorTracker();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	
	// Tracker
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "-- RingActorTracker Public Attributes --")
	TArray<ARingActor*> ActiveRingActors;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "-- RingActorTracker Public Functions --")
	bool canMoveRingActor();
	
};
