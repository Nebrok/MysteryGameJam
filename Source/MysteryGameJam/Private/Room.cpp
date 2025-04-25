// Fill out your copyright notice in the Description page of Project Settings.

#include "Room.h"
#include "RoomManager.h"
#include "ScoreKeeping.h"
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

	MassiveIfCheck();
}

void ARoom::UpdatePamphlet()
{
	if (Pamphlet)
	{
		Pamphlet->SetMaterial(0, RoomScoreMats[GetWorld()->GetGameInstance()->GetSubsystem<UScoreKeeping>()->GetScore()]);
	}

}

/*
* We just had 4 days
* Unreal unknown, it was new
* We all know this sucks
*/
void ARoom::MassiveIfCheck()
{
	if (Anomaly->PosterGone)
	{
		PosterGone();
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
	if (Anomaly->Box4Moved)
	{
		Box4Moved();
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
	if (Anomaly->SwappedFurniture1)
	{
		SwappedFurniture1();
	}
	if (Anomaly->SwappedFurniture2)
	{
		SwappedFurniture2();
	}
	if (Anomaly->SwappedFurniture3)
	{
		SwappedFurniture3();
	}
	if (Anomaly->EyesUnderBed)
	{
		EyesUnderBed();
	}
	if (Anomaly->LampMoved)
	{
		LampMoved();
	}
	if (Anomaly->PaintingMoved)
	{
		PaintingMoved();
	}
	if (Anomaly->PaintingChanged)
	{
		PaintingChanged();
	}
	if (Anomaly->PersonOutSideWindow)
	{
		PersonOutsideWindow();
	}
	if (Anomaly->AddedAirVent)
	{
		AddedAirVent();
	}
	if (Anomaly->DeleteBox1)
	{
		DeleteBox1();
	}
	if (Anomaly->CornerChairRotated)
	{
		CornerChairRotated();
	}
	if (Anomaly->BedsideRotated)
	{
		BedsideRotated();
	}
	if (Anomaly->PillowDeleted)
	{
		PillowDeleted();
	}
	if (Anomaly->TowelsDeleted)
	{
		TowelsDeleted();
	}
	if (Anomaly->BigToilet)
	{
		BigToilet();
	}
	if (Anomaly->TallLamp)
	{
		TallLamp();
	}
	if (Anomaly->ChairsSwapped)
	{
		ChairsSwapped();
	}
	if (Anomaly->PamphletTableFlipped)
	{
		PamphletTableFlipped();
	}
	if (Anomaly->Room666)
	{
		Room666();
	}
	if (Anomaly->AddToiletPaper)
	{
		AddToiletPaper();
	}
}


void ARoom::SetRoomObjectReferences_Implementation()
{
}

void ARoom::TestAnomaly()
{
	
}

void ARoom::PosterGone()
{
	
}

void ARoom::DifferentTime()
{
	auto minuteQuatRotation = MinuteHand->GetRelativeTransform().GetRotation();
	FRotator minuteRotation = FRotator(0, 0, 210);
	MinuteHand->SetRelativeRotation(minuteRotation);

	auto hourQuatRotation = HourHand->GetRelativeTransform().GetRotation();
	FRotator hourRotation = FRotator(0, 0, 105);
	HourHand->SetRelativeRotation(hourRotation);
}

void ARoom::UnmadeBed()
{

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
	FRotator newRotation = FRotator(quatRotation.Euler().X, quatRotation.Euler().Z + 180, quatRotation.Euler().Y);
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

void ARoom::SwappedFurniture1()
{
	FVector tempPos = BedLamp->GetRelativeLocation();

	BedLamp->SetRelativeLocation(Box3->GetRelativeLocation());
	Box3->SetRelativeLocation(tempPos);

}

void ARoom::SwappedFurniture2()
{
}

void ARoom::SwappedFurniture3()
{
}

void ARoom::EyesUnderBed()
{
}

void ARoom::LampMoved()
{
	FloorLampRef->SetRelativeLocation(FloorLampRef->GetRelativeLocation() + FVector(0, 150, 0));
}

void ARoom::PaintingMoved()
{
}

void ARoom::PersonOutsideWindow()
{
}

void ARoom::AddedAirVent()
{
}

void ARoom::PaintingChanged()
{
}

void ARoom::DeleteBox1()
{
	Box1->DestroyComponent();
}

void ARoom::CornerChairRotated()
{
	auto quatRotation = CornerChair->GetRelativeTransform().GetRotation();
	FRotator newRotation = FRotator(quatRotation.Euler().X, quatRotation.Euler().Z + 90, quatRotation.Euler().Y);
	CornerChair->SetRelativeRotation(newRotation);
}

void ARoom::BedsideRotated()
{
	auto quatRotation = BedsideTable->GetRelativeTransform().GetRotation();
	FRotator newRotation = FRotator(quatRotation.Euler().X, quatRotation.Euler().Z + 90, quatRotation.Euler().Y);
	BedsideTable->SetRelativeRotation(newRotation);
}

void ARoom::PillowDeleted()
{
	Pillow->DestroyComponent();
}

void ARoom::TowelsDeleted()
{
	Towel1Ref->DestroyComponent();
	Towel2Ref->DestroyComponent();
}

void ARoom::BigToilet()
{
	Toilet->SetRelativeScale3D(Toilet->GetRelativeScale3D() * 1.5f);
	Sink->SetRelativeScale3D(Sink->GetRelativeScale3D() * 1.5f);
}

void ARoom::TallLamp()
{
	FloorLampRef->SetRelativeScale3D(FloorLampRef->GetRelativeScale3D() + FVector(0, 0, 0.4));
}

void ARoom::Room666()
{
	Pamphlet->SetMaterial(0, RoomScoreMats[9]);
}

void ARoom::PamphletTableFlipped()
{
	auto quatRotation = PamphletTable->GetRelativeTransform().GetRotation();
	FRotator newRotation = FRotator(quatRotation.Euler().X, quatRotation.Euler().Z + 180, quatRotation.Euler().Y);
	PamphletTable->SetRelativeRotation(newRotation);
}

void ARoom::ChairsSwapped()
{
	TiltedChair->SetRelativeLocation(FVector (-160, -287, 8.291));
	NotTiltedChair->SetRelativeLocation(FVector(-238, -317, -1.354));
	
	auto quatRotation = NotTiltedChair->GetRelativeTransform().GetRotation();
	FRotator newRotation = FRotator(quatRotation.Euler().X, quatRotation.Euler().Z -70, quatRotation.Euler().Y);
	NotTiltedChair->SetRelativeRotation(newRotation);
}

void ARoom::Box4Moved()
{
	Box4->SetRelativeLocation(FVector(-335, 124, 1.53));
}

void ARoom::AddToiletPaper()
{
	ToiletPaperRoll->SetRelativeLocation(ToiletPaperRoll->GetRelativeLocation() + FVector(0, 0, 20));
}


