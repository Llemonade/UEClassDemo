// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Cube.generated.h"

UCLASS()
class CPPTEST_API ACube : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACube();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	class UStaticMeshComponent* CubeMesh;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	UMaterialInstance* CubeMaterial;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	UMaterialInstance* DamagedCubeMaterial;

	FTimerHandle DamageTimer;

	void OnTakeDamage();

	void ResetDamage();

	UFUNCTION()
	void OnComponentHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

	
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void MarkAsImportant();
private:
	// 是否为重要目标
	bool bIsImportant;

	// 缩放状态
	bool bScaledOnce;

	// 处理命中
	void HandleHit(bool bIsBullet);
	
};
