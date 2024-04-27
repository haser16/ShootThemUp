// ShootThemUp. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "STUPlayerState.generated.h"

UCLASS()
class SHOOTTHEMUP_API ASTUPlayerState : public APlayerState
{
    GENERATED_BODY()
public:
    void SetTeamId(int32 ID) { TeamId = ID; }
    int32 GetTeamId() const { return TeamId; }

    void SetTeamColor(FLinearColor Color) { TeamColor = Color; }
    FLinearColor GetTeamColor() const { return TeamColor; }

    void AddKills() { ++KillsNum; }
    int32 GetKillsNum() { return KillsNum; }

    void AddDeath() { ++DeathNum; }
    int32 GetDeathNum() { return DeathNum; }

    void LogInfo();

private:
    int32 TeamId;
    FLinearColor TeamColor;

    int32 KillsNum = 0;
    int32 DeathNum = 0;
};
