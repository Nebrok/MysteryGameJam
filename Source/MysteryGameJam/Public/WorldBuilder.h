// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RoomManager.h"
#include "WorldBuilder.generated.h"

class ARoom;
class ADoor;

UCLASS()
class MYSTERYGAMEJAM_API AWorldBuilder : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AWorldBuilder();
	URoomManager* RoomManager;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<ARoom> BaseRoom;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<ADoor> BaseDoor;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<ARoom> EndRoom;

	void SpawnInitRooms();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
