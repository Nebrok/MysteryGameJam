// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include <iostream>
#include <random>
#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "AnomalyManager.generated.h"

/**
 * 
 */
UCLASS()
class MYSTERYGAMEJAM_API UAnomalyManager : public UGameInstanceSubsystem
{
	GENERATED_BODY()
	
public:

	UFUNCTION(BlueprintCallable)
	void SetAnomalies();

	UFUNCTION(BlueprintCallable)
	void CorrectSelection();

	UFUNCTION(BlueprintCallable)
	void WrongSelection();

private:

	void LoadRooms();

};
