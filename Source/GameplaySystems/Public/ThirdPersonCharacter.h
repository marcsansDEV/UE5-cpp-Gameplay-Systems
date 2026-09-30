// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BasicCharacter.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "ThirdPersonCharacter.generated.h"

/**
 * 
 */
UCLASS()
class GAMEPLAYSYSTEMS_API AThirdPersonCharacter : public ABasicCharacter
{
	GENERATED_BODY()

public:

	AThirdPersonCharacter();

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera")
	USpringArmComponent* CameraBoom;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera")
	UCameraComponent* FollowCamera;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Camera")
	float CameraDistance = 300.0f;

};
