// ShootThemUp. All Rights Reserved.

#include "Weapon/STUBaseWeapon.h"
#include "Components/SkeletalMeshComponent.h"
#include "GameFramework/Character.h"
#include "GameFramework/Controller.h"

DEFINE_LOG_CATEGORY_STATIC(LogBaseWeapon, All, All)

ASTUBaseWeapon::ASTUBaseWeapon()
{

    PrimaryActorTick.bCanEverTick = false;

    WeaponMesh = CreateDefaultSubobject<USkeletalMeshComponent>("Weapon Mesh");
    SetRootComponent(WeaponMesh);
}

void ASTUBaseWeapon::BeginPlay()
{
    Super::BeginPlay();

    check(WeaponMesh);
}

void ASTUBaseWeapon::StartFire()
{

}

void ASTUBaseWeapon::StopFire()
{
    
}

void ASTUBaseWeapon::MakeShot()
{

}

APlayerController *ASTUBaseWeapon::GetPlayerController() const
{
    const auto Player = Cast<ACharacter>(GetOwner());
    if (!Player)
        return nullptr;

    return Player->GetController<APlayerController>();
}

void ASTUBaseWeapon::MakeDamage(const FHitResult &HitResult)
{
    const auto DamagedActor = HitResult.GetActor();

    if (!DamagedActor)
        return;

    DamagedActor->TakeDamage(DamageAmount, FDamageEvent(), GetPlayerController(), this);
}
