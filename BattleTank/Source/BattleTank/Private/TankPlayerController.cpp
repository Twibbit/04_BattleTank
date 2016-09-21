// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "Public/TankPlayerController.h"


// Called every frame
void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimTowardsCrossair();

}


	
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
void ATankPlayerController::AimTowardsCrossair()
{
	if (!GetControlledTank()) { return; }
	//Get world location if linetrace through crosshair
	//if it hits the landscape
		//Tell controlled tank to aim at this point
}
