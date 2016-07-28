// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/SaveGame.h"
#include "THanoiSaveFile.generated.h"

/**
 * 
 */
UCLASS()
class TOWEROFHANOI_V3_API UTHanoiSaveFile : public USaveGame
{
	GENERATED_BODY()
	
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "-- THanoiSaveFile Public Attributes --")
	FString m_PlayerName;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "-- THanoiSaveFile Public Attributes --")
	int32 m_PlayTimeRecord;

	UFUNCTION(BlueprintCallable, Category = "-- THanoiSaveFile Public Functions --")
	void SavePlayerData(FString playerName, int32 playTimeRecord);


	// SaveFile
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "-- THanoiSaveFile Public Attributes --")
	int32 UserIndex;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "-- THanoiSaveFile Public Attributes --")
	FString SaveSlotName;

	UTHanoiSaveFile();
	
};
