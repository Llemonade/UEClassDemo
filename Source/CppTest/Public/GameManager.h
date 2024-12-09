// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "CppTest/Public/Cube.h"
#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "GameManager.generated.h"

/**
 * 
 */
UCLASS()
class CPPTEST_API AGameManager : public AGameModeBase
{
	GENERATED_BODY()
	
public:
    
    AGameManager();

protected:
    
    virtual void BeginPlay() override;

public:
    
    virtual void Tick(float DeltaTime) override;

    
    UFUNCTION(BlueprintCallable)
    void StartGame();

    UFUNCTION(BlueprintCallable)
    void EndGame();

    
    void AddScore(APlayerController* Player, int32 Points);

private:
    
    TMap<APlayerController*, int32> PlayerScores;

    
    int32 GetTotalScore() const;

    void SpawnTargets(int32 TargetCount);

    
    void PrintScores() const;

    
    float GameTimeLimit;

    
    float ElapsedTime;

    
    bool bIsGameRunning;

    TArray<ACube*> Targets;
	
};