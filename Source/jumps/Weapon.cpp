// Fill out your copyright notice in the Description page of Project Settings.


#include "Weapon.h"
#include "Bullet.h"
#include "Engine/World.h"
#include "UnrealNetwork.h"
#include "Engine.h"
#include "PaperSpriteComponent.h"


AWeapon::AWeapon() {

	// Bullet network settings
	bReplicates = true;
	SetReplicates(true);
	bNetLoadOnClient = true;

	spriteComponent = GetRenderComponent();
	spriteComponent->SetIsReplicated(true);
	spriteComponent->SetMobility(EComponentMobility::Stationary);
	spriteComponent->SetGenerateOverlapEvents(true);
	spriteComponent->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	spriteComponent->SetCollisionResponseToChannel(ECollisionChannel::ECC_Pawn, ECollisionResponse::ECR_Overlap);
}

void AWeapon::BeginPlay() {

	Super::BeginPlay();

	if (Role == ROLE_SimulatedProxy) {
		GetRenderComponent()->SetSprite(weaponSprite);
	}
}

void AWeapon::GetLifetimeReplicatedProps(TArray< FLifetimeProperty > & OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AWeapon, weaponSprite);
}


void AWeapon::setWeaponProps(int _stackCapacity, int _fireRate, float _damage, float _bulletSpeed, UPaperSprite* _bulletSprite) {
	
	GetRenderComponent()->SetSprite(weaponSprite);
//	UE_LOG(LogTemp, Warning, TEXT("ssssssssssss %s"),*_weaponSprite->GetName());

	stackCapacity = _stackCapacity;
	fireRate = _fireRate;
	damage = _damage;
	bulletSpeed = _bulletSpeed;
	bulletSprite = _bulletSprite;
}

void AWeapon::shot(FTransform initialBulletTransform) {

	UWorld* World = GetWorld();

	ABullet* Bullet = World->SpawnActorDeferred<ABullet>(ABullet::StaticClass(), initialBulletTransform);
	Bullet->bulletSprite = bulletSprite;
	Bullet->setBulletProps(bulletSpeed, damage);
	Bullet->FinishSpawning(initialBulletTransform);
	
	
}