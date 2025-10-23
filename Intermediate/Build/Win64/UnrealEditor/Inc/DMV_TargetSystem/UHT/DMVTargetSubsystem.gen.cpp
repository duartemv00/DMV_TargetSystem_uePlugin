// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "DMVTargetSubsystem.h"
#include "Engine/GameInstance.h"
#include "GameplayTagContainer.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

void EmptyLinkFunctionForGeneratedCodeDMVTargetSubsystem() {}

// ********** Begin Cross Module References ********************************************************
DMV_TARGETSYSTEM_API UClass* Z_Construct_UClass_UDMVTargetComponent_NoRegister();
DMV_TARGETSYSTEM_API UClass* Z_Construct_UClass_UDMVTargetSubsystem();
DMV_TARGETSYSTEM_API UClass* Z_Construct_UClass_UDMVTargetSubsystem_NoRegister();
DMV_TARGETSYSTEM_API UScriptStruct* Z_Construct_UScriptStruct_FPlayerTargetList();
ENGINE_API UClass* Z_Construct_UClass_UGameInstanceSubsystem();
GAMEPLAYTAGS_API UScriptStruct* Z_Construct_UScriptStruct_FGameplayTag();
GAMEPLAYTAGS_API UScriptStruct* Z_Construct_UScriptStruct_FGameplayTagContainer();
UPackage* Z_Construct_UPackage__Script_DMV_TargetSystem();
// ********** End Cross Module References **********************************************************

// ********** Begin ScriptStruct FPlayerTargetList *************************************************
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FPlayerTargetList;
class UScriptStruct* FPlayerTargetList::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FPlayerTargetList.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FPlayerTargetList.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FPlayerTargetList, (UObject*)Z_Construct_UPackage__Script_DMV_TargetSystem(), TEXT("PlayerTargetList"));
	}
	return Z_Registration_Info_UScriptStruct_FPlayerTargetList.OuterSingleton;
}
struct Z_Construct_UScriptStruct_FPlayerTargetList_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "ModuleRelativePath", "Public/DMVTargetSubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TargetsArray_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** The internal list of targets. */" },
#endif
		{ "ModuleRelativePath", "Public/DMVTargetSubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "The internal list of targets." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TargetsSet_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** An internal store for the targets in a set so that we can do O(1) operations to maintain uniqueness. */" },
#endif
		{ "ModuleRelativePath", "Public/DMVTargetSubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "An internal store for the targets in a set so that we can do O(1) operations to maintain uniqueness." },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FWeakObjectPropertyParams NewProp_TargetsArray_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_TargetsArray;
	static const UECodeGen_Private::FWeakObjectPropertyParams NewProp_TargetsSet_ElementProp;
	static const UECodeGen_Private::FSetPropertyParams NewProp_TargetsSet;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FPlayerTargetList>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FWeakObjectPropertyParams Z_Construct_UScriptStruct_FPlayerTargetList_Statics::NewProp_TargetsArray_Inner = { "TargetsArray", nullptr, (EPropertyFlags)0x0004000000080008, UECodeGen_Private::EPropertyGenFlags::WeakObject, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_UDMVTargetComponent_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UScriptStruct_FPlayerTargetList_Statics::NewProp_TargetsArray = { "TargetsArray", nullptr, (EPropertyFlags)0x0044008000000008, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPlayerTargetList, TargetsArray), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TargetsArray_MetaData), NewProp_TargetsArray_MetaData) };
