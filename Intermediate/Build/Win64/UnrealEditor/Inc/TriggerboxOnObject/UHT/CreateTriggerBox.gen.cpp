// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "TriggerboxOnObject/TriggerBox/CreateTriggerBox.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeCreateTriggerBox() {}
// Cross Module References
	ENGINE_API UClass* Z_Construct_UClass_ATriggerBox();
	TRIGGERBOXONOBJECT_API UClass* Z_Construct_UClass_ACreateTriggerBox();
	TRIGGERBOXONOBJECT_API UClass* Z_Construct_UClass_ACreateTriggerBox_NoRegister();
	UPackage* Z_Construct_UPackage__Script_TriggerboxOnObject();
// End Cross Module References
	void ACreateTriggerBox::StaticRegisterNativesACreateTriggerBox()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ACreateTriggerBox);
	UClass* Z_Construct_UClass_ACreateTriggerBox_NoRegister()
	{
		return ACreateTriggerBox::StaticClass();
	}
	struct Z_Construct_UClass_ACreateTriggerBox_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ACreateTriggerBox_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_ATriggerBox,
		(UObject* (*)())Z_Construct_UPackage__Script_TriggerboxOnObject,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ACreateTriggerBox_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "IncludePath", "TriggerBox/CreateTriggerBox.h" },
		{ "ModuleRelativePath", "TriggerBox/CreateTriggerBox.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_ACreateTriggerBox_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ACreateTriggerBox>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_ACreateTriggerBox_Statics::ClassParams = {
		&ACreateTriggerBox::StaticClass,
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
		METADATA_PARAMS(Z_Construct_UClass_ACreateTriggerBox_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_ACreateTriggerBox_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ACreateTriggerBox()
	{
		if (!Z_Registration_Info_UClass_ACreateTriggerBox.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ACreateTriggerBox.OuterSingleton, Z_Construct_UClass_ACreateTriggerBox_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_ACreateTriggerBox.OuterSingleton;
	}
	template<> TRIGGERBOXONOBJECT_API UClass* StaticClass<ACreateTriggerBox>()
	{
		return ACreateTriggerBox::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(ACreateTriggerBox);
	ACreateTriggerBox::~ACreateTriggerBox() {}
	struct Z_CompiledInDeferFile_FID_HostProject_Plugins_TriggerboxOnObject_Source_TriggerboxOnObject_TriggerBox_CreateTriggerBox_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_HostProject_Plugins_TriggerboxOnObject_Source_TriggerboxOnObject_TriggerBox_CreateTriggerBox_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_ACreateTriggerBox, ACreateTriggerBox::StaticClass, TEXT("ACreateTriggerBox"), &Z_Registration_Info_UClass_ACreateTriggerBox, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ACreateTriggerBox), 2340182995U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_HostProject_Plugins_TriggerboxOnObject_Source_TriggerboxOnObject_TriggerBox_CreateTriggerBox_h_4168485234(TEXT("/Script/TriggerboxOnObject"),
		Z_CompiledInDeferFile_FID_HostProject_Plugins_TriggerboxOnObject_Source_TriggerboxOnObject_TriggerBox_CreateTriggerBox_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_HostProject_Plugins_TriggerboxOnObject_Source_TriggerboxOnObject_TriggerBox_CreateTriggerBox_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
