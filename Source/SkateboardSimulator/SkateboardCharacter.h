// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "InputActionValue.h"
#include "SkateboardCharacter.generated.h"

class ABaseSkateboard;

UCLASS()
class SKATEBOARDSIMULATOR_API ASkateboardCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	ASkateboardCharacter();

protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Enhanced Input")
    class UInputMappingContext* InputMapping;

    FTimerHandle TimerHandle;

public:	
	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION(BlueprintPure)
	float GetPoints() const;

	UFUNCTION(BlueprintPure)
	bool ImpulsePressed() const;

	void AddPoints(int PointsToAdd);

private:

	UPROPERTY(EditAnywhere, Category = "Enhanced Input")
	class UInputAction* ImpulseInputAction;

	UPROPERTY(EditAnywhere, Category = "Enhanced Input")
	class UInputAction* BalanceInputAction;

	UPROPERTY(EditAnywhere, Category = "Enhanced Input")
	class UInputAction* JumpInputAction;

	UPROPERTY(VisibleAnywhere, Category = "Components")
	UStaticMeshComponent* SkateboardMesh;

	UPROPERTY(EditAnywhere, Category = "Movement")
	float ImpulseForce = 1000.f; //Impulse force

	UPROPERTY(EditAnywhere, Category = "Movement")
	float ReduceVelocityFactor = 0.9f; //Reduces velocity by 10%

	UPROPERTY(EditAnywhere, Category = "Movement")
	float TurnRate = 45.f;

	UPROPERTY(VisibleAnywhere, Category = "Camera")
	class USpringArmComponent* SpringArm;

	UPROPERTY(VisibleAnywhere, Category = "Camera")
	class UCameraComponent* Camera;

	UPROPERTY(VisibleAnywhere, Category = "Points")
    float Points;

	bool bImpulsePressed;

	void Impulse(const FInputActionValue& Value);
	void Balance(const FInputActionValue& Value);
	void JumpUp(const FInputActionValue& Value);

	void ImpulseAnim(const FInputActionValue& Value);
	void JumpAnim(const FInputActionValue& Value);
};