const UECodeGen_Private::FWeakObjectPropertyParams Z_Construct_UScriptStruct_FPlayerTargetList_Statics::NewProp_TargetsSet_ElementProp = { "TargetsSet", nullptr, (EPropertyFlags)0x0004000000080008, UECodeGen_Private::EPropertyGenFlags::WeakObject, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_UDMVTargetComponent_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FSetPropertyParams Z_Construct_UScriptStruct_FPlayerTargetList_Statics::NewProp_TargetsSet = { "TargetsSet", nullptr, (EPropertyFlags)0x0044008000000008, UECodeGen_Private::EPropertyGenFlags::Set, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPlayerTargetList, TargetsSet), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TargetsSet_MetaData), NewProp_TargetsSet_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FPlayerTargetList_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPlayerTargetList_Statics::NewProp_TargetsArray_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPlayerTargetList_Statics::NewProp_TargetsArray,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPlayerTargetList_Statics::NewProp_TargetsSet_ElementProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPlayerTargetList_Statics::NewProp_TargetsSet,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPlayerTargetList_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FPlayerTargetList_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_DMV_TargetSystem,
	nullptr,
	&NewStructOps,
	"PlayerTargetList",
	Z_Construct_UScriptStruct_FPlayerTargetList_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPlayerTargetList_Statics::PropPointers),
	sizeof(FPlayerTargetList),
	alignof(FPlayerTargetList),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000005),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPlayerTargetList_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FPlayerTargetList_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FPlayerTargetList()
{
	if (!Z_Registration_Info_UScriptStruct_FPlayerTargetList.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FPlayerTargetList.InnerSingleton, Z_Construct_UScriptStruct_FPlayerTargetList_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_FPlayerTargetList.InnerSingleton;
}
// ********** End ScriptStruct FPlayerTargetList ***************************************************

// ********** Begin Class UDMVTargetSubsystem Function RegisterTargetForContext ********************
struct Z_Construct_UFunction_UDMVTargetSubsystem_RegisterTargetForContext_Statics
{
	struct DMVTargetSubsystem_eventRegisterTargetForContext_Parms
	{
		UDMVTargetComponent* Target;
		FGameplayTag TargetContextIdentifier;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Targeting" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Registers a potential target for the specified target context. */" },
#endif
		{ "ModuleRelativePath", "Public/DMVTargetSubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Registers a potential target for the specified target context." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Target_MetaData[] = {
		{ "EditInline", "true" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TargetContextIdentifier_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Target;
	static const UECodeGen_Private::FStructPropertyParams NewProp_TargetContextIdentifier;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UDMVTargetSubsystem_RegisterTargetForContext_Statics::NewProp_Target = { "Target", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DMVTargetSubsystem_eventRegisterTargetForContext_Parms, Target), Z_Construct_UClass_UDMVTargetComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Target_MetaData), NewProp_Target_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UDMVTargetSubsystem_RegisterTargetForContext_Statics::NewProp_TargetContextIdentifier = { "TargetContextIdentifier", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DMVTargetSubsystem_eventRegisterTargetForContext_Parms, TargetContextIdentifier), Z_Construct_UScriptStruct_FGameplayTag, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TargetContextIdentifier_MetaData), NewProp_TargetContextIdentifier_MetaData) }; // 133831994
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDMVTargetSubsystem_RegisterTargetForContext_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDMVTargetSubsystem_RegisterTargetForContext_Statics::NewProp_Target,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDMVTargetSubsystem_RegisterTargetForContext_Statics::NewProp_TargetContextIdentifier,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDMVTargetSubsystem_RegisterTargetForContext_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDMVTargetSubsystem_RegisterTargetForContext_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UDMVTargetSubsystem, nullptr, "RegisterTargetForContext", Z_Construct_UFunction_UDMVTargetSubsystem_RegisterTargetForContext_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDMVTargetSubsystem_RegisterTargetForContext_Statics::PropPointers), sizeof(Z_Construct_UFunction_UDMVTargetSubsystem_RegisterTargetForContext_Statics::DMVTargetSubsystem_eventRegisterTargetForContext_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDMVTargetSubsystem_RegisterTargetForContext_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDMVTargetSubsystem_RegisterTargetForContext_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UDMVTargetSubsystem_RegisterTargetForContext_Statics::DMVTargetSubsystem_eventRegisterTargetForContext_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UDMVTargetSubsystem_RegisterTargetForContext()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDMVTargetSubsystem_RegisterTargetForContext_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UDMVTargetSubsystem::execRegisterTargetForContext)
{
	P_GET_OBJECT(UDMVTargetComponent,Z_Param_Target);
	P_GET_STRUCT_REF(FGameplayTag,Z_Param_Out_TargetContextIdentifier);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->RegisterTargetForContext(Z_Param_Target,Z_Param_Out_TargetContextIdentifier);
	P_NATIVE_END;
}
// ********** End Class UDMVTargetSubsystem Function RegisterTargetForContext **********************

