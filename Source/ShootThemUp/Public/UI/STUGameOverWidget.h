// ShootThemUp. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "STUCoreTypes.h"
#include "UI/STUBaseWidget.h"
#include "STUGameOverWidget.generated.h"

class UVerticalBox;
class UButton;

UCLASS()
class SHOOTTHEMUP_API USTUGameOverWidget : public USTUBaseWidget
{
    GENERATED_BODY()

protected:
    UPROPERTY(meta = (BindWidget))
    UVerticalBox* PlayerStatBox;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "UI")
    TSubclassOf<UUserWidget> PlayerStatRowWidgetClass;

    UPROPERTY(meta = (BindWidget))
    UButton* ButtonResetLevel;

    virtual void NativeOnInitialized() override;

private:
    void OnMatchStateChanged(ESTUMatchState State);
    void UpdatePlayersStat();

    UFUNCTION()
    void OnResetLevel();
};
