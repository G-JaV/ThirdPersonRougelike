// Fill out your copyright notice in the Description page of Project Settings.


#include "TCharacter.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "..\Public\TCharacter.h"

// Sets default values
ATCharacter::ATCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MySpringArm = CreateDefaultSubobject<USpringArmComponent>("SpringArm");
	MySpringArm->SetupAttachment(RootComponent);

	MyCamera = CreateDefaultSubobject<UCameraComponent>("Camera");
	MyCamera->SetupAttachment(MySpringArm);

}

// Called when the game starts or when spawned
void ATCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

void ATCharacter::MoveForward(float Value)
{
	AddMovementInput(GetActorForwardVector(), Value);
}

// Called every frame
void ATCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ATCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveForward",this,&ATCharacter::MoveForward);
	PlayerInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
}

