// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "Modules/ModuleManager.h"

/**
 * Editor-only module for DMV_TargetSystem. Registers detail customizations - see
 * FDMVTargetFilterBaseCustomization - that only make sense in editor builds, so they live in a
 * separate Editor-type module rather than the Runtime DMV_TargetSystem module (which must stay
 * loadable in cooked/packaged builds that never link PropertyEditor/UnrealEd/Slate).
 */
class FDMV_TargetSystemEditorModule : public IModuleInterface
{
public:

	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
};
