// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "MyGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class VERSIONCONTROL_API AMyGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
	
public:
    // Constructor
    AMyGameModeBase();

protected:
    // Default pawn class for the player
    UPROPERTY(EditDefaultsOnly, Category = "Gameplay")
    TSubclassOf<class APlayerCharacter> DefaultPawnClass;

    // Game rules or initialization logic
    virtual void BeginPlay() override;
};
