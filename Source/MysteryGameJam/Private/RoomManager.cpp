// Fill out your copyright notice in the Description page of Project Settings.


#include "RoomManager.h"
#include "Door.h"
#include "Room.h"

void URoomManager::SpawnNewRooms(ARoom* callingRoom)
{
	bool movedForward = callingRoom == ForwardRoom;
	
	for (int i = 0; i < Doors.Num(); i++)
	{
		Doors[i]->Destroy();
	}
	Doors.Empty();

	CurrentRoom->Destroy();
	CurrentRoom = callingRoom;

	if (movedForward)
	{
		BackRoom->Destroy();
	}
	else
	{
		ForwardRoom->Destroy();
	}
	
	FActorSpawnParameters spawnParams;
	spawnParams.bNoFail = true;

	ARoom* newForwardRoom = GetWorld()->SpawnActor<ARoom>(CurrentRoom->BaseRoom, CurrentRoom->GetActorLocation() + (CurrentRoom->GetActorRightVector() * -700), CurrentRoom->GetActorRotation() + FRotator(0, -90, 0), spawnParams);
	ARoom* newBackRoom = GetWorld()->SpawnActor<ARoom>(CurrentRoom->BaseRoom, CurrentRoom->GetActorLocation() + (CurrentRoom->GetActorForwardVector() * -700), CurrentRoom->GetActorRotation() + FRotator(0, 180, 0), spawnParams);

	ADoor* newForwardDoor = GetWorld()->SpawnActor<ADoor>(BaseDoor, CurrentRoom->GetActorLocation() + (CurrentRoom->GetActorRightVector() * -350), CurrentRoom->GetActorRotation() + FRotator(0, 0, 0), spawnParams);
	ADoor* newBackDoor = GetWorld()->SpawnActor<ADoor>(BaseDoor, CurrentRoom->GetActorLocation() + (CurrentRoom->GetActorForwardVector() * -350), CurrentRoom->GetActorRotation() + FRotator(0, -90, 0), spawnParams);

	newForwardDoor->RoomConnected = newForwardRoom;
	newBackDoor->RoomConnected = newBackRoom;

	Doors.Add(newForwardDoor);
	Doors.Add(newBackDoor);

	//SpawnNewRoom(CurrentRoom->BaseRoom, GetBackRoomLocation(), CurrentRoom->GetActorForwardVector().BackwardVector.ToOrientationRotator());
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
