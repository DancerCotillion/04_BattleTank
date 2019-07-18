// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h" //must be the last include

class UTankAimingComponent;

UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	void BeginPlay() override;
	void Tick(float DeltaTime) override;

protected:
	UFUNCTION(BlueprintImplementableEvent, Category = "Setup")
	void FoundAimingComponent(UTankAimingComponent* AimingCompRef);

private:
	void AimTowardCrosshair();
	//return OUT parameter, true if hit location.
	bool GetSightRayLocation(FVector& OutHitLocation) const;

	UPROPERTY(EditDefaultsOnly)
	float CrossHairXLocation = 0.5; 

	UPROPERTY(EditDefaultsOnly)
	float CrossHairYLocation = 0.3333;

	UPROPERTY(EditDefaultsOnly)
	float LineTraceEnd = 1000000;

	bool GetLookDirection(FVector2D ScreenLocation, FVector& WorldDirection) const;
	bool GetLookVectorHitLocation(FVector LookDirection, FVector& HitLocation) const;
};
