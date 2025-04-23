// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include <iostream>
#include <random>
#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "AnomalySelectBaseAsset.h"
#include "AnomalyManager.generated.h"

class ARoom;
/**
 * 
 */
UCLASS()
class MYSTERYGAMEJAM_API UAnomalyManager : public UGameInstanceSubsystem
{
	GENERATED_BODY()
	
public:

	UFUNCTION(BlueprintCallable)
	void LoadAllAnomalies(TArray<UAnomalySelectBaseAsset*> loadAnomalies);

	UFUNCTION(BlueprintCallable)
	bool GetAnomaly(ARoom* callingRoom);

	UFUNCTION(BlueprintCallable)
	void CorrectSelection();

	UFUNCTION(BlueprintCallable)
	void WrongSelection();

private:

	TArray<UAnomalySelectBaseAsset*> allAnomalies;

};
