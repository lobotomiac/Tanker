// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "TutorialPawn.generated.h"

UCLASS()
class TANKER_API ATutorialPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ATutorialPawn();

	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* CubeMesh = nullptr;

	UPROPERTY(VisibleAnywhere, Category = Camera)
	UCameraComponent* Camera = nullptr;

	UPROPERTY(VisibleAnywhere, Category = Camera)
	USpringArmComponent* SpringArm = nullptr;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void MoveForward(float value);
	void MoveRight(float value);
	
};
