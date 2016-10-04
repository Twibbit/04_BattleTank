// Fill out your copyright notice in the Description page of Project Settings.



#include "BattleTank.h"
#include "Tank.h"
#include "TankAIController.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

}
// Called Every Frame
void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	auto PlayerTank = Cast<ATank>(PlayerPawn);

	auto MyTank = Cast<ATank>(GetPawn());

	if (PlayerTank && MyTank)
	{
		//TODO Move towards the player

		//Aim at the player
		MyTank->AimAt(PlayerTank->GetActorLocation());

		MyTank->Fire();//TODO Limit Firing Rate
	}

}
