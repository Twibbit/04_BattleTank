// Fill out your copyright notice in the Description page of Project Settings.



#include "BattleTank.h"
#include "TankAIController.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("AI Controller Begin Play"));
	auto TempTank = GetControlledTank();
	if (TempTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("AIController possessing: %s"), *(TempTank->GetName()));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AI: Get Controlled Tank Failed"));
	}
}
ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}