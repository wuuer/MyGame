// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "SlAiTypes.h"
#include "Widgets/SCompoundWidget.h"



class SBox;
class STextBlock;
class SVerticalBox;


struct MenuGroup;
class SSlAiGameOptionWidget;
class SSlAiNewGameWidget;
class SSlAiChooseRecordWidget;



//Ĭ������

class MYGAME_API SSlAiMenuWidget : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SSlAiMenuWidget)
	{}



	SLATE_END_ARGS()

	// Constructs this widget with InArgs Ĭ������
	void Construct(const FArguments& InArgs);



private:

	//�󶨴�����MenuItem�ķ���
	void MenuItemOnClicked(EMenuItem::Type ItemType);
	//�޸�����
	void ChangeCulture(ECultureTeam culture);
	//�޸�����
	void ChangeVolume(const float MusicVolume,const float SoundVolume);
	//��ʼ�����пؼ�
	void InitializedMenuList();
	//ѡ����ʾ�Ľ���
	void ChooseWidget(EMenuType::Type WidgetType);
	//�޸Ĳ˵��Ĵ�С
	void ResetWidgetSize(float NewWidget, float NewHeight);


private:


	//��ȡMenu��ʽ
	const struct FSlAiMenuStyle *MenuStyle;

	//������ڵ�
	TSharedPtr<SBox>RootSizeBox;

	//�������
	TSharedPtr<STextBlock>TitleText;
	//�������洹ֱ�б�
	TSharedPtr<SVerticalBox>ContentBox;
	//����˵���
	TMap<EMenuType::Type, TSharedPtr<MenuGroup>>MenuMap;
	//��Ϸ����Widget��ָ��
	TSharedPtr<SSlAiGameOptionWidget>GameOptionWidget;
	//����Ϸ�ؼ�ָ��
	TSharedPtr<SSlAiNewGameWidget>NewGameWidget;
	//ѡ��浵�ؼ�ָ��
	TSharedPtr<SSlAiChooseRecordWidget>ChooseRecordWidget;

};
