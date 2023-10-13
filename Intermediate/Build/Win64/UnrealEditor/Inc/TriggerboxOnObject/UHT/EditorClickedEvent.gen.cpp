// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "TriggerboxOnObject/Public/EditorClickedEvent.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeEditorClickedEvent() {}
// Cross Module References
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	TRIGGERBOXONOBJECT_API UClass* Z_Construct_UClass_AEditorClickedEvent();
	TRIGGERBOXONOBJECT_API UClass* Z_Construct_UClass_AEditorClickedEvent_NoRegister();
	UPackage* Z_Construct_UPackage__Script_TriggerboxOnObject();
// End Cross Module References
	void AEditorClickedEvent::StaticRegisterNativesAEditorClickedEvent()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AEditorClickedEvent);
	UClass* Z_Construct_UClass_AEditorClickedEvent_NoRegister()
	{
		return AEditorClickedEvent::StaticClass();
	}
	struct Z_Construct_UClass_AEditorClickedEvent_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AEditorClickedEvent_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_TriggerboxOnObject,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AEditorClickedEvent_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "EditorClickedEvent.h" },
		{ "ModuleRelativePath", "Public/EditorClickedEvent.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AEditorClickedEvent_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AEditorClickedEvent>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_AEditorClickedEvent_Statics::ClassParams = {
		&AEditorClickedEvent::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_AEditorClickedEvent_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AEditorClickedEvent_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AEditorClickedEvent()
	{
		if (!Z_Registration_Info_UClass_AEditorClickedEvent.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AEditorClickedEvent.OuterSingleton, Z_Construct_UClass_AEditorClickedEvent_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_AEditorClickedEvent.OuterSingleton;
	}
	template<> TRIGGERBOXONOBJECT_API UClass* StaticClass<AEditorClickedEvent>()
	{
		return AEditorClickedEvent::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(AEditorClickedEvent);
	AEditorClickedEvent::~AEditorClickedEvent() {}
	struct Z_CompiledInDeferFile_FID_HostProject_Plugins_TriggerboxOnObject_Source_TriggerboxOnObject_Public_EditorClickedEvent_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_HostProject_Plugins_TriggerboxOnObject_Source_TriggerboxOnObject_Public_EditorClickedEvent_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_AEditorClickedEvent, AEditorClickedEvent::StaticClass, TEXT("AEditorClickedEvent"), &Z_Registration_Info_UClass_AEditorClickedEvent, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AEditorClickedEvent), 2259392546U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_HostProject_Plugins_TriggerboxOnObject_Source_TriggerboxOnObject_Public_EditorClickedEvent_h_694522153(TEXT("/Script/TriggerboxOnObject"),
		Z_CompiledInDeferFile_FID_HostProject_Plugins_TriggerboxOnObject_Source_TriggerboxOnObject_Public_EditorClickedEvent_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_HostProject_Plugins_TriggerboxOnObject_Source_TriggerboxOnObject_Public_EditorClickedEvent_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
