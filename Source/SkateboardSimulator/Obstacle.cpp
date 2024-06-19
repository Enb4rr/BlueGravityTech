// Fill out your copyright notice in the Description page of Project Settings.


#include "Obstacle.h"
#include "Components/BoxComponent.h"
#include "SkateboardCharacter.h"

// Sets default values
AObstacle::AObstacle()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CollisionBoxComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("Collision Box"));
    RootComponent = CollisionBoxComponent;

	ObstacleMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Base Mesh"));
    ObstacleMesh -> SetupAttachment(CollisionBoxComponent);

	CollisionBoxComponent -> OnComponentBeginOverlap.AddDynamic(this, &AObstacle::OnOverlapBegin);
}

// Called when the game starts or when spawned
void AObstacle::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AObstacle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AObstacle::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
    ASkateboardCharacter* Character = Cast<ASkateboardCharacter>(OtherActor);
    if (Character)
    {
        Character-> AddPoints(PointsToAdd);
    }
}
