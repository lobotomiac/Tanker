// Fill out your copyright notice in the Description page of Project Settings.

#include "TutorialPawn.h"
#include "Components/InputComponent.h"
#include "GameFramework/FloatingPawnMovement.h"


// Sets default values
ATutorialPawn::ATutorialPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CreateDefaultSubobject<UFloatingPawnMovement>("PawnMovement");

	CubeMesh = CreateDefaultSubobject<UStaticMeshComponent>("CubeMesh");
	CameraMesh = CreateDefaultSubobject<UCameraComponent>("CameraMesh");

}

// Called when the game starts or when spawned
void ATutorialPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATutorialPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void ATutorialPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveForward", this, &ATutorialPawn::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &ATutorialPawn::MoveRight);
}

void ATutorialPawn::MoveForward(float value)
{
	AddMovementInput(GetActorForwardVector(), value);
}

// Left & Right movement component
void ATutorialPawn::MoveRight(float value)
{
	AddMovementInput(GetActorRightVector(), value);
}

