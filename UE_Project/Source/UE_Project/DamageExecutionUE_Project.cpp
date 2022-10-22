// Fill out your copyright notice in the Description page of Project Settings.


#include "DamageExecutionUE_Project.h"

UDamageExecutionUE_Project::UDamageExecutionUE_Project(const FObjectInitializer& objectInalizer) : Super(objectInalizer)
{
	Attstruct Attributes;

	RelevantAttributesToCapture.Add(Attributes.HealthDef);
	InvalidScopedModifierAttributes.Add(Attributes.HealthDef);

	RelevantAttributesToCapture.Add(Attributes.DamageModDef);
}

void UDamageExecutionUE_Project::Execute_Implementation(const FGameplayEffectCustomExecutionParameters & ExecutionParams, OUT FGameplayEffectCustomExecutionOutput & OutExecutionOutput) const
{
	Attstruct Attributes;

	const FGameplayEffectSpec& Spec = ExecutionParams.GetOwningSpec();

	UAbilitySystemComponent* TargetASC = ExecutionParams.GetTargetAbilitySystemComponent();
	UAbilitySystemComponent* SourceASC = ExecutionParams.GetSourceAbilitySystemComponent();

	AActor* TargetActor = TargetASC ? TargetASC->AvatarActor : nullptr;
	AActor* SourceActor = SourceASC ? SourceASC->AvatarActor : nullptr;

	const FGameplayTagContainer* TargetTags = Spec.CapturedTargetTags.GetAggregatedTags();
	const FGameplayTagContainer* SourceTags = Spec.CapturedSourceTags.GetAggregatedTags();

	FAggregatorEvaluateParameters EvaluationParameters;
	EvaluationParameters.TargetTags = TargetTags;
	EvaluationParameters.SourceTags = SourceTags;

	float Health = 0.f;
	ExecutionParams.AttemptCalculateCapturedAttributeMagnitude(Attributes.HealthDef, EvaluationParameters, Health);

	float DamageMod = 0.f;
	ExecutionParams.AttemptCalculateCapturedAttributeMagnitude(Attributes.DamageModDef , EvaluationParameters, DamageMod);

	float DamageDone = 10 * DamageMod; // 10을 프로퍼티로 드러내서 할 수 있겠다.

	OutExecutionOutput.AddOutputModifier(FGameplayModifierEvaluatedData(Attributes.HealthProperty, EGameplayModOp::Additive, -DamageDone));

}