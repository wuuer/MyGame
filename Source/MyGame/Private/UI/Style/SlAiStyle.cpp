// Fill out your copyright notice in the Description page of Project Settings.


#include "SlAiStyle.h"// Style实例
#include "SlateStyleRegistry.h"
#include "SlateGameResources.h"//引入资源头文件


TSharedPtr<FSlateStyleSet> SlAiStyle::MyStyleInstance = NULL;

void SlAiStyle::Initialize()
{

	if (!MyStyleInstance.IsValid())
	{
		MyStyleInstance = Create();
		FSlateStyleRegistry::RegisterSlateStyle(*MyStyleInstance);

	}


}

FName SlAiStyle::GetStyleSetNema()
{
	static FName MyStyleName(TEXT("SlAiStyle")); //
	return MyStyleName;

}

void SlAiStyle::ShutDown()
{

	FSlateStyleRegistry::UnRegisterSlateStyle(*MyStyleInstance);
	ensure(MyStyleInstance.IsUnique());
	MyStyleInstance.Reset();

}

const ISlateStyle& SlAiStyle::Get()
{

	return *MyStyleInstance;

}

TSharedRef<class FSlateStyleSet> SlAiStyle::Create()
{

	TSharedRef<FSlateStyleSet> StyleRef = FSlateGameResources::New(SlAiStyle::GetStyleSetNema(), "/Game/UI/SlAiStyle", "/Game/UI/SlAiStyle");
	//StyleRef->Set("MenuItemFont", FSlateFontInfo("Roboto-Regular.ttf", 50));

	

	return StyleRef;

}





