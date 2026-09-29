// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "Framework/Commands/Commands.h"
#include "ExtendedCharacterMovementStyle.h"

class FExtendedCharacterMovementCommands : public TCommands<FExtendedCharacterMovementCommands>
{
public:

	FExtendedCharacterMovementCommands()
		: TCommands<FExtendedCharacterMovementCommands>(TEXT("ExtendedCharacterMovement"), NSLOCTEXT("Contexts", "ExtendedCharacterMovement", "ExtendedCharacterMovement Plugin"), NAME_None, FExtendedCharacterMovementStyle::GetStyleSetName())
	{
	}

	// TCommands<> interface
	virtual void RegisterCommands() override;

public:
	TSharedPtr< FUICommandInfo > PluginAction;
};
