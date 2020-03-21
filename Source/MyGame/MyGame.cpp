// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "MyGame.h"
#include "Modules/ModuleManager.h"
#include "Public/UI/Style/SlAiStyle.h"
#include "SlateStyleRegistry.h"


//IMPLEMENT_PRIMARY_GAME_MODULE( FDefaultGameModuleImpl, MyGame, "MyGame" );//默认模块名


IMPLEMENT_PRIMARY_GAME_MODULE(FMySlateModule, MyGame, "MyGame");//自定义模块,名为FMySlateModule

void FMySlateModule::StartupModule()
{
	//先取消注册，保证不会重复注册
	FSlateStyleRegistry::UnRegisterSlateStyle(SlAiStyle::GetStyleSetNema());
	SlAiStyle::Initialize();
}

void FMySlateModule::ShutdownModule()
{
	SlAiStyle::ShutDown();
}