// Fill out your copyright notice in the Description page of Project Settings.


#include "AnomalyManager.h"
#include "Room.h"


void UAnomalyManager::LoadAllAnomalies(TArray<UAnomalySelectBaseAsset*> loadAnomalies)
{
	allAnomalies = loadAnomalies;

}

UAnomalySelectBaseAsset* UAnomalyManager::GetAnomaly()
{
	//int anomalyPresent = rand() % 2;
	//
	//if (anomalyPresent == 0) //DO NOTHING
	//{
	//	UE_LOG(LogTemp, Display, TEXT("There is no anomaly"));
	//	return nullptr;
	//}
	//else
	//{
	//	int randomAnomaly = rand() % allAnomalies.Num();
	//
	//	UE_LOG(LogTemp, Display, TEXT("There is an anomaly: %d"), randomAnomaly);
	//
	//	return allAnomalies[randomAnomaly];
	//}

	return nullptr;
}

void UAnomalyManager::CorrectSelection()
{
}

void UAnomalyManager::WrongSelection()
{
}

