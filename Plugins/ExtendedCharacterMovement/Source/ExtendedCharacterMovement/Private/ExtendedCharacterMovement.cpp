// Copyright Epic Games, Inc. All Rights Reserved.

#include "ExtendedCharacterMovement.h"
#include "ExtendedCharacterMovementStyle.h"
#include "ExtendedCharacterMovementCommands.h"
#include "Misc/MessageDialog.h"
#include "ToolMenus.h"

static const FName ExtendedCharacterMovementTabName("ExtendedCharacterMovement");

#define LOCTEXT_NAMESPACE "FExtendedCharacterMovementModule"

void FExtendedCharacterMovementModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
	
	FExtendedCharacterMovementStyle::Initialize();
	FExtendedCharacterMovementStyle::ReloadTextures();

	FExtendedCharacterMovementCommands::Register();
	
	PluginCommands = MakeShareable(new FUICommandList);

	PluginCommands->MapAction(
		FExtendedCharacterMovementCommands::Get().PluginAction,
		FExecuteAction::CreateRaw(this, &FExtendedCharacterMovementModule::PluginButtonClicked),
		FCanExecuteAction());

	UToolMenus::RegisterStartupCallback(FSimpleMulticastDelegate::FDelegate::CreateRaw(this, &FExtendedCharacterMovementModule::RegisterMenus));
}

void FExtendedCharacterMovementModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.

	UToolMenus::UnRegisterStartupCallback(this);

	UToolMenus::UnregisterOwner(this);

	FExtendedCharacterMovementStyle::Shutdown();

	FExtendedCharacterMovementCommands::Unregister();
}

void FExtendedCharacterMovementModule::PluginButtonClicked()
{
	// Put your "OnButtonClicked" stuff here
	FText DialogText = FText::Format(
							LOCTEXT("PluginButtonDialogText", "Add code to {0} in {1} to override this button's actions"),
							FText::FromString(TEXT("FExtendedCharacterMovementModule::PluginButtonClicked()")),
							FText::FromString(TEXT("ExtendedCharacterMovement.cpp"))
					   );
	FMessageDialog::Open(EAppMsgType::Ok, DialogText);
}

void FExtendedCharacterMovementModule::RegisterMenus()
{
	// Owner will be used for cleanup in call to UToolMenus::UnregisterOwner
	FToolMenuOwnerScoped OwnerScoped(this);

	{
		UToolMenu* Menu = UToolMenus::Get()->ExtendMenu("LevelEditor.MainMenu.Window");
		{
			FToolMenuSection& Section = Menu->FindOrAddSection("WindowLayout");
			Section.AddMenuEntryWithCommandList(FExtendedCharacterMovementCommands::Get().PluginAction, PluginCommands);
		}
	}

	{
		UToolMenu* ToolbarMenu = UToolMenus::Get()->ExtendMenu("LevelEditor.LevelEditorToolBar.PlayToolBar");
		{
			FToolMenuSection& Section = ToolbarMenu->FindOrAddSection("PluginTools");
			{
				FToolMenuEntry& Entry = Section.AddEntry(FToolMenuEntry::InitToolBarButton(FExtendedCharacterMovementCommands::Get().PluginAction));
				Entry.SetCommandList(PluginCommands);
			}
		}
	}
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FExtendedCharacterMovementModule, ExtendedCharacterMovement)