// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActor.h"

// Sets default values
AMyActor::AMyActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AMyActor::BeginPlay()
{
	Super::BeginPlay();
	
	UE_LOG(LogTemp, Warning, TEXT("Actor is Spawned"));
	start.X = 0;
	start.Y = 0;
	
	UE_LOG(LogTemp, Warning, TEXT("Start : (%f, %f)"), start.X, start.Y);

	this->move();
	UE_LOG(LogTemp, Warning, TEXT("END : (%f, %f)"), start.X, start.Y);

	
}

// Called every frame
void AMyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AMyActor::move() {
	for (int i = 0; i < 10; i++) {
		start.X += AMyActor::step();
		start.Y += AMyActor::step();
		UE_LOG(LogTemp, Display, TEXT("Move : (%f, %f)"), start.X, start.Y);
	}
}

int32_t AMyActor::step() {
	return FMath::RandRange(0, 1);	// X와 Y축이 각각 0~1 칸 이동
}