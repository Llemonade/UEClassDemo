// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ScoreManager.generated.h"


UCLASS()
class CPPTEST_API UScoreManager : public UObject
{
    GENERATED_BODY()

public:
    UScoreManager();

    
    void AddScore(APlayerController* Player, int32 Points);

    
    int32 GetScore(APlayerController* Player) const;

    
    int32 GetTotalScore() const;

    
    void PrintScores() const;

private:
    
    TMap<APlayerController*, int32> PlayerScores;
};
