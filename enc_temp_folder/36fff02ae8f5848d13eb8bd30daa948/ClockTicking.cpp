// Fill out your copyright notice in the Description page of Project Settings.


#include "ClockTicking.h"

// Sets default values for this component's properties
UClockTicking::UClockTicking()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UClockTicking::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UClockTicking::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{

	if (!AllowedToTick)
	{
		return;
	}
	
	TimeElapsed += DeltaTime;
	
	if (TimeElapsed < 1)
	{
		return;
	}
	
	SecondHand->SetRelativeRotation(SecondHand->GetRelativeRotation().Add(0, 0, 6));
	
	TimeElapsed = 0;
	SecondsElapsed++;
	
	if (SecondsElapsed == 60)
	{
		//DIE HERE
	}

}

