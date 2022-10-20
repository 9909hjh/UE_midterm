// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class UE_Project : ModuleRules
{
	public UE_Project(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay" });
	}
}
