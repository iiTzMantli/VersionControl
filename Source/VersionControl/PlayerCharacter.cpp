// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerCharacter.h"
#include "Boss.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/Engine.h"

APlayerCharacter::APlayerCharacter()
{
    PrimaryActorTick.bCanEverTick = true;

    // Initialize the damage the player can deal
    DamageAmount = 20.0f;
}

// Called every frame
void APlayerCharacter::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

// Set up player input
void APlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
    Super::SetupPlayerInputComponent(PlayerInputComponent);

    // Bind the attack function to the input key
    PlayerInputComponent->BindAction("Attack", IE_Pressed, this, &APlayerCharacter::OnAttack);
}

// Attack function
void APlayerCharacter::OnAttack()
{
    // Find the boss in the level (assuming the boss is of type ABossCharacter)
    ABoss* TargetBoss = Cast<ABoss>(UGameplayStatics::GetActorOfClass(GetWorld(), ABoss::StaticClass()));

    if (TargetBoss)
    {
        AttackBoss(TargetBoss); // Apply damage to the boss
    }
    else
    {
        if (GEngine)
        {
            GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("No boss found!"));
        }
    }
}

// Deal damage to the boss
void APlayerCharacter::AttackBoss(AActor* TargetBoss)
{
    if (TargetBoss)
    {
        UGameplayStatics::ApplyDamage(TargetBoss, DamageAmount, GetController(), this, UDamageType::StaticClass());

        // Debug message showing attack
        if (GEngine)
        {
            GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("Player attacked the boss!"));
        }
    }
}
