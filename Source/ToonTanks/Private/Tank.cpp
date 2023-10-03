// Fill out your copyright notice in the Description page of Project Settings.


#include "Tank.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"

ATank::ATank()
{
	SpringArmComp = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArmComp"));
	SpringArmComp->SetupAttachment(RootComponent);

	CameraComp = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComp"));
	CameraComp->SetupAttachment(SpringArmComp);


}

//void ATank::Tick(float DeltaTime)
//{
//	Super::Tick(DeltaTime);
//	throw std::logic_error("The method or operation is not implemented.");
//}
//
//void ATank::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
//{
//	Super::SetupPlayerInputComponent(PlayerInputComponent);
//	throw std::logic_error("The method or operation is not implemented.");
//}
//
//void ATank::BeginPlay()
//{
//	Super::BeginPlay();
//	throw std::logic_error("The method or operation is not implemented.");
//}
