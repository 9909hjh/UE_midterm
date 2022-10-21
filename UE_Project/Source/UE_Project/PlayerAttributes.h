// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "PlayerAttributes.generated.h"

/**
 * 
 */
UCLASS()
class UE_PROJECT_API UPlayerAttributes : public UAttributeSet
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadwrite, Category = "Abilities | stats")
		FGameplayAttributeData Speed;
	UPROPERTY(EditAnywhere, BlueprintReadwrite, Category = "Abilities | stats")
		FGameplayAttributeData Health;
	UPROPERTY(EditAnywhere, BlueprintReadwrite, Category = "Abilities | stats")
		FGameplayAttributeData DamageMod;

	//--------------------------------------------------------------------------

	UFUNCTION(Category = "Abilities | Function")
		FGameplayAttribute SpeedAttribute();
	UFUNCTION(Category = "Abilities | Function")
		FGameplayAttribute HealthAttribute();
	UFUNCTION(Category = "Abilities | Function")
		FGameplayAttribute DamageModAttribute();

};
