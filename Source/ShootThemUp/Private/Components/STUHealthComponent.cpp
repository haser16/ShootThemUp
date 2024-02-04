// ShootThemUp. All Rights Reserved.

#include "STUHealthComponent.h"
#include "GameFramework/Actor.h"

DEFINE_LOG_CATEGORY_STATIC(LogHealthComponent, All, All);

USTUHealthComponent::USTUHealthComponent()
{
    PrimaryComponentTick.bCanEverTick = false;
}

void USTUHealthComponent::BeginPlay()
{
    Super::BeginPlay();

    Health = MaxHealth;
    OnHeathChanged.Broadcast(Health);

    AActor *ComponentOwner = GetOwner();

    if (ComponentOwner)
    {
        ComponentOwner->OnTakeAnyDamage.AddDynamic(this, &USTUHealthComponent::OnTakeAnyDamage);
    }
}

void USTUHealthComponent::OnTakeAnyDamage(AActor *DamagedActor, float Damage, const class UDamageType *DamageType,
                                          class AController *InstigatedBy, AActor *DamageCauser)
{

    if (Damage <= 0.0f || IsDead()) return;

    Health = FMath::Clamp(Health - Damage, 0.0f, MaxHealth);
    OnHeathChanged.Broadcast(Health);

    if (IsDead())
    {
        OnDeath.Broadcast();
    }
    
}