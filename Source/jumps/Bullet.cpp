// Fill out your copyright notice in the Description page of Project Settings.


#include "Bullet.h"
#include "PaperSpriteComponent.h"
#include "UnrealNetwork.h"
#include "Engine.h"
#include "Math.h"
#include "PaperSprite.h"



ABullet::ABullet() {

	PrimaryActorTick.bCanEverTick = true;

	spriteComponent = GetRenderComponent();
	spriteComponent->SetMobility(EComponentMobility::Stationary);
	spriteComponent->SetGenerateOverlapEvents(true);
	spriteComponent->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	spriteComponent->SetCollisionResponseToChannel(ECollisionChannel::ECC_Pawn, ECollisionResponse::ECR_Overlap);



	// Scale bullet size
	FVector scale = FVector(0.25, 0.25, 0.25);
	spriteComponent->SetWorldScale3D(scale);

	// Bullet network settings
	bReplicates = true;
	bReplicateMovement = false;
	bNetLoadOnClient = true;

	// BUllet movement component settings
	ProjectileMovementComponent = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileMovementComponent"));
	ProjectileMovementComponent->InitialSpeed = 0;
	ProjectileMovementComponent->MaxSpeed = 0;
	ProjectileMovementComponent->ProjectileGravityScale = 0;
	ProjectileMovementComponent->bRotationFollowsVelocity = false;
	ProjectileMovementComponent->bShouldBounce = false;
	ProjectileMovementComponent->bConstrainToPlane = true;

	FVector c = FVector(1, 0, 0);
	ProjectileMovementComponent->ConstrainLocationToPlane(c);



}


void ABullet::BeginPlay() {
	Super::BeginPlay();

	if (HasAuthority()) {
		GetRenderComponent()->SetMobility(EComponentMobility::Movable);
	}else {
		GetRenderComponent()->SetSprite(bulletSprite);
		GetRenderComponent()->SetMobility(EComponentMobility::Movable);
	}
}

void ABullet::Tick(float DeltaSeconds) {

	Super::Tick(DeltaSeconds);

	if (HasAuthority()) {
		bulletLocation = GetActorLocation();
	}else {
		FVector actualLocation = GetActorLocation();
		FVector iterpolatedLocation = FMath::VInterpTo(actualLocation, bulletLocation, DeltaSeconds, 10);
		SetActorLocation(iterpolatedLocation);
	}



}

void ABullet::GetLifetimeReplicatedProps(TArray< FLifetimeProperty > & OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(ABullet, bulletLocation);
	DOREPLIFETIME(ABullet, bulletSprite);
}

void ABullet::setBulletProps(float _bulletSpeed, float _damage) {

	GetRenderComponent()->SetSprite(bulletSprite);
	damage = _damage;
	bulletSpeed = _bulletSpeed;

	FVector velocity = FVector(bulletSpeed, 0, 0);
	ProjectileMovementComponent->Velocity = velocity;
}