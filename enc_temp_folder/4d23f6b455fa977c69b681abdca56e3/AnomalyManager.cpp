// Fill out your copyright notice in the Description page of Project Settings.


#include "AnomalyManager.h"


void UAnomalyManager::SetAnomalies(TArray<UAnomalySelectBaseAsset*> loadAnomalies)
{
	allAnomalies = loadAnomalies;

	GetAnomaly();
}

void UAnomalyManager::GetAnomaly()
{
	int anomalyPresent = rand() % 2;

	if (anomalyPresent == 0) //LOAD NORMAL ROOM HERE
	{
		UE_LOG(LogTemp, Display, TEXT("There is no anomaly"));
	}
	else if (anomalyPresent == 1) //LOAD ANOMALY ROOM HERE
	{
		int randomAnomaly = rand() % allAnomalies.Num();

		UE_LOG(LogTemp, Display, TEXT("Index: %d"), randomAnomaly);
	}
}

void UAnomalyManager::CorrectSelection()
{
}

void UAnomalyManager::WrongSelection()
{
}