// ********** Begin Class UDMVTargetSubsystem Function RegisterTargetForContexts *******************
struct Z_Construct_UFunction_UDMVTargetSubsystem_RegisterTargetForContexts_Statics
{
	struct DMVTargetSubsystem_eventRegisterTargetForContexts_Parms
	{
		UDMVTargetComponent* Target;
		FGameplayTagContainer TargetContextIdentifiers;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Targeting" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Registers a potential target for the specified target contexts. */" },
#endif
		{ "ModuleRelativePath", "Public/DMVTargetSubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Registers a potential target for the specified target contexts." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Target_MetaData[] = {
		{ "EditInline", "true" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TargetContextIdentifiers_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Target;
	static const UECodeGen_Private::FStructPropertyParams NewProp_TargetContextIdentifiers;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UDMVTargetSubsystem_RegisterTargetForContexts_Statics::NewProp_Target = { "Target", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DMVTargetSubsystem_eventRegisterTargetForContexts_Parms, Target), Z_Construct_UClass_UDMVTargetComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Target_MetaData), NewProp_Target_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UDMVTargetSubsystem_RegisterTargetForContexts_Statics::NewProp_TargetContextIdentifiers = { "TargetContextIdentifiers", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DMVTargetSubsystem_eventRegisterTargetForContexts_Parms, TargetContextIdentifiers), Z_Construct_UScriptStruct_FGameplayTagContainer, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TargetContextIdentifiers_MetaData), NewProp_TargetContextIdentifiers_MetaData) }; // 2104890724
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDMVTargetSubsystem_RegisterTargetForContexts_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDMVTargetSubsystem_RegisterTargetForContexts_Statics::NewProp_Target,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDMVTargetSubsystem_RegisterTargetForContexts_Statics::NewProp_TargetContextIdentifiers,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDMVTargetSubsystem_RegisterTargetForContexts_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDMVTargetSubsystem_RegisterTargetForContexts_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UDMVTargetSubsystem, nullptr, "RegisterTargetForContexts", Z_Construct_UFunction_UDMVTargetSubsystem_RegisterTargetForContexts_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDMVTargetSubsystem_RegisterTargetForContexts_Statics::PropPointers), sizeof(Z_Construct_UFunction_UDMVTargetSubsystem_RegisterTargetForContexts_Statics::DMVTargetSubsystem_eventRegisterTargetForContexts_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDMVTargetSubsystem_RegisterTargetForContexts_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDMVTargetSubsystem_RegisterTargetForContexts_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UDMVTargetSubsystem_RegisterTargetForContexts_Statics::DMVTargetSubsystem_eventRegisterTargetForContexts_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UDMVTargetSubsystem_RegisterTargetForContexts()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDMVTargetSubsystem_RegisterTargetForContexts_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UDMVTargetSubsystem::execRegisterTargetForContexts)
{
	P_GET_OBJECT(UDMVTargetComponent,Z_Param_Target);
	P_GET_STRUCT_REF(FGameplayTagContainer,Z_Param_Out_TargetContextIdentifiers);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->RegisterTargetForContexts(Z_Param_Target,Z_Param_Out_TargetContextIdentifiers);
	P_NATIVE_END;
}
// ********** End Class UDMVTargetSubsystem Function RegisterTargetForContexts *********************

