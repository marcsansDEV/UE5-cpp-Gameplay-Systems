// Copyright Epic Games, Inc. All Rights Reserved.

#include "ExtendedCharacterMovementStyle.h"
#include "ExtendedCharacterMovement.h"
#include "Framework/Application/SlateApplication.h"
#include "Styling/SlateStyleRegistry.h"
#include "Slate/SlateGameResources.h"
#include "Interfaces/IPluginManager.h"
#include "Styling/SlateStyleMacros.h"

#define RootToContentDir Style->RootToContentDir

TSharedPtr<FSlateStyleSet> FExtendedCharacterMovementStyle::StyleInstance = nullptr;

void FExtendedCharacterMovementStyle::Initialize()
{
	if (!StyleInstance.IsValid())
	{
		StyleInstance = Create();
		FSlateStyleRegistry::RegisterSlateStyle(*StyleInstance);
	}
}

void FExtendedCharacterMovementStyle::Shutdown()
{
	FSlateStyleRegistry::UnRegisterSlateStyle(*StyleInstance);
	ensure(StyleInstance.IsUnique());
	StyleInstance.Reset();
}

FName FExtendedCharacterMovementStyle::GetStyleSetName()
{
	static FName StyleSetName(TEXT("ExtendedCharacterMovementStyle"));
	return StyleSetName;
}


const FVector2D Icon16x16(16.0f, 16.0f);
const FVector2D Icon20x20(20.0f, 20.0f);

TSharedRef< FSlateStyleSet > FExtendedCharacterMovementStyle::Create()
{
	TSharedRef< FSlateStyleSet > Style = MakeShareable(new FSlateStyleSet("ExtendedCharacterMovementStyle"));
	Style->SetContentRoot(IPluginManager::Get().FindPlugin("ExtendedCharacterMovement")->GetBaseDir() / TEXT("Resources"));

	Style->Set("ExtendedCharacterMovement.PluginAction", new IMAGE_BRUSH_SVG(TEXT("PlaceholderButtonIcon"), Icon20x20));
	return Style;
}

void FExtendedCharacterMovementStyle::ReloadTextures()
{
	if (FSlateApplication::IsInitialized())
	{
		FSlateApplication::Get().GetRenderer()->ReloadTextureResources();
	}
}

const ISlateStyle& FExtendedCharacterMovementStyle::Get()
{
	return *StyleInstance;
}
