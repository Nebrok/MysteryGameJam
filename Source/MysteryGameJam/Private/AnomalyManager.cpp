// Fill out your copyright notice in the Description page of Project Settings.


#include "AnomalyManager.h"

void UAnomalyManager::SetAnomalies()
{
	int anomalyPresent = rand() % 2;

	if (anomalyPresent == 0) //LOAD NORMAL ROOM HERE
	{
		UE_LOG(LogTemp, Display, TEXT("There is no anomaly")); 
	}
	else if (anomalyPresent == 1) //LOAD ANOMALY ROOM HERE
	{
		UE_LOG(LogTemp, Display, TEXT("There is an anomaly"));
	}

}

void UAnomalyManager::CorrectSelection()
{
}

void UAnomalyManager::WrongSelection()
{
}

void UAnomalyManager::LoadRooms()
{
}
