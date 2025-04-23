// Fill out your copyright notice in the Description page of Project Settings.


#include "AnomalyManager.h"
#include "Room.h"


void UAnomalyManager::LoadAllAnomalies(TArray<UAnomalySelectBaseAsset*> loadAnomalies)
{
	allAnomalies = loadAnomalies;

}

bool UAnomalyManager::GetAnomaly(ARoom* callingRoom)
{
	int anomalyPresent = rand() % 2;

	if (anomalyPresent == 0) //DO NOTHING
	{
		UE_LOG(LogTemp, Display, TEXT("There is no anomaly"));
		return false;
	}
	else
	{
		int randomAnomaly = rand() % allAnomalies.Num();

		UE_LOG(LogTemp, Display, TEXT("There is an anomaly: %d"), randomAnomaly);

		//LOAD ANOMALY ROOM HERE

		return true;
	}
}

void UAnomalyManager::CorrectSelection()
{
}

void UAnomalyManager::WrongSelection()
{
}

