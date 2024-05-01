// ShootThemUp. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "STUCoreTypes.h"
#include "STUGameModeBase.generated.h"

class AAIController;

UCLASS()
class SHOOTTHEMUP_API ASTUGameModeBase : public AGameModeBase
{
    GENERATED_BODY()

public:
    ASTUGameModeBase();

    FOnMatchStateChangedSignature OnMatchStateChanged;

    virtual void StartPlay();
    virtual UClass* GetDefaultPawnClassForController_Implementation(AController* InController) override;
   
    void Killed(AController* KillerController, AController* VictimController);
    void RespawnRequest(AController* Controller);

    FGameData GetGameData() const { return GameData; }
    int32 GetCurrentRoundNum() const { return CurrenRound; }
    int32 GetRoundSecondsRemaining() const { return RoundCoundDown; }

    virtual bool SetPause(APlayerController* PC, FCanUnpause CanUnpauseDelegate = FCanUnpause()) override;
    virtual bool ClearPause() override;


protected:
    UPROPERTY(EditDefaultsOnly, Category = "Game")
    TSubclassOf<AAIController> AIControllerClass;

    UPROPERTY(EditDefaultsOnly, Category = "Game")
    TSubclassOf<APawn> AIPawnClass;

    UPROPERTY(EditDefaultsOnly, Category = "Game")
    FGameData GameData;

private:
    ESTUMatchState MatchState = ESTUMatchState::WaitingToStart;
    int32 CurrenRound = 1;
    int32 RoundCoundDown = 0;
    FTimerHandle GameRoundTimerHandle;

    void SpawBots();
    void StartRound();
    void GameTimerUpdate();

    void ResetPlayers();
    void ResetOnePlayer(AController* Controller);

    void CreateTeamsInfo();
    FLinearColor DetermineColorByTeamId(int32 TeamId) const;
    void SetPlayerColor(AController* Controller);

    void LogPlayerInfo();

    void StartRespawn(AController* Controller);

    void GameOver();

    void SetMatchState(ESTUMatchState State);
};
