// Fill out your copyright notice in the Description page of Project Settings.


#include "WorldBuilder.h"
#include "Room.h"
#include "AnomalyManager.h"
#include "Door.h"

// Sets default values
AWorldBuilder::AWorldBuilder()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AWorldBuilder::BeginPlay()
{
	Super::BeginPlay();

	RoomManager = GetWorld()->GetGameInstance()->GetSubsystem<URoomManager>();


	//Remove for build
	int numAnomaly = 0;
	for (int i = 0; i < 10000; i++)
	{
		if (GetWorld()->GetGameInstance()->GetSubsystem<UAnomalyManager>()->GetAnomaly() != nullptr)
			numAnomaly++;
	}
	UE_LOG(LogTemp, Display, TEXT("Diceroll Check: %f"), numAnomaly/ 10000.0f);

	SpawnInitRooms();
}

void AWorldBuilder::SpawnInitRooms()
{
	RoomManager->BaseRoom = BaseRoom;
	RoomManager->BaseDoor = BaseDoor;
	RoomManager->EndRoom = EndRoom;

	FActorSpawnParameters spawnParams;
	spawnParams.bNoFail = true;

	ARoom* newCurrentRoom = GetWorld()->SpawnActor<ARoom>(BaseRoom, FVector(0,0,0), FRotator(0, 0, 0), spawnParams);
	ARoom* newForwardRoom = GetWorld()->SpawnActor<ARoom>(BaseRoom, newCurrentRoom->GetActorLocation() + (newCurrentRoom->GetActorRightVector() * -700), newCurrentRoom->GetActorRotation() + FRotator(0,-90,0), spawnParams);
	ARoom* newBackRoom = GetWorld()->SpawnActor<ARoom>(BaseRoom, newCurrentRoom->GetActorLocation() + (newCurrentRoom->GetActorForwardVector() * -700), newCurrentRoom->GetActorRotation() + FRotator(0,180,0), spawnParams);

	ADoor* newForwardDoor = GetWorld()->SpawnActor<ADoor>(BaseDoor, newCurrentRoom->GetActorLocation() + (newCurrentRoom->GetActorRightVector() * -350) + (newCurrentRoom->GetActorForwardVector() * -57), newCurrentRoom->GetActorRotation() + FRotator(0, 0, 0), spawnParams);
	ADoor* newBackDoor = GetWorld()->SpawnActor<ADoor>(BaseDoor, newCurrentRoom->GetActorLocation() + (newCurrentRoom->GetActorForwardVector() * -350) + (newCurrentRoom->GetActorRightVector() * 57), newCurrentRoom->GetActorRotation() + FRotator(0, -90, 0), spawnParams);


	RoomManager->CurrentRoom = newCurrentRoom;
	RoomManager->ForwardRoom = newForwardRoom;
	RoomManager->BackRoom = newBackRoom;

	RoomManager->ForwardDoor = newForwardDoor;
	RoomManager->BackDoor = newBackDoor;

	newCurrentRoom->SetRoomObjectReferences();
	newForwardRoom->SetRoomObjectReferences();
	newBackRoom->SetRoomObjectReferences();

	newCurrentRoom->ClockTicking->AllowedToTick = true;

	newForwardDoor->IsForward = true;
	newForwardDoor->RoomConnected = newForwardRoom;
	newBackDoor->RoomConnected = newBackRoom;


}

// Called every frame
void AWorldBuilder::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

