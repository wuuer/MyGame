// Fill out your copyright notice in the Description page of Project Settings.


#include "SlAiMenuHud.h"
#include "SSlAiMenuHUDWidget.h"
#include "SlateBasics.h"  //����Widget�������ͷ�ļ�

ASlAiMenuHud::ASlAiMenuHud()
{
	if (GEngine && GEngine->GameViewport)
	{
		SAssignNew(MenuHudWidget, SSlAiMenuHUDWidget);//����Widgetһ�ַ���,�����ָ��

		GEngine->GameViewport->AddViewportWidgetContent(SNew(SWeakWidget).PossiblyNullContent(MenuHudWidget.ToSharedRef()));
		//SNewΪ����Widget��һ�ַ���


	}
}
