// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class CppTest : ModuleRules
{
	public CppTest(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput" });
	}
}
