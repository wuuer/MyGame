// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "MyGame.h"
#include "Modules/ModuleManager.h"
#include "Public/UI/Style/SlAiStyle.h"
#include "SlateStyleRegistry.h"


//IMPLEMENT_PRIMARY_GAME_MODULE( FDefaultGameModuleImpl, MyGame, "MyGame" );//Ĭ��ģ����


IMPLEMENT_PRIMARY_GAME_MODULE(FMySlateModule, MyGame, "MyGame");//�Զ���ģ��,��ΪFMySlateModule

void FMySlateModule::StartupModule()
{
	//��ȡ��ע�ᣬ��֤�����ظ�ע��.
	FSlateStyleRegistry::UnRegisterSlateStyle(SlAiStyle::GetStyleSetNema());
	SlAiStyle::Initialize();
}

void FMySlateModule::ShutdownModule()
{
	SlAiStyle::ShutDown();
}