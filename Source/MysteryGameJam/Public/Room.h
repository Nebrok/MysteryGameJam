// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Room.generated.h"

class UAnomalySelectBaseAsset;
class URoomManager;

UCLASS()
class MYSTERYGAMEJAM_API ARoom : public AActor
{
	GENERATED_BODY()

public:	
	// Sets default values for this actor's properties
	ARoom();

	UGameInstance* GameInstance;
	URoomManager* RoomManager;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<ARoom> BaseRoom;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<AActor> DefaultCube;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	UAnomalySelectBaseAsset* Anomaly;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	bool HasAnomaly = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UStaticMeshComponent* CuckChair;


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void FlipWallpaper();

	void DifferentTime();

	void UnmadeBed();

	void AlternateBathroomTiling();

	void CarpetColourChange();

	void LampFlicker();

	void NarrowBedLegs();

	void CuckChairRotated();

	void PersonInCuckChair();

	void DeadBodyBathTub();

	void BloodPoolBathroom();

	void WiltedFlower();

	void CloseBathroomDoor();

	void SwappedFurniture1();

	void SwappedFurniture2();

	void SwappedFurniture3();

	void EyesUnderBed();

	void LampMoved();

	void PaintingMoved();

	void PersonOutsideWindow();

	void AddedAirVent();

	void PaintingChanged();


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable)
	void CheckForAnomalyChanges();

	UFUNCTION(BlueprintCallable)
	void DefaultAnomaly();

	UFUNCTION(BlueprintCallable)
	void TestAnomaly();

};
