// Fill out your copyright notice in the Description page of Project Settings.


#include "Boss.h"
#include "Engine/Engine.h"



float ABoss::TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser)
{
	// Call the base class implementation
	Super::TakeDamage(DamageAmount, DamageEvent, EventInstigator, DamageCauser);

	// Reduce the boss's health
	Health -= DamageAmount;

	// Log damage and health status to the debug log
	if (GEngine)
	{
		FString HealthMessage = FString::Printf(TEXT("Boss takes %f damage! Current Health: %f"), DamageAmount, Health);
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Orange, HealthMessage);
	}

	// Check if the boss should transition to Phase 2
	if (Health <= 50.0f && !bIsPhaseTwo)
	{
		TransitionToPhaseTwo();

	}

	// Check if the boss is dead
	if (Health <= 0.0f)
	{
		// Log death
		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Boss has been defeated!"));
		}

		// Call death function or destroy the boss
		Destroy();
	}

	return DamageAmount;  // Return the amount of damage taken
}

// Sets default values
ABoss::ABoss()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Phase one boss states
	Health = 100.0f;
	AttackPower = 20.0f;
	Speed = 600.0f;
	bIsPhaseTwo = false; 
}

// Called when the game starts or when spawned
void ABoss::BeginPlay()
{
	Super::BeginPlay();

	//It will log the phase one stats
	LogBossStats();
	
}

// Logging the boss stats to debug console
void ABoss::LogBossStats()
{
	if (GEngine)
	{
		FString Stats = FString::Printf(TEXT("Health: %f, Attack Power: %f, Speed: %f"), Health, AttackPower, Speed);
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, Stats);
	}
}

void ABoss::TriggerPhaseTwo()
{
	if (!bIsPhaseTwo)
	{
		bIsPhaseTwo = true;
		TransitionToPhaseTwo();

		// Log message to say the function was called
		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("Phase Two Triggered!"));
		}
	}
}

void ABoss::TransitionToPhaseTwo()
{
	if (!bIsPhaseTwo)
	{
		bIsPhaseTwo = true;

		//double the size of my boss
		SetActorScale3D(FVector(2.0f));

		//double the stats for the boss
		AttackPower *= 2;
		Speed *= 2;

		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Boss has moved to Phase 2!"));
		}

		LogBossStats();
	}
}

//Perform stronger attack in Phase 2
void ABoss::PhaseTwoAttack()
{
	if (bIsPhaseTwo)
	{
		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, TEXT("Boss' next attack is a strong Phase 2 attack!"));
		}
	}
}

// Called every frame
void ABoss::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (bIsPhaseTwo)
	{
		PhaseTwoAttack(); //this will initiate phase two new attack which will be stronger than phase ones
	}
}

// Called to bind functionality to input
void ABoss::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

