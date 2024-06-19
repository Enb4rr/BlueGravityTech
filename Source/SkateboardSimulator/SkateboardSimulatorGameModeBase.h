// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "SkateboardSimulatorGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class SKATEBOARDSIMULATOR_API ASkateboardSimulatorGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
	
public:

	virtual void Scored();

};
