// Fill out your copyright notice in the Description page of Project Settings.


#include "SkateboardPlayerController.h"
#include "TimerManager.h"
#include "Blueprint/UserWidget.h"

void ASkateboardPlayerController::BeginPlay()
{
    Super::BeginPlay();

    HUD = CreateWidget(this, HUDClass);
    if(HUD != nullptr)
    {
        HUD -> AddToViewport();
    }
}

void ASkateboardPlayerController::GameHasEnded(class AActor* EndGameFocus, bool bIsWinner)
{
    Super::GameHasEnded(EndGameFocus, bIsWinner);
    HUD -> RemoveFromParent();

    UUserWidget* WinScreen = CreateWidget(this, WinScreenClass);
    if(WinScreen != nullptr)
    {
        WinScreen -> AddToViewport();
    }

    GetWorldTimerManager().SetTimer(RestartTimer, this, &APlayerController::RestartLevel, RestartDelay);
}

