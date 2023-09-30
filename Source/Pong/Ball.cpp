#include "Ball.h"

ABall::ABall() : Super()
{
	PrimaryActorTick.bCanEverTick = true;

	SetReplicates(true);

	static ConstructorHelpers::FObjectFinder<UStaticMesh> _ballMesh(TEXT("/Script/Engine.StaticMesh'/Engine/BasicShapes/Sphere.Sphere'"));
	
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Ball");
	Mesh->SetStaticMesh(_ballMesh.Object);
	Mesh->SetIsReplicated(true);

	/*Mesh collision set up*/
	Mesh->SetNotifyRigidBodyCollision(true);
	Mesh->SetCollisionProfileName("BlockAllDynamic");
	Mesh->SetSimulatePhysics(true);
	Mesh->SetEnableGravity(false);

	Speed = 400.f;
}

void ABall::BeginPlay()
{
	Super::BeginPlay();

	/*Set initial movement direction*/
	if(HasAuthority()){
		float _x = FMath::RandBool() ? -1.f : 1.f;
		float _y = FMath::RandBool() ? -1.f : 1.f;
		Velocity = FVector(_x, _y, 0);
	}

	Mesh->OnComponentHit.AddDynamic(this, &ABall::OnHit);
}

void ABall::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	/*Move ball*/
	if(HasAuthority())
		AddActorWorldOffset(Velocity * Speed * DeltaTime);
}

void ABall::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	//Change ball direction on hit
	//Increase speed
	if (HasAuthority()) {
		Velocity = Cast<ABoard>(OtherActor) ?
			FVector(Velocity.X * -1.f, Velocity.Y, Velocity.Z) :
			FVector(Velocity.X, Velocity.Y * -1.f, Velocity.Z);

		Speed += 50;
	}
}
