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

	//修改菜单音量

	void ResetMenuVolume(float MusciVal, float SoundVal);


public:

	//语言
	ECultureTeam CurrentCulture;//定义修改语言的枚举值,用于切换场景

	//音量
	float MusicVolume;
	float SoundVolume;

	//存档数据
	TArray<FString>RecordDataList;


private:



	static TSharedRef<SlAiDataHandle> Create();


	//根据Enum类型获取字符串
	template<typename TEnum>
	FString GetEnumValueAsString(const FString& Name, TEnum Value);

	//根据字符串获取Enum值
	template<typename TEnum>
	TEnum GetEnumValueFromString(const FString& Name,FString Value);

	//初始化存档数据
	void  InitRecordData();



private:



	static TSharedPtr<SlAiDataHandle> DataInstance;




};


