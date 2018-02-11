#pragma once

#include "GameFramework/Actor.h"
#include "SimpleObject.generated.h"

UCLASS()
class TANKER_API ASimpleObject : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ASimpleObject();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaSeconds) override;

	float RunningTime;

	UPROPERTY(EditAnywhere)
	float ScalingFactor;
};