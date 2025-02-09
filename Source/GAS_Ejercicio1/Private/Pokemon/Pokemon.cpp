

#include "Pokemon/Pokemon.h"


APokemon::APokemon()
{
	PrimaryActorTick.bCanEverTick = true;
}

void APokemon::BeginPlay()
{
	Super::BeginPlay();
	InitializePoke();
}

void APokemon::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void APokemon::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

void APokemon::ApplyDamage(const int& InDamage)
{
	PokemonAttributes->Health -= InDamage;
}

void APokemon::InitializePoke()
{
	
	if (PokemonData)
	{
		TArray<FPokemonAttributes*> OutData;
		
		PokemonData->GetAllRows(TEXT(""), OutData);

		if (!OutData.IsEmpty())
		{
			FPokemonAttributes** Attr = OutData.FindByPredicate([this](FPokemonAttributes* Row)
			{
				return Row->PokemonTag.MatchesTag(PokemonTag);
			});

			if (Attr) PokemonAttributes = *Attr;
			
		}
		
	}
}

