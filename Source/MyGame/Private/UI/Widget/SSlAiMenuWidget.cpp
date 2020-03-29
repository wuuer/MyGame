// Fill out your copyright notice in the Description page of Project Settings.


#include "SSlAiMenuWidget.h"
#include "SlateOptMacros.h"
#include "SBox.h"
#include "STextBlock.h"
#include "SImage.h"
#include "SSlAiMenuItemWidget.h"
#include "SlAiMenuWidgetStyle.h"
#include "SlAiStyle.h"
#include "SSlAiGameOptionWidget.h"
#include "SlAiIntemational.h"
#include "SBoxPanel.h"
#include "SlAiHelper.h"









BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
void SSlAiMenuWidget::Construct(const FArguments& InArgs)
{
	//获取编辑器的MenuStyle
	MenuStyle = &SlAiStyle::Get().GetWidgetStyle<FSlAiMenuStyle>("BP_MySlateWidgetStyle");



	//FInternationalization::Get().SetCurrentCulture(TEXT("en"));



	ChildSlot
	[
		SAssignNew(RootSizeBox,SBox)//Sbox只能插入一个组件
		[
			SNew(SOverlay)
			+SOverlay::Slot()
			.HAlign(HAlign_Fill)
			.VAlign(VAlign_Fill)
			.Padding(0.f, 50.f, 0.f, 0.f)
			[
				SNew(SImage)
				.Image(&MenuStyle->MenuBackGroupBrush)
			]


			+ SOverlay::Slot()
			.HAlign(HAlign_Left)
			.VAlign(VAlign_Center)
			.Padding(0.f,25.f,0.f,0.f)
			[
				SNew(SImage)
				.Image(&MenuStyle->LeftIconBrush)
			]


			+ SOverlay::Slot()
			.HAlign(HAlign_Right)
			.VAlign(VAlign_Center)
			.Padding(0.f, 25.f, 0.f, 0.f)
			[
				SNew(SImage)
				.Image(&MenuStyle->RightIconBrush)
			]


			+ SOverlay::Slot()
			.HAlign(HAlign_Center)
			.VAlign(VAlign_Top)
			[
				SNew(SBox)
				.WidthOverride(400.f)
				.HeightOverride(100.f)
				[
					SNew(SBorder)
					.BorderImage(&MenuStyle->TitleBorderBrush)
					.HAlign(HAlign_Center)
					.VAlign(VAlign_Center)
					[
						SAssignNew(TitleText,STextBlock)
						.Text(FTextMenu)
						.Font(MenuStyle->Font_60)


					]
				]
			]



			+SOverlay::Slot()
			.HAlign(HAlign_Center)
			.VAlign(VAlign_Top)
			.Padding(FMargin(0.f,130.f,0.f,0.f))
			[
				
				SAssignNew(ContentBox,SVerticalBox)




			]

		]
	];


	RootSizeBox->SetWidthOverride(600.f);
	RootSizeBox->SetHeightOverride(510.f);

	ContentBox->AddSlot()
		[


			SNew(SSlAiGameOptionWidget)



		];


}
END_SLATE_FUNCTION_BUILD_OPTIMIZATION

void SSlAiMenuWidget::MenuItemOnClicked(EMenuItem::Type ItemType)
{
	//SlAiHelpher::Debug(FString("hhhhh"),5.f);
}
