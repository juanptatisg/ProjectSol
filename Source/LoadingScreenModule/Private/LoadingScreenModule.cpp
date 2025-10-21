#include "../Public/LoadingScreenModule.h"

void FLoadingScreenModule::StartupModule()
{
	//Log when module initialises
	UE_LOG(LogTemp, Warning, TEXT("FloadingScreenModule::StartupModule"));

}

bool FLoadingScreenModule::IsGameModule() const
{
	//Identifies this as a runtime module vs editor-only
	return true;
}

void FLoadingScreenModule::StartLoadingScreen()
{
	//Log when loading screen is requested
	UE_LOG(LogTemp, Warning, TEXT("FLoadingScreenModule::StartLoadingScreen"));

}

//Registers this module withg Unreal Engine's Module system
void IMPLEMENT_GAME_MODULE(FLoadingScreenModule, LoadingScreenModule);