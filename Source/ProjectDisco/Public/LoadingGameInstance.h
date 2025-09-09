// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "LoadingGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTDISCO_API ULoadingGameInstance : public UGameInstance
{
	GENERATED_BODY()

public:

	//Override the Init function from UGameInstance
	//Called when the GameInstance is inititalized
	virtual void Init() override;

	//UFunction() required for binding to the PreLoadMap delegate
	//Called before a new map starts loading
	UFUNCTION()
	virtual void BeginLoadingScreen(const FString& MapName);

	//UFUNCTION() required for binding to the PostLoadMapWithWorld delegate
	//Called after a map has finished loading
	UFUNCTION()
	virtual void EndLoadingScreen(UWorld* InLoadedWorld);

};