// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BasePawn.h"
#include "Turret.generated.h"



class ATank;
/**
 * 
 */
UCLASS()
class TOONTANKS_API ATurret : public ABasePawn
{
	GENERATED_BODY()
	
public:
	ATurret();

	virtual void Tick(float DeltaTime) override;

	void HandleDestruction();

protected:


	UPROPERTY(EditDefaultsOnly, Category="Turret")
	int32 FireRange; 

	FTimerHandle FireRateTimerHandle;
	float FireRate; 

	void CheckFireCondition(); 

	bool InFireRange();


	virtual void BeginPlay() override;

private:

	class ATank* Tank; 

};
