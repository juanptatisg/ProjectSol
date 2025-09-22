#pragma once

#include "C:\Program Files\Epic Games\UE_5.5\Engine\Source\Runtime\Core\Public\CoreMinimal.h"
#include "C:\Program Files\Epic Games\UE_5.5\Engine\Source\Runtime\Core\Public\Modules\ModuleInterface.h"

//Loading screen module implementation
// Handles initialisation and display of loading screens during gameplay
class FLoadingScreenModule : public IModuleInterface
{
public:
	//Called when module is first loaded
	virtual void StartupModule() override;
	
	//Identifies this as a game module, not an editor module
	virtual bool IsGameModule() const override;

	//Shows the loading screen during level transitions
	virtual void StartLoadingScreen();

};