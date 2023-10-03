// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/PlayerCharacter.h"

#include "AbilitySystemComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Player/AuraPlayerState.h"

APlayerCharacter::APlayerCharacter()
{
	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate =FRotator(0.f, 400.f, 0.f);
	GetCharacterMovement()->bConstrainToPlane = true;
	GetCharacterMovement()->bSnapToPlaneAtStart = true;

	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll = false;
	bUseControllerRotationYaw =false;
}

void APlayerCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);
	//Server
	HandleInitAbility();
}

void APlayerCharacter::OnRep_PlayerState()
{
	Super::OnRep_PlayerState();
	//Client
	HandleInitAbility();
}

void APlayerCharacter::HandleInitAbility()
{
	//Init Ability actor for Client and Server
	AAuraPlayerState* PlayerState = GetPlayerState<AAuraPlayerState>();
	check(PlayerState)
	PlayerState->GetAbilitySystemComponent()->InitAbilityActorInfo(PlayerState, this);
	AbilitySystemComponent = PlayerState->GetAbilitySystemComponent();
	AttributeSet = PlayerState->GetAttributeSet();
}
