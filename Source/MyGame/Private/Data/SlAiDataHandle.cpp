// Fill out your copyright notice in the Description page of Project Settings.


#include "SlAiDataHandle.h"
#include "Internationalization.h"
#include "SlAiSingleton.h"
#include "SlAiJsonHandle.h"
#include "SlAiHelper.h"


//#include "SlAiStyle.h"

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
	
	//��ʼ���浵����
	InitRecordData();




}

void SlAiDataHandle::ResetMenuVolume(float MusciVol, float SoundVol)
{

	if (MusciVol > 0)
	{
		MusicVolume = MusciVol;
	}
	if (SoundVol > 0)
	{
		SoundVolume = SoundVol;
	}


	//���´浵����
	SlAiSingleton<SlAiJsonHandle>::Get()->UpdateRecordData(GetEnumValueAsString<ECultureTeam>(FString("ECultureTeam"), CurrentCulture), MusicVolume, SoundVolume, &RecordDataList);



}


template<typename TEnum>
FString SlAiDataHandle::GetEnumValueAsString(const FString& Name, TEnum Value)
{
	const UEnum* EnumPtr = FindObject<UEnum>(ANY_PACKAGE, *Name, true);
	if (!EnumPtr)
	{
		return FString("InValid");

	}
	return EnumPtr->GetEnumName((int32)Value);


}

template<typename TEnum>
TEnum SlAiDataHandle::GetEnumValueFromString(const FString& Name, FString Value)
{
	const UEnum* EnumPtr = FindObject<UEnum>(ANY_PACKAGE, *Name, true);
	if (!EnumPtr)
	{
		return TEnum(0);
	}
	return (TEnum)EnumPtr->GetIndexByName(FName(*FString(Value)));


}



void SlAiDataHandle::InitRecordData()
{

	RecordName = FString("");

	//��ȡ����
	FString Culture;
	//��ȡ�浵����
	SlAiSingleton<SlAiJsonHandle>::Get()->RecordDataJsonRead(Culture, MusicVolume, SoundVolume, RecordDataList);


	//��ʼ������
	ChangeLocalizationCulture(GetEnumValueFromString<ECultureTeam>(FString("ECultureTeam"),Culture));
	



	

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

	//��ֵ,�޸����Ե�ö��ֵ,�����л�����
	CurrentCulture = Culture;

	//���´浵����
	SlAiSingleton<SlAiJsonHandle>::Get()->UpdateRecordData(GetEnumValueAsString<ECultureTeam>(FString("ECultureTeam"), CurrentCulture), MusicVolume, SoundVolume, &RecordDataList);

}


