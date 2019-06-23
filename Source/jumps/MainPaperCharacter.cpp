// Fill out your copyright notice in the Description page of Project Settings.


#include "MainPaperCharacter.h"


void AMainPaperCharacter::changeActiveWeapon(AWeapon* weapon) {

	//AWeapon* copy = NewObject<AWeapon>();
	//copy->set
	activeWeapon = weapon;
}

AWeapon* AMainPaperCharacter::getActiveWeapon() {
	return activeWeapon;
}