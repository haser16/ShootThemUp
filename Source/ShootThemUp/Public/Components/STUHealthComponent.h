// ShootThemUp. All Rights Reserved.

#pragma once

#include "Components/ActorComponent.h"
#include "CoreMinimal.h"
#include "STUHealthComponent.generated.h"

DECLARE_MULTICAST_DELEGATE(FOnDeath);
DECLARE_MULTICAST_DELEGATE_OneParam(FOnHealthChanged, float);

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class SHOOTTHEMUP_API USTUHealthComponent : public UActorComponent
{
    GENERATED_BODY()

  public:
    USTUHealthComponent();

    float GetHealth() const
    {
        return Health;
    }

    UFUNCTION(BlueprintCallable)
    bool IsDead() const
    {
        return Health <= 0.0f;
    }

    FOnDeath OnDeath;
    FOnHealthChanged OnHeathChanged;

  protected:
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Health", meta = (ClampMin = "0.0", ClampMax = "1000"))
    float MaxHealth = 100.0f;

    virtual void BeginPlay() override;

  private:
    float Health = 0.0f;

    UFUNCTION()
    void OnTakeAnyDamage(AActor *DamagedActor, float Damage, const class UDamageType *DamageType,
                         class AController *InstigatedBy, AActor *DamageCauser);
};
