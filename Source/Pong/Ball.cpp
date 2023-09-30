#include "Ball.h"

ABall::ABall() : Super()
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

	Speed = 400.f;
}
void ABall::BeginPlay()
{
	Super::BeginPlay();
	if(HasAuthority()){
		GEngine->AddOnScreenDebugMessage(-1, 1, FColor::Green, "BeginPlay");
		float _x = FMath::RandBool() ? -1.f : 1.f;
		float _y = FMath::RandBool() ? -1.f : 1.f;

		Velocity = FVector(_x, _y, 0);
	}
}

void ABall::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if(HasAuthority())
		AddActorWorldOffset(Velocity * Speed * DeltaTime);
}


void ABall::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	if (HasAuthority()) {
		GEngine->AddOnScreenDebugMessage(-1, 1, FColor::Green, "Hit");
		Velocity = Cast<ABoard>(OtherActor) ?
			FVector(Velocity.X * -1.f, Velocity.Y, Velocity.Z) :
			FVector(Velocity.X, Velocity.Y * -1.f, Velocity.Z);
		Speed += 50;
	}
}
