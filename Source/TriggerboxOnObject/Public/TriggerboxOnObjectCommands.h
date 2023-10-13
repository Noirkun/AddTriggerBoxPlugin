// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Framework/Commands/Commands.h"
#include "TriggerboxOnObjectStyle.h"

class FTriggerboxOnObjectCommands : public TCommands<FTriggerboxOnObjectCommands>
{
public:

	FTriggerboxOnObjectCommands()
		: TCommands<FTriggerboxOnObjectCommands>(TEXT("TriggerboxOnObject"), NSLOCTEXT("Contexts", "TriggerboxOnObject", "TriggerboxOnObject Plugin"), NAME_None, FTriggerboxOnObjectStyle::GetStyleSetName())
	{
	}

	// TCommands<> interface
	virtual void RegisterCommands() override;

public:
	TSharedPtr< FUICommandInfo > OpenPluginWindow;
};