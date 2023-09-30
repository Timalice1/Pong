#include "Gate.h"
#include "PongGameModeBase.h"
#include <Kismet/GameplayStatics.h>

AGate::AGate()
{
	PrimaryActorTick.bCanEverTick = true;

	BoxComponent = CreateDefaultSubobject<UBoxComponent>("Gates");
	BoxComponent->SetCollisionProfileName("OverlapAllDynamics");
	RootComponent = BoxComponent;

}

void AGate::BeginPlay()
{
	Super::BeginPlay();
	BoxComponent->OnComponentBeginOverlap.AddDynamic(this, &AGate::OverlapBegin);
}

void AGate::OverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	GetWorld()->DestroyActor(OtherActor);
	APongGameModeBase* _gameMode = Cast<APongGameModeBase>(UGameplayStatics::GetGameMode(GetWorld()));
	_gameMode->SpawnBall();
}
