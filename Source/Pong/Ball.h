#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Board.h"

#include "Ball.generated.h"

UCLASS()
class PONG_API ABall : public AActor
{
	GENERATED_BODY()

	FVector Velocity;
	
	float Speed;
	
public:	
	ABall();

	virtual void Tick(float DeltaTime) override;

protected:
	virtual void BeginPlay() override;

	UPROPERTY(VisibleDefaultsOnly)
	UStaticMeshComponent* Mesh;

	UPROPERTY(EditDefaultsOnly)
	float InitialSpeed;

	UPROPERTY(EditDefaultsOnly)
	float Acceleration;

	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

};
