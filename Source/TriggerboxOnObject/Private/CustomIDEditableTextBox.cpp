// Fill out your copyright notice in the Description page of Project Settings.


#include "CustomIDEditableTextBox.h"

CustomIDEditableTextBox::CustomIDEditableTextBox()
{
	srand(time(nullptr));
	ID=rand();
}

CustomIDEditableTextBox::~CustomIDEditableTextBox()
{
}
