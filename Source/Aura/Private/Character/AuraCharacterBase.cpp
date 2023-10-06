// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/AuraCharacterBase.h"
#include "AbilitySystemComponent.h"

// Sets default values
AAuraCharacterBase::AAuraCharacterBase()
{
 	
	PrimaryActorTick.bCanEverTick = false;
	OptimizationComponent = CreateDefaultSubobject<UOptimizationProxyComponent>(TEXT("OptimizationComponent"));
	
	
	Weapon = CreateDefaultSubobject<USkeletalMeshComponent>("Weapon");
	Weapon->SetupAttachment(GetMesh(), FName("WeaponHandSocket"));
	Weapon-> SetCollisionEnabled(ECollisionEnabled::NoCollision);
}

UAbilitySystemComponent* AAuraCharacterBase::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

void AAuraCharacterBase::BeginPlay()
{
	Super::BeginPlay();
}

void AAuraCharacterBase::HandleInitAbility()
{
}



void AAuraCharacterBase::InitDefaultAttributes() const
{
	InitializeAttributes(DefaultPrimaryAttributes, 1.f);
	InitializeAttributes(DefaultSecondaryAttributes, 1.f);
}

void AAuraCharacterBase::InitializeAttributes(const TSubclassOf<UGameplayEffect> Attributes, const float Level) const
{
	check(IsValid(GetAbilitySystemComponent()));
	check(Attributes);
	
	FGameplayEffectContextHandle ContextHandle= GetAbilitySystemComponent()->MakeEffectContext();
	ContextHandle.AddSourceObject(this);
	const FGameplayEffectSpecHandle SpecHandle =  GetAbilitySystemComponent()->MakeOutgoingSpec(Attributes, Level, ContextHandle);
	GetAbilitySystemComponent()->ApplyGameplayEffectSpecToTarget(*SpecHandle.Data.Get(), GetAbilitySystemComponent());
}



