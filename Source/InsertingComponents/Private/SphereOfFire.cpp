// Fill out your copyright notice in the Description page of Project Settings.


#include "SphereOfFire.h"
#include "Components/SphereComponent.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
ASphereOfFire::ASphereOfFire()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	CollisionSphere = CreateDefaultSubobject<USphereComponent>(TEXT("Raiz"));
	CollisionSphere->InitSphereRadius(100.f);
	CollisionSphere->SetCollisionProfileName(TEXT("OverlapAllDynamic"));
	RootComponent = CollisionSphere;

	VisibleSphere = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Sphere"));
	VisibleSphere->SetupAttachment(RootComponent);

}

// Called when the game starts or when spawned
void ASphereOfFire::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASphereOfFire::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

