// Copyright Epic Games, Inc. All Rights Reserved.

#include "UE_ProjectGameMode.h"
#include "UE_ProjectCharacter.h"
#include "UObject/ConstructorHelpers.h"

AUE_ProjectGameMode::AUE_ProjectGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