// ********** Begin Class UDMVTargetSubsystem Function UnregisterTargetForContext ******************
struct Z_Construct_UFunction_UDMVTargetSubsystem_UnregisterTargetForContext_Statics
{
	struct DMVTargetSubsystem_eventUnregisterTargetForContext_Parms
	{
		UDMVTargetComponent* Target;
		FGameplayTag TargetContextIdentifier;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Targeting" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Unregisters a target from the specified target context. */" },
#endif
		{ "ModuleRelativePath", "Public/DMVTargetSubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Unregisters a target from the specified target context." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Target_MetaData[] = {
		{ "EditInline", "true" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TargetContextIdentifier_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Target;
	static const UECodeGen_Private::FStructPropertyParams NewProp_TargetContextIdentifier;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UDMVTargetSubsystem_UnregisterTargetForContext_Statics::NewProp_Target = { "Target", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DMVTargetSubsystem_eventUnregisterTargetForContext_Parms, Target), Z_Construct_UClass_UDMVTargetComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Target_MetaData), NewProp_Target_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UDMVTargetSubsystem_UnregisterTargetForContext_Statics::NewProp_TargetContextIdentifier = { "TargetContextIdentifier", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DMVTargetSubsystem_eventUnregisterTargetForContext_Parms, TargetContextIdentifier), Z_Construct_UScriptStruct_FGameplayTag, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TargetContextIdentifier_MetaData), NewProp_TargetContextIdentifier_MetaData) }; // 133831994
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDMVTargetSubsystem_UnregisterTargetForContext_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDMVTargetSubsystem_UnregisterTargetForContext_Statics::NewProp_Target,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDMVTargetSubsystem_UnregisterTargetForContext_Statics::NewProp_TargetContextIdentifier,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDMVTargetSubsystem_UnregisterTargetForContext_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDMVTargetSubsystem_UnregisterTargetForContext_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UDMVTargetSubsystem, nullptr, "UnregisterTargetForContext", Z_Construct_UFunction_UDMVTargetSubsystem_UnregisterTargetForContext_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDMVTargetSubsystem_UnregisterTargetForContext_Statics::PropPointers), sizeof(Z_Construct_UFunction_UDMVTargetSubsystem_UnregisterTargetForContext_Statics::DMVTargetSubsystem_eventUnregisterTargetForContext_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDMVTargetSubsystem_UnregisterTargetForContext_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDMVTargetSubsystem_UnregisterTargetForContext_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UDMVTargetSubsystem_UnregisterTargetForContext_Statics::DMVTargetSubsystem_eventUnregisterTargetForContext_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UDMVTargetSubsystem_UnregisterTargetForContext()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDMVTargetSubsystem_UnregisterTargetForContext_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UDMVTargetSubsystem::execUnregisterTargetForContext)
{
	P_GET_OBJECT(UDMVTargetComponent,Z_Param_Target);
	P_GET_STRUCT_REF(FGameplayTag,Z_Param_Out_TargetContextIdentifier);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->UnregisterTargetForContext(Z_Param_Target,Z_Param_Out_TargetContextIdentifier);
	P_NATIVE_END;
}
// ********** End Class UDMVTargetSubsystem Function UnregisterTargetForContext ********************

// ********** Begin Class UDMVTargetSubsystem Function UnregisterTargetForContexts *****************
struct Z_Construct_UFunction_UDMVTargetSubsystem_UnregisterTargetForContexts_Statics
{
	struct DMVTargetSubsystem_eventUnregisterTargetForContexts_Parms
	{
		UDMVTargetComponent* Target;
		FGameplayTagContainer TargetContextIdentifiers;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Targeting" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Unregisters a target from the specified target contexts. */" },
#endif
		{ "ModuleRelativePath", "Public/DMVTargetSubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Unregisters a target from the specified target contexts." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Target_MetaData[] = {
		{ "EditInline", "true" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TargetContextIdentifiers_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Target;
	static const UECodeGen_Private::FStructPropertyParams NewProp_TargetContextIdentifiers;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UDMVTargetSubsystem_UnregisterTargetForContexts_Statics::NewProp_Target = { "Target", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DMVTargetSubsystem_eventUnregisterTargetForContexts_Parms, Target), Z_Construct_UClass_UDMVTargetComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Target_MetaData), NewProp_Target_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UDMVTargetSubsystem_UnregisterTargetForContexts_Statics::NewProp_TargetContextIdentifiers = { "TargetContextIdentifiers", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DMVTargetSubsystem_eventUnregisterTargetForContexts_Parms, TargetContextIdentifiers), Z_Construct_UScriptStruct_FGameplayTagContainer, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TargetContextIdentifiers_MetaData), NewProp_TargetContextIdentifiers_MetaData) }; // 2104890724
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDMVTargetSubsystem_UnregisterTargetForContexts_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDMVTargetSubsystem_UnregisterTargetForContexts_Statics::NewProp_Target,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDMVTargetSubsystem_UnregisterTargetForContexts_Statics::NewProp_TargetContextIdentifiers,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDMVTargetSubsystem_UnregisterTargetForContexts_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDMVTargetSubsystem_UnregisterTargetForContexts_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UDMVTargetSubsystem, nullptr, "UnregisterTargetForContexts", Z_Construct_UFunction_UDMVTargetSubsystem_UnregisterTargetForContexts_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDMVTargetSubsystem_UnregisterTargetForContexts_Statics::PropPointers), sizeof(Z_Construct_UFunction_UDMVTargetSubsystem_UnregisterTargetForContexts_Statics::DMVTargetSubsystem_eventUnregisterTargetForContexts_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDMVTargetSubsystem_UnregisterTargetForContexts_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDMVTargetSubsystem_UnregisterTargetForContexts_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UDMVTargetSubsystem_UnregisterTargetForContexts_Statics::DMVTargetSubsystem_eventUnregisterTargetForContexts_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UDMVTargetSubsystem_UnregisterTargetForContexts()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDMVTargetSubsystem_UnregisterTargetForContexts_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UDMVTargetSubsystem::execUnregisterTargetForContexts)
{
	P_GET_OBJECT(UDMVTargetComponent,Z_Param_Target);
	P_GET_STRUCT_REF(FGameplayTagContainer,Z_Param_Out_TargetContextIdentifiers);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->UnregisterTargetForContexts(Z_Param_Target,Z_Param_Out_TargetContextIdentifiers);
	P_NATIVE_END;
}
// ********** End Class UDMVTargetSubsystem Function UnregisterTargetForContexts *******************

