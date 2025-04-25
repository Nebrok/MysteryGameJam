// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ClockTicking.h"
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

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	UClockTicking* ClockTicking;

	//Room Object References
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Existing Object Reference")
	UStaticMeshComponent* CornerChair;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Existing Object Reference")
	UStaticMeshComponent* CuckChair;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Existing Object Reference")
	UStaticMeshComponent* BedsideTable;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Existing Object Reference")
	UStaticMeshComponent* ClockBack;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Existing Object Reference")
	UStaticMeshComponent* HourHand;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Existing Object Reference")
	UStaticMeshComponent* MinuteHand;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Existing Object Reference")
	UStaticMeshComponent* FloorLampRef;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Existing Object Reference")
	UStaticMeshComponent* Pillow;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Existing Object Reference")
	UStaticMeshComponent* Box1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Existing Object Reference")
	UStaticMeshComponent* Box2;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Existing Object Reference")
	UStaticMeshComponent* Box3;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Existing Object Reference")
	UStaticMeshComponent* Towel1Ref;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Existing Object Reference")
	UStaticMeshComponent* Towel2Ref;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Existing Object Reference")
	UStaticMeshComponent* BedLamp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Existing Object Reference")
	UStaticMeshComponent* Sink;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Existing Object Reference")
	UStaticMeshComponent* Toilet;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Existing Object Reference")
	UStaticMeshComponent* Pamphlet;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Existing Object Reference")
	TArray<UMaterial*> RoomScoreMats;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Existing Object Reference")
	UStaticMeshComponent* PamphletTable;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Existing Object Reference")
	UStaticMeshComponent* TiltedChair;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Existing Object Reference")
	UStaticMeshComponent* NotTiltedChair;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Existing Object Reference")
	UStaticMeshComponent* Box4;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Existing Object Reference")
	UDecalComponent* Poster;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Existing Object Reference")
	UStaticMeshComponent* ToiletPaperRoll;

	//Static Meshes for spawning to room
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "New Object Reference")
	UStaticMesh* NewPillow1;



protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void PosterGone();

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

	void DeleteBox1();

	void CornerChairRotated();

	void BedsideRotated();

	void PillowDeleted();

	void TowelsDeleted();

	void BigToilet();

	void TallLamp();

	void Room666();

	void PamphletTableFlipped();

	void ChairsSwapped();

	void Box4Moved();

	void AddToiletPaper();

private:
	void MassiveIfCheck();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable)
	void CheckForAnomalyChanges();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void SetRoomObjectReferences();

	UFUNCTION()
	void UpdatePamphlet();

	void SetRoomObjectReferences_Implementation();

	UFUNCTION(BlueprintCallable)
	void TestAnomaly();

};
