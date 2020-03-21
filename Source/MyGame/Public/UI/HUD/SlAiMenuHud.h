// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "SlAiMenuHud.generated.h"

/**
 * 
 */
UCLASS()
class MYGAME_API ASlAiMenuHud : public AHUD
{
	GENERATED_BODY()
	

public:

	ASlAiMenuHud();

	TSharedPtr<class SSlAiMenuHUDWidget>MenuHudWidget;


};
