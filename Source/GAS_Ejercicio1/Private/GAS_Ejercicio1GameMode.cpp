// Copyright Epic Games, Inc. All Rights Reserved.

#include "GAS_Ejercicio1GameMode.h"
#include "GAS_Ejercicio1PlayerController.h"
#include "GAS_Ejercicio1Character.h"
#include "UObject/ConstructorHelpers.h"

AGAS_Ejercicio1GameMode::AGAS_Ejercicio1GameMode()
{
	// use our custom PlayerController class
	PlayerControllerClass = AGAS_Ejercicio1PlayerController::StaticClass();

	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/TopDown/Blueprints/BP_TopDownCharacter"));
	if (PlayerPawnBPClass.Class != nullptr)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}

	// set default controller to our Blueprinted controller
	static ConstructorHelpers::FClassFinder<APlayerController> PlayerControllerBPClass(TEXT("/Game/TopDown/Blueprints/BP_TopDownPlayerController"));
	if(PlayerControllerBPClass.Class != NULL)
	{
		PlayerControllerClass = PlayerControllerBPClass.Class;
	}
}