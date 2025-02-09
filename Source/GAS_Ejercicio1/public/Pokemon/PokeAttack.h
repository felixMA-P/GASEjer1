
#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "UObject/Object.h"
#include "PokeAttack.generated.h"


class APokemon;

UCLASS(Blueprintable)
class GAS_EJERCICIO1_API UPokeAttack : public UObject
{
	GENERATED_BODY()

	friend APokemon;

public:

	UPROPERTY(EditAnywhere)
	FName Name;

	UPROPERTY(EditAnywhere)
	FGameplayTag AttackType;
	
	UPROPERTY(EditAnywhere)
	int BaseDamage;

	UPROPERTY(EditAnywhere)
	int NumberOfUses;

	UPROPERTY(EditAnywhere)
	int MaxNumberOfUses;
	
	virtual void Attack(APokemon* Target);

	UFUNCTION(BlueprintImplementableEvent)
	void AttackEvent(APokemon* Target,const float& Damage);

	UPROPERTY(EditAnywhere)
	UDataTable* TableTypes;
	
};
