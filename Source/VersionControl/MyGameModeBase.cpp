// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameModeBase.h"
#include "PlayerCharacter.h"
#include "Boss.h"
#include "Kismet/GameplayStatics.h"

AMyGameModeBase::AMyGameModeBase()
{
    // Set the default pawn class to your custom player character
    static ConstructorHelpers::FClassFinder<APlayerCharacter> PlayerPawnClassFinder(TEXT("/Game/Blueprints/BP_PlayerCharacter")); // Change this path to your actual blueprint path
    DefaultPawnClass = PlayerPawnClassFinder.Class;

    // Set default game rules or any additional settings here
}

void AMyGameModeBase::BeginPlay()
{
    Super::BeginPlay();

    // Initialize the boss character or other game elements
    // For example, spawn the boss character if needed
    if (GetWorld())
    {
        FVector BossLocation(0.0f, 0.0f, 0.0f); // Set the desired spawn location
        FRotator BossRotation(0.0f, 0.0f, 0.0f); // Set the desired rotation
        AActor* BossActor = GetWorld()->SpawnActor<ABoss>(BossLocation, BossRotation);

        if (GEngine)
        {
            GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("Boss spawned in the level!"));
        }
    }
}
