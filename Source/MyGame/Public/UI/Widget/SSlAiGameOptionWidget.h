// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SlAiTypes.h"
#include "Widgets/SCompoundWidget.h"



class SCheckBox;
class SSlider;
class STextBlock;


/**
 * 
 */
class MYGAME_API SSlAiGameOptionWidget : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SSlAiGameOptionWidget)
	{}
	SLATE_END_ARGS()

	/** Constructs this widget with InArgs */
	void Construct(const FArguments& InArgs);


private:


	//统一设置样式
	void StyleInitialize();

	//中文CheckBox事件
	void ZhCheckBoxStateChanged(ECheckBoxState NewState);
	//英文CheckBox事件
	void EnCheckBoxStateChanged(ECheckBoxState NewState);
	//音量变化事件
	void MusicSliderChanged(float Value);
	//音效变化事件
	void SoundSliderChanged(float Value);
	//进度条百分比
	TSharedPtr<STextBlock>MuTextBlock;
	TSharedPtr<STextBlock>SoTextBlock;


private:

	//获取Menu样式
	const struct FSlAiMenuStyle *MenuStyle;



	//获取Checkbox指针
	TSharedPtr<SCheckBox> EnCheckBox;
	TSharedPtr<SCheckBox> ZhCheckBox;

	//两个滑条
	TSharedPtr<SSlider>MuSlider;//背景音乐
	TSharedPtr<SSlider>SoSlider;//背景音效


};
