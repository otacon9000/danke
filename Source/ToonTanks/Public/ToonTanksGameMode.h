// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "ToonTanksGameMode.generated.h"


class ATank;
class AToonTanksPlayerController;
/**
 * 
 */
UCLASS()
class TOONTANKS_API AToonTanksGameMode : public AGameModeBase
{
	GENERATED_BODY()
	
public:

	AToonTanksGameMode();


	void ActorDied(AActor* DeadActor);

	UFUNCTION(BlueprintImplementableEvent)
	void StartGame();

	
	UFUNCTION(BlueprintImplementableEvent)
	void GameOver(bool bWonGame);

protected:

	virtual void BeginPlay() override;

private:

	ATank* Tank;
	AToonTanksPlayerController* ToonTanksPlayerController; 

	float StartDelay; 

	void HandleGameStart();

	int32 TargetTurret;
	int32 GetTurretTargetCount();

};
