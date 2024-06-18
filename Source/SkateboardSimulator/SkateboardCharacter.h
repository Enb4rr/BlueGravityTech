// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "InputActionValue.h"
#include "SkateboardCharacter.generated.h"

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

public:	
	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:

	UPROPERTY(EditAnywhere, Category = "Enhanced Input")
	class UInputAction* ImpulseInputAction;

	UPROPERTY(EditAnywhere, Category = "Enhanced Input")
	class UInputAction* BalanceInputAction;

	UPROPERTY(EditAnywhere, Category = "Enhanced Input")
	class UInputAction* LookInputAction;

	UPROPERTY(EditAnywhere, Category = "Enhanced Input")
	class UInputAction* JumpInputAction;

	void Impulse(const FInputActionValue& Value);
	void Balance(const FInputActionValue& Value);
	void Look(const FInputActionValue& Value);
	void JumpUp(const FInputActionValue& Value);
};
