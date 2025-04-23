// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "RoomManager.generated.h"


class ARoom;
class ADoor;

/**
 * 
 */
UCLASS()
class MYSTERYGAMEJAM_API URoomManager : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	ARoom* ForwardRoom;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	ARoom* CurrentRoom;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	ARoom* BackRoom;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<ADoor> BaseDoor;

	TArray<ADoor*> Doors;

	UFUNCTION(BlueprintCallable)
	void SpawnNewRooms(ARoom* callingRoom);

	UFUNCTION(BlueprintCallable)
	void SpawnNewDoors();
	
	FVector GetBackRoomLocation();

	AActor* SpawnNewRoom(UClass* baseRoom, FVector location, FRotator rotation);

	void CheckCorrectDoor(bool forward);

};


