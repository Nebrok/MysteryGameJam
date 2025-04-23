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

	RoomManager = GetWorld()->GetGameInstance()->GetSubsystem<URoomManager>();
	InitialTransform = GetTransform();
	
}

// Called every frame
void ADoor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ADoor::OpenDoor()
{
	//Check if correct door
	//If correct update room with anomaly chance + increase score
	//If incorrect, don't run anomaly check + set score to 0




	Rotate = true;
	UE_LOG(LogTemp, Display, TEXT("The door is being opened"));

	RoomManager->SpawnNewRooms(RoomConnected);

}

