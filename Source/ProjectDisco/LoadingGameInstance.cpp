// Fill out your copyright notice in the Description page of Project Settings.


#include "LoadingGameInstance.h"
#include <Runtime/MoviePlayer/Public/MoviePlayer.h>



void ULoadingGameInstance::Init()
{
	//call parent class initialisation first
	Super::Init();
	
	//bind BeginLoadingScreen to the PreLoadMap Delegate
	FCoreUObjectDelegates::PreLoadMap.AddUObject(this, &ULoadingGameInstance::BeginLoadingScreen);

	//Bind EndLoadingScreen to the PostLoadMapWithWorld Delegate
	FCoreUObjectDelegates::PostLoadMapWithWorld.AddUObject(this, &ULoadingGameInstance::EndLoadingScreen);

}

void ULoadingGameInstance::BeginLoadingScreen(const FString& InMapName)
{
	UE_LOG(LogTemp, Warning, TEXT("ULoadingGameInstance::BeginLoadingScreen: %s"), *InMapName);

	//Create a struct to hold all loading screen settings
	FLoadingScreenAttributes LoadingScreen;

	//Don't end loading screen immediately upon completion of loading
	LoadingScreen.bAutoCompleteWhenLoadingCompletes = false;

	//Set minimum time for loading
	LoadingScreen.MinimumLoadingScreenDisplayTime = 2.0f;


	//Create and assign a basic test widget for the loading screen
	//LoadingScreen.WidgetLoadingScreen = FLoadingScreenAttributes::NewTestLoadingScreenWidget();


	
	
	//Prevent users from skipping the loading screen movie
	LoadingScreen.bMoviesAreSkippable = false;
	
	//Add a path to the mopve that will play during loading
	//Should be located within Content/Movies directory
	LoadingScreen.MoviePaths.Add(TEXT("LoadingScreenMovie"));

	


	//Tell the MoviePlayer to display our loading screen with these settings
	GetMoviePlayer()->SetupLoadingScreen(LoadingScreen);

	
	
	//Start playing the movie
	GetMoviePlayer()->PlayMovie();
	
	
}

void ULoadingGameInstance::EndLoadingScreen(UWorld* InLoadedWorld)
{
	UE_LOG(LogTemp, Warning, TEXT("ULoadingGameInstance::EndLoadingScreen: %s"), *InLoadedWorld->GetName());

	

}