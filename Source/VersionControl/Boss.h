// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Boss.generated.h"

UCLASS()
class VERSIONCONTROL_API ABoss : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ABoss();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	//Boss stats
	float Health;
	float AttackPower;
	float Speed;

	//boss phase control
	bool bIsPhaseTwo;

	//function to move to phase two
	void TransitionToPhaseTwo();

	//new added moves for phase two
	void PhaseTwoAttack();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	//Deal damage
	void PerformAttack();

	//Show debug log
	void LogBossStats();

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	virtual float TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser) override;

};
