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

	CurrentRoom->ClockTicking->AllowedToTick = true;

	FActorSpawnParameters spawnParams;
	spawnParams.bNoFail = true;
	ADoor* newForwardDoor = GetWorld()->SpawnActor<ADoor>(BaseDoor, CurrentRoom->GetActorLocation() + (CurrentRoom->GetActorRightVector() * -350) + (CurrentRoom->GetActorForwardVector() * -57), CurrentRoom->GetActorRotation() + FRotator(0, 0, 0), spawnParams);

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

	FVector currentRoomLocation = CurrentRoom->GetActorLocation();
	FRotator currentRoomRotation = CurrentRoom->GetActorRotation();

	ARoom* newForwardRoom;
	ARoom* newBackRoom;

	if (GetWorld()->GetGameInstance()->GetSubsystem<UScoreKeeping>()->GetScore() == 7) //More magic numbers
	{
		if (CurrentRoom->HasAnomaly)
		{
			newForwardRoom = SpawnNewRoom(currentRoomLocation + (CurrentRoom->GetActorRightVector() * -700), currentRoomRotation + FRotator(0, -90, 0));
			newBackRoom = SpawnEndRoom(currentRoomLocation + (CurrentRoom->GetActorForwardVector() * -700), currentRoomRotation + FRotator(0, 180, 0));
		}
		else
		{
			newForwardRoom = SpawnEndRoom(currentRoomLocation + (CurrentRoom->GetActorRightVector() * -700), currentRoomRotation + FRotator(0, -90, 0));
			newBackRoom = SpawnNewRoom(currentRoomLocation + (CurrentRoom->GetActorForwardVector() * -700), currentRoomRotation + FRotator(0, 180, 0));
		}
	}
	else
	{
		newForwardRoom = SpawnNewRoom(currentRoomLocation + (CurrentRoom->GetActorRightVector() * -700), currentRoomRotation + FRotator(0, -90, 0));
		newBackRoom = SpawnNewRoom(currentRoomLocation + (CurrentRoom->GetActorForwardVector() * -700), currentRoomRotation + FRotator(0, 180, 0));
	}

	ForwardRoom = newForwardRoom;
	BackRoom = newBackRoom;
	ForwardDoor->RoomConnected = ForwardRoom;

	ADoor* newBackDoor = GetWorld()->SpawnActor<ADoor>(BaseDoor, currentRoomLocation + (CurrentRoom->GetActorForwardVector() * -350) + (CurrentRoom->GetActorRightVector() * 57), currentRoomRotation + FRotator(0, -90, 0), spawnParams);
	
	newBackDoor->RoomConnected = BackRoom;
	BackDoor = newBackDoor;
}

ARoom* URoomManager::SpawnNewRoom(FVector location, FRotator rotation)
{
	FActorSpawnParameters spawnParams;
	spawnParams.bNoFail = true;


	ARoom* newRoom = GetWorld()->SpawnActor<ARoom>(BaseRoom, location, rotation, spawnParams);
	return newRoom;
}

ARoom* URoomManager::SpawnEndRoom(FVector location, FRotator rotation)
{
	FActorSpawnParameters spawnParams;
	spawnParams.bNoFail = true;


	ARoom* newRoom = GetWorld()->SpawnActor<ARoom>(EndRoom, location, rotation, spawnParams);
	return newRoom;
}

void URoomManager::CheckCorrectDoor(bool forward)
{
	auto scoreSubsystem = GetWorld()->GetGameInstance()->GetSubsystem<UScoreKeeping>();

	if (forward && !CurrentRoom->HasAnomaly || !forward && CurrentRoom->HasAnomaly)
	{
		//score ++
		UE_LOG(LogTemp, Display, TEXT("YAY"));


		scoreSubsystem->AddToScore();


		if (scoreSubsystem->GetScore() >= 8) //Magic Number for num correct need to fix
		{
			//Dont worry about it
		}
		else
		{
			ForwardRoom->UpdatePamphlet();
			BackRoom->UpdatePamphlet();

			ForwardRoom->CheckForAnomalyChanges();
			BackRoom->CheckForAnomalyChanges();
		}

		return;
	}

	//score = 0
	UE_LOG(LogTemp, Display, TEXT("NOUR"));
	scoreSubsystem->ResetScore();
}
