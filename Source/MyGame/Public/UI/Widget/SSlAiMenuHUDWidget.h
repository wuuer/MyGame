// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Widgets/SCompoundWidget.h"
#include "SOverlay.h"


/**默认生成
 * 
 */
class MYGAME_API SSlAiMenuHUDWidget : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SSlAiMenuHUDWidget)
	{}
	SLATE_END_ARGS()

	// Constructs this widget with InArgs 默认生成
	void Construct(const FArguments& InArgs);



private:
		
	//绑定UIScaler的函数
	float GetUIScaler() const;
	//获取屏幕尺寸
	FVector2D GetViewportSize() const;

	//FReply OnClicked();//插槽绑定OnClicked方法


private:


	//获取Menu样式
	const struct FSlAiMenuStyle *MySlateStyle;
	//DPI缩放系数
	TAttribute<float>UIScaler;
	//SOverlay::FOverlaySlot* ImageSlot;	////OnClick绑定获取Image的Slot
	//菜单指针
	TSharedPtr<class SSlAiMenuWidget> MenuWidget;




};
