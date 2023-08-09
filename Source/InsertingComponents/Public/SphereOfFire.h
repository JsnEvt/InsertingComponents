// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SphereOfFire.generated.h"

UCLASS()
class INSERTINGCOMPONENTS_API ASphereOfFire : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASphereOfFire();

private:
	UPROPERTY(EditAnywhere, Category = "Components")
		UStaticMeshComponent* VisibleSphere;

	UPROPERTY(EditAnywhere, Category = "Components")
		class USphereComponent* CollisionSphere;



protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
