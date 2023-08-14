// Fill out your copyright notice in the Description page of Project Settings.


#include "SphereOfFire.h"
#include "Components/SphereComponent.h"
#include "Components/StaticMeshComponent.h"
#include "UObject/ConstructorHelpers.h"
#include "Particles/ParticleSystemComponent.h"
#include "Components/TextRenderComponent.h"

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

	FireOfParticle = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("FireParticle"));
		FireOfParticle->SetupAttachment(VisibleSphere);
		FireOfParticle->bAutoActivate = true;

	DisplayText = CreateDefaultSubobject<UTextRenderComponent>(TEXT("Text"));

	DisplayText->SetupAttachment(VisibleSphere);
	DisplayText->SetRelativeLocation(FVector(0.f, 0.f, 110.f));
	DisplayText->SetHorizontalAlignment(EHTA_Center);
	DisplayText->SetYScale(1.f);
	DisplayText->SetXScale(1.f);
	DisplayText->SetText(FText::FromString("C++ na Unreal Udemy"));
	DisplayText->SetTextRenderColor(FColor::Red);
	DisplayText->SetVisibility(true);

	OnActorBeginOverlap.AddDynamic(this, &ASphereOfFire::StartedOverlapping);
	OnActorEndOverlap.AddDynamic(this, &ASphereOfFire::EndedOverlay);

	VisibleSphere->SetupAttachment(RootComponent);

	ConstructorHelpers::FObjectFinder<UStaticMesh>Sphere(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Sphere.Shape_Sphere'"));

	ConstructorHelpers::FObjectFinder<UMaterialInterface>SphereMaterial(TEXT("Material'/Game/StarterContent/Materials/M_Metal_Gold.M_Metal_Gold'"));

	ConstructorHelpers::FObjectFinder<UParticleSystem>Fire(TEXT("ParticleSystem'/Game/StarterContent/Particles/P_Fire.P_Fire'"));

		if (Sphere.Succeeded() && SphereMaterial.Succeeded() && Fire.Succeeded())
		{
			VisibleSphere->SetStaticMesh(Sphere.Object);
			VisibleSphere->SetMaterial(0, SphereMaterial.Object);
			FireOfParticle->SetTemplate(Fire.Object);
			VisibleSphere->SetRelativeLocation(FVector(0.f, 0.f, -60.f));
	}

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
//Esta função será chamada caso alguma bluprint criada a partir dessa classe(Parent) não sobrescreva esta função
void ASphereOfFire::StartedOverlapping_Implementation(AActor* OverlappedActor, AActor* OtherActor)
{
	FString OutputString;
	OutputString = "Overlapping via C++ code the actor:" + OtherActor->GetName() + " !";

	DisplayText->SetText(FText::FromString(OutputString));
}

//Esta função será chamada caso alguma bluprint criada a partir dessa classe(Parent) não sobrescreva esta função
void ASphereOfFire::EndedOverlay_Implementation(AActor* OverlappedActor, AActor* OtherActor)
{
	DisplayText->SetText(FText::FromString(TEXT("I stopped overlapping via C++ code.")));
}
