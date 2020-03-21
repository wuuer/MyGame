// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Styling/SlateWidgetStyle.h"
#include "SlateWidgetStyleContainerBase.h"
#include "SlateBrush.h"//引入笔刷头文件
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





	UPROPERTY(EditAnywhere, Category = "MenuHud")//创建笔刷
		FSlateBrush MenuHudBackGroupBrush;

	UPROPERTY(EditAnywhere, Category = "Menu")//创建笔刷
		FSlateBrush MenuBackGroupBrush;

	UPROPERTY(EditAnywhere, Category = "Menu")//创建笔刷
		FSlateBrush LeftIconBrush;

	UPROPERTY(EditAnywhere, Category = "Menu")//创建笔刷
		FSlateBrush RightIconBrush;

	UPROPERTY(EditAnywhere, Category = "Menu")//创建笔刷
		FSlateBrush TitleBorderBrush;

	UPROPERTY(EditAnywhere, Category = "MenuItem")//创建笔刷
		FSlateBrush MenuItemBrush;




	//字体大小
	UPROPERTY(EditAnywhere, Category = "Common")
		FSlateFontInfo Font_60;

	UPROPERTY(EditAnywhere, Category = "Common")
		FSlateFontInfo Font_40;

	UPROPERTY(EditAnywhere, Category = "Common")
		FSlateFontInfo Font_30;

	//黑色颜色
	UPROPERTY(EditAnywhere, Category = "Common")
		FLinearColor FontColor_white;
	//白色颜色
	UPROPERTY(EditAnywhere, Category = "Common")
		FLinearColor FontColor_Black;








	//创建GameOption背景
	UPROPERTY(EditAnywhere, Category = "GameOption")
		FSlateBrush GameOptionBrush;

	//CheckBox的Brush被选中
	UPROPERTY(EditAnywhere, Category = "GameOption")
		FSlateBrush CheckedBoxBrush;
	//CheckBox的Brush不被选中
	UPROPERTY(EditAnywhere, Category = "GameOption")
		FSlateBrush UnCheckedBoxBrush;

	//Slider的背景Brush
	UPROPERTY(EditAnywhere, Category = "GameOption")
		FSlateBrush SliderBarBrush;



	//Slider的样式
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

