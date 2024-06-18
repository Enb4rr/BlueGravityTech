// Fill out your copyright notice in the Description page of Project Settings.


#include "SkateboardCharacter.h"
#include "InputMappingContext.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInput/Public/EnhancedInputComponent.h"
#include "InputActionValue.h"

// Sets default values
ASkateboardCharacter::ASkateboardCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ASkateboardCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASkateboardCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ASkateboardCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	// Get the player controller
    APlayerController* PC = Cast<APlayerController>(GetController());
 
    // Get the local player subsystem
    UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PC->GetLocalPlayer());
    // Clear out existing mapping, and add our mapping
    Subsystem->ClearAllMappings();
    Subsystem->AddMappingContext(InputMapping, 0);

	// Get the EnhancedInputComponent
	UEnhancedInputComponent* PEI = Cast<UEnhancedInputComponent>(PlayerInputComponent);

	PEI -> BindAction(ImpulseInputAction, ETriggerEvent::Triggered, this, &ASkateboardCharacter::Impulse);
    PEI -> BindAction(BalanceInputAction, ETriggerEvent::Triggered, this, &ASkateboardCharacter::Balance);
	PEI -> BindAction(LookInputAction, ETriggerEvent::Triggered, this, &ASkateboardCharacter::Look);
	PEI -> BindAction(JumpInputAction, ETriggerEvent::Triggered, this, &ASkateboardCharacter::JumpUp);
}

void ASkateboardCharacter::Impulse(const FInputActionValue& Value)
{
    if (Controller != nullptr)
    {
        const FVector2D MoveValue = Value.Get<FVector2D>();
        const FRotator MovementRotation(0, Controller->GetControlRotation().Yaw, 0);
 
        // Forward/Backward direction
        if (MoveValue.Y != 0.f)
        {
            // Get forward vector
            const FVector Direction = MovementRotation.RotateVector(FVector::ForwardVector);
 
            AddMovementInput(Direction, MoveValue.Y);
        }
 
        // Right/Left direction
        if (MoveValue.X != 0.f)
        {
            // Get right vector
            const FVector Direction = MovementRotation.RotateVector(FVector::RightVector);
 
            AddMovementInput(Direction, MoveValue.X);
        }
    }
}

void ASkateboardCharacter::Balance(const FInputActionValue& Value)
{

}

void ASkateboardCharacter::Look(const FInputActionValue& Value)
{
    if (Controller != nullptr)
    {
        const FVector2D LookValue = Value.Get<FVector2D>();
 
        if (LookValue.X != 0.f)
        {
            AddControllerYawInput(LookValue.X * -1.f);
        }
 
        if (LookValue.Y != 0.f)
        {
            AddControllerPitchInput(LookValue.Y);
        }
    }
}

void ASkateboardCharacter::JumpUp(const FInputActionValue& Value)
{
	if(Controller != nullptr) Jump();
}

