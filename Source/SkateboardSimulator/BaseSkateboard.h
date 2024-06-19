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
	void Jump();
	void AttachToPlayer();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

private:

	UPROPERTY(VisibleAnywhere, Category = "Components")
	USceneComponent* AttachPoint;

	UPROPERTY(VisibleAnywhere, Category = "Components")
	UStaticMeshComponent* BaseMesh;

	UPROPERTY(VisibleAnywhere, Category = "Components")
	UStaticMeshComponent* FrontMetallicMesh;

	UPROPERTY(VisibleAnywhere, Category = "Components")
	UStaticMeshComponent* BackMetallicMesh;

	UPROPERTY(VisibleAnywhere, Category = "Components")
	UStaticMeshComponent* FrontLeftWheelMesh;

	UPROPERTY(VisibleAnywhere, Category = "Components")
	UStaticMeshComponent* FrontRightWheelMesh;

	UPROPERTY(VisibleAnywhere, Category = "Components")
	UStaticMeshComponent* BackLeftWheelMesh;

	UPROPERTY(VisibleAnywhere, Category = "Components")
	UStaticMeshComponent* BackRightWheelMesh;
};
