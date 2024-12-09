// Copyright Epic Games, Inc. All Rights Reserved.

#include "CppTestGameMode.h"
#include "CppTestCharacter.h"
#include "UObject/ConstructorHelpers.h"

ACppTestGameMode::ACppTestGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

}
