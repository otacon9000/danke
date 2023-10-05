// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BasePawn.h"
#include "Tank.generated.h"


class USpringArmComponent;
class UCameraComponent;

/**
 * 
 */
UCLASS()
class TOONTANKS_API ATank : public ABasePawn
{
	GENERATED_BODY()

public:
	ATank();

	void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	virtual void Tick(float DeltaTime) override; 

	void HandleDestruction();

	APlayerController* GetTankPlayerController() const; 

protected:

	virtual void BeginPlay() override; 
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	USpringArmComponent* SpringArmComp;
		
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UCameraComponent* CameraComp; 

	UPROPERTY(EditAnywhere, Category = "Movement")
	float MovementSpeed;

	UPROPERTY(EditAnywhere, Category="Movement")
	float TurnRate;

	APlayerController* PC; 

	void Move(float Value);

	void Turn(float Value); 

};
