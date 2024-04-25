// ShootThemUp. All Rights Reserved.

#include "Components/STUAIPerceptionComponent.h"
#include "AIController.h"
#include "Components/STUHealthComponent.h"
#include "Perception/AISenseConfig_Sight.h"
#include "STUUtils.h"

AActor *USTUAIPerceptionComponent::GetClosestEnemy() const
{
    TArray<AActor *> PerceiveActors;
    GetCurrentlyPerceivedActors(UAISense_Sight::StaticClass(), PerceiveActors);

    if (PerceiveActors.Num() == 0)
        return nullptr;

    const auto Controller = Cast<AAIController>(GetOwner());
    if (!Controller)
        return nullptr;

    const auto Pawn = Controller->GetPawn();
    if (!Pawn)
        return nullptr;

    float BestDistance = MAX_FLT;
    AActor *BestPawn = nullptr;

    for (const auto PerceiveActor : PerceiveActors)
    {
        const auto HealthComponent = STUUtils::GetSTUPlayerComponent<USTUHealthComponent>(PerceiveActor);

        if (HealthComponent && !HealthComponent->IsDead()) // TODO: check if enemis or not
        {
            const auto CurrentDistance = (PerceiveActor->GetActorLocation() - Pawn->GetActorLocation()).Size();
            if (CurrentDistance < BestDistance)
            {
                BestDistance = CurrentDistance;
                BestPawn = PerceiveActor;
            }
        }
    }
    return BestPawn;
}
