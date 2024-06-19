// Fill out your copyright notice in the Description page of Project Settings.


#include "SkateboardCharacter.h"
#include "InputMappingContext.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInput/Public/EnhancedInputComponent.h"
#include "InputActionValue.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"

// Sets default values
ASkateboardCharacter::ASkateboardCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

    SkateboardMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Base Mesh"));
    SkateboardMesh -> SetupAttachment(RootComponent);

    // Set base turn rates for the camera
    BaseTurnRate = 45.f;
    BaseLookUpRate = 45.f;

    SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("Spring Arm"));
    SpringArm -> SetupAttachment(RootComponent);

    Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
    Camera -> SetupAttachment(SpringArm);

    if (SpringArm) SpringArm -> bUsePawnControlRotation = false;
    if (Camera) Camera -> bUsePawnControlRotation = false;

    CameraRotation = FRotator::ZeroRotator;
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
    PEI -> BindAction(TurnInputAction, ETriggerEvent::Triggered, this, &ASkateboardCharacter::Turn);
	PEI -> BindAction(JumpInputAction, ETriggerEvent::Triggered, this, &ASkateboardCharacter::JumpUp);
}

void ASkateboardCharacter::Impulse(const FInputActionValue& Value)
{
    if (Controller != nullptr)
    {
        const FVector2D MoveValue = Value.Get<FVector2D>();
        const FRotator MovementRotation(0, Controller->GetControlRotation().Yaw, 0);
 
        //Forward/Backward direction
        if (MoveValue.Y != 0.f)
        {
            const FVector Direction = MovementRotation.RotateVector(FVector::ForwardVector);
            AddMovementInput(Direction, MoveValue.Y);
        }
    }
}

void ASkateboardCharacter::Balance(const FInputActionValue& Value)
{
    if(Controller != nullptr)
    {
        const FVector2D MoveValue = Value.Get<FVector2D>();
        const FRotator MovementRotation(0, Controller->GetControlRotation().Yaw, 0);

        // Right/Left direction
        if (MoveValue.X != 0.f)
        {
            // Get right vector
            const FVector Direction = MovementRotation.RotateVector(FVector::RightVector);
 
            AddMovementInput(Direction, MoveValue.X);
        }
    }
}

void ASkateboardCharacter::Turn(const FInputActionValue& Value)
{
    if(Controller != nullptr)
    {
        const FVector2D LookValue = Value.Get<FVector2D>();

        if (LookValue.X != 0.f) CameraRotation.Yaw += LookValue.X * BaseTurnRate * GetWorld() -> GetDeltaSeconds();
        if (LookValue.Y != 0.f) CameraRotation.Pitch += LookValue.Y * BaseLookUpRate * GetWorld()->GetDeltaSeconds();

        SpringArm -> SetWorldRotation(CameraRotation);
    }
}

void ASkateboardCharacter::JumpUp(const FInputActionValue& Value)
{
	if(Controller != nullptr) Jump();
}

