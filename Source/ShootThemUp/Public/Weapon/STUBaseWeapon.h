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

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
    float TraceMaxDistance = 1500.0f;


    virtual void BeginPlay() override;

    void MakeShot();
    APlayerController *GetPlayerController() const;

    bool GetPlayerViewPoint(FVector &ViewLocation, FRotator &ViewRotation) const;
    FVector GetMuzzleWorldLocation() const;
    bool GetTraceData(FVector &TraceStart, FVector &TraceEnd) const;
    void MakeHit(FHitResult &HitResult, const FVector &TraceStart, const FVector &TraceEnd);

  private:
    FTimerHandle ShotTimerHandle;
};
