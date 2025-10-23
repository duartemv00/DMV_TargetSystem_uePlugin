// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "DMVTargetComponent.h"
#include "GameplayTagContainer.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

void EmptyLinkFunctionForGeneratedCodeDMVTargetComponent() {}

// ********** Begin Cross Module References ********************************************************
DMV_TARGETSYSTEM_API UClass* Z_Construct_UClass_UDMVTargetComponent();
DMV_TARGETSYSTEM_API UClass* Z_Construct_UClass_UDMVTargetComponent_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_USceneComponent();
GAMEPLAYTAGS_API UScriptStruct* Z_Construct_UScriptStruct_FGameplayTagContainer();
UPackage* Z_Construct_UPackage__Script_DMV_TargetSystem();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UDMVTargetComponent Function ResetInterest *******************************
struct Z_Construct_UFunction_UDMVTargetComponent_ResetInterest_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/DMVTargetComponent.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDMVTargetComponent_ResetInterest_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UDMVTargetComponent, nullptr, "ResetInterest", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00080401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDMVTargetComponent_ResetInterest_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDMVTargetComponent_ResetInterest_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_UDMVTargetComponent_ResetInterest()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDMVTargetComponent_ResetInterest_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UDMVTargetComponent::execResetInterest)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ResetInterest();
	P_NATIVE_END;
}
// ********** End Class UDMVTargetComponent Function ResetInterest *********************************

// ********** Begin Class UDMVTargetComponent ******************************************************
void UDMVTargetComponent::StaticRegisterNativesUDMVTargetComponent()
{
	UClass* Class = UDMVTargetComponent::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "ResetInterest", &UDMVTargetComponent::execResetInterest },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
FClassRegistrationInfo Z_Registration_Info_UClass_UDMVTargetComponent;
UClass* UDMVTargetComponent::GetPrivateStaticClass()
{
	using TClass = UDMVTargetComponent;
	if (!Z_Registration_Info_UClass_UDMVTargetComponent.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			StaticPackage(),
			TEXT("DMVTargetComponent"),
			Z_Registration_Info_UClass_UDMVTargetComponent.InnerSingleton,
			StaticRegisterNativesUDMVTargetComponent,
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
	return Z_Registration_Info_UClass_UDMVTargetComponent.InnerSingleton;
}
UClass* Z_Construct_UClass_UDMVTargetComponent_NoRegister()
{
	return UDMVTargetComponent::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UDMVTargetComponent_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "BlueprintType", "true" },
		{ "ClassGroupNames", "Custom" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Scene Component which registers as a potential target for player auto-targeting. Derived classes can be created with additional functionality.\n */" },
#endif
		{ "HideCategories", "Trigger PhysicsVolume" },
		{ "IncludePath", "DMVTargetComponent.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/DMVTargetComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Scene Component which registers as a potential target for player auto-targeting. Derived classes can be created with additional functionality." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_BaseInterest_MetaData[] = {
		{ "Category", "DMVTargetComponent" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// INTEREST //\n" },
#endif
		{ "ModuleRelativePath", "Public/DMVTargetComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "INTEREST" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Interest_MetaData[] = {
		{ "ModuleRelativePath", "Public/DMVTargetComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TargetContextIdentifiers_MetaData[] = {
		{ "Categories", "ID.TargetEvaluationContext" },
		{ "Category", "Targeting" },
		{ "ModuleRelativePath", "Public/DMVTargetComponent.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFloatPropertyParams NewProp_BaseInterest;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Interest;
	static const UECodeGen_Private::FStructPropertyParams NewProp_TargetContextIdentifiers;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UDMVTargetComponent_ResetInterest, "ResetInterest" }, // 3171392322
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UDMVTargetComponent>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UDMVTargetComponent_Statics::NewProp_BaseInterest = { "BaseInterest", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDMVTargetComponent, BaseInterest), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_BaseInterest_MetaData), NewProp_BaseInterest_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UDMVTargetComponent_Statics::NewProp_Interest = { "Interest", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDMVTargetComponent, Interest), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Interest_MetaData), NewProp_Interest_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UDMVTargetComponent_Statics::NewProp_TargetContextIdentifiers = { "TargetContextIdentifiers", nullptr, (EPropertyFlags)0x0020080000010015, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDMVTargetComponent, TargetContextIdentifiers), Z_Construct_UScriptStruct_FGameplayTagContainer, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TargetContextIdentifiers_MetaData), NewProp_TargetContextIdentifiers_MetaData) }; // 2104890724
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UDMVTargetComponent_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDMVTargetComponent_Statics::NewProp_BaseInterest,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDMVTargetComponent_Statics::NewProp_Interest,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDMVTargetComponent_Statics::NewProp_TargetContextIdentifiers,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UDMVTargetComponent_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UDMVTargetComponent_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_USceneComponent,
	(UObject* (*)())Z_Construct_UPackage__Script_DMV_TargetSystem,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UDMVTargetComponent_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UDMVTargetComponent_Statics::ClassParams = {
	&UDMVTargetComponent::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_UDMVTargetComponent_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_UDMVTargetComponent_Statics::PropPointers),
	0,
	0x00B000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UDMVTargetComponent_Statics::Class_MetaDataParams), Z_Construct_UClass_UDMVTargetComponent_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UDMVTargetComponent()
{
	if (!Z_Registration_Info_UClass_UDMVTargetComponent.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UDMVTargetComponent.OuterSingleton, Z_Construct_UClass_UDMVTargetComponent_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UDMVTargetComponent.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR(UDMVTargetComponent);
UDMVTargetComponent::~UDMVTargetComponent() {}
// ********** End Class UDMVTargetComponent ********************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_WRH_proj_5_6_Plugins_DMV_TargetSystem_Source_DMV_TargetSystem_Public_DMVTargetComponent_h__Script_DMV_TargetSystem_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UDMVTargetComponent, UDMVTargetComponent::StaticClass, TEXT("UDMVTargetComponent"), &Z_Registration_Info_UClass_UDMVTargetComponent, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UDMVTargetComponent), 105053376U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_WRH_proj_5_6_Plugins_DMV_TargetSystem_Source_DMV_TargetSystem_Public_DMVTargetComponent_h__Script_DMV_TargetSystem_3239918436(TEXT("/Script/DMV_TargetSystem"),
	Z_CompiledInDeferFile_FID_WRH_proj_5_6_Plugins_DMV_TargetSystem_Source_DMV_TargetSystem_Public_DMVTargetComponent_h__Script_DMV_TargetSystem_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_WRH_proj_5_6_Plugins_DMV_TargetSystem_Source_DMV_TargetSystem_Public_DMVTargetComponent_h__Script_DMV_TargetSystem_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
