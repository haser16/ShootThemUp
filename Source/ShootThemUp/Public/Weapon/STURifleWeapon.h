// ShootThemUp. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Weapon/STUBaseWeapon.h"
#include "STURifleWeapon.generated.h"

class USTUWeaponFXComponent;

UCLASS()
class SHOOTTHEMUP_API ASTURifleWeapon : public ASTUBaseWeapon
{
    GENERATED_BODY()

  public:
    ASTURifleWeapon();

    virtual void StartFire() override;
    virtual void StopFire() override;

  protected:
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
    float TimeBetweenShots = 0.1f;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
    float DamageAmount = 10.0f;

    UPROPERTY(VisibleAnywhere, Category = "VFX")
    USTUWeaponFXComponent *WeaponFXComponent;

    virtual void BeginPlay() override;
    virtual void MakeShot();

  private:
    FTimerHandle ShotTimerHandle;

    void MakeDamage(const FHitResult &HitResult);
};
