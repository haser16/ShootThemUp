// ShootThemUp. All Rights Reserved.

#pragma once

#include "Components/ActorComponent.h"
#include "CoreMinimal.h"
#include "STUWeaponComponent.generated.h"

class ASTUBaseWeapon;

USTRUCT(BlueprintType)
struct FWeaponData
{
    GENERATED_USTRUCT_BODY()

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Weapon")
    TSubclassOf<ASTUBaseWeapon> WeaponClass;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Weapon")
    UAnimMontage* ReloadAnimMontage;
};

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class SHOOTTHEMUP_API USTUWeaponComponent : public UActorComponent
{
    GENERATED_BODY()

  public:
    USTUWeaponComponent();

    void StartFire();
    void StopFire();
    void NextWeapon();
    void Reload();

  protected:
    UPROPERTY(EditDefaultsOnly, Category = "Weapon")
    TArray<FWeaponData> WeaponData;

    UPROPERTY(EditDefaultsOnly, Category = "Weapon")
    FName WeaponEquipSocketName = "WeaponSocket";

    UPROPERTY(EditDefaultsOnly, Category = "Weapon")
    FName WeaponArmorySocketName = "ArmorySocket";

    UPROPERTY(EditDefaultsOnly, Category = "Animation")
    UAnimMontage *EquiAnimMontage;

    virtual void BeginPlay() override;
    virtual void EndPlay(const EEndPlayReason::Type EEndPlayReason) override;

  private:
    UPROPERTY()
    ASTUBaseWeapon *CurrentWeapon = nullptr;

    UPROPERTY()
    TArray<ASTUBaseWeapon *> Weapons;

    UPROPERTY()
    UAnimMontage *CurrentReloadAnimMontage = nullptr;

    int32 CurrentWeaponIndex = 0;
    bool EquipAnimInProgress = false;

    void SpawnWeapons();
    void AttachWeaponToScoket(ASTUBaseWeapon *Weapon, USceneComponent *SceneComponent, const FName &SocketName);
    void EquipWeapon(int32 WeaponIndex);

    void PlayAnimMontage(UAnimMontage *Animation);
    void InitAnimations();
    void OnEquipFinished(USkeletalMeshComponent *MeshComponent);

    bool CanFire() const;
    bool CanEquip() const;
};
