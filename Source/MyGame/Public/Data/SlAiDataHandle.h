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



	//�޸���Ӣ��

	void ChangeLocalizationCulture(ECultureTeam Culture);

	//�޸Ĳ˵�����

	void ResetMenuVolume(float MusciVol, float SoundVol);


public:

	//����
	ECultureTeam CurrentCulture;//�����޸����Ե�ö��ֵ,�����л�����

	//����
	float MusicVolume;
	float SoundVolume;

	//�浵����
	TArray<FString>RecordDataList;


private:



	static TSharedRef<SlAiDataHandle> Create();


	//����Enum���ͻ�ȡ�ַ���
	template<typename TEnum>
	FString GetEnumValueAsString(const FString& Name, TEnum Value);

	//�����ַ�����ȡEnumֵ
	template<typename TEnum>
	TEnum GetEnumValueFromString(const FString& Name,FString Value);

	//��ʼ���浵����
	void  InitRecordData();



private:



	static TSharedPtr<SlAiDataHandle> DataInstance;




};


