// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "DMVTargetEvaluator.h"
#include "GameplayTagContainer.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

void EmptyLinkFunctionForGeneratedCodeDMVTargetEvaluator() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
DMV_TARGETSYSTEM_API UClass* Z_Construct_UClass_UDMVTargetComponent_NoRegister();
DMV_TARGETSYSTEM_API UClass* Z_Construct_UClass_UDMVTargetEvaluator();
DMV_TARGETSYSTEM_API UClass* Z_Construct_UClass_UDMVTargetEvaluator_NoRegister();
DMV_TARGETSYSTEM_API UClass* Z_Construct_UClass_UDMVTargetFilter_Base_NoRegister();
DMV_TARGETSYSTEM_API UClass* Z_Construct_UClass_UXM_TargetEvaluationContext();
DMV_TARGETSYSTEM_API UClass* Z_Construct_UClass_UXM_TargetEvaluationContext_NoRegister();
DMV_TARGETSYSTEM_API UFunction* Z_Construct_UDelegateFunction_DMV_TargetSystem_FilteringFinished__DelegateSignature();
DMV_TARGETSYSTEM_API UFunction* Z_Construct_UDelegateFunction_DMV_TargetSystem_PlayerAutoTargetsCleared__DelegateSignature();
DMV_TARGETSYSTEM_API UFunction* Z_Construct_UDelegateFunction_DMV_TargetSystem_ValidPlayerAutoTargetFound__DelegateSignature();
DMV_TARGETSYSTEM_API UScriptStruct* Z_Construct_UScriptStruct_FEvaluationContexts();
DMV_TARGETSYSTEM_API UScriptStruct* Z_Construct_UScriptStruct_FEvaluationFilters();
DMV_TARGETSYSTEM_API UScriptStruct* Z_Construct_UScriptStruct_FFilterInformation();
DMV_TARGETSYSTEM_API UScriptStruct* Z_Construct_UScriptStruct_FTargetInputContext();
ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UActorComponent();
GAMEPLAYTAGS_API UScriptStruct* Z_Construct_UScriptStruct_FGameplayTag();
GAMEPLAYTAGS_API UScriptStruct* Z_Construct_UScriptStruct_FGameplayTagContainer();
UPackage* Z_Construct_UPackage__Script_DMV_TargetSystem();
// ********** End Cross Module References **********************************************************

