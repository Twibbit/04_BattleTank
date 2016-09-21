// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Tank.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
public:
	ATank* GetControlledTank() const;
	//Return an OUT parameter, True if hit landscape
	bool GetSightRayHitLocation(FVector &HitLocation) const;

	void Tick(float DeltaTime) override;

	void BeginPlay() override;


	//start the tank moving the barrel so that a shot would hit it where the crosshair intersects the world
	void AimTowardsCrossair();
	
	
	
};
