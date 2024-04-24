// ShootThemUp. All Rights Reserved.

#include "AI/Decorators/STU_HealthPercentDecorator.h"
#include "AIController.h"
#include "Components/STUHealthComponent.h"
#include "STUUtils.h"

USTU_HealthPercentDecorator::USTU_HealthPercentDecorator()
{
    NodeName = "HealthPercent";
}

bool USTU_HealthPercentDecorator::CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const
{
    const auto Controller = OwnerComp.GetAIOwner();

    if (!Controller) return false;

    const auto HealthComponent = STUUtils::GetSTUPlayerComponent<USTUHealthComponent>(Controller->GetPawn());
    if (!HealthComponent || HealthComponent->IsDead()) return false;

    return HealthComponent->GetHealthPercent() <= HealthPercent;
}