// ********** Begin ScriptStruct FTargetInputContext ***********************************************
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FTargetInputContext;
class UScriptStruct* FTargetInputContext::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FTargetInputContext.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FTargetInputContext.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FTargetInputContext, (UObject*)Z_Construct_UPackage__Script_DMV_TargetSystem(), TEXT("TargetInputContext"));
	}
	return Z_Registration_Info_UScriptStruct_FTargetInputContext.OuterSingleton;
}
struct Z_Construct_UScriptStruct_FTargetInputContext_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/DMVTargetEvaluator.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TargetComponent_MetaData[] = {
		{ "Category", "TargetInputContext" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/DMVTargetEvaluator.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TargetActor_MetaData[] = {
		{ "Category", "TargetInputContext" },
		{ "ModuleRelativePath", "Public/DMVTargetEvaluator.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_TargetComponent;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_TargetActor;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FTargetInputContext>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FTargetInputContext_Statics::NewProp_TargetComponent = { "TargetComponent", nullptr, (EPropertyFlags)0x001000000008001c, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FTargetInputContext, TargetComponent), Z_Construct_UClass_UDMVTargetComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TargetComponent_MetaData), NewProp_TargetComponent_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FTargetInputContext_Statics::NewProp_TargetActor = { "TargetActor", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FTargetInputContext, TargetActor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TargetActor_MetaData), NewProp_TargetActor_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FTargetInputContext_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FTargetInputContext_Statics::NewProp_TargetComponent,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FTargetInputContext_Statics::NewProp_TargetActor,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FTargetInputContext_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FTargetInputContext_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_DMV_TargetSystem,
	nullptr,
	&NewStructOps,
	"TargetInputContext",
	Z_Construct_UScriptStruct_FTargetInputContext_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FTargetInputContext_Statics::PropPointers),
	sizeof(FTargetInputContext),
	alignof(FTargetInputContext),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000005),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FTargetInputContext_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FTargetInputContext_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FTargetInputContext()
{
	if (!Z_Registration_Info_UScriptStruct_FTargetInputContext.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FTargetInputContext.InnerSingleton, Z_Construct_UScriptStruct_FTargetInputContext_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_FTargetInputContext.InnerSingleton;
}
// ********** End ScriptStruct FTargetInputContext *************************************************

// ********** Begin Delegate FFilteringFinished ****************************************************
struct Z_Construct_UDelegateFunction_DMV_TargetSystem_FilteringFinished__DelegateSignature_Statics
{
	struct _Script_DMV_TargetSystem_eventFilteringFinished_Parms
	{
		UDMVTargetComponent* Targets;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** When the filters are done */" },
#endif
		{ "ModuleRelativePath", "Public/DMVTargetEvaluator.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "When the filters are done" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Targets_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Targets;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FDelegateFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UDelegateFunction_DMV_TargetSystem_FilteringFinished__DelegateSignature_Statics::NewProp_Targets = { "Targets", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_DMV_TargetSystem_eventFilteringFinished_Parms, Targets), Z_Construct_UClass_UDMVTargetComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Targets_MetaData), NewProp_Targets_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_DMV_TargetSystem_FilteringFinished__DelegateSignature_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_DMV_TargetSystem_FilteringFinished__DelegateSignature_Statics::NewProp_Targets,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_DMV_TargetSystem_FilteringFinished__DelegateSignature_Statics::PropPointers) < 2048);
const UECodeGen_Private::FDelegateFunctionParams Z_Construct_UDelegateFunction_DMV_TargetSystem_FilteringFinished__DelegateSignature_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UPackage__Script_DMV_TargetSystem, nullptr, "FilteringFinished__DelegateSignature", Z_Construct_UDelegateFunction_DMV_TargetSystem_FilteringFinished__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_DMV_TargetSystem_FilteringFinished__DelegateSignature_Statics::PropPointers), sizeof(Z_Construct_UDelegateFunction_DMV_TargetSystem_FilteringFinished__DelegateSignature_Statics::_Script_DMV_TargetSystem_eventFilteringFinished_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00120000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_DMV_TargetSystem_FilteringFinished__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_DMV_TargetSystem_FilteringFinished__DelegateSignature_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UDelegateFunction_DMV_TargetSystem_FilteringFinished__DelegateSignature_Statics::_Script_DMV_TargetSystem_eventFilteringFinished_Parms) < MAX_uint16);
UFunction* Z_Construct_UDelegateFunction_DMV_TargetSystem_FilteringFinished__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUDelegateFunction(&ReturnFunction, Z_Construct_UDelegateFunction_DMV_TargetSystem_FilteringFinished__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void FFilteringFinished_DelegateWrapper(const FScriptDelegate& FilteringFinished, UDMVTargetComponent* Targets)
{
	struct _Script_DMV_TargetSystem_eventFilteringFinished_Parms
	{
		UDMVTargetComponent* Targets;
	};
	_Script_DMV_TargetSystem_eventFilteringFinished_Parms Parms;
	Parms.Targets=Targets;
	FilteringFinished.ProcessDelegate<UObject>(&Parms);
}
// ********** End Delegate FFilteringFinished ******************************************************

// ********** Begin Delegate FValidPlayerAutoTargetFound *******************************************
struct Z_Construct_UDelegateFunction_DMV_TargetSystem_ValidPlayerAutoTargetFound__DelegateSignature_Statics
{
	struct _Script_DMV_TargetSystem_eventValidPlayerAutoTargetFound_Parms
	{
		AActor* Actor;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** When a valid target is selected */" },
#endif
		{ "ModuleRelativePath", "Public/DMVTargetEvaluator.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "When a valid target is selected" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Actor;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FDelegateFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UDelegateFunction_DMV_TargetSystem_ValidPlayerAutoTargetFound__DelegateSignature_Statics::NewProp_Actor = { "Actor", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_DMV_TargetSystem_eventValidPlayerAutoTargetFound_Parms, Actor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_DMV_TargetSystem_ValidPlayerAutoTargetFound__DelegateSignature_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_DMV_TargetSystem_ValidPlayerAutoTargetFound__DelegateSignature_Statics::NewProp_Actor,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_DMV_TargetSystem_ValidPlayerAutoTargetFound__DelegateSignature_Statics::PropPointers) < 2048);
const UECodeGen_Private::FDelegateFunctionParams Z_Construct_UDelegateFunction_DMV_TargetSystem_ValidPlayerAutoTargetFound__DelegateSignature_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UPackage__Script_DMV_TargetSystem, nullptr, "ValidPlayerAutoTargetFound__DelegateSignature", Z_Construct_UDelegateFunction_DMV_TargetSystem_ValidPlayerAutoTargetFound__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_DMV_TargetSystem_ValidPlayerAutoTargetFound__DelegateSignature_Statics::PropPointers), sizeof(Z_Construct_UDelegateFunction_DMV_TargetSystem_ValidPlayerAutoTargetFound__DelegateSignature_Statics::_Script_DMV_TargetSystem_eventValidPlayerAutoTargetFound_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00120000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_DMV_TargetSystem_ValidPlayerAutoTargetFound__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_DMV_TargetSystem_ValidPlayerAutoTargetFound__DelegateSignature_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UDelegateFunction_DMV_TargetSystem_ValidPlayerAutoTargetFound__DelegateSignature_Statics::_Script_DMV_TargetSystem_eventValidPlayerAutoTargetFound_Parms) < MAX_uint16);
UFunction* Z_Construct_UDelegateFunction_DMV_TargetSystem_ValidPlayerAutoTargetFound__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUDelegateFunction(&ReturnFunction, Z_Construct_UDelegateFunction_DMV_TargetSystem_ValidPlayerAutoTargetFound__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void FValidPlayerAutoTargetFound_DelegateWrapper(const FScriptDelegate& ValidPlayerAutoTargetFound, AActor* Actor)
{
	struct _Script_DMV_TargetSystem_eventValidPlayerAutoTargetFound_Parms
	{
		AActor* Actor;
	};
	_Script_DMV_TargetSystem_eventValidPlayerAutoTargetFound_Parms Parms;
	Parms.Actor=Actor;
	ValidPlayerAutoTargetFound.ProcessDelegate<UObject>(&Parms);
}
// ********** End Delegate FValidPlayerAutoTargetFound *********************************************

// ********** Begin Delegate FPlayerAutoTargetsCleared *********************************************
struct Z_Construct_UDelegateFunction_DMV_TargetSystem_PlayerAutoTargetsCleared__DelegateSignature_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** When all saved targets are deleted */" },
#endif
		{ "ModuleRelativePath", "Public/DMVTargetEvaluator.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "When all saved targets are deleted" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FDelegateFunctionParams FuncParams;
};
const UECodeGen_Private::FDelegateFunctionParams Z_Construct_UDelegateFunction_DMV_TargetSystem_PlayerAutoTargetsCleared__DelegateSignature_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UPackage__Script_DMV_TargetSystem, nullptr, "PlayerAutoTargetsCleared__DelegateSignature", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00120000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_DMV_TargetSystem_PlayerAutoTargetsCleared__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_DMV_TargetSystem_PlayerAutoTargetsCleared__DelegateSignature_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UDelegateFunction_DMV_TargetSystem_PlayerAutoTargetsCleared__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUDelegateFunction(&ReturnFunction, Z_Construct_UDelegateFunction_DMV_TargetSystem_PlayerAutoTargetsCleared__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void FPlayerAutoTargetsCleared_DelegateWrapper(const FScriptDelegate& PlayerAutoTargetsCleared)
{
	PlayerAutoTargetsCleared.ProcessDelegate<UObject>(NULL);
}
// ********** End Delegate FPlayerAutoTargetsCleared ***********************************************

// ********** Begin Class UXM_TargetEvaluationContext **********************************************
void UXM_TargetEvaluationContext::StaticRegisterNativesUXM_TargetEvaluationContext()
{
}
FClassRegistrationInfo Z_Registration_Info_UClass_UXM_TargetEvaluationContext;
UClass* UXM_TargetEvaluationContext::GetPrivateStaticClass()
{
	using TClass = UXM_TargetEvaluationContext;
	if (!Z_Registration_Info_UClass_UXM_TargetEvaluationContext.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			StaticPackage(),
			TEXT("XM_TargetEvaluationContext"),
			Z_Registration_Info_UClass_UXM_TargetEvaluationContext.InnerSingleton,
			StaticRegisterNativesUXM_TargetEvaluationContext,
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
	return Z_Registration_Info_UClass_UXM_TargetEvaluationContext.InnerSingleton;
}
UClass* Z_Construct_UClass_UXM_TargetEvaluationContext_NoRegister()
{
	return UXM_TargetEvaluationContext::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UXM_TargetEvaluationContext_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "ClassGroupNames", "Custom" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Object representing a targeting context,\n * which allows individual systems to register different requirements for target evaluation. */" },
#endif
		{ "IncludePath", "DMVTargetEvaluator.h" },
		{ "ModuleRelativePath", "Public/DMVTargetEvaluator.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Object representing a targeting context,\nwhich allows individual systems to register different requirements for target evaluation." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ContextIdentifier_MetaData[] = {
		{ "Categories", "ID.TargetEvaluationContext" },
		{ "Category", "XM_TargetEvaluationContext" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Id for the context. Must be unique from other contexts added to the same evaluator component. */" },
#endif
		{ "ModuleRelativePath", "Public/DMVTargetEvaluator.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Id for the context. Must be unique from other contexts added to the same evaluator component." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ParentContextIdentifier_MetaData[] = {
		{ "Categories", "ID.TargetEvaluationContext" },
		{ "Category", "XM_TargetEvaluationContext" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Id of the functional group of which the context is part\n\x09 * Can be shared between differnt contexts */" },
#endif
		{ "ModuleRelativePath", "Public/DMVTargetEvaluator.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Id of the functional group of which the context is part\nCan be shared between differnt contexts" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnValidTargetFound_MetaData[] = {
		{ "ModuleRelativePath", "Public/DMVTargetEvaluator.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnTargetCleared_MetaData[] = {
		{ "ModuleRelativePath", "Public/DMVTargetEvaluator.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnFilteringFinished_MetaData[] = {
		{ "ModuleRelativePath", "Public/DMVTargetEvaluator.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_ContextIdentifier;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ParentContextIdentifier;
	static const UECodeGen_Private::FDelegatePropertyParams NewProp_OnValidTargetFound;
	static const UECodeGen_Private::FDelegatePropertyParams NewProp_OnTargetCleared;
	static const UECodeGen_Private::FDelegatePropertyParams NewProp_OnFilteringFinished;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UXM_TargetEvaluationContext>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UXM_TargetEvaluationContext_Statics::NewProp_ContextIdentifier = { "ContextIdentifier", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UXM_TargetEvaluationContext, ContextIdentifier), Z_Construct_UScriptStruct_FGameplayTag, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ContextIdentifier_MetaData), NewProp_ContextIdentifier_MetaData) }; // 133831994
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UXM_TargetEvaluationContext_Statics::NewProp_ParentContextIdentifier = { "ParentContextIdentifier", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UXM_TargetEvaluationContext, ParentContextIdentifier), Z_Construct_UScriptStruct_FGameplayTag, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ParentContextIdentifier_MetaData), NewProp_ParentContextIdentifier_MetaData) }; // 133831994
const UECodeGen_Private::FDelegatePropertyParams Z_Construct_UClass_UXM_TargetEvaluationContext_Statics::NewProp_OnValidTargetFound = { "OnValidTargetFound", nullptr, (EPropertyFlags)0x0010000000080000, UECodeGen_Private::EPropertyGenFlags::Delegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UXM_TargetEvaluationContext, OnValidTargetFound), Z_Construct_UDelegateFunction_DMV_TargetSystem_ValidPlayerAutoTargetFound__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnValidTargetFound_MetaData), NewProp_OnValidTargetFound_MetaData) }; // 3756794100
const UECodeGen_Private::FDelegatePropertyParams Z_Construct_UClass_UXM_TargetEvaluationContext_Statics::NewProp_OnTargetCleared = { "OnTargetCleared", nullptr, (EPropertyFlags)0x0010000000080000, UECodeGen_Private::EPropertyGenFlags::Delegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UXM_TargetEvaluationContext, OnTargetCleared), Z_Construct_UDelegateFunction_DMV_TargetSystem_PlayerAutoTargetsCleared__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnTargetCleared_MetaData), NewProp_OnTargetCleared_MetaData) }; // 871069982
const UECodeGen_Private::FDelegatePropertyParams Z_Construct_UClass_UXM_TargetEvaluationContext_Statics::NewProp_OnFilteringFinished = { "OnFilteringFinished", nullptr, (EPropertyFlags)0x0010000000080000, UECodeGen_Private::EPropertyGenFlags::Delegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UXM_TargetEvaluationContext, OnFilteringFinished), Z_Construct_UDelegateFunction_DMV_TargetSystem_FilteringFinished__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnFilteringFinished_MetaData), NewProp_OnFilteringFinished_MetaData) }; // 1740310588
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UXM_TargetEvaluationContext_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UXM_TargetEvaluationContext_Statics::NewProp_ContextIdentifier,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UXM_TargetEvaluationContext_Statics::NewProp_ParentContextIdentifier,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UXM_TargetEvaluationContext_Statics::NewProp_OnValidTargetFound,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UXM_TargetEvaluationContext_Statics::NewProp_OnTargetCleared,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UXM_TargetEvaluationContext_Statics::NewProp_OnFilteringFinished,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UXM_TargetEvaluationContext_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UXM_TargetEvaluationContext_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UObject,
	(UObject* (*)())Z_Construct_UPackage__Script_DMV_TargetSystem,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UXM_TargetEvaluationContext_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UXM_TargetEvaluationContext_Statics::ClassParams = {
	&UXM_TargetEvaluationContext::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_UXM_TargetEvaluationContext_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_UXM_TargetEvaluationContext_Statics::PropPointers),
	0,
	0x009000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UXM_TargetEvaluationContext_Statics::Class_MetaDataParams), Z_Construct_UClass_UXM_TargetEvaluationContext_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UXM_TargetEvaluationContext()
{
	if (!Z_Registration_Info_UClass_UXM_TargetEvaluationContext.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UXM_TargetEvaluationContext.OuterSingleton, Z_Construct_UClass_UXM_TargetEvaluationContext_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UXM_TargetEvaluationContext.OuterSingleton;
}
UXM_TargetEvaluationContext::UXM_TargetEvaluationContext(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UXM_TargetEvaluationContext);
UXM_TargetEvaluationContext::~UXM_TargetEvaluationContext() {}
// ********** End Class UXM_TargetEvaluationContext ************************************************

// ********** Begin ScriptStruct FEvaluationContexts ***********************************************
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FEvaluationContexts;
class UScriptStruct* FEvaluationContexts::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FEvaluationContexts.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FEvaluationContexts.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FEvaluationContexts, (UObject*)Z_Construct_UPackage__Script_DMV_TargetSystem(), TEXT("EvaluationContexts"));
	}
	return Z_Registration_Info_UScriptStruct_FEvaluationContexts.OuterSingleton;
}
struct Z_Construct_UScriptStruct_FEvaluationContexts_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/DMVTargetEvaluator.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TargetEvaluationContexts_MetaData[] = {
		{ "Category", "EvaluationContexts" },
		{ "ModuleRelativePath", "Public/DMVTargetEvaluator.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_TargetEvaluationContexts_ValueProp;
	static const UECodeGen_Private::FStructPropertyParams NewProp_TargetEvaluationContexts_Key_KeyProp;
	static const UECodeGen_Private::FMapPropertyParams NewProp_TargetEvaluationContexts;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FEvaluationContexts>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FEvaluationContexts_Statics::NewProp_TargetEvaluationContexts_ValueProp = { "TargetEvaluationContexts", nullptr, (EPropertyFlags)0x0000000000000001, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 1, Z_Construct_UClass_UXM_TargetEvaluationContext_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FEvaluationContexts_Statics::NewProp_TargetEvaluationContexts_Key_KeyProp = { "TargetEvaluationContexts_Key", nullptr, (EPropertyFlags)0x0000000000000001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FGameplayTag, METADATA_PARAMS(0, nullptr) }; // 133831994
const UECodeGen_Private::FMapPropertyParams Z_Construct_UScriptStruct_FEvaluationContexts_Statics::NewProp_TargetEvaluationContexts = { "TargetEvaluationContexts", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Map, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FEvaluationContexts, TargetEvaluationContexts), EMapPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TargetEvaluationContexts_MetaData), NewProp_TargetEvaluationContexts_MetaData) }; // 133831994
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FEvaluationContexts_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FEvaluationContexts_Statics::NewProp_TargetEvaluationContexts_ValueProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FEvaluationContexts_Statics::NewProp_TargetEvaluationContexts_Key_KeyProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FEvaluationContexts_Statics::NewProp_TargetEvaluationContexts,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FEvaluationContexts_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FEvaluationContexts_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_DMV_TargetSystem,
	nullptr,
	&NewStructOps,
	"EvaluationContexts",
	Z_Construct_UScriptStruct_FEvaluationContexts_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FEvaluationContexts_Statics::PropPointers),
	sizeof(FEvaluationContexts),
	alignof(FEvaluationContexts),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FEvaluationContexts_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FEvaluationContexts_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FEvaluationContexts()
{
	if (!Z_Registration_Info_UScriptStruct_FEvaluationContexts.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FEvaluationContexts.InnerSingleton, Z_Construct_UScriptStruct_FEvaluationContexts_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_FEvaluationContexts.InnerSingleton;
}
// ********** End ScriptStruct FEvaluationContexts *************************************************

// ********** Begin ScriptStruct FFilterInformation ************************************************
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FFilterInformation;
class UScriptStruct* FFilterInformation::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FFilterInformation.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FFilterInformation.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FFilterInformation, (UObject*)Z_Construct_UPackage__Script_DMV_TargetSystem(), TEXT("FilterInformation"));
	}
	return Z_Registration_Info_UScriptStruct_FFilterInformation.OuterSingleton;
}
struct Z_Construct_UScriptStruct_FFilterInformation_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/DMVTargetEvaluator.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Threshold_MetaData[] = {
		{ "Category", "FilterInformation" },
		{ "ModuleRelativePath", "Public/DMVTargetEvaluator.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OutputNumber_MetaData[] = {
		{ "Category", "FilterInformation" },
		{ "ModuleRelativePath", "Public/DMVTargetEvaluator.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FilterClass_MetaData[] = {
		{ "Category", "Abilities" },
		{ "ModuleRelativePath", "Public/DMVTargetEvaluator.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Threshold;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_OutputNumber;
	static const UECodeGen_Private::FClassPropertyParams NewProp_FilterClass;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FFilterInformation>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FFilterInformation_Statics::NewProp_Threshold = { "Threshold", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FFilterInformation, Threshold), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Threshold_MetaData), NewProp_Threshold_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FFilterInformation_Statics::NewProp_OutputNumber = { "OutputNumber", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FFilterInformation, OutputNumber), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OutputNumber_MetaData), NewProp_OutputNumber_MetaData) };
