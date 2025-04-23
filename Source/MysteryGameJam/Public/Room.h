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

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable)
	void CheckForAnomalyChanges();

	UFUNCTION(BlueprintCallable)
	void DefaultAnomaly();

};
