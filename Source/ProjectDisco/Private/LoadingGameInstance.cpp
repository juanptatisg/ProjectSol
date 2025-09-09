// Fill out your copyright notice in the Description page of Project Settings.


#include "LoadingGameInstance.h"
#include <Runtime/MoviePlayer/Public/MoviePlayer.h>

void ULoadingGameInstance::Init()
{

	//Call parent class initialisation first
	Super::Init();

	//Bind BeginLoadingScreen function to the PreLoadMap delegate
	//This ensures our function is called right before a map begins loading
	FCoreUObjectDelegates::PreLoadMap.AddUObject(this, &ULoadingGameInstance::BeginLoadingScreen);

	//Bind EndLoadingScreen function to the PostLoadMapWithWorld delegate
	//This ensures our function is called after a map has finished loading]
	FCoreUObjectDelegates::PostLoadMapWithWorld.AddUObject(this, &ULoadingGameInstance::EndLoadingScreen);

}

//called before a map begins loading
void ULoadingGameInstance::BeginLoadingScreen(const FString& InMapName)
{
	UE_LOG(LogTemp, Warning, TEXT("ULoadingGameInstance::BeginLoadingScreen: %s"), *InMapName);


	//Create a struct to hold all our loading screen settings
	FLoadingScreenAttributes LoadingScreen;

	//Don't automatically remove the loading screen when loading completes
	//This gives us manual control over when top hide it
	LoadingScreen.bAutoCompleteWhenLoadingCompletes = false;

	//set minimum time the loading screen will be displayed (in seconds)
	//This prevents the "flash" lading screens for quick loads
	LoadingScreen.MinimumLoadingScreenDisplayTime = 2.0f;

	//create and assign a basic test widget for the loading screen
	//this is unreals built in test widget, useful for prototyping
	LoadingScreen.WidgetLoadingScreen = FLoadingScreenAttributes::NewTestLoadingScreenWidget();

	//Tell MoviePlayer to display our loading screen with these settings
	GetMoviePlayer()->SetupLoadingScreen(LoadingScreen);


}

//Called after a map has finished loading
void ULoadingGameInstance::EndLoadingScreen(UWorld* InLoadedWorld)
{
	UE_LOG(LogTemp, Warning, TEXT("ULoadingGameInstance::EndLoadingScreen: %s"), *InLoadedWorld->GetName());

}