const UECodeGen_Private::FClassPropertyParams Z_Construct_UScriptStruct_FFilterInformation_Statics::NewProp_FilterClass = { "FilterClass", nullptr, (EPropertyFlags)0x0014000000000005, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FFilterInformation, FilterClass), Z_Construct_UClass_UClass, Z_Construct_UClass_UDMVTargetFilter_Base_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FilterClass_MetaData), NewProp_FilterClass_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FFilterInformation_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FFilterInformation_Statics::NewProp_Threshold,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FFilterInformation_Statics::NewProp_OutputNumber,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FFilterInformation_Statics::NewProp_FilterClass,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FFilterInformation_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FFilterInformation_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_DMV_TargetSystem,
	nullptr,
	&NewStructOps,
	"FilterInformation",
	Z_Construct_UScriptStruct_FFilterInformation_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FFilterInformation_Statics::PropPointers),
	sizeof(FFilterInformation),
	alignof(FFilterInformation),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FFilterInformation_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FFilterInformation_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FFilterInformation()
{
	if (!Z_Registration_Info_UScriptStruct_FFilterInformation.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FFilterInformation.InnerSingleton, Z_Construct_UScriptStruct_FFilterInformation_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_FFilterInformation.InnerSingleton;
}
// ********** End ScriptStruct FFilterInformation **************************************************

// ********** Begin ScriptStruct FEvaluationFilters ************************************************
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FEvaluationFilters;
class UScriptStruct* FEvaluationFilters::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FEvaluationFilters.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FEvaluationFilters.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FEvaluationFilters, (UObject*)Z_Construct_UPackage__Script_DMV_TargetSystem(), TEXT("EvaluationFilters"));
	}
	return Z_Registration_Info_UScriptStruct_FEvaluationFilters.OuterSingleton;
}
struct Z_Construct_UScriptStruct_FEvaluationFilters_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/DMVTargetEvaluator.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SubContextId_MetaData[] = {
		{ "Categories", "ID.TargetEvaluationContext" },
		{ "Category", "EvaluationFilters" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// FGameplayTagContainer SubContextId;\n" },
#endif
		{ "ModuleRelativePath", "Public/DMVTargetEvaluator.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "FGameplayTagContainer SubContextId;" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FiltersForSubcontext_MetaData[] = {
		{ "Category", "EvaluationFilters" },
		{ "ModuleRelativePath", "Public/DMVTargetEvaluator.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_SubContextId;
	static const UECodeGen_Private::FStructPropertyParams NewProp_FiltersForSubcontext_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_FiltersForSubcontext;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FEvaluationFilters>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FEvaluationFilters_Statics::NewProp_SubContextId = { "SubContextId", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FEvaluationFilters, SubContextId), Z_Construct_UScriptStruct_FGameplayTagContainer, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SubContextId_MetaData), NewProp_SubContextId_MetaData) }; // 2104890724
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FEvaluationFilters_Statics::NewProp_FiltersForSubcontext_Inner = { "FiltersForSubcontext", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FFilterInformation, METADATA_PARAMS(0, nullptr) }; // 1083896650
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UScriptStruct_FEvaluationFilters_Statics::NewProp_FiltersForSubcontext = { "FiltersForSubcontext", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FEvaluationFilters, FiltersForSubcontext), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FiltersForSubcontext_MetaData), NewProp_FiltersForSubcontext_MetaData) }; // 1083896650
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FEvaluationFilters_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FEvaluationFilters_Statics::NewProp_SubContextId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FEvaluationFilters_Statics::NewProp_FiltersForSubcontext_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FEvaluationFilters_Statics::NewProp_FiltersForSubcontext,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FEvaluationFilters_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FEvaluationFilters_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_DMV_TargetSystem,
	nullptr,
	&NewStructOps,
	"EvaluationFilters",
	Z_Construct_UScriptStruct_FEvaluationFilters_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FEvaluationFilters_Statics::PropPointers),
	sizeof(FEvaluationFilters),
	alignof(FEvaluationFilters),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FEvaluationFilters_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FEvaluationFilters_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FEvaluationFilters()
{
	if (!Z_Registration_Info_UScriptStruct_FEvaluationFilters.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FEvaluationFilters.InnerSingleton, Z_Construct_UScriptStruct_FEvaluationFilters_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_FEvaluationFilters.InnerSingleton;
}
// ********** End ScriptStruct FEvaluationFilters **************************************************

// ********** Begin Class UDMVTargetEvaluator Function AddTargetEvaluationContext ******************
struct Z_Construct_UFunction_UDMVTargetEvaluator_AddTargetEvaluationContext_Statics
{
	struct DMVTargetEvaluator_eventAddTargetEvaluationContext_Parms
	{
		FGameplayTag ParentContext;
		FGameplayTag ContextIdentifier;
		TArray<FFilterInformation> FiltersForTheContext;
		FScriptDelegate OnValidTargetFound;
		FScriptDelegate OnTargetCleared;
		FScriptDelegate OnFilteringFinished;
		UXM_TargetEvaluationContext* ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "AutoCreateRefTerm", "ContextIdentifier, ParentContext" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Adds a new target evaluation context to be evaluated. */" },
#endif
		{ "ModuleRelativePath", "Public/DMVTargetEvaluator.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Adds a new target evaluation context to be evaluated." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ParentContext_MetaData[] = {
		{ "Categories", "ID.TargetEvaluationContext" },
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ContextIdentifier_MetaData[] = {
		{ "Categories", "ID.TargetEvaluationContext" },
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_ParentContext;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ContextIdentifier;
	static const UECodeGen_Private::FStructPropertyParams NewProp_FiltersForTheContext_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_FiltersForTheContext;
	static const UECodeGen_Private::FDelegatePropertyParams NewProp_OnValidTargetFound;
	static const UECodeGen_Private::FDelegatePropertyParams NewProp_OnTargetCleared;
	static const UECodeGen_Private::FDelegatePropertyParams NewProp_OnFilteringFinished;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UDMVTargetEvaluator_AddTargetEvaluationContext_Statics::NewProp_ParentContext = { "ParentContext", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DMVTargetEvaluator_eventAddTargetEvaluationContext_Parms, ParentContext), Z_Construct_UScriptStruct_FGameplayTag, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ParentContext_MetaData), NewProp_ParentContext_MetaData) }; // 133831994
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UDMVTargetEvaluator_AddTargetEvaluationContext_Statics::NewProp_ContextIdentifier = { "ContextIdentifier", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DMVTargetEvaluator_eventAddTargetEvaluationContext_Parms, ContextIdentifier), Z_Construct_UScriptStruct_FGameplayTag, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ContextIdentifier_MetaData), NewProp_ContextIdentifier_MetaData) }; // 133831994
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UDMVTargetEvaluator_AddTargetEvaluationContext_Statics::NewProp_FiltersForTheContext_Inner = { "FiltersForTheContext", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FFilterInformation, METADATA_PARAMS(0, nullptr) }; // 1083896650
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UDMVTargetEvaluator_AddTargetEvaluationContext_Statics::NewProp_FiltersForTheContext = { "FiltersForTheContext", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DMVTargetEvaluator_eventAddTargetEvaluationContext_Parms, FiltersForTheContext), EArrayPropertyFlags::None, METADATA_PARAMS(0, nullptr) }; // 1083896650
const UECodeGen_Private::FDelegatePropertyParams Z_Construct_UFunction_UDMVTargetEvaluator_AddTargetEvaluationContext_Statics::NewProp_OnValidTargetFound = { "OnValidTargetFound", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Delegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DMVTargetEvaluator_eventAddTargetEvaluationContext_Parms, OnValidTargetFound), Z_Construct_UDelegateFunction_DMV_TargetSystem_ValidPlayerAutoTargetFound__DelegateSignature, METADATA_PARAMS(0, nullptr) }; // 3756794100
const UECodeGen_Private::FDelegatePropertyParams Z_Construct_UFunction_UDMVTargetEvaluator_AddTargetEvaluationContext_Statics::NewProp_OnTargetCleared = { "OnTargetCleared", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Delegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DMVTargetEvaluator_eventAddTargetEvaluationContext_Parms, OnTargetCleared), Z_Construct_UDelegateFunction_DMV_TargetSystem_PlayerAutoTargetsCleared__DelegateSignature, METADATA_PARAMS(0, nullptr) }; // 871069982
const UECodeGen_Private::FDelegatePropertyParams Z_Construct_UFunction_UDMVTargetEvaluator_AddTargetEvaluationContext_Statics::NewProp_OnFilteringFinished = { "OnFilteringFinished", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Delegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DMVTargetEvaluator_eventAddTargetEvaluationContext_Parms, OnFilteringFinished), Z_Construct_UDelegateFunction_DMV_TargetSystem_FilteringFinished__DelegateSignature, METADATA_PARAMS(0, nullptr) }; // 1740310588
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UDMVTargetEvaluator_AddTargetEvaluationContext_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DMVTargetEvaluator_eventAddTargetEvaluationContext_Parms, ReturnValue), Z_Construct_UClass_UXM_TargetEvaluationContext_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDMVTargetEvaluator_AddTargetEvaluationContext_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDMVTargetEvaluator_AddTargetEvaluationContext_Statics::NewProp_ParentContext,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDMVTargetEvaluator_AddTargetEvaluationContext_Statics::NewProp_ContextIdentifier,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDMVTargetEvaluator_AddTargetEvaluationContext_Statics::NewProp_FiltersForTheContext_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDMVTargetEvaluator_AddTargetEvaluationContext_Statics::NewProp_FiltersForTheContext,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDMVTargetEvaluator_AddTargetEvaluationContext_Statics::NewProp_OnValidTargetFound,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDMVTargetEvaluator_AddTargetEvaluationContext_Statics::NewProp_OnTargetCleared,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDMVTargetEvaluator_AddTargetEvaluationContext_Statics::NewProp_OnFilteringFinished,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDMVTargetEvaluator_AddTargetEvaluationContext_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDMVTargetEvaluator_AddTargetEvaluationContext_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDMVTargetEvaluator_AddTargetEvaluationContext_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UDMVTargetEvaluator, nullptr, "AddTargetEvaluationContext", Z_Construct_UFunction_UDMVTargetEvaluator_AddTargetEvaluationContext_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDMVTargetEvaluator_AddTargetEvaluationContext_Statics::PropPointers), sizeof(Z_Construct_UFunction_UDMVTargetEvaluator_AddTargetEvaluationContext_Statics::DMVTargetEvaluator_eventAddTargetEvaluationContext_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDMVTargetEvaluator_AddTargetEvaluationContext_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDMVTargetEvaluator_AddTargetEvaluationContext_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UDMVTargetEvaluator_AddTargetEvaluationContext_Statics::DMVTargetEvaluator_eventAddTargetEvaluationContext_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UDMVTargetEvaluator_AddTargetEvaluationContext()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDMVTargetEvaluator_AddTargetEvaluationContext_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UDMVTargetEvaluator::execAddTargetEvaluationContext)
{
	P_GET_STRUCT_REF(FGameplayTag,Z_Param_Out_ParentContext);
	P_GET_STRUCT_REF(FGameplayTag,Z_Param_Out_ContextIdentifier);
	P_GET_TARRAY(FFilterInformation,Z_Param_FiltersForTheContext);
	P_GET_PROPERTY(FDelegateProperty,Z_Param_OnValidTargetFound);
	P_GET_PROPERTY(FDelegateProperty,Z_Param_OnTargetCleared);
	P_GET_PROPERTY(FDelegateProperty,Z_Param_OnFilteringFinished);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(UXM_TargetEvaluationContext**)Z_Param__Result=P_THIS->AddTargetEvaluationContext(Z_Param_Out_ParentContext,Z_Param_Out_ContextIdentifier,Z_Param_FiltersForTheContext,FValidPlayerAutoTargetFound(Z_Param_OnValidTargetFound),FPlayerAutoTargetsCleared(Z_Param_OnTargetCleared),FFilteringFinished(Z_Param_OnFilteringFinished));
	P_NATIVE_END;
}
// ********** End Class UDMVTargetEvaluator Function AddTargetEvaluationContext ********************

