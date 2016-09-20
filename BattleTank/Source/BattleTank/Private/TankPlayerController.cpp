// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "Public/TankPlayerController.h"




ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("Player Controller Begin Play"));
	auto TempTank = GetControlledTank();
	if (TempTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("PlayerController possessing: %s"), *(TempTank->GetName()));
	}
	else 
	{
		UE_LOG(LogTemp, Warning, TEXT("Get Controlled Tank Failed"));
	}
}
