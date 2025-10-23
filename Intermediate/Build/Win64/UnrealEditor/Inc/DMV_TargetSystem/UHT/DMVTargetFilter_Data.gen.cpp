// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Filters/DMVTargetFilter_Data.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

void EmptyLinkFunctionForGeneratedCodeDMVTargetFilter_Data() {}

// ********** Begin Cross Module References ********************************************************
DMV_TARGETSYSTEM_API UClass* Z_Construct_UClass_UDMVTargetFilter_Base_NoRegister();
DMV_TARGETSYSTEM_API UClass* Z_Construct_UClass_UDMVTargetFilter_Data();
DMV_TARGETSYSTEM_API UClass* Z_Construct_UClass_UDMVTargetFilter_Data_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UDataAsset();
UPackage* Z_Construct_UPackage__Script_DMV_TargetSystem();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UDMVTargetFilter_Data ****************************************************
void UDMVTargetFilter_Data::StaticRegisterNativesUDMVTargetFilter_Data()
{
}
FClassRegistrationInfo Z_Registration_Info_UClass_UDMVTargetFilter_Data;
UClass* UDMVTargetFilter_Data::GetPrivateStaticClass()
{
	using TClass = UDMVTargetFilter_Data;
	if (!Z_Registration_Info_UClass_UDMVTargetFilter_Data.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			StaticPackage(),
			TEXT("DMVTargetFilter_Data"),
			Z_Registration_Info_UClass_UDMVTargetFilter_Data.InnerSingleton,
			StaticRegisterNativesUDMVTargetFilter_Data,
			sizeof(TClass),
			alignof(TClass),
			TClass::StaticClassFlags,
			TClass::StaticClassCastFlags(),
			TClass::StaticConfigName(),
			(UClass::ClassConstructorType)InternalConstructor<TClass>,
			(UClass::ClassVTableHelperCtorCallerType)InternalVTableHelperCtorCaller<TClass>,
			UOBJECT_CPPCLASS_STATICFUNCTIONS_FORCLASS(TClass),
			&TClass::Super::StaticClass,
			&TClass::WithinClass::StaticClass
		);
	}
	return Z_Registration_Info_UClass_UDMVTargetFilter_Data.InnerSingleton;
}
UClass* Z_Construct_UClass_UDMVTargetFilter_Data_NoRegister()
{
	return UDMVTargetFilter_Data::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UDMVTargetFilter_Data_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * This class is used so designers don't have to use the main character controller to set new filters\n * This allows for many developers to work on different targetings at the same time.\n */" },
#endif
		{ "IncludePath", "Filters/DMVTargetFilter_Data.h" },
		{ "ModuleRelativePath", "Public/Filters/DMVTargetFilter_Data.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "This class is used so designers don't have to use the main character controller to set new filters\nThis allows for many developers to work on different targetings at the same time." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FilterList_Inner_MetaData[] = {
		{ "Category", "Filters List" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Filters/DMVTargetFilter_Data.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FilterList_MetaData[] = {
		{ "Category", "Filters List" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Filters/DMVTargetFilter_Data.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_FilterList_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_FilterList;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UDMVTargetFilter_Data>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UDMVTargetFilter_Data_Statics::NewProp_FilterList_Inner = { "FilterList", nullptr, (EPropertyFlags)0x0002000000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_UDMVTargetFilter_Base_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FilterList_Inner_MetaData), NewProp_FilterList_Inner_MetaData) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UDMVTargetFilter_Data_Statics::NewProp_FilterList = { "FilterList", nullptr, (EPropertyFlags)0x0010008000000009, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDMVTargetFilter_Data, FilterList), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FilterList_MetaData), NewProp_FilterList_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UDMVTargetFilter_Data_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDMVTargetFilter_Data_Statics::NewProp_FilterList_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDMVTargetFilter_Data_Statics::NewProp_FilterList,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UDMVTargetFilter_Data_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UDMVTargetFilter_Data_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UDataAsset,
	(UObject* (*)())Z_Construct_UPackage__Script_DMV_TargetSystem,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UDMVTargetFilter_Data_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UDMVTargetFilter_Data_Statics::ClassParams = {
	&UDMVTargetFilter_Data::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_UDMVTargetFilter_Data_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_UDMVTargetFilter_Data_Statics::PropPointers),
	0,
	0x009000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UDMVTargetFilter_Data_Statics::Class_MetaDataParams), Z_Construct_UClass_UDMVTargetFilter_Data_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UDMVTargetFilter_Data()
{
	if (!Z_Registration_Info_UClass_UDMVTargetFilter_Data.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UDMVTargetFilter_Data.OuterSingleton, Z_Construct_UClass_UDMVTargetFilter_Data_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UDMVTargetFilter_Data.OuterSingleton;
}
UDMVTargetFilter_Data::UDMVTargetFilter_Data(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UDMVTargetFilter_Data);
UDMVTargetFilter_Data::~UDMVTargetFilter_Data() {}
// ********** End Class UDMVTargetFilter_Data ******************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_WRH_proj_5_6_Plugins_DMV_TargetSystem_Source_DMV_TargetSystem_Public_Filters_DMVTargetFilter_Data_h__Script_DMV_TargetSystem_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UDMVTargetFilter_Data, UDMVTargetFilter_Data::StaticClass, TEXT("UDMVTargetFilter_Data"), &Z_Registration_Info_UClass_UDMVTargetFilter_Data, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UDMVTargetFilter_Data), 3080538159U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_WRH_proj_5_6_Plugins_DMV_TargetSystem_Source_DMV_TargetSystem_Public_Filters_DMVTargetFilter_Data_h__Script_DMV_TargetSystem_1485929606(TEXT("/Script/DMV_TargetSystem"),
	Z_CompiledInDeferFile_FID_WRH_proj_5_6_Plugins_DMV_TargetSystem_Source_DMV_TargetSystem_Public_Filters_DMVTargetFilter_Data_h__Script_DMV_TargetSystem_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_WRH_proj_5_6_Plugins_DMV_TargetSystem_Source_DMV_TargetSystem_Public_Filters_DMVTargetFilter_Data_h__Script_DMV_TargetSystem_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
