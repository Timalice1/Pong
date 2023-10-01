#include "PlayerControllerBase.h"
#include <Kismet/GameplayStatics.h>
#include "PongGameModeBase.h"

void APlayerControllerBase::BeginPlay()
{
	Super::BeginPlay();

	if (IsLocalController()) 
		SR_SpawnPlayer();

}

void APlayerControllerBase::SR_SpawnPlayer_Implementation() {
	APongGameModeBase* _gameMode = Cast<APongGameModeBase>(UGameplayStatics::GetGameMode(GetWorld()));
	_gameMode->SpawnPlayer(this);
}