// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PaperSprite.h"
#include "PaperSpriteActor.h"
#include "Weapon.generated.h"

/**
 * 
 */
UCLASS()
class JUMPS_API AWeapon : public APaperSpriteActor
{
	GENERATED_BODY()

public:
	AWeapon();

protected:

	virtual void BeginPlay() override;

private:

	int stackCapacity;
	int stackState;
	int fireRate;
	float damage;
	float bulletSpeed;

	UPaperSprite* bulletSprite;


public:
		

	UPROPERTY(Replicated)
	UPaperSprite* weaponSprite;

	UPaperSpriteComponent* spriteComponent;

	UFUNCTION(BlueprintCallable)
	void shot(FTransform initialBulletTransform);

	UFUNCTION(BlueprintCallable)
	void setWeaponProps(int stackCapacity, int fireRate, float damage, float bulletSpeed, UPaperSprite* bulletSprite);

	
};
