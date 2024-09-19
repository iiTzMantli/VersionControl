// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "PlayerCharacter.generated.h"

UCLASS()
class VERSIONCONTROL_API APlayerCharacter : public ACharacter
{
    GENERATED_BODY()

public:
    // Constructor
    APlayerCharacter();

protected:
    // Damage amount the player deals to the boss
    float DamageAmount;

    // This is called out to attack the boss
    void AttackBoss(AActor* TargetBoss);

public:
    // Called every frame
    virtual void Tick(float DeltaTime) override;

    // Input functions to trigger attack
    void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
    void OnAttack();
};
