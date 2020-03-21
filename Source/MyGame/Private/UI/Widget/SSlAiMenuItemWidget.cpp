// Fill out your copyright notice in the Description page of Project Settings.


#include "SSlAiMenuItemWidget.h"
#include "SlAiMenuWidgetStyle.h"
#include "SlAiStyle.h"
#include "SBox.h"
#include "SImage.h"
#include "STextBlock.h"

#include "SlateOptMacros.h"

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
void SSlAiMenuItemWidget::Construct(const FArguments& InArgs)
{


	//��ȡ�༭����MenuStyle
	MenuStyle = &SlAiStyle::Get().GetWidgetStyle<FSlAiMenuStyle>("BP_MySlateWidgetStyle");




	OnClicked = InArgs._OnClicked;//��ȡ�¼�
	ItemType = InArgs._ItemType.Get();//��ȡ���Բ���











	
	ChildSlot
	[
		SNew(SBox)
		.WidthOverride(500.f)
		.HeightOverride(100.f)

		[
		SNew(SOverlay)
		+SOverlay::Slot()
		.VAlign(VAlign_Fill)
		.HAlign(HAlign_Fill)

			[
			SNew(SImage)
			.Image(&MenuStyle->MenuItemBrush)
			.ColorAndOpacity(this, &SSlAiMenuItemWidget::GetTintColor)
			]
		+SOverlay::Slot()
		.VAlign(VAlign_Center)
		.HAlign(HAlign_Center)

			[
				SNew(STextBlock)
				.Text(InArgs._ItemText)
				.Font(MenuStyle->Font_60)
			]

		]

		

	];

	//��ʼ��
	bIsMouseButtonDown = false;





}
END_SLATE_FUNCTION_BUILD_OPTIMIZATION

FReply SSlAiMenuItemWidget::OnMouseButtonDown(const FGeometry & MyGeometry, const FPointerEvent & MouseEvent)
{

	bIsMouseButtonDown = true;

	return FReply::Handled();
}

FReply SSlAiMenuItemWidget::OnMouseButtonUp(const FGeometry & MyGeometry, const FPointerEvent & MouseEvent)
{

	//�����ť�����˲���OnClickedί�а��з�����ִ��
	if (bIsMouseButtonDown)
	{
		bIsMouseButtonDown = false;
		OnClicked.ExecuteIfBound(ItemType);

	}

	return FReply::Handled();


}

void SSlAiMenuItemWidget::OnMouseLeave(const FPointerEvent & MyGeometry)
{

	bIsMouseButtonDown = false;


}

FSlateColor SSlAiMenuItemWidget::GetTintColor() const
{
	if (bIsMouseButtonDown) return FLinearColor(1.f, 0.1f, 0.1f, 0.5f);
	return FLinearColor(1.f, 1.f, 1.f, 1.f);
	
}
