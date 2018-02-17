// Fill out your copyright notice in the Description page of Project Settings.

#include "Tutorial.h"



// Sets default values
ATutorial::ATutorial()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("TutorialMesh");

}

// Called when the game starts or when spawned
void ATutorial::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATutorial::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector NewLocation = GetActorLocation();
	NewLocation.Z += 1.0f;
	SetActorLocation(NewLocation); 
}

