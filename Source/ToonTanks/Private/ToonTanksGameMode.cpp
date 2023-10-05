// Fill out your copyright notice in the Description page of Project Settings.


#include "ToonTanksGameMode.h"
#include "Kismet/GameplayStatics.h"
#include "Tank.h"
#include "Turret.h"
#include "ToonTanksPlayerController.h"


AToonTanksGameMode::AToonTanksGameMode()
{
    StartDelay = 3.f;
    TargetTurret = 0;
}

void AToonTanksGameMode::BeginPlay()
{
	Super::BeginPlay(); 

    HandleGameStart();

}

void AToonTanksGameMode::HandleGameStart()
{
    TargetTurret = GetTurretTargetCount();
    Tank = Cast<ATank>(UGameplayStatics::GetPlayerPawn(this, 0));
    ToonTanksPlayerController = Cast<AToonTanksPlayerController>(UGameplayStatics::GetPlayerController(this, 0));

    StartGame();

    if(ToonTanksPlayerController)
    {
        ToonTanksPlayerController->SetPlayerEnabledState(false);

        FTimerHandle PlayerTimerHandle;
        FTimerDelegate PlayerEnableTimerDelegate = FTimerDelegate::CreateUObject(ToonTanksPlayerController, &AToonTanksPlayerController::SetPlayerEnabledState, true);

        GetWorldTimerManager().SetTimer(PlayerTimerHandle, PlayerEnableTimerDelegate, StartDelay, false);


    }
}



int32 AToonTanksGameMode::GetTurretTargetCount()
{
    TArray<AActor*> Turrets;
    UGameplayStatics::GetAllActorsOfClass(this, ATurret::StaticClass(), Turrets);
    return Turrets.Num();
}

void AToonTanksGameMode::ActorDied(AActor* DeadActor)
{
    if (DeadActor == Tank)
    {
        Tank->HandleDestruction();
        if (Tank->GetTankPlayerController())
        {
            ToonTanksPlayerController->SetPlayerEnabledState(false);
        }
        GameOver(false);
    }
    else if (ATurret* DestroyedTower = Cast<ATurret>(DeadActor))
    {
        DestroyedTower->HandleDestruction();
        --TargetTurret;

        if (TargetTurret == 0)
        {
            GameOver(true);
        }
    }

}

