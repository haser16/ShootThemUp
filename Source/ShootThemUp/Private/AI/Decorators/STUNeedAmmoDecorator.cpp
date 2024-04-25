// ShootThemUp. All Rights Reserved.

#include "AI/Decorators/STUNeedAmmoDecorator.h"
#include "Weapon/STUBaseWeapon.h"
#include "STUUtils.h"
#include "Components/STUWeaponComponent.h"
#include "AIController.h"

USTUNeedAmmoDecorator::USTUNeedAmmoDecorator()
{
    NodeName = "NeedAmmo";
}

bool USTUNeedAmmoDecorator::CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const
{
    const auto Controller = OwnerComp.GetAIOwner();
    if (!Controller) return false;

    const auto WeaponComponent = STUUtils::GetSTUPlayerComponent<USTUWeaponComponent>(Controller->GetPawn());
    if (!WeaponComponent) return false;

    return WeaponComponent->NeedAmmo(WeaponType);
}


