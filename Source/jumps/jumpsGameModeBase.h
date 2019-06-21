// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "jumpsGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class JUMPS_API AjumpsGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable)
	void spawnWeapon(FTransform spawnLocation, int stackCapacity, int fireRate, float damage, float bulletSpeed, UPaperSprite* bulletSprite, UPaperSprite* weaponSprite );
	
};
