// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "GameFramework/Character.h"
#include "GAS_Ejercicio1Character.generated.h"


class UBaseAttack;

USTRUCT(BlueprintType)
struct FCharacterAttributes: public FTableRowBase
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere)
	FGameplayTag GameplayClassTag;
	
	UPROPERTY(EditAnywhere)
	float Health;
	
	UPROPERTY(EditAnywhere)
	float AttackStrength;
	
	UPROPERTY(EditAnywhere)
	float Speed;
	
	UPROPERTY(EditAnywhere)
	UAnimMontage* AttackAnimation;

	UPROPERTY(EditAnywhere)
	TSubclassOf<UBaseAttack> PrimaryAttack;
};

UCLASS(Blueprintable)
class AGAS_Ejercicio1Character : public ACharacter
{
	GENERATED_BODY()

public:
	AGAS_Ejercicio1Character();

	// Called every frame.
	virtual void Tick(float DeltaSeconds) override;

	/** Returns TopDownCameraComponent subobject **/
	FORCEINLINE class UCameraComponent* GetTopDownCameraComponent() const { return TopDownCameraComponent; }
	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }

private:
	/** Top down camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* TopDownCameraComponent;

	/** Camera boom positioning the camera above the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* CameraBoom;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="GameplayTags", Meta = (AllowPrivateAccess = "true"))
	FGameplayTag CharacterClassTag;

	FCharacterAttributes* CharacterAttributes;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Attributes", Meta = (AllowPrivateAccess = "true"))
	UDataTable* CharacterData;

	void InitializeCharacter();

protected:
	virtual void BeginPlay() override;
};

