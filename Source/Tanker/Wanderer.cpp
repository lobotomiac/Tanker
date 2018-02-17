// Fill out your copyright notice in the Description page of Project Settings.
// Actor that moves to one place after a timer goes off, and back after a second one


#include "Wanderer.h"


// Sets default values
AWanderer::AWanderer()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	CountdownText = CreateDefaultSubobject<UTextRenderComponent>(TEXT("CountdownNumber"));
	CountdownText->SetHorizontalAlignment(EHTA_Center);
	CountdownText->SetWorldSize(150.0f);
	RootComponent = CountdownText;

	GoFromStartIn = 3;
	BackToStartIn = 5;

	WanderDistance = 200;
}

// Called when the game starts or when spawned
void AWanderer::BeginPlay()
{
	Super::BeginPlay();

	UpdateTimerDisplay(GoFromStartIn);
	GetWorldTimerManager().SetTimer(CountdownTimerHandle, this, &AWanderer::AdvanceTimer, 1.0f, true);

	UpdateTimerDisplay(BackToStartIn);
	GetWorldTimerManager().SetTimer(CountdownTimerHandle, this, &AWanderer::RetreatTimer, 1.0f, true);

}

// Called every frame
void AWanderer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AWanderer::UpdateTimerDisplay(int time)
{
	CountdownText->SetText(FString::FromInt(FMath::Max(time, 0)));
}

void AWanderer::AdvanceTimer()
{
	--GoFromStartIn;
	UpdateTimerDisplay(GoFromStartIn);
	if (GoFromStartIn < 1)
	{
		// We're done counting down, so stop running the timer.
		GetWorldTimerManager().ClearTimer(CountdownTimerHandle);
		//Perform any special actions we want to do when the timer ends.
		MoveActorFromStart();
	}
}

void AWanderer::MoveActorFromStart_Implementation()
{
	FVector StartLocation = GetActorLocation();
	FVector NewLocation;
	NewLocation.X = StartLocation.X + WanderDistance;

	SetActorLocation(NewLocation);


}


void AWanderer::RetreatTimer()
{
	--BackToStartIn;
	UpdateTimerDisplay(BackToStartIn);
	if (BackToStartIn < 1)
	{
		// We're done counting down, so stop running the timer.
		GetWorldTimerManager().ClearTimer(CountdownTimerHandle);
		//Perform any special actions we want to do when the timer ends.
		MoveActorToStart();
	}
}

void AWanderer::MoveActorToStart_Implementation()
{
	FVector StartLocation = GetActorLocation();
	FVector NewLocation;
	NewLocation.X = StartLocation.X - WanderDistance;

	SetActorLocation(NewLocation);

	UpdateTimerDisplay(BackToStartIn);
}

