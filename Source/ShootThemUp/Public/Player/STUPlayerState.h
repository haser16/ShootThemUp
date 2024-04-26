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

private:
    int32 TeamId;
    FLinearColor TeamColor;
};
