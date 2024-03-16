// ShootThemUp. All Rights Reserved.

#include "Pickaps/STUAmmoPickup.h"
#include "Components/STUHealthComponent.h"
#include "Components/STUWeaponComponent.h"
#include "STUUtils.h"

DEFINE_LOG_CATEGORY_STATIC(LogAmmoPickups, All, All);

bool ASTUAmmoPickup::GivePickupTo(APawn *PlayerPawn)
{
    const auto HealthComponent = STUUtils::GetSTUPlayerComponent<USTUHealthComponent>(PlayerPawn);
    if (!HealthComponent || HealthComponent->IsDead())
        return false;

    const auto WeaponComponent = STUUtils::GetSTUPlayerComponent<USTUWeaponComponent>(PlayerPawn);
    if (!WeaponComponent)
        return false;

    return WeaponComponent->TryToAddAmmo(WeaponType, ClipsAmount);
}
