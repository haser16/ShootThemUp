// ShootThemUp. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Weapon/STUBaseWeapon.h"
#include "STURifleWeapon.generated.h"


UCLASS()
class SHOOTTHEMUP_API ASTURifleWeapon : public ASTUBaseWeapon
{
    GENERATED_BODY()

  public:
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
    float TimeBetweenShots = 0.1f;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
    float DamageAmount = 10.0f;

    virtual void StartFire() override;
    virtual void StopFire() override;

  protected:
    virtual void MakeShot();

  private:
    FTimerHandle ShotTimerHandle;

    void MakeDamage(const FHitResult &HitResult);
};
