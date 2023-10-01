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
	
	int ConnectedPlayers;

public:
	void SpawnBall();
	void SpawnPlayer(APlayerController* Controller);

protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere)
	TSubclassOf<ABall> BallClass;

	UPROPERTY(EditAnywhere)
	TSubclassOf<ABoard> BoardClass;
};
