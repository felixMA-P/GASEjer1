
#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "GameFramework/Pawn.h"
#include "Pokemon.generated.h"

class UPokeAttack;

USTRUCT(BlueprintType)
struct FPokemonAttributes : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FGameplayTag PokemonTag;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FGameplayTagContainer PokemonTypes;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Health;
	
};

USTRUCT(BlueprintType)
struct FPokemonTypesRow : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FGameplayTag AttackerType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FGameplayTagContainer NotVeryEffectivePokemonTypes;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FGameplayTagContainer SupperEffectivePokemonTypes;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FGameplayTagContainer NullPokemonTypes;
	
};

UCLASS()
class GAS_EJERCICIO1_API APokemon : public APawn
{
	GENERATED_BODY()

public:
	APokemon();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void ApplyDamage(const int&  InDamage);

	FORCEINLINE FGameplayTagContainer& GetPokemonTypes() { return PokemonAttributes->PokemonTypes; }

private:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Attributes", Meta = (AllowPrivateAccess = "true"))
	TArray<TSubclassOf<UPokeAttack>>Attacks;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Attributes", Meta = (AllowPrivateAccess = "true"))
	FGameplayTag PokemonTag;
	
	FPokemonAttributes* PokemonAttributes;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Attributes", Meta = (AllowPrivateAccess = "true"))
	UDataTable* PokemonData;

	void InitializePoke();
};
