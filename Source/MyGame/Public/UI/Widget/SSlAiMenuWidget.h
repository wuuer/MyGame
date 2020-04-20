// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "SlAiTypes.h"
#include "Widgets/SCompoundWidget.h"



class SBox;
class STextBlock;
class SVerticalBox;



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



private:


	//������ڵ�
	TSharedPtr<SBox>RootSizeBox;
	//��ȡMenu��ʽ
	const struct FSlAiMenuStyle *MenuStyle;
	//�������
	TSharedPtr<STextBlock>TitleText;
	//�������洹ֱ�б�
	TSharedPtr<SVerticalBox>ContentBox;




};
