// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BaseSkateboard.generated.h"

UCLASS()
class SKATEBOARDSIMULATOR_API ABaseSkateboard : public AActor
{
	GENERATED_BODY()
	
public:	
	ABaseSkateboard();

	void Move();
	void Drift();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

private:

	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* BaseMesh;
};
