// Fill out your copyright notice in the Description page of Project Settings.

#include "TowerOfHanoi_V3.h"
#include "THanoiSaveFile.h"

UTHanoiSaveFile::UTHanoiSaveFile()
{
	SaveSlotName = TEXT("THanoiSaveSlot");
	UserIndex = 0;
}


void UTHanoiSaveFile::SavePlayerData(FString playerName, int32 playTimeRecord)
{

	this->m_PlayerName = playerName;
	this->m_PlayTimeRecord = playTimeRecord;
}

