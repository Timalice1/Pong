// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Ball.h"

#include "PongGameModeBase.generated.h"

UCLASS()
class PONG_API APongGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
	
public:
	void SpawnBall();

protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere)
	TSubclassOf<ABall> BallClass;

};
