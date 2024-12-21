// Fill out your copyright notice in the Description page of Project Settings.


#include "GameManager.h"
#include "Kismet/GameplayStatics.h"
#include "EngineUtils.h"

AGameManager::AGameManager()
{
    PrimaryActorTick.bCanEverTick = true;
    GameTimeLimit = 40.0f; 
    ElapsedTime = 0.0f;
    bIsGameRunning = true;
}


void AGameManager::BeginPlay()
{
    Super::BeginPlay();

    UE_LOG(LogTemp, Log, TEXT("Game Started!"));
    StartGame();
}


void AGameManager::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    if (bIsGameRunning)
    {
        ElapsedTime += DeltaTime;

        if (ElapsedTime >= GameTimeLimit)
        {
            bIsGameRunning = false;
            EndGame();
        }
    }
}

void AGameManager::StartGame()
{
    //SpawnTargets(20); // 生成20个方块
    TArray<ACube*> FoundCubes;

    for (TActorIterator<ACube> It(GetWorld()); It; ++It)
    {
        ACube* Cube = *It;
        if (Cube)
        {
            FoundCubes.Add(Cube);
        }
    }
    // 随机设置重要目标
    int32 i = 0;
    for (; i < 5 && i< FoundCubes.Num() - 1; )
    {
        int32 Index = FMath::RandRange(0, FoundCubes.Num() - 1);
        if (FoundCubes[Index])
        {
            FoundCubes[Index]->MarkAsImportant();
            i++;

        }
    }


}
void AGameManager::EndGame()
{
    UE_LOG(LogTemp, Log, TEXT("Game Over!"));

    
    PrintScores();
    UKismetSystemLibrary::QuitGame(this, nullptr, EQuitPreference::Quit, false);
}


void AGameManager::AddScore(APlayerController* Player, int32 Points)
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


int32 AGameManager::GetTotalScore() const
{
    int32 TotalScore = 0;
    for (const auto& Pair : PlayerScores)
    {
        TotalScore += Pair.Value;
    }
    return TotalScore;
}


void AGameManager::PrintScores() const
{
    for (const auto& Pair : PlayerScores)
    {
        UE_LOG(LogTemp, Log, TEXT("Player: %s, Score: %d"), *Pair.Key->GetName(), Pair.Value);
    }
    UE_LOG(LogTemp, Log, TEXT("Total Score: %d"), GetTotalScore());
}
void AGameManager::SpawnTargets(int32 TargetCount)
{
    for (int32 i = 0; i < TargetCount; ++i)
    {
        FVector Location = FVector(FMath::RandRange(-500, 500), FMath::RandRange(-500, 500), FMath::RandRange(100, 500));
        ACube* Target = GetWorld()->SpawnActor<ACube>(Location, FRotator::ZeroRotator);
        if (Target)
        {
            Targets.Add(Target);
        }
    }
}



