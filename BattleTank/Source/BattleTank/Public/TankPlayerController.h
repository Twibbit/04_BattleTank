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
private:
	ATank* GetControlledTank() const;
	//Return an OUT parameter, True if hit landscape
	bool GetSightRayHitLocation(FVector &HitLocation) const;

	void Tick(float DeltaTime) override;

	void BeginPlay() override;

	//start the tank moving the barrel so that a shot would hit it where the crosshair intersects the world
	void AimTowardsCrossair();

	bool GetLookDirection(FVector2D ScreenLocation, FVector & LookDirection) const;
	bool GetLookVectorHitLocation(FVector LookDirection, FVector &HitLocation) const;
	

	
	UPROPERTY(EditAnywhere)
	float CrossHairXLocation = 0.5f; 
	UPROPERTY(EditAnywhere)
	float CrossHairYLocation = 0.3333f;
	UPROPERTY(EditAnywhere)
	float LineTraceRange = 1000000.0f;
	
		
};
