// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PaperSprite.h"
#include "Engine/DataTable.h"
#include "WeaponStruct.generated.h"


USTRUCT(BlueprintType)
struct JUMPS_API FWeaponStruct : public FTableRowBase
{
	GENERATED_BODY()

		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Flower Struct")
		int stackCapacity;

	    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Flower Struct")
		int fireRate;

	    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Flower Struct")
		float damage;

		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Flower Struct")
		float bulletSpeed;

		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Flower Struct")
		UPaperSprite* weaopnSprite;

		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Flower Struct")
		UPaperSprite* bulletSprite;
};