using UnrealBuildTool;


    //Critical: Module must have "PreLoadingScreen" Load timing in .uproject
    //Otherwise module won't initialise early enough to handle loading screens
    public class LoadingScreenModule : ModuleRules
{
        public LoadingScreenModule(ReadOnlyTargetRules Target) : base(Target)
        {
            //Specify the primary header file for precompiled headers
            PrivatePCHHeaderFile = "Public/LoadingScreenModule.h";
            
            //Use shared precompiled headers for better compile times
            PCHUsage = PCHUsageMode.UseSharedPCHs;

            PublicDependencyModuleNames.AddRange(
                new string[] {
                    "Core",
                    "Modules"
                }
            );


            //Add core unreal engine modules as private dependencies
            PrivateDependencyModuleNames.AddRange(
                new string[] {
                    "Core",         //Core UE functionality
                    "CoreUObject"   //Base UObject system
                   
                }
            );
        }
}