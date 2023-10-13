// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */
class TRIGGERBOXONOBJECT_API CustomIDEditableTextBox :public SEditableTextBox
{
public:
	CustomIDEditableTextBox();
	~CustomIDEditableTextBox();

	int32 ID;
	int32 GetTextID() const {return ID;};
};
