#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "GameFramework/FloatingPawnMovement.h"
#include "Camera/CameraComponent.h"

#include "Board.generated.h"

UCLASS()
class PONG_API ABoard : public APawn
{
	GENERATED_BODY()

public:

	ABoard();
	
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	virtual void BeginPlay() override;

	UPROPERTY(VisibleDefaultsOnly)
	UStaticMeshComponent* Mesh;

	UPROPERTY(VisibleDefaultsOnly)
	UCameraComponent* Camera;

	UPROPERTY(VisibleDefaultsOnly)
	UFloatingPawnMovement* PawnMovement;

	void MoveRight(float AxisValue);

	UFUNCTION(BlueprintCallable, Server, Reliable)
	void SR_SetLocation(FVector NewLocation);
};