// ********** Begin Class UDMVTargetEvaluator Function GetCurrentTarget ****************************
struct Z_Construct_UFunction_UDMVTargetEvaluator_GetCurrentTarget_Statics
{
	struct DMVTargetEvaluator_eventGetCurrentTarget_Parms
	{
		FGameplayTag ContextIdentifier;
		AActor* ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "AutoCreateRefTerm", "ContextIdentifier" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Gets the current target actor for the given evaluation context. */" },
#endif
		{ "ModuleRelativePath", "Public/DMVTargetEvaluator.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Gets the current target actor for the given evaluation context." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ContextIdentifier_MetaData[] = {
		{ "Categories", "ID.TargetEvaluationContext" },
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_ContextIdentifier;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UDMVTargetEvaluator_GetCurrentTarget_Statics::NewProp_ContextIdentifier = { "ContextIdentifier", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DMVTargetEvaluator_eventGetCurrentTarget_Parms, ContextIdentifier), Z_Construct_UScriptStruct_FGameplayTag, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ContextIdentifier_MetaData), NewProp_ContextIdentifier_MetaData) }; // 133831994
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UDMVTargetEvaluator_GetCurrentTarget_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DMVTargetEvaluator_eventGetCurrentTarget_Parms, ReturnValue), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDMVTargetEvaluator_GetCurrentTarget_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDMVTargetEvaluator_GetCurrentTarget_Statics::NewProp_ContextIdentifier,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDMVTargetEvaluator_GetCurrentTarget_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDMVTargetEvaluator_GetCurrentTarget_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDMVTargetEvaluator_GetCurrentTarget_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UDMVTargetEvaluator, nullptr, "GetCurrentTarget", Z_Construct_UFunction_UDMVTargetEvaluator_GetCurrentTarget_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDMVTargetEvaluator_GetCurrentTarget_Statics::PropPointers), sizeof(Z_Construct_UFunction_UDMVTargetEvaluator_GetCurrentTarget_Statics::DMVTargetEvaluator_eventGetCurrentTarget_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDMVTargetEvaluator_GetCurrentTarget_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDMVTargetEvaluator_GetCurrentTarget_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UDMVTargetEvaluator_GetCurrentTarget_Statics::DMVTargetEvaluator_eventGetCurrentTarget_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UDMVTargetEvaluator_GetCurrentTarget()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDMVTargetEvaluator_GetCurrentTarget_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UDMVTargetEvaluator::execGetCurrentTarget)
{
	P_GET_STRUCT_REF(FGameplayTag,Z_Param_Out_ContextIdentifier);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(AActor**)Z_Param__Result=P_THIS->GetCurrentTarget(Z_Param_Out_ContextIdentifier);
	P_NATIVE_END;
}
// ********** End Class UDMVTargetEvaluator Function GetCurrentTarget ******************************

