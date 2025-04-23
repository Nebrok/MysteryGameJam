// Fill out your copyright notice in the Description page of Project Settings.

#include "Room.h"
#include "RoomManager.h"
#include "AnomalyManager.h"

// Sets default values
ARoom::ARoom()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ARoom::BeginPlay()
{
	Super::BeginPlay();
	GameInstance = GetWorld()->GetGameInstance();
	RoomManager = GameInstance->GetSubsystem<URoomManager>();

}

// Called every frame
void ARoom::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ARoom::CheckForAnomalyChanges()
{
	Anomaly = GameInstance->GetSubsystem<UAnomalyManager>()->GetAnomaly();
	if (Anomaly != nullptr)
	{
		HasAnomaly = true;
		DefaultAnomaly();
	}
}

void ARoom::DefaultAnomaly()
{
	FActorSpawnParameters spawnParams;
	spawnParams.bNoFail = true;

	FVector location = GetActorLocation();

	AActor* newRoom = GetWorld()->SpawnActor<AActor>(DefaultCube, location, FRotator(0,0,0), spawnParams);
}

