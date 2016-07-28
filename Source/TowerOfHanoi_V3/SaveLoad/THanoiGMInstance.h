// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine/GameInstance.h"
#include "THanoiGMInstance.generated.h"

/**
 * 
 */
//DECLARE_EVENT(FSyncToGInstanceDelegate, FString, int32);

UCLASS()
class TOWEROFHANOI_V3_API UTHanoiGMInstance : public UGameInstance
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "-- THanoiGMInstance Public Attributes --")
	FString PlayerName;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "-- THanoiGMInstance Public Attributes --")
	int32 PlayTimeRecord;

	//UPROPERTY(BlueprintAssignable, Category = "Custom Events")
		//FSyncToGInstanceDelegate SyncGInstanceEvent;

	UFUNCTION(BlueprintCallable, Category = "-- THanoiGMInstance Public Functions --")
	void SyncDataToGMInstance(FString pName, int32 pTimeRecord);
	
	
};
