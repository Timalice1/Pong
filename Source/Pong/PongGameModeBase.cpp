#include "PongGameModeBase.h"
#include <Kismet/GameplayStatics.h>

void APongGameModeBase::BeginPlay()
{
	Super::BeginPlay();
	SpawnBall();
}

void APongGameModeBase::SpawnBall(){
	GetWorld()->SpawnActor<ABall>(BallClass, FVector(0, 0, 60), FRotator::ZeroRotator);
}

