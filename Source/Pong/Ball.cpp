#include "Ball.h"
#include "Board.h"

ABall::ABall()
{
	PrimaryActorTick.bCanEverTick = true;

	SetReplicates(true);

	static ConstructorHelpers::FObjectFinder<UStaticMesh> _ballMesh(TEXT("/Script/Engine.StaticMesh'/Engine/BasicShapes/Sphere.Sphere'"));
	
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Ball");
	Mesh->SetStaticMesh(_ballMesh.Object);
	Mesh->SetIsReplicated(true);

	Mesh->SetCollisionProfileName("BlockAllDynamic");
	Mesh->SetSimulatePhysics(true);
	Mesh->SetEnableGravity(false);


	Mesh->OnComponentHit.AddDynamic(this, &ABall::OnHit);

	Speed = 10.f;
}

void ABall::BeginPlay()
{
	Super::BeginPlay();

	float _x = FMath::RandBool() ? -1.f : 1.f;
	float _y = FMath::RandBool() ? -1.f : 1.f;

	Velocity = FVector(_x, _y, 0);
	
}

void ABall::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AddActorWorldOffset(Velocity * Speed);
}

void ABall::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	if (Cast<ABoard>(OtherActor))
		Velocity = FVector(Velocity.X * -1.f, Velocity.Y, Velocity.Z);
	else 
		Velocity = FVector(Velocity.X, Velocity.Y * -1.f, Velocity.Z);
	
	Speed++;
}
