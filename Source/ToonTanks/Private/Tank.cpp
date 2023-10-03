// Fill out your copyright notice in the Description page of Project Settings.


#include "Tank.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Components/InputComponent.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/PlayerController.h"
#include "DrawDebugHelpers.h"

ATank::ATank()
{
	SpringArmComp = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArmComp"));
	SpringArmComp->SetupAttachment(RootComponent);

	CameraComp = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComp"));
	CameraComp->SetupAttachment(SpringArmComp);

	MovementSpeed = 300.f;
	TurnRate = 5.f; 

}


void ATank::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis(TEXT("MoveForward"), this, &ATank::Move);
	PlayerInputComponent->BindAxis(TEXT("Turn"), this, &ATank::Turn);
	
}

void ATank::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime); 

	FHitResult HitResult;
	if(PC!=nullptr)
	{
		PC->GetHitResultUnderCursor(ECollisionChannel::ECC_Visibility, false, HitResult);
		FVector ImpactPointLocation = HitResult.ImpactPoint;

		DrawDebugSphere(GetWorld(), ImpactPointLocation, 20.f, 6, FColor::Red, false);
		RotateTurret(ImpactPointLocation);
	}
}

void ATank::BeginPlay()
{
	Super::BeginPlay(); 

	PC = Cast<APlayerController>(GetController()); 
}

void ATank::Move(float Value)
{
	FVector DeltaLocation = FVector::ZeroVector; 
	DeltaLocation.X = Value * UGameplayStatics::GetWorldDeltaSeconds(this) * MovementSpeed;

	AddActorLocalOffset(DeltaLocation, true);
}

void ATank::Turn(float Value)
{
	FRotator DeltaRotation = FRotator::ZeroRotator;

	DeltaRotation.Yaw = Value * TurnRate * UGameplayStatics::GetWorldDeltaSeconds(this);

	AddActorLocalRotation(DeltaRotation, true);

	
}

