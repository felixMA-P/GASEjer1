// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class GAS_Ejercicio1 : ModuleRules
{
	public GAS_Ejercicio1(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "NavigationSystem", "AIModule", "Niagara", "EnhancedInput" });
        
        PrivateDependencyModuleNames.AddRange(new string[]{"GameplayAbilities", "GameplayTasks", "GameplayTags"});
    }
}
