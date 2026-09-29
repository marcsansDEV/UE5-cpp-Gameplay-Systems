// Copyright Epic Games, Inc. All Rights Reserved.

#include "ExtendedCharacterMovementCommands.h"

#define LOCTEXT_NAMESPACE "FExtendedCharacterMovementModule"

void FExtendedCharacterMovementCommands::RegisterCommands()
{
	UI_COMMAND(PluginAction, "ExtendedCharacterMovement", "Execute ExtendedCharacterMovement action", EUserInterfaceActionType::Button, FInputChord());
}

#undef LOCTEXT_NAMESPACE
