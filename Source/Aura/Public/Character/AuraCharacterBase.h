// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemInterface.h"
#include "GameFramework/Character.h"
#include "OptimizationComponent.h"
#include "Interface/CombatInterface.h"
#include "AuraCharacterBase.generated.h"


class UGameplayEffect;
class USkeletalMeshComponent;
class UOptimizationProxyComponent;
class UAbilitySystemComponent;
class UAttributeSet;
UCLASS(Abstract)
class AURA_API AAuraCharacterBase : public ACharacter, public IAbilitySystemInterface, public ICombatInterface
{
	GENERATED_BODY()

public:
	AAuraCharacterBase();
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;
	UAttributeSet* GetAttributeSet() const {return AttributeSet;}
protected:
	virtual  void BeginPlay() override;
	
	UPROPERTY(EditAnywhere, Category="Combat")
	TObjectPtr<USkeletalMeshComponent> Weapon;
	
	UPROPERTY()
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent;

	UPROPERTY()
	TObjectPtr<UAttributeSet> AttributeSet;
	
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Optimization, meta= (AllowPrivateAccess = "true"))
	TObjectPtr<UOptimizationProxyComponent> OptimizationComponent;

	virtual void HandleInitAbility();

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Attributes")
	TSubclassOf<UGameplayEffect> DefaultPrimaryAttributes;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Attributes")
	TSubclassOf<UGameplayEffect> DefaultSecondaryAttributes;
	
	void InitDefaultAttributes() const;

	void InitializeAttributes(TSubclassOf<UGameplayEffect> Attributes, float Level) const;
};
