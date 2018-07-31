// Fill out your copyright notice in the Description page of Project Settings.


#include "SimpleObject.h"
#include "UnrealMathUtility.h"


// Sets default values
ASimpleObject::ASimpleObject()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	ObjectMesh = CreateDefaultSubobject<UStaticMeshComponent>("ObjectMesh");
}

// Called when the game starts or when spawned
void ASimpleObject::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void ASimpleObject::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// adding a "free moving" behaviour to an actor
	FVector NewLocation = GetActorLocation();
	float DeltaHeight = (FMath::Sin(RunningTime + DeltaTime * 0.7) - FMath::Sin(RunningTime));
	NewLocation.Z += FMath::Sin(RunningTime * 3.50) * DeltaTime * 60.0f;      //Scale our height by a factor of 
	NewLocation.X += FMath::Sin(RunningTime*2.42) * DeltaTime * 30.0f;
	NewLocation.Y += FMath::Sin(RunningTime *2.4) * DeltaTime * 50.0f;

	RunningTime += DeltaTime;

	SetActorLocation(NewLocation);
	/*	 it's a mathematcial problem :
	We 're adding to the NewLocation a Sinus value (in other words a coefficient staying between 1 and -1) multiplied by DeltaTime 
	(the object will move in fonction of the time and not in function of the frames, like this if you have 30 fps or 200 fps the object will move at the same speed), multiplied by a float 
	(a strenght factor).
	To change the periodicity of the movement, you have to deal with the sinus.
	Imagine the sinus graph with the angles values (on X axis) replaced by the RunningTime values and the Y axis (between -1 and 1) represents a coefficient of the object's Z location.
	To accelerate the periodicity of the movement, in other words to "contract" the sinus' graph in the X axis, you can multiply the RunningTime factor. 
	It's what I did on my NewLocation.Z by example. So the Z movement will change faster in function of the time because the coefficient will change between 1 and -1 faster in function of the time.
	And if you want to slow the periodicity you can "expand" the graph by multiplying the RunningTime factor by something between 1 and 0.
	And if you multiply with different coefficients the RunningTime in the sinus of each X,Y,Z components, 
	you'll have different periodicities on each components and then a more "naturally" floating object.			*/

}

