// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SlAiTypes.h"
#include "Widgets/SCompoundWidget.h"



class SCheckBox;
class SSlider;
class STextBlock;


//�޸���Ӣ��ί��
DECLARE_DELEGATE_OneParam(FChaneCulture, const ECultureTeam)
//�޸�������ί��
DECLARE_DELEGATE_TwoParams(FChaneVolume, const float, const float)



/**
 * 
 */
class MYGAME_API SSlAiGameOptionWidget : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SSlAiGameOptionWidget)
	{}


	SLATE_EVENT(FChaneCulture, ChangeCulture)

	SLATE_EVENT(FChaneVolume, ChangeVolume)


	SLATE_END_ARGS()

	/** Constructs this widget with InArgs */
	void Construct(const FArguments& InArgs);


private:


	//ͳһ������ʽ
	void StyleInitialize();

	//����CheckBox�¼�
	void ZhCheckBoxStateChanged(ECheckBoxState NewState);
	//Ӣ��CheckBox�¼�
	void EnCheckBoxStateChanged(ECheckBoxState NewState);
	//�����仯�¼�
	void MusicSliderChanged(float Value);
	//��Ч�仯�¼�
	void SoundSliderChanged(float Value);
	//�������ٷֱ�
	TSharedPtr<STextBlock>MuTextBlock;
	TSharedPtr<STextBlock>SoTextBlock;


private:

	//��ȡMenu��ʽ
	const struct FSlAiMenuStyle *MenuStyle;



	//��ȡCheckboxָ��
	TSharedPtr<SCheckBox> EnCheckBox;
	TSharedPtr<SCheckBox> ZhCheckBox;

	//��������
	TSharedPtr<SSlider>MuSlider;//��������
	TSharedPtr<SSlider>SoSlider;//������Ч

	//ί�б���
	FChaneCulture ChangeCulture;
	FChaneVolume ChangeVolume;


};
