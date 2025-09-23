#pragma once
#include "Modules/ModuleInterface.h"

//Loading screen module implementation
// Handles initialisation and display of loading screens during gameplay
class FLoadingScreenModule : public IModuleInterface
{
public:
	//Called when module is first loaded
	virtual void StartupModule() override;
	
	//Identifies this as a game module, not an editor module
	virtual bool IsGameModule() const override;

	//Shows the loading svreen during level transitions
	virtual void StartLoadingScreen();

};