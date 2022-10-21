// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerAttributes.h"

FGameplayAttribute UPlayerAttributes::SpeedAttribute()
{
	static UProperty* Property = FindFieldChecked<UProperty>(UPlayerAttributes::StaticClass(), GET_MEMBER_NAME_CHECKED(UPlayerAttributes, Speed));
	return FGameplayAttribute(Property);
}

FGameplayAttribute UPlayerAttributes::HealthAttribute()
{
	static UProperty* Property = FindFieldChecked<UProperty>(UPlayerAttributes::StaticClass(), GET_MEMBER_NAME_CHECKED(UPlayerAttributes, Health));
	return FGameplayAttribute(Property);
}

FGameplayAttribute UPlayerAttributes::DamageModAttribute()
{
	static UProperty* Property = FindFieldChecked<UProperty>(UPlayerAttributes::StaticClass(), GET_MEMBER_NAME_CHECKED(UPlayerAttributes, DamageMod));
	return FGameplayAttribute(Property);
}
