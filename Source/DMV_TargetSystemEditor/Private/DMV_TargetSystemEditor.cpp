// Copyright Epic Games, Inc. All Rights Reserved.

#include "DMV_TargetSystemEditor.h"
#include "DMV_TargetFilterDataCustomization.h"
#include "Filters/DMV_TargetFilter_Data.h"
#include "PropertyEditorModule.h"

#define LOCTEXT_NAMESPACE "FDMV_TargetSystemEditorModule"

void FDMV_TargetSystemEditorModule::StartupModule()
{
	FPropertyEditorModule& PropertyModule = FModuleManager::LoadModuleChecked<FPropertyEditorModule>("PropertyEditor");
	PropertyModule.RegisterCustomClassLayout(
		UDMVTargetFilter_Data::StaticClass()->GetFName(),
		FOnGetDetailCustomizationInstance::CreateStatic(&FDMVTargetFilterDataCustomization::MakeInstance));
}

void FDMV_TargetSystemEditorModule::ShutdownModule()
{
	if (FModuleManager::Get().IsModuleLoaded("PropertyEditor"))
	{
		FPropertyEditorModule& PropertyModule = FModuleManager::GetModuleChecked<FPropertyEditorModule>("PropertyEditor");
		PropertyModule.UnregisterCustomClassLayout(UDMVTargetFilter_Data::StaticClass()->GetFName());
	}
}

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FDMV_TargetSystemEditorModule, DMV_TargetSystemEditor)
