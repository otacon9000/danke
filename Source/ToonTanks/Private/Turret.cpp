// Fill out your copyright notice in the Description page of Project Settings.


#include "Turret.h"
#include "Kismet/GameplayStatics.h"
#include "Tank.h"

ATurret::ATurret()
{
	FireRange = 50; 
}

void ATurret::BeginPlay()
{
	Super::BeginPlay();

	Tank = Cast<ATank>(UGameplayStatics::GetPlayerPawn(this, 0)); 
}


void ATurret::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);


	if (Tank != nullptr)
	{
		float Distance = FVector::Dist(GetActorLocation(), Tank->GetActorLocation());

		if(Distance < FireRange)
		{
			RotateTurret(Tank->GetActorLocation());
		}
	}	
}

