#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EditorClickedEvent.generated.h"

DECLARE_DELEGATE(FAddButtonClicked);

// オブジェクトを選択したときに情報を格納する構造体
struct SelectObjectStruct
{
	FText DisplayName;
	AActor* SelectObject;
};

class ACreateTriggerBox;

UCLASS()
class TRIGGERBOXONOBJECT_API AEditorClickedEvent : public AActor
{
	GENERATED_BODY()
	
public:	
	AEditorClickedEvent();

#if WITH_EDITORONLY_DATA
	// オブジェクトを選択したときに呼び出される関数
	void OnObjectSelected(UObject* Object);
	// 選択したオブジェクトのウィジェットを作成する関数
	void CreateSelectObjectsWidget();
	// 生成ボタンがクリックされたときに呼び出される関数
	void CreateButtonClicked();
	
	// エディターで選択したオブジェクトを格納する配列
	inline static TArray<UObject*> SelectedObjects;
	inline static TArray<SelectObjectStruct> SelectActors;
	inline static int32 SelectActorsNum;
	inline static TSharedPtr<SVerticalBox> VerticalBox;
	inline static TArray<FText> SetActorName;

	// 文字を入力するTextBoxの変数
	TSharedPtr<SEditableTextBox> SelectEditable;

	// ボタンがクリックされたときに実行されるデリゲート
	FAddButtonClicked AddButtonClicked;
	
	static FText GetDisplayName(int size){return SelectActors[size].DisplayName;};
	static AActor* GetSelectObject(int size){return SelectActors[size].SelectObject;};
#endif
};
