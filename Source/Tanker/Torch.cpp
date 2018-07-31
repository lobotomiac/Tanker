// Fill out your copyright notice in the Description page of Project Settings.

#include "Torch.h"


// Sets default values
ATorch::ATorch()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Torch = CreateDefaultSubobject<UStaticMeshComponent>("Torch");
	
	BurnoutText = CreateDefaultSubobject<UTextRenderComponent>(TEXT("BurnoutText"));
	BurnoutText->SetHorizontalAlignment(EHTA_Center);
	BurnoutText->SetWorldSize(150.0f);
	RootComponent = BurnoutText;

	BurningTime = 5;

}

// Called when the game starts or when spawned
void ATorch::BeginPlay()
{
	Super::BeginPlay();
	GetWorldTimerManager().SetTimer(CountdownTimerHandle, this, &ATorch::AdvanceTimer, 1.0f, true);
	
}

// Called every frame
void ATorch::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


void ATorch::AdvanceTimer()
{
	--BurningTime;
	if (BurningTime < 1)
	{
		//	we're done counting, stop running the timer
		GetWorldTimerManager().ClearTimer(CountdownTimerHandle);
		//TorchBurnedOut();
	}
}

void ATorch::TorchBurnedOut()
{
	BurnoutText->SetText("Burned out.");
}
