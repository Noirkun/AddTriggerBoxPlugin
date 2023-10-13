// Copyright Epic Games, Inc. All Rights Reserved.

#include "TriggerboxOnObjectCommands.h"

#define LOCTEXT_NAMESPACE "FTriggerboxOnObjectModule"

void FTriggerboxOnObjectCommands::RegisterCommands()
{
	UI_COMMAND(OpenPluginWindow, "TriggerboxOnObject", "Bring up TriggerboxOnObject window", EUserInterfaceActionType::Button, FInputChord());
}

#undef LOCTEXT_NAMESPACE
