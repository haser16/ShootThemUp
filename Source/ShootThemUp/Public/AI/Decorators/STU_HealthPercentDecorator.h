// ShootThemUp. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTDecorator.h"
#include "STU_HealthPercentDecorator.generated.h"

UCLASS()
class SHOOTTHEMUP_API USTU_HealthPercentDecorator : public UBTDecorator
{
    GENERATED_BODY()

public:
    USTU_HealthPercentDecorator();

protected:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI")
    float HealthPercent = 0.6f;

    virtual bool CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const;
};
