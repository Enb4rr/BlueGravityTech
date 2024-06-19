// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseSkateboard.h"

// Sets default values
ABaseSkateboard::ABaseSkateboard()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	AttachPoint = CreateDefaultSubobject<USceneComponent>(TEXT("Attach Point"));
	RootComponent = AttachPoint;

	BaseMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Base Mesh"));
	BaseMesh -> SetupAttachment(AttachPoint);

	FrontMetallicMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Front Metallic Mesh"));
	FrontMetallicMesh -> SetupAttachment(BaseMesh);

	BackMetallicMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Back Metallic Mesh"));
	BackMetallicMesh -> SetupAttachment(BaseMesh);

	FrontLeftWheelMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Front Left Wheel Mesh"));
	FrontLeftWheelMesh -> SetupAttachment(FrontMetallicMesh);

	FrontRightWheelMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Front Right Wheel Mesh"));
	FrontRightWheelMesh -> SetupAttachment(FrontMetallicMesh);

	BackLeftWheelMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Back Left Wheel Mesh"));
	BackLeftWheelMesh -> SetupAttachment(BackMetallicMesh);

	BackRightWheelMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Back Right Wheel Mesh"));
	BackRightWheelMesh -> SetupAttachment(BackMetallicMesh);
}

// Called when the game starts or when spawned
void ABaseSkateboard::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABaseSkateboard::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABaseSkateboard::Move()
{

}

void ABaseSkateboard::Jump()
{
	
}

void ABaseSkateboard::AttachToPlayer()
{

}

