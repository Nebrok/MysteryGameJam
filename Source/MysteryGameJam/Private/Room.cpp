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

	if (Anomaly == nullptr)
	{
		return;
	}

	HasAnomaly = true;
	DefaultAnomaly();

	if (Anomaly->FlipWallPaper)
	{
		FlipWallpaper();
	}
	if (Anomaly->DiffrentTime)
	{
		DifferentTime();
	}
	if (Anomaly->UnmadeBed)
	{
		UnmadeBed();
	}
	if (Anomaly->AlternateBathroomTiling)
	{
		AlternateBathroomTiling();
	}
	if (Anomaly->CarpetColourChange)
	{
		CarpetColourChange();
	}
	if (Anomaly->LampFlicked)
	{
		LampFlicker();
	}
	if (Anomaly->NarrowBedLegs)
	{
		NarrowBedLegs();
	}
	if (Anomaly->CuckChairRotated)
	{
		CuckChairRotated();
	}
	if (Anomaly->PersonInCuckChair)
	{
		PersonInCuckChair();
	}
	if (Anomaly->DeadBodyBathTub)
	{
		DeadBodyBathTub();
	}
	if (Anomaly->WiltedFlower)
	{
		WiltedFlower();
	}
	if (Anomaly->ClosedBathroomDoor)
	{
		CloseBathroomDoor();
	}
	

}

void ARoom::DefaultAnomaly()
{
	FActorSpawnParameters spawnParams;
	spawnParams.bNoFail = true;

	FVector location = GetActorLocation();

	AActor* newRoom = GetWorld()->SpawnActor<AActor>(DefaultCube, location, FRotator(0,0,0), spawnParams);
}

void ARoom::TestAnomaly()
{
	CuckChairRotated();
}


void ARoom::FlipWallpaper()
{
	int foo = 5;
	bool bar = false;
	if (foo == 5)
	{
		bar = true;
	}
}

void ARoom::DifferentTime()
{
}

void ARoom::UnmadeBed()
{
	//Unmaking the bed her e:)
	int hej = 3;
}

void ARoom::AlternateBathroomTiling()
{
}

void ARoom::CarpetColourChange()
{
}

void ARoom::LampFlicker()
{
}

void ARoom::NarrowBedLegs()
{
}

void ARoom::CuckChairRotated()
{

	auto quatRotation = CuckChair->GetRelativeTransform().GetRotation();
	FRotator newRotation = FRotator(quatRotation.Euler().X, quatRotation.Euler().Z + 90, quatRotation.Euler().Y);
	CuckChair->SetRelativeRotation(newRotation);
}

void ARoom::PersonInCuckChair()
{
}

void ARoom::DeadBodyBathTub()
{
}

void ARoom::BloodPoolBathroom()
{
}

void ARoom::WiltedFlower()
{
}

void ARoom::CloseBathroomDoor()
{
}

