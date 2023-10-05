// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseProjectile.h"
#include "Components/CapsuleComponent.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "GameFramework/Actor.h"
#include "AttributeComponent.h"
#include "GameFramework/DamageType.h"
#include "Kismet/GameplayStatics.h"
#include "Particles/ParticleSystemComponent.h"



// Sets default values
ABaseProjectile::ABaseProjectile()
{

	PrimaryActorTick.bCanEverTick = false;

	ProjectileComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ProjectileComp"));
	RootComponent = ProjectileComp;

	MoveComp = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("MoveComp"));
	MoveComp->InitialSpeed = 1000.f;
	MoveComp->MaxSpeed = 1000.f; 

	TrailParticlesComp = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("TrailComp"));
	TrailParticlesComp->SetupAttachment(RootComponent);


	Damage = 50.f;

}

// Called when the game starts or when spawned
void ABaseProjectile::BeginPlay()
{
	Super::BeginPlay();
	
	ProjectileComp->OnComponentHit.AddDynamic(this, &ABaseProjectile::OnHit); 

	if (ensure(LaunchSound))
	{
		UGameplayStatics::PlaySoundAtLocation(this, LaunchSound, GetActorLocation());

	}


}


// Called every frame
void ABaseProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABaseProjectile::OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{

	AActor* MyOwner = GetOwner();

	if (MyOwner == nullptr) 
	{	
		Destroy();
		return; 
	}

	AController* InstigatorController = MyOwner->GetInstigatorController();
	auto DamageTypeClass = UDamageType::StaticClass();

	if (OtherActor && OtherActor != this && OtherActor != MyOwner)
	{
		UGameplayStatics::ApplyDamage(OtherActor, Damage, InstigatorController, this, DamageTypeClass);

		if (HitParticles)
		{
			UGameplayStatics::SpawnEmitterAtLocation(this, HitParticles, GetActorLocation(), GetActorRotation());
		}
		
		if (ensure(HitSound))
		{
			UGameplayStatics::PlaySoundAtLocation(this, HitSound, GetActorLocation());

		}
		
		
	}

	Destroy();
}
