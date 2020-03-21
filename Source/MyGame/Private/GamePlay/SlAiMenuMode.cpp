// Fill out your copyright notice in the Description page of Project Settings.


#include "SlAiMenuMode.h"
#include "SlAiMenuController.h"
#include "SlAiMenuHUD.h"

ASlAiMenuMode::ASlAiMenuMode()
{

	PlayerControllerClass = ASlAiMenuController::StaticClass();
	HUDClass = ASlAiMenuHud::StaticClass();

}
