#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/BoxComponent.h"

#include "Gate.generated.h"

UCLASS()
class PONG_API AGate : public AActor
{
	GENERATED_BODY()
	
public:	
	AGate();

protected:
	virtual void BeginPlay() override;

	UPROPERTY(VisibleDefaultsOnly)
	UBoxComponent* BoxComponent;

	UFUNCTION()
	void OverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
};
