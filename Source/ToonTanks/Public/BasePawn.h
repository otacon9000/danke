// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "BasePawn.generated.h"


class UCapsuleComponent;
class UStaticMeshComponent;
class USceneComponent;
class ABaseProjectile; 

UCLASS()
class TOONTANKS_API ABasePawn : public APawn
{
	GENERATED_BODY()

public:
	ABasePawn();

	void HandleDestruction(); 

protected:
	
	void RotateTurret(FVector LookAtTarget);

	void Fire();

private:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Componets", meta = (AllowPrivateAccess = "true"))
	UCapsuleComponent* CapsuleComp;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Componets", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* BaseMesh;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Componets", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* TurretMesh;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Componets", meta = (AllowPrivateAccess = "true"))
	USceneComponent* ProjectileSpawnPoint;

	UPROPERTY(EditDefaultsOnly, Category = "Combat")
	TSubclassOf<ABaseProjectile> ProjectileClass;


};
