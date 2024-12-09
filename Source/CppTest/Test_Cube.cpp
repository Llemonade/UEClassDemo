// Fill out your copyright notice in the Description page of Project Settings.


#include "Test_Cube.h"
#include "Components/BoxComponent.h"
#include "GameFramework/Actor.h"

// Sets default values
ATest_Cube::ATest_Cube()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

    CubeMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("CubeMesh"));

    CubeMaterial = CreateDefaultSubobject<UMaterialInstance>(TEXT("CubeMaterial"));
    CubeMesh ->SetSimulatePhysics(true);
    UBoxComponent* BoxComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxComponent"));
    RootComponent = BoxComponent;
    BoxComponent->SetSimulatePhysics(true);
    BoxComponent->OnComponentHit.AddDynamic(this, &ATest_Cube::OnHit);

    Points = 10; // defalut
    bIsImportantTarget = false;
    HitCount = 0;
}

// Called when the game starts or when spawned
void ATest_Cube::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATest_Cube::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ATest_Cube::OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
    if (OtherActor )
    {
        HitCount++;
        if (HitCount == 1)
        {
            SetActorScale3D(GetActorScale3D() * 0.5f); 
        }
        else if (HitCount >= 2)
        {
            Destroy(); 
        }

        
        int32 ScoredPoints = bIsImportantTarget ? Points * 2 : Points;
        
        //OnDestroyed(); 
    }
}