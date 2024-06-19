// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseSkateboard.h"

// Sets default values
ABaseSkateboard::ABaseSkateboard()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	BaseMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Base Mesh"));
	BaseMesh -> SetupAttachment(RootComponent);
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
	UE_LOG(LogTemp, Display, TEXT("Moving"));
}

void ABaseSkateboard::Drift()
{
	UE_LOG(LogTemp, Display, TEXT("Drifting"));
}

