// Copyright DuarteMV. All Rights Reserved.

#pragma once

#include "Modules/ModuleManager.h"

/**
 * Editor-only module for DMV_TargetSystem, for everything that only makes sense in editor builds.
 */
class FDMV_TargetSystemEditorModule : public IModuleInterface
{
public:

	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
};
