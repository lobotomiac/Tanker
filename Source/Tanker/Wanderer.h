// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
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
	int32 GoFromStartIn;

	UPROPERTY(EditAnywhere)
	int32 BackToStartIn;

	UPROPERTY(EditAnywhere)
	float WanderDistance;

	UTextRenderComponent* CountdownText;

	void UpdateTimerDisplay(int time);

	void AdvanceTimer();

	void RetreatTimer();


	UFUNCTION(BlueprintNativeEvent)
	void MoveActorFromStart();
	virtual void MoveActorFromStart_Implementation();

	UFUNCTION(BlueprintNativeEvent)
	void MoveActorToStart();
	virtual void MoveActorToStart_Implementation();

	FTimerHandle CountdownTimerHandle;
};
