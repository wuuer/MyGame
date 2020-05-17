// Fill out your copyright notice in the Description page of Project Settings.


#include "SlAiMenuWidgetStyle.h"
#include "SlAiStyle.h"

#include "SSlAiMenuWidget.h"
#include "SlateOptMacros.h"
#include "SBox.h"
#include "STextBlock.h"
#include "SImage.h"
#include "SSlAiMenuItemWidget.h"
#include "SSlAiGameOptionWidget.h"
#include "SSlAiNewGameWidget.h"
#include "SSlAiChooseRecordWidget.h"


#include "SlAiIntemational.h"
#include "SBoxPanel.h"
#include "SlAiHelper.h"
#include "SlAiDataHandle.h"


struct MenuGroup
{

	//菜单标题
	FText MenuName;
	//菜单高度
	float MenuHeight;
	//下属组件
	TArray<TSharedPtr<SCompoundWidget>>ChildWidget;
	//构造函数
	MenuGroup(const FText Name, const float Height, TArray<TSharedPtr<SCompoundWidget>>*Childern)
	{
		MenuName = Name;
		MenuHeight = Height;
		for (TArray<TSharedPtr<SCompoundWidget>>::TIterator It(*Childern); It; ++It)
		{
			ChildWidget.Add(*It);
		}


	}


};







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





	InitializedMenuList();

}
END_SLATE_FUNCTION_BUILD_OPTIMIZATION

void SSlAiMenuWidget::MenuItemOnClicked(EMenuItem::Type ItemType)
{
	//SlAiHelper::Debug(FString("hhhhh"),5.f);
}

void SSlAiMenuWidget::ChangeCulture(ECultureTeam culture)
{

	SlAiDataHandle::Get()->ChangeLocalizationCulture(culture);


}

void SSlAiMenuWidget::ChangeVolume(const float MusicVolume, const float SoundVolume)
{
	SlAiDataHandle::Get()->ResetMenuVolume(MusicVolume, SoundVolume);
}

