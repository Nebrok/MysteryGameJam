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
	bool PosterGone;
	UPROPERTY(EditAnywhere)
	bool DiffrentTime;
	UPROPERTY(EditAnywhere)
	bool UnmadeBed;
	UPROPERTY(EditAnywhere)
	bool ChairsSwapped;
	UPROPERTY(EditAnywhere)
	bool AlternateBathroomTiling;
	UPROPERTY(EditAnywhere)
	bool CarpetColourChange;
	UPROPERTY(EditAnywhere)
	bool LampFlicked;
	UPROPERTY(EditAnywhere)
	bool Box4Moved;
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
	UPROPERTY(EditAnywhere)
	bool SwappedFurniture1;
	UPROPERTY(EditAnywhere)
	bool SwappedFurniture2;
	UPROPERTY(EditAnywhere)
	bool SwappedFurniture3;
	UPROPERTY(EditAnywhere)
	bool EyesUnderBed;
	UPROPERTY(EditAnywhere)
	bool LampMoved;
	UPROPERTY(EditAnywhere)
	bool PaintingMoved;
	UPROPERTY(EditAnywhere)
	bool PersonOutSideWindow;
	UPROPERTY(EditAnywhere)
	bool AddedAirVent;
	UPROPERTY(EditAnywhere)
	bool PaintingChanged;
	UPROPERTY(EditAnywhere)
	bool DeleteBox1;
	UPROPERTY(EditAnywhere)
	bool CornerChairRotated;
	UPROPERTY(EditAnywhere)
	bool BedsideRotated;
	UPROPERTY(EditAnywhere)
	bool PillowDeleted;
	UPROPERTY(EditAnywhere)
	bool TowelsDeleted;
	UPROPERTY(EditAnywhere)
	bool BigToilet;
	UPROPERTY(EditAnywhere)
	bool TallLamp;
	UPROPERTY(EditAnywhere)
	bool Room666;
	UPROPERTY(EditAnywhere)
	bool PamphletTableFlipped;
	UPROPERTY(EditAnywhere)
	bool AddToiletPaper;
	UPROPERTY(EditAnywhere)
	bool SwapMiddleChair;
	UPROPERTY(EditAnywhere)
	bool BricksNotInPicture;

};
