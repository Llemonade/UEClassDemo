// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Test_Cube.generated.h"

UCLASS()
class CPPTEST_API ATest_Cube : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATest_Cube();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	class UStaticMeshComponent* CubeMesh;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	UMaterialInstance* CubeMaterial;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Target")
	int32 Points; 

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Target")
	bool bIsImportantTarget; 

	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

private:
	int32 HitCount;

	
};