// ********** Begin Class UDMVTargetEvaluator Function GetCurrentTargetComponent *******************
struct Z_Construct_UFunction_UDMVTargetEvaluator_GetCurrentTargetComponent_Statics
{
	struct DMVTargetEvaluator_eventGetCurrentTargetComponent_Parms
	{
		FGameplayTag ContextIdentifier;
		UDMVTargetComponent* ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "AutoCreateRefTerm", "ContextIdentifier" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Gets the current target for the given evaluation context. */" },
#endif
		{ "ModuleRelativePath", "Public/DMVTargetEvaluator.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Gets the current target for the given evaluation context." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ContextIdentifier_MetaData[] = {
		{ "Categories", "ID.TargetEvaluationContext" },
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ReturnValue_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_ContextIdentifier;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UDMVTargetEvaluator_GetCurrentTargetComponent_Statics::NewProp_ContextIdentifier = { "ContextIdentifier", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DMVTargetEvaluator_eventGetCurrentTargetComponent_Parms, ContextIdentifier), Z_Construct_UScriptStruct_FGameplayTag, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ContextIdentifier_MetaData), NewProp_ContextIdentifier_MetaData) }; // 133831994
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UDMVTargetEvaluator_GetCurrentTargetComponent_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000080588, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DMVTargetEvaluator_eventGetCurrentTargetComponent_Parms, ReturnValue), Z_Construct_UClass_UDMVTargetComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ReturnValue_MetaData), NewProp_ReturnValue_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDMVTargetEvaluator_GetCurrentTargetComponent_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDMVTargetEvaluator_GetCurrentTargetComponent_Statics::NewProp_ContextIdentifier,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDMVTargetEvaluator_GetCurrentTargetComponent_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDMVTargetEvaluator_GetCurrentTargetComponent_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDMVTargetEvaluator_GetCurrentTargetComponent_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UDMVTargetEvaluator, nullptr, "GetCurrentTargetComponent", Z_Construct_UFunction_UDMVTargetEvaluator_GetCurrentTargetComponent_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDMVTargetEvaluator_GetCurrentTargetComponent_Statics::PropPointers), sizeof(Z_Construct_UFunction_UDMVTargetEvaluator_GetCurrentTargetComponent_Statics::DMVTargetEvaluator_eventGetCurrentTargetComponent_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDMVTargetEvaluator_GetCurrentTargetComponent_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDMVTargetEvaluator_GetCurrentTargetComponent_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UDMVTargetEvaluator_GetCurrentTargetComponent_Statics::DMVTargetEvaluator_eventGetCurrentTargetComponent_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UDMVTargetEvaluator_GetCurrentTargetComponent()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDMVTargetEvaluator_GetCurrentTargetComponent_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UDMVTargetEvaluator::execGetCurrentTargetComponent)
{
	P_GET_STRUCT_REF(FGameplayTag,Z_Param_Out_ContextIdentifier);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(UDMVTargetComponent**)Z_Param__Result=P_THIS->GetCurrentTargetComponent(Z_Param_Out_ContextIdentifier);
	P_NATIVE_END;
}
// ********** End Class UDMVTargetEvaluator Function GetCurrentTargetComponent *********************

