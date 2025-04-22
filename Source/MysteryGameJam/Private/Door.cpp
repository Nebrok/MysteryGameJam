// Fill out your copyright notice in the Description page of Project Settings.


#include "Door.h"

// Sets default values
ADoor::ADoor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


	SceneComponent = CreateDefaultSubobject<USceneComponent>(TEXT("SceneComponent"));
	RootComponent = SceneComponent;

	CollisionComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("CollisionComponent"));
	CollisionComponent->SetupAttachment(RootComponent);

}

// Called when the game starts or when spawned
void ADoor::BeginPlay()
{
	Super::BeginPlay();

	InitialTransform = GetTransform();
	
}

// Called every frame
void ADoor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	auto gotRotation = InitialTransform.GetRotation();
	FRotator NewRotation = FRotator(gotRotation.X, gotRotation.Z + 90, gotRotation.Y);

	if (Rotate)
	{
		SetActorRotation(NewRotation);
	}
}

void ADoor::OpenDoor()
{
	Rotate = true;
	UE_LOG(LogTemp, Display, TEXT("The door is being opened"));
}

