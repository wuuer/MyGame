// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */


UENUM()
enum class ECultureTeam : uint8 {


	EN = 0,
	ZH = 1,

};


//Menu∞¥≈•¿‡–Õ
namespace EMenuItem
{

	enum Type
	{

		None,
		StartGame,
		GameOption,
		QuitGame,
		NewGame,
		LoadRecord,
		StartGameGoBack,
		GameOptionGoBack,
		NewGameGoBack,
		ChooseRecordGoBack,
		EnterGame,
		EnterRecord


	};

}
