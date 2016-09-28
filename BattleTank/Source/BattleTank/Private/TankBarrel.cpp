// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankBarrel.h"


void UTankBarrel::Elevate(float RelativeSpeed)
{
	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1.f, 1.f);
	
	//Move the barrel the right amount this frame
	
	//Given a max elvation speed, and the frame time
	auto ElevationChange = (RelativeSpeed * MaxDegreesPerSecond)* (GetWorld()->DeltaTimeSeconds);
	auto RawNewElevation = RelativeRotation.Pitch + ElevationChange;
	auto ClampedElevation = FMath::Clamp<float>(RawNewElevation, MinDegreesElevation, MaxDegreesElevation);
	SetRelativeRotation(FRotator(ClampedElevation, 0, 0));
}

