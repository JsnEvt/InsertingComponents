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

	UPROPERTY(Editanywhere, Category = "Components")
		UParticleSystemComponent* FireOfParticle;

protected:
	UPROPERTY(EditAnywhere, Category = "Variables")
		bool VariableEditAnywhere;
	
	UPROPERTY(VisibleAnywhere, Category = "Variables")
		float VariableVisibleAnywhere;

	UPROPERTY(EditDefaultsOnly, Category = "Variables")
		float VariableEditDefaultOnly;

	UPROPERTY(VisibleDefaultsOnly, Category = "Variables")
		float VariableVisibleDefaultsOnly;

	UPROPERTY(BluePrintReadWrite, Category = "Variables")
		FVector VariableBlueprintReadWrite = FVector(0.f, 0.f, -180.f);

	UPROPERTY(BlueprintReadOnly, Category = "Variables")
		FString VariableBlueprintReadOnly = "Blueprint Text";

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Variables")
		FString VariableEditAnywhereBlueprintReadWrite = "Editable Text";

	UPROPERTY(BlueprintReadOnly, Category = "Variables")
		FString VariableEditAnywhereBlueprintReadOnly = "Other Text";



	UFUNCTION()
		void StartedOverlapping(AActor* OverlappedActor, AActor* OtherActor);

	UFUNCTION()
		void EndedOverlay(AActor* OverlappedActor, AActor* OtherActor);

	class UTextRenderComponent* DisplayText;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
