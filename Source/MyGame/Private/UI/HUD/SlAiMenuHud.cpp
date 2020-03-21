// Fill out your copyright notice in the Description page of Project Settings.


#include "SlAiMenuHud.h"
#include "SSlAiMenuHUDWidget.h"
#include "SlateBasics.h"  //创建Widget的引入的头文件

ASlAiMenuHud::ASlAiMenuHud()
{
	if (GEngine && GEngine->GameViewport)
	{
		SAssignNew(MenuHudWidget, SSlAiMenuHUDWidget);//创建Widget一种方法,后面跟指针

		GEngine->GameViewport->AddViewportWidgetContent(SNew(SWeakWidget).PossiblyNullContent(MenuHudWidget.ToSharedRef()));
		//SNew为创建Widget另一种方法


	}
}
