// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PaperCharacter.h"
#include "Bullet.h"
#include "Weapon.h"
#include "MainPaperCharacter.generated.h"

/**
 * 
 */
UCLASS()
class JUMPS_API AMainPaperCharacter : public APaperCharacter
{
	GENERATED_BODY()

private:

	AWeapon* activeWeapon;

public:

	UFUNCTION(BlueprintCallable)
	void changeActiveWeapon(AWeapon* weapon);

	UFUNCTION(BlueprintCallable,BlueprintPure)
	AWeapon* getActiveWeapon();

};
