// Copyright Epic Games, Inc. All Rights Reserved.

#include "TriggerboxOnObject.h"
#include "TriggerboxOnObjectStyle.h"
#include "TriggerboxOnObjectCommands.h"
#include "LevelEditor.h"
#include "Widgets/Docking/SDockTab.h"
#include "Widgets/Layout/SBox.h"
#include "Widgets/Text/STextBlock.h"
#include "ToolMenus.h"
#include "Components/BoxComponent.h"
#include "Engine/TriggerBox.h"

static const FName TriggerboxOnObjectTabName("TriggerboxOnObject");

#define LOCTEXT_NAMESPACE "FTriggerboxOnObjectModule"

void FTriggerboxOnObjectModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
	
	FTriggerboxOnObjectStyle::Initialize();
	FTriggerboxOnObjectStyle::ReloadTextures();

	FTriggerboxOnObjectCommands::Register();
	
	PluginCommands = MakeShareable(new FUICommandList);

	PluginCommands->MapAction(
		FTriggerboxOnObjectCommands::Get().OpenPluginWindow,
		FExecuteAction::CreateRaw(this, &FTriggerboxOnObjectModule::PluginButtonClicked),
		FCanExecuteAction());

	UToolMenus::RegisterStartupCallback(FSimpleMulticastDelegate::FDelegate::CreateRaw(this, &FTriggerboxOnObjectModule::RegisterMenus));
	
	FGlobalTabmanager::Get()->RegisterNomadTabSpawner(TriggerboxOnObjectTabName, FOnSpawnTab::CreateRaw(this, &FTriggerboxOnObjectModule::OnSpawnPluginTab))
		.SetDisplayName(LOCTEXT("FTriggerboxOnObjectTabTitle", "TriggerboxOnObject"))
		.SetMenuType(ETabSpawnerMenuType::Hidden);
}

void FTriggerboxOnObjectModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.

	UToolMenus::UnRegisterStartupCallback(this);

	UToolMenus::UnregisterOwner(this);

	FTriggerboxOnObjectStyle::Shutdown();

	FTriggerboxOnObjectCommands::Unregister();

	FGlobalTabmanager::Get()->UnregisterNomadTabSpawner(TriggerboxOnObjectTabName);
}

TSharedRef<SDockTab> FTriggerboxOnObjectModule::OnSpawnPluginTab(const FSpawnTabArgs& SpawnTabArgs)
{
	return SNew(SDockTab)
		.TabRole(ETabRole::NomadTab)
		[
		SAssignNew(AEditorClickedEvent::VerticalBox,SVerticalBox)	//EditorClickedEventからSlateを追加
				
		];
}


void FTriggerboxOnObjectModule::PluginButtonClicked()
{
	FGlobalTabmanager::Get()->TryInvokeTab(TriggerboxOnObjectTabName);
}

void FTriggerboxOnObjectModule::RegisterMenus()
{
	static const FName MainMenuName("MainFrame.MainMenu");
	UToolMenus* ToolMenus = UToolMenus::Get();
	if (ToolMenus->IsMenuRegistered(MainMenuName))
	{
		return;
	}
	UToolMenu* MenuBar = ToolMenus->ExtendMenu(MainMenuName);
	
	FToolMenuOwnerScoped OwnerScoped(this);

	{
		UToolMenu* Menu = UToolMenus::Get()->ExtendMenu("MainFrame.MainMenu.MyTool");
		{
			//メニューバーの中のセクションの名前
			FToolMenuSection& Section = Menu->AddSection("AddTrigger",LOCTEXT("AddTrigger","AddTrigger"));
			Section.AddMenuEntryWithCommandList(FTriggerboxOnObjectCommands::Get().OpenPluginWindow, PluginCommands);
		}
	}
	
	MenuBar->AddSubMenu(
		"MainMenu",
		NAME_None,
		"MyTool",									    	  //ポイントの名称
		LOCTEXT("MenuBarName", "MyTool"),					  //メニューバーの名前
		LOCTEXT("MyToolToolTip", "CreateMyPlugin")			  //メニューバーにカーソルを合わせた時のツールチップ
	);

}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FTriggerboxOnObjectModule, TriggerboxOnObject)