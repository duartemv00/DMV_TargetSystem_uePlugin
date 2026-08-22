// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class DMV_TargetSystemEditor : ModuleRules
{
	public DMV_TargetSystemEditor(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(
			new string[]
			{
				"Core",
			}
			);


		PrivateDependencyModuleNames.AddRange(
			new string[]
			{
				"CoreUObject",
				"Engine",
				"Slate",
				"SlateCore",
				"UnrealEd",
				"PropertyEditor",
				"DMV_TargetSystem",
			}
			);
	}
}
