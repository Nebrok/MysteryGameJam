// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ClockTicking.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class MYSTERYGAMEJAM_API UClockTicking : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UClockTicking();

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	float TimeElapsed;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	int SecondsElapsed;

	//UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	bool AllowedToTick = false;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	UStaticMeshComponent* SecondHand;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
