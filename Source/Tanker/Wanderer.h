// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "App.h"
#include "Components/TextRenderComponent.h"
#include "GameFramework/Actor.h"
#include "Wanderer.generated.h"

UCLASS()
class TANKER_API AWanderer : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AWanderer();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere)
	int32 CountdownTime = 3;

	FVector StartLocation, NewLocation;

	UTextRenderComponent* CountdownText;

	void UpdateTimerDisplay();

	void AdvanceTimer();

	UFUNCTION(BlueprintNativeEvent)
	void CountdownHasFinished();
	virtual void CountdownHasFinished_Implementation();

	FTimerHandle CountdownTimerHandle;
};
