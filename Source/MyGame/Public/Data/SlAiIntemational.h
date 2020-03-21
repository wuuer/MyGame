// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "CoreMinimal.h"

/**
 * 
 */
class MYGAME_API SlAiIntemational
{
public:

	static void Register(FText Value)

	{
		return;
	}



};

#define LOCTEXT_NAMESPACE "SlAiMenu"

////主界面


//FText FTextMenu; = LOCTEXT("Menu", "Menu");//菜单
//LOCTEXT("StartGame", "StartGame");//开始游戏
//FText FTextMenu = LOCTEXT("Menu", "Menu");//菜单
//FText FTextStartGame = LOCTEXT("StartGame", "StartGame");//开始游戏
////SlAiIntemational::Register(LOCTEXT("GameOption", "GameOption"));//游戏设置
////SlAiIntemational::Register(LOCTEXT("QuitGame", "QuitGame"));//退出游戏
////
////SlAiIntemational::Register(LOCTEXT("NewGame", "NewGame"));//新游戏
////SlAiIntemational::Register(LOCTEXT("LoadRecord", "LoadRecord"));//加载存档
////
////SlAiIntemational::Register(LOCTEXT("ChooseRecord", "ChooseRecord"));//选择存档
////
////进入游戏界面
////SlAiIntemational::Register(LOCTEXT("RecordName", "RecordName"));//存档名
////SlAiIntemational::Register(LOCTEXT("EnterGame", "EnterGame"));//进入游戏
////SlAiIntemational::Register(LOCTEXT("EnterRecord", "EnterRecord"));//进入存档
////SlAiIntemational::Register(LOCTEXT("RecordNameHint", "Input Record Name!");//输入存档名
////SlAiIntemational::Register(LOCTEXT("NameRepeatedHint", "Record Name Repeated!");//输入存档名
////
////游戏设置界面
//FText FTextChineseChange = 
//LOCTEXT("Chinese", "Chinese");//中文
//FText FTextEnglishChange = 
//LOCTEXT("English", "English");//英文
////SlAiIntemational::Register(LOCTEXT("Music", "Music"));//音乐
////SlAiIntemational::Register(LOCTEXT("Sound", "Sound"));//音效
//
//
////另一种方法
////FText FTextGoodbyeWorld =(NSLOCTEXT("SlAiMenu","Menu", "1234"));


#undef LOCTEXT_NAMESPACE