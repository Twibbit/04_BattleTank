// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankTurret.h"



void UTankTurret::RotateTurret(float RelativeSpeed)
{
	auto WorldTime = GetWorld()->GetTimeSeconds();
	UE_LOG(LogTemp, Warning, TEXT("%f: RotateTurret Called"), WorldTime);
	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1.f, 1.f);

	
	auto RotationChange = (RelativeSpeed * MaxDegreesPerSecond)* (GetWorld()->DeltaTimeSeconds);
	auto NewRotation = RotationChange + RelativeRotation.Yaw;
	SetRelativeRotation(FRotator(0,NewRotation,0));
}
