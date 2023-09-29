#include "Board.h"

ABoard::ABoard()
{
	PrimaryActorTick.bCanEverTick = true;

	static ConstructorHelpers::FObjectFinder<UStaticMesh> _cubeMesh(TEXT("/Script/Engine.StaticMesh'/Engine/BasicShapes/Cube.Cube'"));

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Board");
	Mesh->SetStaticMesh(_cubeMesh.Object);
	Mesh->CastShadow = false;

	Camera = CreateDefaultSubobject<UCameraComponent>("Camera");
	Camera->AttachToComponent(Mesh, FAttachmentTransformRules::KeepRelativeTransform);

	PawnMovement = CreateDefaultSubobject<UFloatingPawnMovement>("Pawn movement component");
}

void ABoard::BeginPlay()
{
	Super::BeginPlay();
}


void ABoard::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAxis("MoveRight", this, &ABoard::MoveRight);
}

void ABoard::MoveRight(float AxisValue)
{
	AddMovementInput(GetActorRightVector() * AxisValue);
	ABoard::SR_SetLocation(GetActorLocation());
}

void ABoard::SR_SetLocation_Implementation(FVector NewLocation) {
	SetActorLocation(NewLocation);
}