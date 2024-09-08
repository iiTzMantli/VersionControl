// Fill out your copyright notice in the Description page of Project Settings.


#include "Boss.h"
#include "Engine/Engine.h"

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

void ABoss::TransitionToPhaseTwo()
{
	if (!bIsPhaseTwo)
	{
		bIsPhaseTwo = true;

		//double the size of my boss
		SetActorScale3D(GetActorScale3D() * 2);

		//double the stats for the boss
		Health *= 2;
		AttackPower *= 2;
		Speed *= 2;

		//New stats will be logged
		LogBossStats();

		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Boss has moved to Phase 2!"));
		}
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

	//when the bosses health drops below 50 initiate phase two
	if (Health <= 50.0f && !bIsPhaseTwo)
	{
		TransitionToPhaseTwo();
	}

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

