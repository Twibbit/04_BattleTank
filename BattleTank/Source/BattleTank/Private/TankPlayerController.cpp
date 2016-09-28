// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "Tank.h"
#include "Public/TankPlayerController.h"



//Get world location of linetrace through crosshair
bool ATankPlayerController::GetSightRayHitLocation(FVector & HitLocation) const
{
	//Find the crosshair position in pixel coordinates.
	int32 ViewPortSizeX, ViewPortSizeY;
	GetViewportSize(ViewPortSizeX, ViewPortSizeY);

	FVector2D ScreenLocation = FVector2D(ViewPortSizeX * CrossHairXLocation, ViewPortSizeY * CrossHairYLocation);
	//"De-Project" the screen position of the crosshair to a world position
	FVector LookDirection;
	
	if (GetLookDirection(ScreenLocation,LookDirection))
	{
		//Line-Trace along that look direction, and see what we hit (up to a max range)
		//
		return GetLookVectorHitLocation(LookDirection, HitLocation);

	} else
	{
		return false;
	}
}

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

	FVector HitLocation;//out parameter
	if (GetSightRayHitLocation(HitLocation)) 
	{
		
		GetControlledTank() -> AimAt(HitLocation);
		//if it hits the landscape
			//TODO Tell controlled tank to aim at this point
	}
	
	
}

bool ATankPlayerController::GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const
{
	FVector CameraWorldLocation;// to be discarded

	return DeprojectScreenPositionToWorld(ScreenLocation.X, ScreenLocation.Y, CameraWorldLocation, LookDirection);
}

bool ATankPlayerController::GetLookVectorHitLocation(FVector LookDirection, FVector & HitLocation) const
{
	FHitResult HitResult;
	FVector CameraLocation;
	FRotator CameraRotation;//throw away

	GetPlayerViewPoint(CameraLocation, CameraRotation);
	if(GetWorld()->LineTraceSingleByChannel(HitResult, CameraLocation, CameraLocation + LineTraceRange * LookDirection, ECC_Visibility)) 
	{
		HitLocation = HitResult.Location;
		UE_LOG(LogTemp, Warning, TEXT("Hit Object: %s"), *HitResult.GetActor()->GetName());
		return true;
	}
	else 
	{
		HitLocation = FVector(0);
		return false;
		
	}

	

}
