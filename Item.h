// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Item.generated.h"
UCLASS()
class RPG_API AItem : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AItem();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sine")
	float Amplitude = 0.25f;

	UPROPERTY(EditAnywhere, BluePrintReadWrite, Category = "Sine")
	float TimeConstant = 5.f;

	UFUNCTION(BlueprintPure)
	float TransformCos();

	UFUNCTION(BlueprintPure)
	float TransformSine();

protected:
	template<typename T>
	T Avg(T First, T Second);

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* ItemMesh;

private:
	UPROPERTY(VisibleAnywhere, BluePrintReadOnly, meta = (AllowPrivateAccess = "true"))
	float RunningTime;
};

template<typename T>
inline T AItem::Avg(T First, T Second)
{
	return (First + Second) / 2;
}
