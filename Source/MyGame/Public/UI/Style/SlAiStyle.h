// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "SlateBasics.h"//���븸��ͷ�ļ�
#include "CoreMinimal.h"






/**
 * 
 */
class MYGAME_API SlAiStyle
{
public:

	static void Initialize();
	static FName GetStyleSetNema();
	static void ShutDown();
	static const ISlateStyle& Get();


private:

	static TSharedRef<class FSlateStyleSet> Create();
	static TSharedPtr<FSlateStyleSet> MyStyleInstance;








};
