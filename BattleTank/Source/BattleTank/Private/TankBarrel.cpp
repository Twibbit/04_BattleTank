// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankBarrel.h"


void UTankBarrel::Elevate(float DegreeesPerSecond)
{
	//Move the barrel the right amount this frame

	//Given a max elvation speed, and the frame time
	UE_LOG(LogTemp, Warning, TEXT("Barrel-Elevate called at speed %f"),DegreeesPerSecond);
}

