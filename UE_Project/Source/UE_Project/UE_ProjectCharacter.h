// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemInterface.h"
#include "AbilitySystemComponent.h"
#include "PlayerAttributes.h"
#include "GameFramework/Character.h"
#include "UE_ProjectCharacter.generated.h"

UCLASS(config=Game)
class AUE_ProjectCharacter : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* CameraBoom;


	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* FollowCamera;
public:
	AUE_ProjectCharacter();


	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Camera)
	float BaseTurnRate;


	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Camera)
	float BaseLookUpRate;

	//Ability System
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Abilities", meta = (AllowPrivateAccess = "ture"))
		class UAbilitySystemComponent* AbilitySystem;

	//UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Abilities")
		//UDataTable* AttrDataTable;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Abilities")
		UDataTable* AttrDataTable;

	UPROPERTY(EditAnywhere, BlueprintReadwrite, Category = "Abilities  | Debugging")
		bool bAttDebugging;

	UPROPERTY(EditAnywhere, BlueprintReadwrite, Category = "Abilities  | Debugging")
		TArray<TSubclassOf<class UGameplayAbility>> DebuggingPassiveAbility;

	UPROPERTY(EditAnywhere, BlueprintReadwrite, Category = "Abilities")
		TArray<TSubclassOf<class UGameplayAbility>> StartingPassiveAbility;

protected:

	void OnResetVR();

	//Ability System
	void BeginPlay() override;


	void MoveForward(float Value);

	void MoveRight(float Value);
	
	void TurnAtRate(float Rate);

	void LookUpAtRate(float Rate);

	void TouchStarted(ETouchIndex::Type FingerIndex, FVector Location);

	void TouchStopped(ETouchIndex::Type FingerIndex, FVector Location);

protected:
	// APawn interface
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	// End of APawn interface

	//Ability System
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override
	{
		return AbilitySystem;
	}

public:

	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }

	FORCEINLINE class UCameraComponent* GetFollowCamera() const { return FollowCamera; }
};

