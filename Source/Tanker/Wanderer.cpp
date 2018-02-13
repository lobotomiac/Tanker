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
}

// Called when the game starts or when spawned
void AWanderer::BeginPlay()
{
	Super::BeginPlay();	

	UpdateTimerDisplay();
	GetWorldTimerManager().SetTimer(CountdownTimerHandle, this, &AWanderer::AdvanceTimer, 1.0f, true);
	StartLocation = GetActorLocation();
	NewLocation = StartLocation;
}

// Called every frame
void AWanderer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}


void AWanderer::UpdateTimerDisplay()
{
    CountdownText->SetText(FString::FromInt(FMath::Max(CountdownTime, 0)));
}


void AWanderer::AdvanceTimer()
{
	--CountdownTime;
	UpdateTimerDisplay();
	if (CountdownTime < 1)
	{
		// We're done counting down, so stop running the timer.
		GetWorldTimerManager().ClearTimer(CountdownTimerHandle);
		//Perform any special actions we want to do when the timer ends.
		CountdownHasFinished();
	}
}

void AWanderer::CountdownHasFinished_Implementation()
{
	if (NewLocation == StartLocation)
	{
		NewLocation.X += 100;
		SetActorLocation(NewLocation);

		CountdownTime = 5;
		UpdateTimerDisplay();
		GetWorldTimerManager().SetTimer(CountdownTimerHandle, this, &AWanderer::AdvanceTimer, 1.0f, true);
	}
	else
	{
		SetActorLocation(StartLocation);
	}
	
}

// TODO make a second event to move Actor back to start
// TODO make both timer values & both to be exposed