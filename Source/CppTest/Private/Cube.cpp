// Fill out your copyright notice in the Description page of Project Settings.


#include "Cube.h"
#include "Kismet/GameplayStatics.h"
#include "CppTest/CppTestProjectile.h"
#include "CppTest/Public/GameManager.h"

// Sets default values
ACube::ACube()
{
    CubeMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("CubeMesh"));
    DamagedCubeMaterial = CreateDefaultSubobject<UMaterialInstance>(TEXT("DamageMaterial"));
    CubeMaterial = CreateDefaultSubobject<UMaterialInstance>(TEXT("CubeMaterial"));

    CubeMesh->SetSimulatePhysics(true);
    bIsImportant = false;
    bScaledOnce = false;
}

// Called when the game starts or when spawned
void ACube::BeginPlay()
{
	Super::BeginPlay();
    CubeMesh->OnComponentHit.AddDynamic(this, &ACube::OnComponentHit);

    if (CubeMaterial)
    {
        CubeMesh->SetMaterial(0, CubeMaterial);
    }
}

// Called every frame
void ACube::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACube::OnTakeDamage()
{
    CubeMesh->SetMaterial(0, DamagedCubeMaterial);
    GetWorld()->GetTimerManager().SetTimer(DamageTimer, this, &ACube::ResetDamage, 1.5f, false);
}
void ACube::ResetDamage()
{
    CubeMesh->SetMaterial(0, CubeMaterial);
}
void ACube::OnComponentHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
    if (OtherActor && OtherActor->IsA(ACppTestProjectile::StaticClass()))
    {
        UGameplayStatics::ApplyDamage(this, 20.0f, nullptr, OtherActor, UDamageType::StaticClass());
        //OnTakeDamage();
        HandleHit(true);
    }
}
void ACube::MarkAsImportant()
{
    bIsImportant = true;
    if (DamagedCubeMaterial)
    {
        CubeMesh->SetMaterial(0, DamagedCubeMaterial);
    }
}
void ACube::HandleHit(bool bIsBullet)
{
    if (!bIsBullet)
        return;

    
    APlayerController* PlayerController = UGameplayStatics::GetPlayerController(this, 0);
    if (!PlayerController)
        return;

    int32 Points = bIsImportant ? 20 : 10;

    
    // ªÒ»° GameManager
    AGameManager* GameManager = Cast<AGameManager>(UGameplayStatics::GetActorOfClass(this, AGameManager::StaticClass()));
    if (!GameManager)
        return;
    if (GameManager)
    {
        GameManager->AddScore(PlayerController, Points);
    }

    if (!bScaledOnce)
    {
        
        SetActorScale3D(GetActorScale3D() * 0.5f);
        bScaledOnce = true;
    }
    else
    {
        
        Destroy();
    }
}