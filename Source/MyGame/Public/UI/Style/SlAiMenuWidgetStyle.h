// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Styling/SlateWidgetStyle.h"
#include "SlateWidgetStyleContainerBase.h"
#include "SlateBrush.h"//�����ˢͷ�ļ�
#include "Fonts/SlateFontInfo.h"
#include "SlateFontInfo.h"
#include "SlateTypes.h"



#include "SlAiMenuWidgetStyle.generated.h"






/**
 * 
 */
USTRUCT()
struct MYGAME_API FSlAiMenuStyle : public FSlateWidgetStyle
{
	GENERATED_USTRUCT_BODY()

	FSlAiMenuStyle();
	virtual ~FSlAiMenuStyle();

	// FSlateWidgetStyle
	virtual void GetResources(TArray<const FSlateBrush*>& OutBrushes) const override;
	static const FName TypeName;
	virtual const FName GetTypeName() const override { return TypeName; };
	static const FSlAiMenuStyle& GetDefault();





	UPROPERTY(EditAnywhere, Category = "MenuHud")//������ˢ
		FSlateBrush MenuHudBackGroupBrush;

	UPROPERTY(EditAnywhere, Category = "Menu")//������ˢ
		FSlateBrush MenuBackGroupBrush;

	UPROPERTY(EditAnywhere, Category = "Menu")//������ˢ
		FSlateBrush LeftIconBrush;

	UPROPERTY(EditAnywhere, Category = "Menu")//������ˢ
		FSlateBrush RightIconBrush;

	UPROPERTY(EditAnywhere, Category = "Menu")//������ˢ
		FSlateBrush TitleBorderBrush;

	UPROPERTY(EditAnywhere, Category = "MenuItem")//������ˢ
		FSlateBrush MenuItemBrush;




	//�����С
	UPROPERTY(EditAnywhere, Category = "Common")
		FSlateFontInfo Font_60;

	UPROPERTY(EditAnywhere, Category = "Common")
		FSlateFontInfo Font_40;

	UPROPERTY(EditAnywhere, Category = "Common")
		FSlateFontInfo Font_30;

	//��ɫ��ɫ
	UPROPERTY(EditAnywhere, Category = "Common")
		FLinearColor FontColor_white;
	//��ɫ��ɫ
	UPROPERTY(EditAnywhere, Category = "Common")
		FLinearColor FontColor_Black;








	//����GameOption����
	UPROPERTY(EditAnywhere, Category = "GameOption")
		FSlateBrush GameOptionBrush;

	//CheckBox��Brush��ѡ��
	UPROPERTY(EditAnywhere, Category = "GameOption")
		FSlateBrush CheckedBoxBrush;
	//CheckBox��Brush����ѡ��
	UPROPERTY(EditAnywhere, Category = "GameOption")
		FSlateBrush UnCheckedBoxBrush;

	//Slider�ı���Brush
	UPROPERTY(EditAnywhere, Category = "GameOption")
		FSlateBrush SliderBarBrush;



	//Slider����ʽ
	UPROPERTY(EditAnywhere, Category = "GameOption")
		FSliderStyle SliderStyle;






};




/**
 */
UCLASS(hidecategories=Object, MinimalAPI)
class USlAiMenuWidgetStyle : public USlateWidgetStyleContainerBase
{
	GENERATED_BODY()

public:
	/** The actual data describing the widget appearance. */
	UPROPERTY(Category=Appearance, EditAnywhere, meta=(ShowOnlyInnerProperties))
	FSlAiMenuStyle WidgetStyle;

	virtual const struct FSlateWidgetStyle* const GetStyle() const override
	{
		return static_cast< const struct FSlateWidgetStyle* >( &WidgetStyle );
	}
};

