#include "Gate.h"

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
}
