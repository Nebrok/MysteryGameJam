// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Room.h"
#include "RoomManager.h"
#include "Components/BoxComponent.h"
#include "Door.generated.h"

UCLASS()
class MYSTERYGAMEJAM_API ADoor : public AActor
{
	GENERATED_BODY()


public:	
	// Sets default values for this actor's properties
	ADoor();

	// So that we can have multiple children connected to the root component
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	USceneComponent* SceneComponent;

	ARoom* RoomConnected;
	URoomManager* RoomManager;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UBoxComponent* CollisionComponent;



protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	FTransform InitialTransform;


	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float RotationIncrement;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	float TotalRotation;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	bool Rotate;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable)
	void OpenDoor();

};
