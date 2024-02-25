// ShootThemUp. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "STUBaseWeapon.generated.h"

class USceletalMeshComponent;

UCLASS()
class SHOOTTHEMUP_API ASTUBaseWeapon : public AActor
{
    GENERATED_BODY()

  public:
    ASTUBaseWeapon();

    virtual void StartFire();
    virtual void StopFire();

  protected:
    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
    USkeletalMeshComponent *WeaponMesh;

    UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
    FName MazzleSocketName = "MuzzleSocket";

    UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
    float TraceMaxDistance = 1500.0f;

    UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
    float DamageAmount = 10.0f;

    virtual void BeginPlay() override;

    void MakeShot();
    void MakeDamage(const FHitResult &HitResult);
    APlayerController *GetPlayerController() const;

    private:
    FTimerHandle ShotTimerHandle;
};
