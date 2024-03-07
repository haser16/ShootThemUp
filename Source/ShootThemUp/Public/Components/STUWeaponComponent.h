// ShootThemUp. All Rights Reserved.

#pragma once

#include "Components/ActorComponent.h"
#include "CoreMinimal.h"
#include "STUWeaponComponent.generated.h"

class ASTUBaseWeapon;

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class SHOOTTHEMUP_API USTUWeaponComponent : public UActorComponent
{
    GENERATED_BODY()

  public:
    USTUWeaponComponent();

    void StartFire();
    void StopFire();
    void NextWeapon();

  protected:

    UPROPERTY(EditDefaultsOnly, Category = "Weapon")
    TArray<TSubclassOf<ASTUBaseWeapon>> WeaponClasses;

    UPROPERTY(EditDefaultsOnly, Category = "Weapon")
    FName WeaponEquipSocketName = "WeaponSocket";

    UPROPERTY(EditDefaultsOnly, Category = "Weapon")
    FName WeaponArmorySocketName = "ArmorySocket";

    virtual void BeginPlay() override;

    private:
      UPROPERTY()
      ASTUBaseWeapon *CurrentWeapon = nullptr;

      UPROPERTY()
      TArray<ASTUBaseWeapon *> Weapons;

      int32 CurrentWeaponIndex = 0;

      void SpawnWeapons();
      void AttachWeaponToScoket(ASTUBaseWeapon *Weapon, USceneComponent *SceneComponent, const FName &SocketName);
      void EquipWeapon(int32 WeaponIndex);

};
