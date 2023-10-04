// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseProjectile.h"
#include "Components/CapsuleComponent.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
ABaseProjectile::ABaseProjectile()
{
	ProjectileComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ProjectileComp"));
	RootComponent = ProjectileComp;

	PrimaryActorTick.bCanEverTick = false;


}

// Called when the game starts or when spawned
void ABaseProjectile::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABaseProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

