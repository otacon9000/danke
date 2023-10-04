// Fill out your copyright notice in the Description page of Project Settings.


#include "AttributeComponent.h"

// Sets default values for this component's properties
UAttributeComponent::UAttributeComponent()
{
	PrimaryComponentTick.bCanEverTick = true;

	MaxHealth = 100.f;
	Health = MaxHealth;
}


// Called when the game starts
void UAttributeComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	GetOwner()->OnTakeAnyDamage.AddDynamic(this, &UAttributeComponent::DamageTaken);
}


// Called every frame
void UAttributeComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}


void UAttributeComponent::DamageTaken(AActor* DamegeActor, float Damage, const UDamageType* DamageType, AController* Instigator, AActor* DamageCauser)
{
	UE_LOG(LogTemp, Log, TEXT("Sono un component"));
}
