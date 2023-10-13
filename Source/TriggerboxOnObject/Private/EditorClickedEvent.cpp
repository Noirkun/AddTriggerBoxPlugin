// Fill out your copyright notice in the Description page of Project Settings.

#include "EditorClickedEvent.h"
#include "Selection.h"


// Sets default values
AEditorClickedEvent::AEditorClickedEvent()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick . bCanEverTick = true;

#if WITH_EDITORONLY_DATA
	USelection::SelectObjectEvent . AddUObject(this, &AEditorClickedEvent::OnObjectSelected);
#endif
}

#if WITH_EDITORONLY_DATA
void AEditorClickedEvent::OnObjectSelected(UObject* Object)
{
	if (VerticalBox.IsValid())
	{
		//トリガーボックス追加のボタン
		VerticalBox -> ClearChildren();
		VerticalBox -> AddSlot()
		.AutoHeight()
		[
			SNew(SButton)
						. Text(FText::FromString("Create TriggerBox"))
						. OnClicked_Lambda([this]()
			             {
				             if (AddButtonClicked.IsBound())
				             {
					             AddButtonClicked.Execute();
				             }
				             return FReply::Handled();
			             })

		];
	}

	if(!SetActorName.IsEmpty())	//オブジェクトが選択された際に一度中身を空にする
	{
		SetActorName.Empty();
		CustomEditableTextBox.Empty();
	}
	
	SelectActors.Empty();
	//UE_LOG(LogTemp, Log, TEXT("%s::OnObjectSelected(): %s was %s."), *GetName(), *Object->GetName(),
		// *FString(Object->IsSelected() ? "selected" : "de-selected"));
	
	//SelectedObjectにエディターで選択したUObjectを格納
	GEditor -> GetSelectedActors() -> GetSelectedObjects(AActor::StaticClass(), SelectedObjects);
	SelectActorsNum = SelectedObjects.Num();	//選択してるUObjectの数

	for (int32 i = 0; i < SelectedObjects.Num(); ++i)
	{
		//UE_LOG(LogTemp, Log, TEXT("SelectActorsNum:%d,SelectedObjects.Num():%d"), SelectActorsNum,SelectedObjects.Num());

		AActor* SelectObject = Cast<AActor, UObject>(SelectedObjects[i]);
		SelectObjectStruct SelectActor = {FText::FromString(*SelectObject -> GetActorLabel()), SelectObject};
		SelectActors.Emplace(SelectActor);
		//UE_LOG(LogTemp, Log, TEXT("アクターの名前:%s,配列のサイズ:%d"), *SelectObject->GetActorLabel(), i);

		SetActorName.SetNum(SelectedObjects.Num());
		//UE_LOG(LogTemp, Log, TEXT("配列のサイズ:%d"), SetActorName.Num());
		

		if (VerticalBox.IsValid())
		{
			//UE_LOG(LogTemp, Log, TEXT("クリエイト!!"));
			VerticalBox -> AddSlot()
			. AutoHeight()
			[
				SNew(SBorder)
				[
					SNew(SHorizontalBox)
					+ SHorizontalBox::Slot()
					[
					SNew(STextBlock)
					. Text(FText::FromString(*SelectObject -> GetActorLabel()))
					]
					+ SHorizontalBox::Slot()
					[
					SAssignNew(SelectEditable,CustomIDEditableTextBox)
					.HintText(FText::FromString("TriggerBox Name"))
					.OnTextChanged_Lambda([this,i](const FText& InText)//各ループのiをキャプチャ
					{
						if (SelectEditable.IsValid() && CustomEditableTextBox.IsValidIndex(i))
							CustomEditableTextBox[i]->SetText(InText);
							
						if(SetActorName.IsEmpty())
							return;

							SetActorName[i]=InText;
						})
					]
				]
			];
			CustomEditableTextBox.Emplace(SelectEditable);
			EditableTextBoxNum.Emplace(CustomEditableTextBox[i].Get()->GetTextID());
			//	UE_LOG(LogTemp, Log, TEXT("Editableのサイズ:%d"), CustomEditableTextBox.Num());
			
		}

	}

	AddButtonClicked.BindLambda([this]
	{
		for (int i = 0; i < SelectActorsNum; i++)
		{
			if (!GetSelectObject(i))
			{
				UE_LOG(LogTemp, Log, TEXT("ObjectData:Null"));
			}
			const UWorld* World = GetSelectObject(i) -> GetWorld();
			ACreateTriggerBox* AttachTriggerBox = World -> GetWorld() -> SpawnActor<ACreateTriggerBox>(
				ACreateTriggerBox::StaticClass(), FVector(0, 0, 0), FRotator(0, 0, 0));

			AttachTriggerBox -> AttachToComponent(GetSelectObject(i) -> GetRootComponent(),
			                                      FAttachmentTransformRules::SnapToTargetIncludingScale);
			if(!SetActorName.IsEmpty())
				AttachTriggerBox->SetActorLabel(SetActorName[i].ToString());
			else
				AttachTriggerBox->SetActorLabel("CreateTriggerBox");

			UE_LOG(LogTemp, Log, TEXT("Attach TriggerBox:%s"), *GetSelectObject(i)->GetActorLabel());
		}
	});
}

#endif
