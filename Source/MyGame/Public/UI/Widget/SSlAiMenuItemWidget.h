// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SlAiTypes.h"
#include "Widgets/SCompoundWidget.h"


//定义一个参数的委托
DECLARE_DELEGATE_OneParam(FItemClicked,const EMenuItem::Type)




/**
 * 
 */
class MYGAME_API SSlAiMenuItemWidget : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SSlAiMenuItemWidget)
	{}






	SLATE_ATTRIBUTE(FText,ItemText)
		
		SLATE_EVENT(FItemClicked, OnClicked)//事件

	SLATE_ATTRIBUTE(EMenuItem::Type,ItemType)//事件

		SLATE_END_ARGS()






	/** Constructs this widget with InArgs */
	void Construct(const FArguments& InArgs);


	//重写组件的OnMouseButtonDown方法
	virtual FReply OnMouseButtonDown(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent)override;
	//重写按钮起来的方法
	virtual FReply OnMouseButtonUp(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent)override;
	//鼠标离开
	virtual void OnMouseLeave(const FPointerEvent& MyGeometry)override;




private:

	//获取颜色
	FSlateColor GetTintColor() const;



private:


	//获取Menu样式
	const struct FSlAiMenuStyle *MenuStyle;

	//按下事件委托
	FItemClicked OnClicked;

	//保存按钮类型
	EMenuItem::Type ItemType;

	//按钮是否按下
	bool bIsMouseButtonDown;





};
