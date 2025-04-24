// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "ScoreKeeping.generated.h"

/**
 * 
 */
UCLASS()
class MYSTERYGAMEJAM_API UScoreKeeping : public UGameInstanceSubsystem
{
	GENERATED_BODY()
	
private:
	int roomScore;

public:

	UFUNCTION(BlueprintCallable)
	int ResetScore();

	UFUNCTION(BlueprintCallable)
	int AddToScore();

	UFUNCTION(BlueprintCallable)
	int GetScore() { return roomScore; }

};
