#include "EditorClickedEvent.h"
#include "Engine/TriggerBox.h"
#include "Selection.h"


AEditorClickedEvent::AEditorClickedEvent()
{
	
	PrimaryActorTick . bCanEverTick = true;

#if WITH_EDITORONLY_DATA
	//エディターで選択したオブジェクトをUSelection::SelectObjectEventに登録
	USelection::SelectObjectEvent . AddUObject(this, &AEditorClickedEvent::OnObjectSelected);
#endif
}

#if WITH_EDITORONLY_DATA
void AEditorClickedEvent::OnObjectSelected(UObject* Object)
{
	if (VerticalBox.IsValid())
	{
		//トリガーボックスを作成するボタン
		VerticalBox -> ClearChildren();
		VerticalBox -> AddSlot()
		.AutoHeight()
		[
			SNew(SButton)
			. Text(FText::FromString("Create TriggerBox"))
			// ボタンがクリックされたときの処理をラムダ式で定義
			. OnClicked_Lambda([this]()
			{
				//デリゲートがバインドされていたら実行
				if (AddButtonClicked.IsBound())
				{
					AddButtonClicked.Execute();
				}
				return FReply::Handled();
			})
		];
	}

	//オブジェクトが選択された際に一度中身を空にする
	if(!SetActorName.IsEmpty())
	{
		SetActorName.Empty();
	}
	
	SelectActors.Empty();
	
	//SelectedObjectにエディターで選択したUObjectを格納
	GEditor -> GetSelectedActors() -> GetSelectedObjects(AActor::StaticClass(), SelectedObjects);
	SelectActorsNum = SelectedObjects.Num();

	// 選択したオブジェクトのウィジェットを作成
	CreateSelectObjectsWidget();

	// 生成ボタンがクリックされたときの処理
	CreateButtonClicked();

}

void AEditorClickedEvent::CreateSelectObjectsWidget()
{
	for (int32 i = 0; i < SelectedObjects.Num(); ++i)
	{
		// 選択したオブジェクトの情報を格納
		AActor* SelectObject = Cast<AActor, UObject>(SelectedObjects[i]);
		SelectObjectStruct SelectActor = {FText::FromString(*SelectObject -> GetActorLabel()), SelectObject};
		SelectActors.Emplace(SelectActor);
		SetActorName.SetNum(SelectedObjects.Num());
		
		if (VerticalBox.IsValid())
		{
			// 選択したオブジェクトの情報を表示するウィジェットを作成する
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
					SAssignNew(SelectEditable,SEditableTextBox)
					.HintText(FText::FromString("TriggerBox Name"))
					// テキストが変更されたときの処理をラムダ式で定義
					.OnTextChanged_Lambda([this,i](const FText& InText)
					{
						if(SetActorName.IsEmpty()){return;}
						
						SetActorName[i]=InText;
					})
					]
				]
			];
		}
	}
}

void AEditorClickedEvent::CreateButtonClicked()
{
	// ボタンがクリックされたときの処理をラムダ式でバインドする
	AddButtonClicked.BindLambda([this]
	{
		for (int i = 0; i < SelectActorsNum; i++)
		{
			// 選択したオブジェクトがnullだったらログを出力する
			if (!GetSelectObject(i))
			{
				UE_LOG(LogTemp, Log, TEXT("ObjectData:Null"));
			}
			const UWorld* World = GetSelectObject(i) -> GetWorld();
			// TriggerBoxを生成
			ATriggerBox* AttachTriggerBox = World -> GetWorld() -> SpawnActor<ATriggerBox>(
				ATriggerBox::StaticClass(), FVector(0, 0, 0), FRotator(0, 0, 0));
			// 選択したオブジェクトにTriggerBoxをアタッチする
			AttachTriggerBox -> AttachToComponent(GetSelectObject(i) -> GetRootComponent(),FAttachmentTransformRules::SnapToTargetIncludingScale);

			// 表示名が決められていなかったら"CreateTriggerBox"という名前を付ける
			if(!SetActorName[i].IsEmpty())
			{
				AttachTriggerBox->SetActorLabel(SetActorName[i].ToString());
			}
			else
			{
				AttachTriggerBox->SetActorLabel("CreateTriggerBox");
			}
		}
	});
}

#endif
