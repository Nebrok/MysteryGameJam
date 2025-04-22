// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */
class MYSTERYGAMEJAM_API AnomalySelectionBase
{
public:
	AnomalySelectionBase();
	~AnomalySelectionBase();


	UPROPERTY(BlueprintReadWrite)
	bool FlipWallPaper;
	UPROPERTY(BlueprintReadWrite)
	bool DiffrentTime;
	UPROPERTY(BlueprintReadWrite)
	bool UnmadeBed;
	UPROPERTY(BlueprintReadWrite)
	bool WeatherChange;
	UPROPERTY(BlueprintReadWrite)
	bool AlternateBathroomTiling;
	UPROPERTY(BlueprintReadWrite)
	bool CarpetColourChange;
	UPROPERTY(BlueprintReadWrite)
	bool LampFlicked;
	UPROPERTY(BlueprintReadWrite)
	bool NarrowBedLegs;
	UPROPERTY(BlueprintReadWrite)
	bool TVStatic;
	UPROPERTY(BlueprintReadWrite)
	bool CuckChairFlipped;

};