// ********** Begin Class UDMVTargetEvaluator Function RemoveTargetEvaluationContext ***************
struct Z_Construct_UFunction_UDMVTargetEvaluator_RemoveTargetEvaluationContext_Statics
{
	struct DMVTargetEvaluator_eventRemoveTargetEvaluationContext_Parms
	{
		FGameplayTag ContextIdentifier;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "AutoCreateRefTerm", "ContextIdentifier" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Removes a target evaluation context so that it will no longer be evaluated. */" },
#endif
		{ "ModuleRelativePath", "Public/DMVTargetEvaluator.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Removes a target evaluation context so that it will no longer be evaluated." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ContextIdentifier_MetaData[] = {
		{ "Categories", "ID.TargetEvaluationContext" },
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_ContextIdentifier;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UDMVTargetEvaluator_RemoveTargetEvaluationContext_Statics::NewProp_ContextIdentifier = { "ContextIdentifier", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DMVTargetEvaluator_eventRemoveTargetEvaluationContext_Parms, ContextIdentifier), Z_Construct_UScriptStruct_FGameplayTag, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ContextIdentifier_MetaData), NewProp_ContextIdentifier_MetaData) }; // 133831994
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDMVTargetEvaluator_RemoveTargetEvaluationContext_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDMVTargetEvaluator_RemoveTargetEvaluationContext_Statics::NewProp_ContextIdentifier,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDMVTargetEvaluator_RemoveTargetEvaluationContext_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDMVTargetEvaluator_RemoveTargetEvaluationContext_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UDMVTargetEvaluator, nullptr, "RemoveTargetEvaluationContext", Z_Construct_UFunction_UDMVTargetEvaluator_RemoveTargetEvaluationContext_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDMVTargetEvaluator_RemoveTargetEvaluationContext_Statics::PropPointers), sizeof(Z_Construct_UFunction_UDMVTargetEvaluator_RemoveTargetEvaluationContext_Statics::DMVTargetEvaluator_eventRemoveTargetEvaluationContext_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDMVTargetEvaluator_RemoveTargetEvaluationContext_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDMVTargetEvaluator_RemoveTargetEvaluationContext_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UDMVTargetEvaluator_RemoveTargetEvaluationContext_Statics::DMVTargetEvaluator_eventRemoveTargetEvaluationContext_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UDMVTargetEvaluator_RemoveTargetEvaluationContext()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDMVTargetEvaluator_RemoveTargetEvaluationContext_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UDMVTargetEvaluator::execRemoveTargetEvaluationContext)
{
	P_GET_STRUCT_REF(FGameplayTag,Z_Param_Out_ContextIdentifier);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->RemoveTargetEvaluationContext(Z_Param_Out_ContextIdentifier);
	P_NATIVE_END;
}
// ********** End Class UDMVTargetEvaluator Function RemoveTargetEvaluationContext *****************

// ********** Begin Class UDMVTargetEvaluator ******************************************************
void UDMVTargetEvaluator::StaticRegisterNativesUDMVTargetEvaluator()
{
	UClass* Class = UDMVTargetEvaluator::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "AddTargetEvaluationContext", &UDMVTargetEvaluator::execAddTargetEvaluationContext },
		{ "GetCurrentTarget", &UDMVTargetEvaluator::execGetCurrentTarget },
		{ "GetCurrentTargetComponent", &UDMVTargetEvaluator::execGetCurrentTargetComponent },
		{ "RemoveTargetEvaluationContext", &UDMVTargetEvaluator::execRemoveTargetEvaluationContext },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
