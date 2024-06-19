// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Obstacle.generated.h"

UCLASS()
class SKATEBOARDSIMULATOR_API AObstacle : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AObstacle();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:

	UPROPERTY(EditAnywhere, Category = "Components")
	UStaticMeshComponent* ObstacleMesh;

	UPROPERTY(VisibleAnywhere, Category = "Components")
    class UBoxComponent* CollisionBoxComponent;

	UPROPERTY(EditAnywhere, Category = "Points")
	int PointsToAdd = 10;

	UFUNCTION()
    void OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor,
        					class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep,
                        		const FHitResult & SweepResult);

};
