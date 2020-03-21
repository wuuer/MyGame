// Fill out your copyright notice in the Description page of Project Settings.


#include "SSlAiMenuHUDWidget.h"
#include "SlateOptMacros.h"
#include "SButton.h"
#include "SImage.h"
#include "SlAiMenuWidgetStyle.h"
#include "SlAiStyle.h"
#include "Engine/Engine.h"
#include "SDPIScaler.h"
#include "SSlAiMenuWidget.h"




BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
void SSlAiMenuHUDWidget::Construct(const FArguments& InArgs)
{
	//��ȡ�༭����MenuStyle
	MySlateStyle = &SlAiStyle::Get().GetWidgetStyle<FSlAiMenuStyle>("BP_MySlateWidgetStyle");
	//�����Ź��򷽷�
	UIScaler.Bind(this, &SSlAiMenuHUDWidget::GetUIScaler);




		ChildSlot
	[



		SNew(SDPIScaler)
		.DPIScale(UIScaler)
		[

	
				SNew(SOverlay)//�����²��,������һ�ַ���
				+ SOverlay::Slot()//����ӽ����
				.HAlign(HAlign_Fill)
				.VAlign(VAlign_Fill)
				.Padding(30.f)//�������¼��30
				[
					SNew(SImage)
					.Image(&MySlateStyle->MenuHudBackGroupBrush)
				]



				+ SOverlay::Slot()//����ӽ����
				.HAlign(HAlign_Center)
				.VAlign(VAlign_Center)
				//.Expose(ImageSlot)			 //��۰�Onclick����,�޸�ImageSlot����

				[
					SAssignNew(MenuWidget,SSlAiMenuWidget)//��������һ�ַ���(ָ��,����ʵ����)
				]


				//+SOverlay::Slot()				//��۰�Onclick����
				//.HAlign(HAlign_Left)
				//.VAlign(VAlign_Top)
				//[

				//	SNew(SButton)
				//	.OnClicked(this,&SSlAiMenuHUDWidget::OnClicked)

				//]
		]



		
	];

}
END_SLATE_FUNCTION_BUILD_OPTIMIZATION

float SSlAiMenuHUDWidget::GetUIScaler() const
{
	return GetViewportSize().Y / 1080.f;
}

FVector2D SSlAiMenuHUDWidget::GetViewportSize() const
{
	FVector2D Result(1920, 1080);

	if (GEngine && GEngine->GameViewport)
		GEngine->GameViewport->GetViewportSize(Result);
	return Result;

	


}

//FReply SSlAiMenuHUDWidget::OnClicked()
//{
//
//	ImageSlot->HAlign(HAlign_Right).VAlign(VAlign_Bottom);
//	return FReply::Handled();
//}
