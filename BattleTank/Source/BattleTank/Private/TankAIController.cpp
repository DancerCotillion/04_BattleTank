// Fill out your copyright notice in the Description page of Project Settings.

#include "Engine/World.h"
#include "TankAimingComponent.h"
#include "TankAIController.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
}

void ATankAIController::Tick(float DeltaTime) {

	Super::Tick(DeltaTime);

	auto ControlledTank = GetPawn();
	auto PlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn();

	if (!ensure(PlayerTank) && ControlledTank) { return; }

	MoveToActor(PlayerTank, AcceptanceRadius);

	auto AimingComponent = ControlledTank->FindComponentByClass<UTankAimingComponent>();
	AimingComponent->AimAt(PlayerTank->GetActorLocation());

	AimingComponent->Fire();
}
	
	/*if (GetPlayerTank()) {
		GetControlledTank()->AimAt(GetPlayerTank()->GetActorLocation());
	}*/


/*ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());

}
ATank* ATankAIController::GetPlayerTank() const
{
	auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (!PlayerPawn) { return nullptr; }
	else {
		return Cast<ATank>(PlayerPawn);
	}
}*/
