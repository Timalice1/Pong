#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"

#include "PlayerControllerBase.generated.h"

UCLASS()
class PONG_API APlayerControllerBase : public APlayerController
{
	GENERATED_BODY()
	
protected:
	virtual void BeginPlay() override;

	UFUNCTION(Server, Reliable)
	void SR_SpawnPlayer();
};
