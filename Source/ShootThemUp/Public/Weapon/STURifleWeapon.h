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

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	float TimeBetweenShots = 0.1f;


    virtual void StartFire() override;
	virtual void StopFire() override;

protected:
    virtual void MakeShot();
	

private:
    FTimerHandle ShotTimerHandle;
};
