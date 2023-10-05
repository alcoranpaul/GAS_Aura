// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Character/AuraCharacterBase.h"
#include "..\Interface\EnemyInterface.h"

#include "EnemyCharacter.generated.h"

/**
 * 
 */
UCLASS()
class AURA_API AEnemyCharacter : public AAuraCharacterBase, public IEnemyInterface
{
	GENERATED_BODY()

public:
	AEnemyCharacter();

	//~ Interface
	virtual void HighlightActor() override;
	virtual void UnHighlightActor() override;
	//
protected:
	virtual void BeginPlay() override;
	virtual void HandleInitAbility() override;
	
};
