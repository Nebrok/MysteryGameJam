// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "AnomalySelectBaseAsset.generated.h"

/**
 * 
 */
UCLASS()
class MYSTERYGAMEJAM_API UAnomalySelectBaseAsset : public UPrimaryDataAsset
{
	GENERATED_BODY()
	
public:
 
	  UPROPERTY(EditAnywhere)
	  bool FlipWallPaper;
	  UPROPERTY(EditAnywhere)
	  bool DiffrentTime;
	  UPROPERTY(EditAnywhere)
	  bool UnmadeBed;
	  UPROPERTY(EditAnywhere)
	  bool WeatherChange;
	  UPROPERTY(EditAnywhere)
	  bool AlternateBathroomTiling;
	  UPROPERTY(EditAnywhere)
	  bool CarpetColourChange;
	  UPROPERTY(EditAnywhere)
	  bool LampFlicked;
	  UPROPERTY(EditAnywhere)
	  bool NarrowBedLegs;
	  UPROPERTY(EditAnywhere)
	  bool TVStatic;
	  UPROPERTY(EditAnywhere)
	  bool CuckChairRotated;
	  UPROPERTY(EditAnywhere)
	  bool PersonInCuckChair;
	  UPROPERTY(EditAnywhere)
	  bool DeadBodyBathTub;
	  UPROPERTY(EditAnywhere)
	  bool BloodPoolBathroom;
	  UPROPERTY(EditAnywhere)
	  bool WiltedFlower;
	  UPROPERTY(EditAnywhere)
	  bool ClosedBathroomDoor;


};
