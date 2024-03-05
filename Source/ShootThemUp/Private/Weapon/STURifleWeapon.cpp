// ShootThemUp. All Rights Reserved.

#include "Weapon/STURifleWeapon.h"
#include "DrawDebugHelpers.h"
#include "Engine/World.h"

void ASTURifleWeapon::StartFire()
{
    MakeShot();
    GetWorldTimerManager().SetTimer(ShotTimerHandle, this, &ASTURifleWeapon::MakeShot, TimeBetweenShots, true);
}

void ASTURifleWeapon::StopFire()
{
    GetWorldTimerManager().ClearTimer(ShotTimerHandle);
}

void ASTURifleWeapon::MakeShot()
{
    if (!GetWorld())
        return;

    const auto Controller = GetPlayerController();
    if (!Controller)
        return;

    FVector ViewLocation;
    FRotator ViewRotation;
    Controller->GetPlayerViewPoint(ViewLocation, ViewRotation);

    const FTransform SocketTransform = WeaponMesh->GetSocketTransform(MazzleSocketName);
    const FVector TraceStart = ViewLocation;              // SocketTransform.GetLocation();
    const FVector ShootDirection = ViewRotation.Vector(); // SocketTransform.GetRotation().GetForwardVector();
    const FVector TraceEnd = TraceStart + ShootDirection * TraceMaxDistance;

    FCollisionQueryParams CollisionParams;
    CollisionParams.AddIgnoredActor(GetOwner());

    FHitResult HitResult;
    GetWorld()->LineTraceSingleByChannel(HitResult, TraceStart, TraceEnd, ECollisionChannel::ECC_Visibility,
                                         CollisionParams);

    if (HitResult.bBlockingHit)
    {
        MakeDamage(HitResult);

        DrawDebugLine(GetWorld(), SocketTransform.GetLocation(), HitResult.ImpactPoint, FColor::Red, false, 3.0f, 0,
                      3.0f);
        DrawDebugSphere(GetWorld(), HitResult.ImpactPoint, 10.0f, 24, FColor::Red, false, 5.0f);
    }
    else
    {
        DrawDebugLine(GetWorld(), SocketTransform.GetLocation(), TraceEnd, FColor::Red, false, 3.0f, 0, 3.0f);
    }
}

void ASTURifleWeapon::MakeDamage(const FHitResult &HitResult)
{
    const auto DamagedActor = HitResult.GetActor();

    if (!DamagedActor)
        return;

    DamagedActor->TakeDamage(DamageAmount, FDamageEvent(), GetPlayerController(), this);
}