// Fill out your copyright notice in the Description page of Project Settings.


#include "RoomManager.h"
#include "ScoreKeeping.h"
#include "Door.h"
#include "Room.h"

void URoomManager::SpawnWhenEnter(ARoom* callingRoom, ADoor* doorThatIsEntered)
{
	bool movedForward = callingRoom == ForwardRoom;

	if (movedForward)
	{
		BackDoor->Destroy();
	}
	else
	{
		ForwardDoor->Destroy();
	}

	RoomExited = CurrentRoom;

	CurrentRoom = callingRoom;

	FActorSpawnParameters spawnParams;
	spawnParams.bNoFail = true;

	ADoor* newForwardDoor = GetWorld()->SpawnActor<ADoor>(BaseDoor, CurrentRoom->GetActorLocation() + (CurrentRoom->GetActorRightVector() * -350), CurrentRoom->GetActorRotation() + FRotator(0, 0, 0), spawnParams);

	ForwardDoor = newForwardDoor;
	ForwardDoor->IsForward = true;

	DoorEntered = doorThatIsEntered;


}

void URoomManager::SpawnAfterAnimation(ARoom* callingRoom)
{

	DoorEntered->Destroy();

	bool movedForward = callingRoom == ForwardRoom;

	if (movedForward)
	{
		BackRoom->Destroy();
	}
	else
	{
		ForwardRoom->Destroy();
	}

	RoomExited->Destroy();

	FActorSpawnParameters spawnParams;
	spawnParams.bNoFail = true;

	ARoom* newForwardRoom = GetWorld()->SpawnActor<ARoom>(CurrentRoom->BaseRoom, CurrentRoom->GetActorLocation() + (CurrentRoom->GetActorRightVector() * -700), CurrentRoom->GetActorRotation() + FRotator(0, -90, 0), spawnParams);
	ARoom* newBackRoom = GetWorld()->SpawnActor<ARoom>(CurrentRoom->BaseRoom, CurrentRoom->GetActorLocation() + (CurrentRoom->GetActorForwardVector() * -700), CurrentRoom->GetActorRotation() + FRotator(0, 180, 0), spawnParams);

	ForwardRoom = newForwardRoom;
	BackRoom = newBackRoom;
	ForwardDoor->RoomConnected = ForwardRoom;

	ADoor* newBackDoor = GetWorld()->SpawnActor<ADoor>(BaseDoor, CurrentRoom->GetActorLocation() + (CurrentRoom->GetActorForwardVector() * -350), CurrentRoom->GetActorRotation() + FRotator(0, -90, 0), spawnParams);
	
	newBackDoor->RoomConnected = BackRoom;
	BackDoor = newBackDoor;
}

FVector URoomManager::GetBackRoomLocation()
{
	FVector location;
	location = CurrentRoom->GetActorLocation() + (CurrentRoom->GetActorForwardVector() * -700);
	return location;
}

AActor* URoomManager::SpawnNewRoom(UClass* baseRoom, FVector location, FRotator rotation)
{
	FActorSpawnParameters spawnParams;
	spawnParams.bNoFail = true;


	AActor* newRoom = GetWorld()->SpawnActor<ARoom>(baseRoom, location, rotation, spawnParams);
	return newRoom;
}

void URoomManager::CheckCorrectDoor(bool forward)
{
	if (forward && !CurrentRoom->HasAnomaly || !forward && CurrentRoom->HasAnomaly)
	{
		//score ++
		UE_LOG(LogTemp, Display, TEXT("YAY"));


		GetWorld()->GetGameInstance()->GetSubsystem<UScoreKeeping>()->AddToScore();

		ForwardRoom->CheckForAnomalyChanges();
		return;
	}

	//score = 0
	UE_LOG(LogTemp, Display, TEXT("NOUR"));
	GetWorld()->GetGameInstance()->GetSubsystem<UScoreKeeping>()->ResetScore();
}
