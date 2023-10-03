// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Character/AuraCharacterBase.h"
#include "Interface/Interaction.h"

#include "EnemyCharacter.generated.h"

/**
 * 
 */
UCLASS()
class AURA_API AEnemyCharacter : public AAuraCharacterBase, public IInteraction
{
	GENERATED_BODY()

public:
	virtual void HighlightActor() override;
	virtual void UnHighlightActor() override;
};
