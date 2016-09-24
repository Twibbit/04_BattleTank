// Fill out your copyright notice in the Description page of Project Settings.



#include "BattleTank.h"
#include "TankAIController.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("AI Controller Begin Play"));
	auto TempTank = GetPlayerTank();
	if (TempTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("AI:PlayerTank possessing: %s"), *(TempTank->GetName()));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AI: Get Player Tank Failed"));
	}
}
// Called Every Frame
void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	auto EnemyTank = GetPlayerTank();
	auto MyTank = GetControlledTank();
	if (EnemyTank && MyTank)
	{
		//TODO Move towards the player

		//Aim at the player
		MyTank->AimAt(EnemyTank->GetActorLocation());
		//fire if ready
	}

}
ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}
ATank* ATankAIController::GetPlayerTank() const
{
	auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (!PlayerPawn) { return nullptr; }
	return Cast<ATank>(PlayerPawn);
}