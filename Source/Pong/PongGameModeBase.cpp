#include "PongGameModeBase.h"
#include "Kismet/GameplayStatics.h"
#include <GameFramework/PlayerStart.h>

void APongGameModeBase::BeginPlay()
{
	Super::BeginPlay();
	ConnectedPlayers = 0;
}

/*Spawn and respawn ball*/
void APongGameModeBase::SpawnBall(){
	GetWorld()->SpawnActor<ABall>(BallClass, FVector(0, 0, 60), FRotator::ZeroRotator);
}

void APongGameModeBase::SpawnPlayer(APlayerController* Controller)
{
	//Spawn player at empty player start
	TArray<AActor*> _outActors;

	UGameplayStatics::GetAllActorsOfClass(GetWorld(), APlayerStart::StaticClass(), _outActors);
	ABoard* _player = GetWorld()->SpawnActor<ABoard>(BoardClass, _outActors[ConnectedPlayers]->GetActorTransform());

	//Possess controller in spawned player
	Controller->Possess(_player);

	ConnectedPlayers++;
	if (ConnectedPlayers == 2) {
		GEngine->AddOnScreenDebugMessage(-1, 1, FColor::Green, "StartGame");
		SpawnBall();
	}
	else
		GEngine->AddOnScreenDebugMessage(-1, 1, FColor::Red, "Waiting for second player");
} 