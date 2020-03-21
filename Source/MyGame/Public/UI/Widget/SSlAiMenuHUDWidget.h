// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Widgets/SCompoundWidget.h"
#include "SOverlay.h"


/**Ĭ������
 * 
 */
class MYGAME_API SSlAiMenuHUDWidget : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SSlAiMenuHUDWidget)
	{}
	SLATE_END_ARGS()

	// Constructs this widget with InArgs Ĭ������
	void Construct(const FArguments& InArgs);



private:
		
	//��UIScaler�ĺ���
	float GetUIScaler() const;
	//��ȡ��Ļ�ߴ�
	FVector2D GetViewportSize() const;

	//FReply OnClicked();//��۰�OnClicked����


private:


	//��ȡMenu��ʽ
	const struct FSlAiMenuStyle *MySlateStyle;
	//DPI����ϵ��
	TAttribute<float>UIScaler;
	//SOverlay::FOverlaySlot* ImageSlot;	////OnClick�󶨻�ȡImage��Slot
	//�˵�ָ��
	TSharedPtr<class SSlAiMenuWidget> MenuWidget;




};
