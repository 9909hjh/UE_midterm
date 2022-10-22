// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PlayerAttributes.h"
#include "AbilitySystemComponent.h"
#include "GameplayEffectExecutionCalculation.h"
#include "DamageExecutionUE_Project.generated.h"

/**
 *
 */
struct Attstruct
{
	DECLARE_ATTRIBUTE_CAPTUREDEF(Health);
	DECLARE_ATTRIBUTE_CAPTUREDEF(DamageMod);

	Attstruct()
	{
		DEFINE_ATTRIBUTE_CAPTUREDEF(UPlayerAttributes, Health, Target, false);
		DEFINE_ATTRIBUTE_CAPTUREDEF(UPlayerAttributes, DamageMod, Source, true);
	}
};

/**
 * 
 */
UCLASS()
class UE_PROJECT_API UDamageExecutionUE_Project : public UGameplayEffectExecutionCalculation
{
	GENERATED_UCLASS_BODY()

	virtual void Execute_Implementation(const FGameplayEffectCustomExecutionParameters& ExecutionParams, OUT FGameplayEffectCustomExecutionOutput& outExecutionOutput) const override;
};
