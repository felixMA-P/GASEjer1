

#include "Pokemon/PokeAttack.h"
#include "Pokemon/Pokemon.h"

void UPokeAttack::Attack(APokemon* Target)
{

	FGameplayTagContainer& TargetTypes = Target->GetPokemonTypes();

	int FinalDamage = BaseDamage;

	if (TableTypes)
	{

		TArray<FPokemonTypesRow*> OutData;

		FPokemonTypesRow* Row;

		TableTypes->GetAllRows(TEXT(""), OutData);

		if (!OutData.IsEmpty())
		{
			FPokemonTypesRow** Attr = OutData.FindByPredicate([this](FPokemonTypesRow* Row)
			{
				return Row->AttackerType.MatchesTag(AttackType);
			});

			if (Attr)
			{
				Row = *Attr;

				if (Row->SupperEffectivePokemonTypes.HasAll(TargetTypes)) FinalDamage = FinalDamage * 4;
				else if (Row->SupperEffectivePokemonTypes.HasAny(TargetTypes)) FinalDamage = FinalDamage * 2;
				
				if (Row->NotVeryEffectivePokemonTypes.HasAll(TargetTypes)) FinalDamage = FinalDamage * 0.25;
				else if (Row->NotVeryEffectivePokemonTypes.HasAny(TargetTypes)) FinalDamage = FinalDamage * 0.5;

				if (Row->NullPokemonTypes.HasAny(TargetTypes)) FinalDamage = FinalDamage * 0;
				
			}
		}
	}
	
	Target->ApplyDamage(FinalDamage);
	AttackEvent(Target, FinalDamage);
	NumberOfUses--;
}
