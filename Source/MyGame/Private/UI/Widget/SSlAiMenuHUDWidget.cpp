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
	//获取编辑器的MenuStyle
	MySlateStyle = &SlAiStyle::Get().GetWidgetStyle<FSlAiMenuStyle>("BP_MySlateWidgetStyle");
	//绑定缩放规则方法
	UIScaler.Bind(this, &SSlAiMenuHUDWidget::GetUIScaler);




		ChildSlot
	[



		SNew(SDPIScaler)
		.DPIScale(UIScaler)
		[

	
				SNew(SOverlay)//创建新插槽,创建的一种方法
				+ SOverlay::Slot()//添加子健插槽
				.HAlign(HAlign_Fill)
				.VAlign(VAlign_Fill)
				.Padding(30.f)//左上右下间距30
				[
					SNew(SImage)
					.Image(&MySlateStyle->MenuHudBackGroupBrush)
				]



				+ SOverlay::Slot()//添加子健插槽
				.HAlign(HAlign_Center)
				.VAlign(VAlign_Center)
				//.Expose(ImageSlot)			 //插槽绑定Onclick方法,修改ImageSlot属性

				[
					SAssignNew(MenuWidget,SSlAiMenuWidget)//创建的另一种方法(指针,类名实例化)
				]


				//+SOverlay::Slot()				//插槽绑定Onclick方法
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
