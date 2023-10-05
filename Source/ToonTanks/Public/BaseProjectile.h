// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BaseProjectile.generated.h"


class UStaticMeshComponent; 
class UProjectileMovementComponent;
class UParticleSystem;
class UParticleSystemComponent;
class USoundBase; 

UCLASS()
class TOONTANKS_API ABaseProjectile : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABaseProjectile();

	virtual void Tick(float DeltaTime) override;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Combat")
	UStaticMeshComponent* ProjectileComp; 

	UPROPERTY(VisibleAnywhere, Category = "Combat")
	UProjectileMovementComponent* MoveComp;

private:
	UPROPERTY(EditAnywhere)
	float Damage; 

	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);
	
	UPROPERTY(EditAnywhere, Category = "Combat")
	UParticleSystem* HitParticles;

	UPROPERTY(VisibleAnywhere, Category = "Combat")
	UParticleSystemComponent* TrailParticlesComp;

	UPROPERTY(EditAnywhere, Category = "Combat")
	USoundBase* LaunchSound;
	UPROPERTY(EditAnywhere, Category = "Combat")
	USoundBase* HitSound;


};
