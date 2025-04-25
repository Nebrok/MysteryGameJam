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
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	ARoom* RoomExited;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	ADoor* ForwardDoor;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	ADoor* DoorEntered;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	ADoor* BackDoor;


	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<ARoom> BaseRoom;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<ADoor> BaseDoor;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<ARoom> EndRoom;

	UFUNCTION(BlueprintCallable)
	void SpawnWhenEnter(ARoom* callingRoom, ADoor* doorThatIsEntered);

	UFUNCTION(BlueprintCallable)
	void SpawnAfterAnimation(ARoom* callingRoom);

	ARoom* SpawnNewRoom(FVector location, FRotator rotation);

	ARoom* SpawnEndRoom(FVector location, FRotator rotation);

	void CheckCorrectDoor(bool forward);

};


