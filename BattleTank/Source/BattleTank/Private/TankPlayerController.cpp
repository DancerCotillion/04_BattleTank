// Fill out your copyright notice in the Description page of Project Settings.


#include "TankPlayerController.h"

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();

	ATank* ControlledTank = GetControlledTank();
	if (!ControlledTank) {
		UE_LOG(LogTemp, Warning, TEXT("No Controlled Tank"));
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("Controlled Tank: %s"), *ControlledTank->GetName());
	}
}

void ATankPlayerController::Tick(float DeltaTime) {

	Super::Tick(DeltaTime);
	AimTowardCrosshair();
}

ATank* ATankPlayerController::GetControlledTank() const
{
	//need to properly explain this code.
	return Cast<ATank>(GetPawn());	
}

void ATankPlayerController::AimTowardCrosshair() 
{
	if (!GetControlledTank()) { return; }

	//Get World Location if linetrace through crosshair
	//if hits something
		//aim towards point
}