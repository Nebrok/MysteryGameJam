// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "AnomalySelectBase.generated.h"

/**
 * 
 */
UCLASS()
class MYSTERYGAMEJAM_API UAnomalySelectBase : public UObject
{
	GENERATED_BODY()
	
public:

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
