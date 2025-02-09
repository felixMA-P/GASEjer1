
#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "BaseAttack.generated.h"


class AUTHUB_GASCharacter;

UCLASS(Blueprintable)
class GAS_EJERCICIO1_API UBaseAttack : public UObject
{
	GENERATED_BODY()

	friend AUTHUB_GASCharacter;
	
	void Attack(AGAS_Ejercicio1Character* CharacterInstigator);
	
public:
	UFUNCTION(BlueprintImplementableEvent)
	void PerformAttack(AGAS_Ejercicio1Character* CharacterInstigator);
};
