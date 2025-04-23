// Fill out your copyright notice in the Description page of Project Settings.


#include "RoomManager.h"
#include "Room.h"

void URoomManager::InitRooms()
{
}

void URoomManager::SpawnNewRooms(ARoom* callingRoom)
{
	//bool movedForward = callingRoom == ForwardRoom;
	
	//CurrentRoom->Destroy();
	CurrentRoom = callingRoom;

	SpawnNewRoom(CurrentRoom->BaseRoom, GetBackRoomLocation(), CurrentRoom->GetActorForwardVector().BackwardVector.ToOrientationRotator());
}

FVector URoomManager::GetBackRoomLocation()
{
	FVector location;
	location = CurrentRoom->GetActorLocation() + (CurrentRoom->GetActorForwardVector() * -700);
	return location;
}

AActor* URoomManager::SpawnNewRoom(UClass* baseRoom, FVector location, FRotator rotation)
{
	if (foo)
	{
		return nullptr;
	}
	foo = true;
	FActorSpawnParameters spawnParams;
	spawnParams.bNoFail = true;


	AActor* newRoom = GetWorld()->SpawnActor<ARoom>(baseRoom, location, rotation, spawnParams);
	return newRoom;
}
