// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PaperSpriteActor.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "PaperSprite.h"
#include "Bullet.generated.h"

/**
 * 
 */
UCLASS()
class JUMPS_API ABullet : public APaperSpriteActor
{
	GENERATED_BODY()

public:

	ABullet();

protected:
	// Called when the game starts or when spawned
	//virtual void BeginPlay() override;
private:

	float damage;

public:
	// Called every frame
	//virtual void Tick(float DeltaSeconds) override;

	// Projectile movement component.
	UProjectileMovementComponent* ProjectileMovementComponent;
	UPaperSpriteComponent* spriteComponent;

	void setBulletProps(float bulletSpeed , float damage , UPaperSprite* bulletSprite);
	

};
