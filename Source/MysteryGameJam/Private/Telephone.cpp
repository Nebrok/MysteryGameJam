// Fill out your copyright notice in the Description page of Project Settings.


#include "Telephone.h"

// Sets default values
ATelephone::ATelephone()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SceneComponent = CreateDefaultSubobject<USceneComponent>(TEXT("SceneComponent"));
	RootComponent = SceneComponent;

	CollisionComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("CollisionComponent"));
	CollisionComponent->SetupAttachment(RootComponent);

}

// Called when the game starts or when spawned
void ATelephone::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATelephone::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

