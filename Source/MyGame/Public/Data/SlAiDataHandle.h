// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "SlAiTypes.h"

#include "CoreMinimal.h"

/**
 * 
 */
class MYGAME_API SlAiDataHandle
{
public:

	SlAiDataHandle();

	static void Initialize();

	static TSharedPtr<SlAiDataHandle> Get();



	//修改中英文

	void ChangeLocalizationCulture(ECultureTeam Culture);


public:


	ECultureTeam CurrentCulture;//定义修改语言的枚举值,用于切换场景





private:



	static TSharedRef<SlAiDataHandle> Create();


private:



	static TSharedPtr<SlAiDataHandle> DataInstance;




};
