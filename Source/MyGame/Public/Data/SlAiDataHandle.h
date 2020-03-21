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


public:


	ECultureTeam CurrentCulture;//�����޸����Ե�ö��ֵ,�����л�����





private:



	static TSharedRef<SlAiDataHandle> Create();


private:



	static TSharedPtr<SlAiDataHandle> DataInstance;




};
