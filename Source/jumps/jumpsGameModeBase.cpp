// Fill out your copyright notice in the Description page of Project Settings.

#include "jumpsGameModeBase.h"
#include "PaperSpriteActor.h"
#include "Weapon.h"
#include "Engine/World.h"
#include "PaperSpriteComponent.h"

void AjumpsGameModeBase::spawnWeapon(FTransform spawnLocation, int stackCapacity, int fireRate, float damage, float bulletSpeed, UPaperSprite* bulletSprite, UPaperSprite* weaponSprite) {

	UWorld* World = GetWorld();

	AWeapon* Weapon = World->SpawnActorDeferred<AWeapon>(AWeapon::StaticClass(), spawnLocation);
	Weapon->setWeaponProps(stackCapacity, fireRate, damage, bulletSpeed, bulletSprite, weaponSprite);
	Weapon->FinishSpawning(spawnLocation);

}