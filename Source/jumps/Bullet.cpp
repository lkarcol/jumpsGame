// Fill out your copyright notice in the Description page of Project Settings.


#include "Bullet.h"
#include "PaperSpriteComponent.h"
#include "PaperSprite.h"



ABullet::ABullet() {

	spriteComponent = GetRenderComponent();
	spriteComponent->SetMobility(EComponentMobility::Stationary);
	spriteComponent->SetCollisionEnabled(ECollisionEnabled::NoCollision);

	// Scale bullet size
	FVector scale = FVector(0.25, 0.25, 0.25);
	spriteComponent->SetWorldScale3D(scale);

	// Bullet network settings
	bReplicates = true;
	bReplicateMovement = true;

	// BUllet movement component settings
	ProjectileMovementComponent = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileMovementComponent"));
	ProjectileMovementComponent->InitialSpeed = 0;
	ProjectileMovementComponent->MaxSpeed = 0;
	ProjectileMovementComponent->ProjectileGravityScale = 0;
	ProjectileMovementComponent->bRotationFollowsVelocity = true;
	ProjectileMovementComponent->bShouldBounce = true;
	ProjectileMovementComponent->Bounciness = 0.3f;


}

void ABullet::setBulletProps(float _bulletSpeed, float _damage, UPaperSprite* _bulletSprite) {

	spriteComponent = GetRenderComponent();
	spriteComponent->SetSprite(_bulletSprite);
	damage = _damage;

	FVector velocity = FVector(_bulletSpeed, 0, 0);
	ProjectileMovementComponent->Velocity = velocity;

}