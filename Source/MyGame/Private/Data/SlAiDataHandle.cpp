// Fill out your copyright notice in the Description page of Project Settings.


#include "SlAiDataHandle.h"
#include "Internationalization.h"


#include "SlAiStyle.h"

TSharedPtr<SlAiDataHandle>SlAiDataHandle::DataInstance = NULL;



void SlAiDataHandle::Initialize()
{
	if (!DataInstance.IsValid())
	{

		DataInstance = Create();
	
	}
	
}

TSharedPtr<SlAiDataHandle> SlAiDataHandle::Get()
{

	Initialize();
	return DataInstance;
}



TSharedRef<SlAiDataHandle> SlAiDataHandle::Create()
{
	TSharedRef<SlAiDataHandle>DataRef = MakeShareable(new SlAiDataHandle());
	return DataRef;

}


SlAiDataHandle::SlAiDataHandle()
{
	//初始化为英文
	CurrentCulture = ECultureTeam::ZH;

}



void SlAiDataHandle::ChangeLocalizationCulture(ECultureTeam Culture)
{
	switch (Culture)
	{

		case ECultureTeam::EN:
				FInternationalization::Get().SetCurrentCulture(TEXT("en"));
				break;

		case ECultureTeam::ZH:
				FInternationalization::Get().SetCurrentCulture(TEXT("zh"));
				break;
		default:
			break;
	}

	//赋值,修改语言的枚举值,用于切换场景
	CurrentCulture = Culture;


}