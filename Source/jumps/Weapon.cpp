// Fill out your copyright notice in the Description page of Project Settings.


#include "Weapon.h"
#include "Bullet.h"
#include "Engine/World.h"
#include "PaperSpriteComponent.h"


AWeapon::AWeapon() {

	// Bullet network settings
	bReplicates = true;
	bReplicateMovement = true;
	bNetLoadOnClient = true;



	spriteComponent = GetRenderComponent();
	spriteComponent->SetIsReplicated(true);
	spriteComponent->SetMobility(EComponentMobility::Stationary);
	spriteComponent->SetGenerateOverlapEvents(true);
	spriteComponent->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	spriteComponent->SetCollisionResponseToChannel(ECollisionChannel::ECC_Pawn, ECollisionResponse::ECR_Overlap);
}

void AWeapon::setWeaponProps(int _stackCapacity, int _fireRate, float _damage, float _bulletSpeed, UPaperSprite* _bulletSprite, UPaperSprite* _weaponSprite ) {

	spriteComponent = GetRenderComponent();
	spriteComponent->SetSprite(_weaponSprite);

	stackCapacity = _stackCapacity;
	fireRate = _fireRate;
	damage = _damage;
	bulletSpeed = _bulletSpeed;
	bulletSprite = _bulletSprite;
}

void AWeapon::shot(FTransform initialBulletTransform) {

	UWorld* World = GetWorld();

	ABullet* Bullet = World->SpawnActorDeferred<ABullet>(ABullet::StaticClass(), initialBulletTransform);
	Bullet->setBulletProps(bulletSpeed, damage, bulletSprite);
	Bullet->spriteComponent->SetMobility(EComponentMobility::Movable);
	Bullet->FinishSpawning(initialBulletTransform);

}