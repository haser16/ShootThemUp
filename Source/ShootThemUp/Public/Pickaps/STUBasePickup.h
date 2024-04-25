// ShootThemUp. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "STUBasePickup.generated.h"

class USphereComponent;

UCLASS()
class SHOOTTHEMUP_API ASTUBasePickup : public AActor
{
    GENERATED_BODY()

public:
    ASTUBasePickup();

protected:
    UPROPERTY(VisibleAnywhere, Category = "Pickaup")
    USphereComponent* CollisionComponent;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pickaup")
    float RespawnTime = 5.0f;

    virtual void BeginPlay() override;
    virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;

public:
    virtual void Tick(float DeltaTime) override;

    bool CouldBeTaken() const;

private:
    float RotationYaw = 0.0f;
    FTimerHandle RespownTimerHandle;

    virtual bool GivePickupTo(APawn* PlayerPawn);

    void PickupWasTaken();
    void Respawn();
    void GenerateRotationYaw();
};
