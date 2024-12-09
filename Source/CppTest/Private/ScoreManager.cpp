// Fill out your copyright notice in the Description page of Project Settings.


#include "ScoreManager.h"
#include "GameFramework/PlayerController.h"

UScoreManager::UScoreManager()
{
}

void UScoreManager::AddScore(APlayerController* Player, int32 Points)
{
    if (!Player)
        return;

    if (PlayerScores.Contains(Player))
    {
        PlayerScores[Player] += Points;
    }
    else
    {
        PlayerScores.Add(Player, Points);
    }
}

int32 UScoreManager::GetScore(APlayerController* Player) const
{
    if (Player && PlayerScores.Contains(Player))
    {
        return PlayerScores[Player];
    }
    return 0;
}

int32 UScoreManager::GetTotalScore() const
{
    int32 TotalScore = 0;
    for (const auto& Pair : PlayerScores)
    {
        TotalScore += Pair.Value;
    }
    return TotalScore;
}

void UScoreManager::PrintScores() const
{
    for (const auto& Pair : PlayerScores)
    {
        UE_LOG(LogTemp, Log, TEXT("Player: %s, Score: %d"), *Pair.Key->GetName(), Pair.Value);
    }
    UE_LOG(LogTemp, Log, TEXT("Total Score: %d"), GetTotalScore());
}