void SSlAiMenuWidget::InitializedMenuList()
{
	
	//实例化主界面
	TArray<TSharedPtr<SCompoundWidget>>MainMenuList;
	MainMenuList.Add(SNew(SSlAiMenuItemWidget).ItemText(NSLOCTEXT("SlAiMenu", "StartGame", "StartGame")).ItemType(EMenuItem::StartGame).OnClicked(this, &SSlAiMenuWidget::MenuItemOnClicked));
	MainMenuList.Add(SNew(SSlAiMenuItemWidget).ItemText(NSLOCTEXT("SlAiMenu", "GameOption", "GameOption")).ItemType(EMenuItem::GameOption).OnClicked(this, &SSlAiMenuWidget::MenuItemOnClicked));
	MainMenuList.Add(SNew(SSlAiMenuItemWidget).ItemText(NSLOCTEXT("SlAiMenu", "QuitGame", "QuitGame")).ItemType(EMenuItem::QuitGame).OnClicked(this, &SSlAiMenuWidget::MenuItemOnClicked));

	MenuMap.Add(EMenuType::MainMenu, MakeShareable(new MenuGroup(NSLOCTEXT("SlAiMenu", "Menu", "Menu"), 510.f, &MainMenuList)));


	//开始游戏界面
	TArray<TSharedPtr<SCompoundWidget>> StartGameList;
	StartGameList.Add(SNew(SSlAiMenuItemWidget).ItemText(NSLOCTEXT("SlAiMenu", "NewGame", "NewGame")).ItemType(EMenuItem::NewGame).OnClicked(this, &SSlAiMenuWidget::MenuItemOnClicked));
	StartGameList.Add(SNew(SSlAiMenuItemWidget).ItemText(NSLOCTEXT("SlAiMenu", "LoadRecord", "LoadRecord")).ItemType(EMenuItem::LoadRecord).OnClicked(this, &SSlAiMenuWidget::MenuItemOnClicked));
	StartGameList.Add(SNew(SSlAiMenuItemWidget).ItemText(NSLOCTEXT("SlAiMenu", "GoBack", "GoBack")).ItemType(EMenuItem::StartGameGoBack).OnClicked(this, &SSlAiMenuWidget::MenuItemOnClicked));

	MenuMap.Add(EMenuType::StartGame, MakeShareable(new MenuGroup(NSLOCTEXT("SlAiMenu", "StartGame", "StartGame"), 510.f, &StartGameList)));


	//游戏设置界面
	TArray<TSharedPtr<SCompoundWidget>> GameOptionList;


	//实例化游戏设置的Widget
	SAssignNew(GameOptionWidget, SSlAiGameOptionWidget)
		.ChangeCulture(this, &SSlAiMenuWidget::ChangeCulture)
		.ChangeVolume(this, &SSlAiMenuWidget::ChangeVolume);
	//添加控件到数组

	GameOptionList.Add(GameOptionWidget);
	GameOptionList.Add(SNew(SSlAiMenuItemWidget).ItemText(NSLOCTEXT("SlAiMenu", "GoBack", "GoBack")).ItemType(EMenuItem::GameOptionGoBack).OnClicked(this, &SSlAiMenuWidget::MenuItemOnClicked));

	MenuMap.Add(EMenuType::GameOption, MakeShareable(new MenuGroup(NSLOCTEXT("SlAiMenu", "GameOption", "GameOption"), 610.f, &GameOptionList)));


	//开始新游戏界面
	TArray<TSharedPtr<SCompoundWidget>> NewGameList;
	SAssignNew(NewGameWidget, SSlAiNewGameWidget);
	NewGameList.Add(NewGameWidget);
	NewGameList.Add(SNew(SSlAiMenuItemWidget).ItemText(NSLOCTEXT("SlAiMenu", "EnterGame", "EnterGame")).ItemType(EMenuItem::EnterGame).OnClicked(this, &SSlAiMenuWidget::MenuItemOnClicked));
	NewGameList.Add(SNew(SSlAiMenuItemWidget).ItemText(NSLOCTEXT("SlAiMenu", "GoBack", "GoBack")).ItemType(EMenuItem::NewGameGoBack).OnClicked(this, &SSlAiMenuWidget::MenuItemOnClicked));

	MenuMap.Add(EMenuType::NewGame, MakeShareable(new MenuGroup(NSLOCTEXT("SlAiMenu", "NewGame", "NewGame"), 510.f, &NewGameList)));


	//选择存档界面
	TArray<TSharedPtr<SCompoundWidget>> ChooseRecordList;
	SAssignNew(ChooseRecordWidget, SSlAiChooseRecordWidget);
	ChooseRecordList.Add(ChooseRecordWidget);
	ChooseRecordList.Add(SNew(SSlAiMenuItemWidget).ItemText(NSLOCTEXT("SlAiMenu", "EnterRecord", "EnterRecord")).ItemType(EMenuItem::EnterRecord).OnClicked(this, &SSlAiMenuWidget::MenuItemOnClicked));
	ChooseRecordList.Add(SNew(SSlAiMenuItemWidget).ItemText(NSLOCTEXT("SlAiMenu", "GoBack", "GoBack")).ItemType(EMenuItem::ChooseRecordGoBack).OnClicked(this, &SSlAiMenuWidget::MenuItemOnClicked));

	MenuMap.Add(EMenuType::ChooseRecord, MakeShareable(new MenuGroup(NSLOCTEXT("SlAiMenu", "LoadRecord", "LoadRecord"), 510.f, &ChooseRecordList)));


	ChooseWidget(EMenuType::MainMenu);

}

void SSlAiMenuWidget::ChooseWidget(EMenuType::Type WidgetType)
{
	//移出所有组件
	ContentBox->ClearChildren();
	//如果Menutype是None
	if (WidgetType == EMenuType::None) return;
	//循环添加组件
	for (TArray<TSharedPtr<SCompoundWidget>>::TIterator It((*MenuMap.Find(WidgetType))->ChildWidget); It; ++It)
	{
		ContentBox->AddSlot().AutoHeight()[(*It)->AsShared()];
	}

	//更改标题
	TitleText->SetText((*MenuMap.Find(WidgetType))->MenuName);

	//修改Size
	ResetWidgetSize(600.f, (*MenuMap.Find(WidgetType))->MenuHeight);

}

//如果不修改高度,NewHeight传入-1
void SSlAiMenuWidget::ResetWidgetSize(float NewWidget, float NewHeight)
{

	RootSizeBox->SetWidthOverride(NewWidget);
	if (NewHeight < 0) return;
	RootSizeBox->SetHeightOverride(NewHeight);


}
