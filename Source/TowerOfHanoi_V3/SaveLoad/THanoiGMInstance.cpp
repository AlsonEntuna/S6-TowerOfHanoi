// Fill out your copyright notice in the Description page of Project Settings.

#include "TowerOfHanoi_V3.h"
#include "THanoiGMInstance.h"

void UTHanoiGMInstance::SyncDataToGMInstance(FString pName, int32 pTimeRecord)
{
	this->PlayerName = pName;
	this->PlayTimeRecord = pTimeRecord;
}