// ********** Begin Class UDMVTargetSubsystem ******************************************************
void UDMVTargetSubsystem::StaticRegisterNativesUDMVTargetSubsystem()
{
	UClass* Class = UDMVTargetSubsystem::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "RegisterTargetForContext", &UDMVTargetSubsystem::execRegisterTargetForContext },
		{ "RegisterTargetForContexts", &UDMVTargetSubsystem::execRegisterTargetForContexts },
		{ "UnregisterTargetForContext", &UDMVTargetSubsystem::execUnregisterTargetForContext },
		{ "UnregisterTargetForContexts", &UDMVTargetSubsystem::execUnregisterTargetForContexts },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
FClassRegistrationInfo Z_Registration_Info_UClass_UDMVTargetSubsystem;
UClass* UDMVTargetSubsystem::GetPrivateStaticClass()
{
	using TClass = UDMVTargetSubsystem;
	if (!Z_Registration_Info_UClass_UDMVTargetSubsystem.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			StaticPackage(),
			TEXT("DMVTargetSubsystem"),
			Z_Registration_Info_UClass_UDMVTargetSubsystem.InnerSingleton,
			StaticRegisterNativesUDMVTargetSubsystem,
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
	return Z_Registration_Info_UClass_UDMVTargetSubsystem.InnerSingleton;
}
UClass* Z_Construct_UClass_UDMVTargetSubsystem_NoRegister()
{
	return UDMVTargetSubsystem::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UDMVTargetSubsystem_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "DMVTargetSubsystem.h" },
		{ "ModuleRelativePath", "Public/DMVTargetSubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PlayerTargetsByContext_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Map of the registered targets, grouped by targeting context. */" },
#endif
		{ "ModuleRelativePath", "Public/DMVTargetSubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Map of the registered targets, grouped by targeting context." },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_PlayerTargetsByContext_ValueProp;
	static const UECodeGen_Private::FStructPropertyParams NewProp_PlayerTargetsByContext_Key_KeyProp;
	static const UECodeGen_Private::FMapPropertyParams NewProp_PlayerTargetsByContext;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UDMVTargetSubsystem_RegisterTargetForContext, "RegisterTargetForContext" }, // 990690126
		{ &Z_Construct_UFunction_UDMVTargetSubsystem_RegisterTargetForContexts, "RegisterTargetForContexts" }, // 1222782521
		{ &Z_Construct_UFunction_UDMVTargetSubsystem_UnregisterTargetForContext, "UnregisterTargetForContext" }, // 2576795039
		{ &Z_Construct_UFunction_UDMVTargetSubsystem_UnregisterTargetForContexts, "UnregisterTargetForContexts" }, // 2241611622
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UDMVTargetSubsystem>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UDMVTargetSubsystem_Statics::NewProp_PlayerTargetsByContext_ValueProp = { "PlayerTargetsByContext", nullptr, (EPropertyFlags)0x0000008000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 1, Z_Construct_UScriptStruct_FPlayerTargetList, METADATA_PARAMS(0, nullptr) }; // 3835829094
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UDMVTargetSubsystem_Statics::NewProp_PlayerTargetsByContext_Key_KeyProp = { "PlayerTargetsByContext_Key", nullptr, (EPropertyFlags)0x0000008000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FGameplayTag, METADATA_PARAMS(0, nullptr) }; // 133831994
const UECodeGen_Private::FMapPropertyParams Z_Construct_UClass_UDMVTargetSubsystem_Statics::NewProp_PlayerTargetsByContext = { "PlayerTargetsByContext", nullptr, (EPropertyFlags)0x0040008000000000, UECodeGen_Private::EPropertyGenFlags::Map, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDMVTargetSubsystem, PlayerTargetsByContext), EMapPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PlayerTargetsByContext_MetaData), NewProp_PlayerTargetsByContext_MetaData) }; // 133831994 3835829094
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UDMVTargetSubsystem_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDMVTargetSubsystem_Statics::NewProp_PlayerTargetsByContext_ValueProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDMVTargetSubsystem_Statics::NewProp_PlayerTargetsByContext_Key_KeyProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDMVTargetSubsystem_Statics::NewProp_PlayerTargetsByContext,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UDMVTargetSubsystem_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UDMVTargetSubsystem_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UGameInstanceSubsystem,
	(UObject* (*)())Z_Construct_UPackage__Script_DMV_TargetSystem,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UDMVTargetSubsystem_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UDMVTargetSubsystem_Statics::ClassParams = {
	&UDMVTargetSubsystem::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_UDMVTargetSubsystem_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_UDMVTargetSubsystem_Statics::PropPointers),
	0,
	0x009000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UDMVTargetSubsystem_Statics::Class_MetaDataParams), Z_Construct_UClass_UDMVTargetSubsystem_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UDMVTargetSubsystem()
{
	if (!Z_Registration_Info_UClass_UDMVTargetSubsystem.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UDMVTargetSubsystem.OuterSingleton, Z_Construct_UClass_UDMVTargetSubsystem_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UDMVTargetSubsystem.OuterSingleton;
}
UDMVTargetSubsystem::UDMVTargetSubsystem() {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UDMVTargetSubsystem);
UDMVTargetSubsystem::~UDMVTargetSubsystem() {}
// ********** End Class UDMVTargetSubsystem ********************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_WRH_proj_5_6_Plugins_DMV_TargetSystem_Source_DMV_TargetSystem_Public_DMVTargetSubsystem_h__Script_DMV_TargetSystem_Statics
{
	static constexpr FStructRegisterCompiledInInfo ScriptStructInfo[] = {
		{ FPlayerTargetList::StaticStruct, Z_Construct_UScriptStruct_FPlayerTargetList_Statics::NewStructOps, TEXT("PlayerTargetList"), &Z_Registration_Info_UScriptStruct_FPlayerTargetList, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FPlayerTargetList), 3835829094U) },
	};
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UDMVTargetSubsystem, UDMVTargetSubsystem::StaticClass, TEXT("UDMVTargetSubsystem"), &Z_Registration_Info_UClass_UDMVTargetSubsystem, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UDMVTargetSubsystem), 1334891681U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_WRH_proj_5_6_Plugins_DMV_TargetSystem_Source_DMV_TargetSystem_Public_DMVTargetSubsystem_h__Script_DMV_TargetSystem_929947482(TEXT("/Script/DMV_TargetSystem"),
	Z_CompiledInDeferFile_FID_WRH_proj_5_6_Plugins_DMV_TargetSystem_Source_DMV_TargetSystem_Public_DMVTargetSubsystem_h__Script_DMV_TargetSystem_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_WRH_proj_5_6_Plugins_DMV_TargetSystem_Source_DMV_TargetSystem_Public_DMVTargetSubsystem_h__Script_DMV_TargetSystem_Statics::ClassInfo),
	Z_CompiledInDeferFile_FID_WRH_proj_5_6_Plugins_DMV_TargetSystem_Source_DMV_TargetSystem_Public_DMVTargetSubsystem_h__Script_DMV_TargetSystem_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_WRH_proj_5_6_Plugins_DMV_TargetSystem_Source_DMV_TargetSystem_Public_DMVTargetSubsystem_h__Script_DMV_TargetSystem_Statics::ScriptStructInfo),
	nullptr, 0);
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
