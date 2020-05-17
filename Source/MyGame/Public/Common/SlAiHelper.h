// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/World.h"



namespace SlAiHelper {



	FORCEINLINE void Debug(FString Message, float Duration = 3.f)
	{
	if (GEngine)
	{

		//Debug message
		GEngine->AddOnScreenDebugMessage(-1, Duration, FColor::Yellow, Message);

	}
	
	
	}

}