FClassRegistrationInfo Z_Registration_Info_UClass_UDMVTargetEvaluator;
UClass* UDMVTargetEvaluator::GetPrivateStaticClass()
{
	using TClass = UDMVTargetEvaluator;
	if (!Z_Registration_Info_UClass_UDMVTargetEvaluator.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			StaticPackage(),
			TEXT("DMVTargetEvaluator"),
			Z_Registration_Info_UClass_UDMVTargetEvaluator.InnerSingleton,
			StaticRegisterNativesUDMVTargetEvaluator,
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
	return Z_Registration_Info_UClass_UDMVTargetEvaluator.InnerSingleton;
}
UClass* Z_Construct_UClass_UDMVTargetEvaluator_NoRegister()
{
	return UDMVTargetEvaluator::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UDMVTargetEvaluator_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "ClassGroupNames", "Custom" },
		{ "IncludePath", "DMVTargetEvaluator.h" },
		{ "ModuleRelativePath", "Public/DMVTargetEvaluator.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Filters_MetaData[] = {
		{ "Category", "DMVTargetEvaluator" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** List of the filters that can be applied to a certain context identified by the id. */" },
#endif
		{ "ModuleRelativePath", "Public/DMVTargetEvaluator.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "List of the filters that can be applied to a certain context identified by the id." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bUpdateInterestByConeAngle_MetaData[] = {
		{ "Category", "DMVTargetEvaluator" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// INTEREST\n// By ANGLE\n" },
#endif
		{ "ModuleRelativePath", "Public/DMVTargetEvaluator.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "INTEREST\nBy ANGLE" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MaxAngleToGainInterest_MetaData[] = {
		{ "Category", "DMVTargetEvaluator" },
		{ "ModuleRelativePath", "Public/DMVTargetEvaluator.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InterestWinInAngle_MetaData[] = {
		{ "Category", "DMVTargetEvaluator" },
		{ "ModuleRelativePath", "Public/DMVTargetEvaluator.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InterestLoseOutAngle_MetaData[] = {
		{ "Category", "DMVTargetEvaluator" },
		{ "ModuleRelativePath", "Public/DMVTargetEvaluator.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bUpdateInterestByDistance_MetaData[] = {
		{ "Category", "DMVTargetEvaluator" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// By DISTANCE\n" },
#endif
		{ "ModuleRelativePath", "Public/DMVTargetEvaluator.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "By DISTANCE" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MaxDistanceToGainInterest_MetaData[] = {
		{ "Category", "DMVTargetEvaluator" },
		{ "ModuleRelativePath", "Public/DMVTargetEvaluator.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InterestWinInDistance_MetaData[] = {
		{ "Category", "DMVTargetEvaluator" },
		{ "ModuleRelativePath", "Public/DMVTargetEvaluator.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InterestLoseOutDistance_MetaData[] = {
		{ "Category", "DMVTargetEvaluator" },
		{ "ModuleRelativePath", "Public/DMVTargetEvaluator.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InitialTargetEvaluationContexts_Inner_MetaData[] = {
		{ "Category", "DMVTargetEvaluator" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Target evaluation contexts that are activated in BeginPlay. Provides a centralized place for defining targeting\n\x09 * parameters that don't need to be dynamically added or removed. */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/DMVTargetEvaluator.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Target evaluation contexts that are activated in BeginPlay. Provides a centralized place for defining targeting\nparameters that don't need to be dynamically added or removed." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InitialTargetEvaluationContexts_MetaData[] = {
		{ "Category", "DMVTargetEvaluator" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Target evaluation contexts that are activated in BeginPlay. Provides a centralized place for defining targeting\n\x09 * parameters that don't need to be dynamically added or removed. */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/DMVTargetEvaluator.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Target evaluation contexts that are activated in BeginPlay. Provides a centralized place for defining targeting\nparameters that don't need to be dynamically added or removed." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ActiveTargetEvaluationContextsMap_MetaData[] = {
		{ "Category", "DMVTargetEvaluator" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Map containing the active target evaluation contexts, keyed by their context identifier for quick lookup. */" },
#endif
		{ "ModuleRelativePath", "Public/DMVTargetEvaluator.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Map containing the active target evaluation contexts, keyed by their context identifier for quick lookup." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CurrentTargetsMap_MetaData[] = {
		{ "Category", "DMVTargetEvaluator" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Map containing the current target for target evaluation contexts. */" },
#endif
		{ "ModuleRelativePath", "Public/DMVTargetEvaluator.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Map containing the current target for target evaluation contexts." },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_Filters_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_Filters;
	static void NewProp_bUpdateInterestByConeAngle_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bUpdateInterestByConeAngle;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_MaxAngleToGainInterest;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_InterestWinInAngle;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_InterestLoseOutAngle;
	static void NewProp_bUpdateInterestByDistance_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bUpdateInterestByDistance;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_MaxDistanceToGainInterest;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_InterestWinInDistance;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_InterestLoseOutDistance;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_InitialTargetEvaluationContexts_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_InitialTargetEvaluationContexts;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ActiveTargetEvaluationContextsMap_ValueProp;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ActiveTargetEvaluationContextsMap_Key_KeyProp;
	static const UECodeGen_Private::FMapPropertyParams NewProp_ActiveTargetEvaluationContextsMap;
	static const UECodeGen_Private::FWeakObjectPropertyParams NewProp_CurrentTargetsMap_ValueProp;
	static const UECodeGen_Private::FStructPropertyParams NewProp_CurrentTargetsMap_Key_KeyProp;
	static const UECodeGen_Private::FMapPropertyParams NewProp_CurrentTargetsMap;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UDMVTargetEvaluator_AddTargetEvaluationContext, "AddTargetEvaluationContext" }, // 3376558497
		{ &Z_Construct_UFunction_UDMVTargetEvaluator_GetCurrentTarget, "GetCurrentTarget" }, // 658488978
		{ &Z_Construct_UFunction_UDMVTargetEvaluator_GetCurrentTargetComponent, "GetCurrentTargetComponent" }, // 276242179
		{ &Z_Construct_UFunction_UDMVTargetEvaluator_RemoveTargetEvaluationContext, "RemoveTargetEvaluationContext" }, // 2459140266
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UDMVTargetEvaluator>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UDMVTargetEvaluator_Statics::NewProp_Filters_Inner = { "Filters", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FEvaluationFilters, METADATA_PARAMS(0, nullptr) }; // 499845306
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UDMVTargetEvaluator_Statics::NewProp_Filters = { "Filters", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDMVTargetEvaluator, Filters), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Filters_MetaData), NewProp_Filters_MetaData) }; // 499845306
void Z_Construct_UClass_UDMVTargetEvaluator_Statics::NewProp_bUpdateInterestByConeAngle_SetBit(void* Obj)
{
	((UDMVTargetEvaluator*)Obj)->bUpdateInterestByConeAngle = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UDMVTargetEvaluator_Statics::NewProp_bUpdateInterestByConeAngle = { "bUpdateInterestByConeAngle", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UDMVTargetEvaluator), &Z_Construct_UClass_UDMVTargetEvaluator_Statics::NewProp_bUpdateInterestByConeAngle_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bUpdateInterestByConeAngle_MetaData), NewProp_bUpdateInterestByConeAngle_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UDMVTargetEvaluator_Statics::NewProp_MaxAngleToGainInterest = { "MaxAngleToGainInterest", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDMVTargetEvaluator, MaxAngleToGainInterest), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MaxAngleToGainInterest_MetaData), NewProp_MaxAngleToGainInterest_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UDMVTargetEvaluator_Statics::NewProp_InterestWinInAngle = { "InterestWinInAngle", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDMVTargetEvaluator, InterestWinInAngle), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InterestWinInAngle_MetaData), NewProp_InterestWinInAngle_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UDMVTargetEvaluator_Statics::NewProp_InterestLoseOutAngle = { "InterestLoseOutAngle", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDMVTargetEvaluator, InterestLoseOutAngle), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InterestLoseOutAngle_MetaData), NewProp_InterestLoseOutAngle_MetaData) };
void Z_Construct_UClass_UDMVTargetEvaluator_Statics::NewProp_bUpdateInterestByDistance_SetBit(void* Obj)
{
	((UDMVTargetEvaluator*)Obj)->bUpdateInterestByDistance = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UDMVTargetEvaluator_Statics::NewProp_bUpdateInterestByDistance = { "bUpdateInterestByDistance", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UDMVTargetEvaluator), &Z_Construct_UClass_UDMVTargetEvaluator_Statics::NewProp_bUpdateInterestByDistance_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bUpdateInterestByDistance_MetaData), NewProp_bUpdateInterestByDistance_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UDMVTargetEvaluator_Statics::NewProp_MaxDistanceToGainInterest = { "MaxDistanceToGainInterest", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDMVTargetEvaluator, MaxDistanceToGainInterest), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MaxDistanceToGainInterest_MetaData), NewProp_MaxDistanceToGainInterest_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UDMVTargetEvaluator_Statics::NewProp_InterestWinInDistance = { "InterestWinInDistance", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDMVTargetEvaluator, InterestWinInDistance), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InterestWinInDistance_MetaData), NewProp_InterestWinInDistance_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UDMVTargetEvaluator_Statics::NewProp_InterestLoseOutDistance = { "InterestLoseOutDistance", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDMVTargetEvaluator, InterestLoseOutDistance), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InterestLoseOutDistance_MetaData), NewProp_InterestLoseOutDistance_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UDMVTargetEvaluator_Statics::NewProp_InitialTargetEvaluationContexts_Inner = { "InitialTargetEvaluationContexts", nullptr, (EPropertyFlags)0x0002000000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_UXM_TargetEvaluationContext_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InitialTargetEvaluationContexts_Inner_MetaData), NewProp_InitialTargetEvaluationContexts_Inner_MetaData) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UDMVTargetEvaluator_Statics::NewProp_InitialTargetEvaluationContexts = { "InitialTargetEvaluationContexts", nullptr, (EPropertyFlags)0x002008800001001d, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDMVTargetEvaluator, InitialTargetEvaluationContexts), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InitialTargetEvaluationContexts_MetaData), NewProp_InitialTargetEvaluationContexts_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UDMVTargetEvaluator_Statics::NewProp_ActiveTargetEvaluationContextsMap_ValueProp = { "ActiveTargetEvaluationContextsMap", nullptr, (EPropertyFlags)0x0000000000020001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 1, Z_Construct_UScriptStruct_FEvaluationContexts, METADATA_PARAMS(0, nullptr) }; // 216723646
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UDMVTargetEvaluator_Statics::NewProp_ActiveTargetEvaluationContextsMap_Key_KeyProp = { "ActiveTargetEvaluationContextsMap_Key", nullptr, (EPropertyFlags)0x0000000000020001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FGameplayTag, METADATA_PARAMS(0, nullptr) }; // 133831994
const UECodeGen_Private::FMapPropertyParams Z_Construct_UClass_UDMVTargetEvaluator_Statics::NewProp_ActiveTargetEvaluationContextsMap = { "ActiveTargetEvaluationContextsMap", nullptr, (EPropertyFlags)0x0040000000020001, UECodeGen_Private::EPropertyGenFlags::Map, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDMVTargetEvaluator, ActiveTargetEvaluationContextsMap), EMapPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ActiveTargetEvaluationContextsMap_MetaData), NewProp_ActiveTargetEvaluationContextsMap_MetaData) }; // 133831994 216723646
const UECodeGen_Private::FWeakObjectPropertyParams Z_Construct_UClass_UDMVTargetEvaluator_Statics::NewProp_CurrentTargetsMap_ValueProp = { "CurrentTargetsMap", nullptr, (EPropertyFlags)0x00040000000a0009, UECodeGen_Private::EPropertyGenFlags::WeakObject, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 1, Z_Construct_UClass_UDMVTargetComponent_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UDMVTargetEvaluator_Statics::NewProp_CurrentTargetsMap_Key_KeyProp = { "CurrentTargetsMap_Key", nullptr, (EPropertyFlags)0x00000000000a0009, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FGameplayTag, METADATA_PARAMS(0, nullptr) }; // 133831994
const UECodeGen_Private::FMapPropertyParams Z_Construct_UClass_UDMVTargetEvaluator_Statics::NewProp_CurrentTargetsMap = { "CurrentTargetsMap", nullptr, (EPropertyFlags)0x0044008000020009, UECodeGen_Private::EPropertyGenFlags::Map, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDMVTargetEvaluator, CurrentTargetsMap), EMapPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CurrentTargetsMap_MetaData), NewProp_CurrentTargetsMap_MetaData) }; // 133831994
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UDMVTargetEvaluator_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDMVTargetEvaluator_Statics::NewProp_Filters_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDMVTargetEvaluator_Statics::NewProp_Filters,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDMVTargetEvaluator_Statics::NewProp_bUpdateInterestByConeAngle,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDMVTargetEvaluator_Statics::NewProp_MaxAngleToGainInterest,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDMVTargetEvaluator_Statics::NewProp_InterestWinInAngle,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDMVTargetEvaluator_Statics::NewProp_InterestLoseOutAngle,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDMVTargetEvaluator_Statics::NewProp_bUpdateInterestByDistance,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDMVTargetEvaluator_Statics::NewProp_MaxDistanceToGainInterest,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDMVTargetEvaluator_Statics::NewProp_InterestWinInDistance,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDMVTargetEvaluator_Statics::NewProp_InterestLoseOutDistance,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDMVTargetEvaluator_Statics::NewProp_InitialTargetEvaluationContexts_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDMVTargetEvaluator_Statics::NewProp_InitialTargetEvaluationContexts,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDMVTargetEvaluator_Statics::NewProp_ActiveTargetEvaluationContextsMap_ValueProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDMVTargetEvaluator_Statics::NewProp_ActiveTargetEvaluationContextsMap_Key_KeyProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDMVTargetEvaluator_Statics::NewProp_ActiveTargetEvaluationContextsMap,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDMVTargetEvaluator_Statics::NewProp_CurrentTargetsMap_ValueProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDMVTargetEvaluator_Statics::NewProp_CurrentTargetsMap_Key_KeyProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDMVTargetEvaluator_Statics::NewProp_CurrentTargetsMap,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UDMVTargetEvaluator_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UDMVTargetEvaluator_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UActorComponent,
	(UObject* (*)())Z_Construct_UPackage__Script_DMV_TargetSystem,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UDMVTargetEvaluator_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UDMVTargetEvaluator_Statics::ClassParams = {
	&UDMVTargetEvaluator::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_UDMVTargetEvaluator_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_UDMVTargetEvaluator_Statics::PropPointers),
	0,
	0x00B000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UDMVTargetEvaluator_Statics::Class_MetaDataParams), Z_Construct_UClass_UDMVTargetEvaluator_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UDMVTargetEvaluator()
{
	if (!Z_Registration_Info_UClass_UDMVTargetEvaluator.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UDMVTargetEvaluator.OuterSingleton, Z_Construct_UClass_UDMVTargetEvaluator_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UDMVTargetEvaluator.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR(UDMVTargetEvaluator);
UDMVTargetEvaluator::~UDMVTargetEvaluator() {}
// ********** End Class UDMVTargetEvaluator ********************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_WRH_proj_5_6_Plugins_DMV_TargetSystem_Source_DMV_TargetSystem_Public_DMVTargetEvaluator_h__Script_DMV_TargetSystem_Statics
{
	static constexpr FStructRegisterCompiledInInfo ScriptStructInfo[] = {
		{ FTargetInputContext::StaticStruct, Z_Construct_UScriptStruct_FTargetInputContext_Statics::NewStructOps, TEXT("TargetInputContext"), &Z_Registration_Info_UScriptStruct_FTargetInputContext, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FTargetInputContext), 235746009U) },
		{ FEvaluationContexts::StaticStruct, Z_Construct_UScriptStruct_FEvaluationContexts_Statics::NewStructOps, TEXT("EvaluationContexts"), &Z_Registration_Info_UScriptStruct_FEvaluationContexts, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FEvaluationContexts), 216723646U) },
		{ FFilterInformation::StaticStruct, Z_Construct_UScriptStruct_FFilterInformation_Statics::NewStructOps, TEXT("FilterInformation"), &Z_Registration_Info_UScriptStruct_FFilterInformation, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FFilterInformation), 1083896650U) },
		{ FEvaluationFilters::StaticStruct, Z_Construct_UScriptStruct_FEvaluationFilters_Statics::NewStructOps, TEXT("EvaluationFilters"), &Z_Registration_Info_UScriptStruct_FEvaluationFilters, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FEvaluationFilters), 499845306U) },
	};
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UXM_TargetEvaluationContext, UXM_TargetEvaluationContext::StaticClass, TEXT("UXM_TargetEvaluationContext"), &Z_Registration_Info_UClass_UXM_TargetEvaluationContext, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UXM_TargetEvaluationContext), 1804445940U) },
		{ Z_Construct_UClass_UDMVTargetEvaluator, UDMVTargetEvaluator::StaticClass, TEXT("UDMVTargetEvaluator"), &Z_Registration_Info_UClass_UDMVTargetEvaluator, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UDMVTargetEvaluator), 1234705996U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_WRH_proj_5_6_Plugins_DMV_TargetSystem_Source_DMV_TargetSystem_Public_DMVTargetEvaluator_h__Script_DMV_TargetSystem_2733675748(TEXT("/Script/DMV_TargetSystem"),
	Z_CompiledInDeferFile_FID_WRH_proj_5_6_Plugins_DMV_TargetSystem_Source_DMV_TargetSystem_Public_DMVTargetEvaluator_h__Script_DMV_TargetSystem_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_WRH_proj_5_6_Plugins_DMV_TargetSystem_Source_DMV_TargetSystem_Public_DMVTargetEvaluator_h__Script_DMV_TargetSystem_Statics::ClassInfo),
	Z_CompiledInDeferFile_FID_WRH_proj_5_6_Plugins_DMV_TargetSystem_Source_DMV_TargetSystem_Public_DMVTargetEvaluator_h__Script_DMV_TargetSystem_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_WRH_proj_5_6_Plugins_DMV_TargetSystem_Source_DMV_TargetSystem_Public_DMVTargetEvaluator_h__Script_DMV_TargetSystem_Statics::ScriptStructInfo),
	nullptr, 0);
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
