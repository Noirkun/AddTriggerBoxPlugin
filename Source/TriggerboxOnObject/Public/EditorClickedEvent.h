// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TriggerboxOnObject/TriggerBox/CreateTriggerBox.h"
#include "CustomIDEditableTextBox.h"
#include "EditorClickedEvent.generated.h"

DECLARE_DELEGATE(FAddButtonClicked);

struct SelectObjectStruct
{
	FText DisplayName;
	AActor* SelectObject;
};


UCLASS()
class TRIGGERBOXONOBJECT_API AEditorClickedEvent : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AEditorClickedEvent();

#if WITH_EDITORONLY_DATA
	void OnObjectSelected(UObject* Object);
	inline static TArray<UObject*> SelectedObjects;
	inline static TArray<SelectObjectStruct> SelectActors;
	inline static int32 SelectActorsNum;
	inline static TSharedPtr<SVerticalBox> VerticalBox;
	inline static TArray<FText> SetActorName;

	TSharedPtr<CustomIDEditableTextBox> SelectEditable;
	TWeakPtr<SEditableTextBox> InputBoxWidget;
	TArray<TSharedPtr<CustomIDEditableTextBox>> CustomEditableTextBox;
	TArray<int32> EditableTextBoxNum;

	FAddButtonClicked AddButtonClicked;
	
	static FText GetDisplayName(int size){return SelectActors[size].DisplayName;};
	static AActor* GetSelectObject(int size){return SelectActors[size].SelectObject;};
#endif
};
