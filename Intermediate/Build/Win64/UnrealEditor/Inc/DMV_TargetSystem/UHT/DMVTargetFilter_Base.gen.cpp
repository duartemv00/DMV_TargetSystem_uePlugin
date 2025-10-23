// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Filters/DMVTargetFilter_Base.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

void EmptyLinkFunctionForGeneratedCodeDMVTargetFilter_Base() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
DMV_TARGETSYSTEM_API UClass* Z_Construct_UClass_ADMVScanForActors_NoRegister();
DMV_TARGETSYSTEM_API UClass* Z_Construct_UClass_UDMVTargetComponent_NoRegister();
DMV_TARGETSYSTEM_API UClass* Z_Construct_UClass_UDMVTargetFilter_Base();
DMV_TARGETSYSTEM_API UClass* Z_Construct_UClass_UDMVTargetFilter_Base_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_APlayerController_NoRegister();
UPackage* Z_Construct_UPackage__Script_DMV_TargetSystem();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UDMVTargetFilter_Base Function Initialize ********************************
struct Z_Construct_UFunction_UDMVTargetFilter_Base_Initialize_Statics
{
	struct DMVTargetFilter_Base_eventInitialize_Parms
	{
		float _Threshold;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** */" },
#endif
		{ "ModuleRelativePath", "Public/Filters/DMVTargetFilter_Base.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFloatPropertyParams NewProp__Threshold;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UDMVTargetFilter_Base_Initialize_Statics::NewProp__Threshold = { "_Threshold", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DMVTargetFilter_Base_eventInitialize_Parms, _Threshold), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDMVTargetFilter_Base_Initialize_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDMVTargetFilter_Base_Initialize_Statics::NewProp__Threshold,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDMVTargetFilter_Base_Initialize_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDMVTargetFilter_Base_Initialize_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UDMVTargetFilter_Base, nullptr, "Initialize", Z_Construct_UFunction_UDMVTargetFilter_Base_Initialize_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDMVTargetFilter_Base_Initialize_Statics::PropPointers), sizeof(Z_Construct_UFunction_UDMVTargetFilter_Base_Initialize_Statics::DMVTargetFilter_Base_eventInitialize_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDMVTargetFilter_Base_Initialize_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDMVTargetFilter_Base_Initialize_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UDMVTargetFilter_Base_Initialize_Statics::DMVTargetFilter_Base_eventInitialize_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UDMVTargetFilter_Base_Initialize()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDMVTargetFilter_Base_Initialize_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UDMVTargetFilter_Base::execInitialize)
{
	P_GET_PROPERTY(FFloatProperty,Z_Param__Threshold);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->Initialize(Z_Param__Threshold);
	P_NATIVE_END;
}
// ********** End Class UDMVTargetFilter_Base Function Initialize **********************************

// ********** Begin Class UDMVTargetFilter_Base Function PerformFilter *****************************
struct DMVTargetFilter_Base_eventPerformFilter_Parms
{
	TArray<UDMVTargetComponent*> PotentialTargets;
	APlayerController* PlayerController;
	TArray<UDMVTargetComponent*> ReturnValue;
};
static FName NAME_UDMVTargetFilter_Base_PerformFilter = FName(TEXT("PerformFilter"));
TArray<UDMVTargetComponent*> UDMVTargetFilter_Base::PerformFilter(TArray<UDMVTargetComponent*> const& PotentialTargets, APlayerController* PlayerController)
{
	UFunction* Func = FindFunctionChecked(NAME_UDMVTargetFilter_Base_PerformFilter);
	if (!Func->GetOwnerClass()->HasAnyClassFlags(CLASS_Native))
	{
		DMVTargetFilter_Base_eventPerformFilter_Parms Parms;
		Parms.PotentialTargets=PotentialTargets;
		Parms.PlayerController=PlayerController;
	ProcessEvent(Func,&Parms);
		return Parms.ReturnValue;
	}
	else
	{
		return PerformFilter_Implementation(PotentialTargets, PlayerController);
	}
}
struct Z_Construct_UFunction_UDMVTargetFilter_Base_PerformFilter_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** */" },
#endif
		{ "ModuleRelativePath", "Public/Filters/DMVTargetFilter_Base.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PotentialTargets_MetaData[] = {
		{ "EditInline", "true" },
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ReturnValue_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_PotentialTargets_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_PotentialTargets;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_PlayerController;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UDMVTargetFilter_Base_PerformFilter_Statics::NewProp_PotentialTargets_Inner = { "PotentialTargets", nullptr, (EPropertyFlags)0x0000000000080000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_UDMVTargetComponent_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UDMVTargetFilter_Base_PerformFilter_Statics::NewProp_PotentialTargets = { "PotentialTargets", nullptr, (EPropertyFlags)0x0010008008000182, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DMVTargetFilter_Base_eventPerformFilter_Parms, PotentialTargets), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PotentialTargets_MetaData), NewProp_PotentialTargets_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UDMVTargetFilter_Base_PerformFilter_Statics::NewProp_PlayerController = { "PlayerController", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DMVTargetFilter_Base_eventPerformFilter_Parms, PlayerController), Z_Construct_UClass_APlayerController_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UDMVTargetFilter_Base_PerformFilter_Statics::NewProp_ReturnValue_Inner = { "ReturnValue", nullptr, (EPropertyFlags)0x0000000000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_UDMVTargetComponent_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UDMVTargetFilter_Base_PerformFilter_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010008000000588, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DMVTargetFilter_Base_eventPerformFilter_Parms, ReturnValue), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ReturnValue_MetaData), NewProp_ReturnValue_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDMVTargetFilter_Base_PerformFilter_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDMVTargetFilter_Base_PerformFilter_Statics::NewProp_PotentialTargets_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDMVTargetFilter_Base_PerformFilter_Statics::NewProp_PotentialTargets,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDMVTargetFilter_Base_PerformFilter_Statics::NewProp_PlayerController,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDMVTargetFilter_Base_PerformFilter_Statics::NewProp_ReturnValue_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDMVTargetFilter_Base_PerformFilter_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDMVTargetFilter_Base_PerformFilter_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDMVTargetFilter_Base_PerformFilter_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UDMVTargetFilter_Base, nullptr, "PerformFilter", Z_Construct_UFunction_UDMVTargetFilter_Base_PerformFilter_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDMVTargetFilter_Base_PerformFilter_Statics::PropPointers), sizeof(DMVTargetFilter_Base_eventPerformFilter_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x0C420C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDMVTargetFilter_Base_PerformFilter_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDMVTargetFilter_Base_PerformFilter_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(DMVTargetFilter_Base_eventPerformFilter_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UDMVTargetFilter_Base_PerformFilter()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDMVTargetFilter_Base_PerformFilter_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UDMVTargetFilter_Base::execPerformFilter)
{
	P_GET_TARRAY_REF(UDMVTargetComponent*,Z_Param_Out_PotentialTargets);
	P_GET_OBJECT(APlayerController,Z_Param_PlayerController);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(TArray<UDMVTargetComponent*>*)Z_Param__Result=P_THIS->PerformFilter_Implementation(Z_Param_Out_PotentialTargets,Z_Param_PlayerController);
	P_NATIVE_END;
}
// ********** End Class UDMVTargetFilter_Base Function PerformFilter *******************************

// ********** Begin Class UDMVTargetFilter_Base Function SortCandidates ****************************
struct DMVTargetFilter_Base_eventSortCandidates_Parms
{
	TArray<UDMVTargetComponent*> PotentialTargets;
	TArray<UDMVTargetComponent*> ReturnValue;
};
static FName NAME_UDMVTargetFilter_Base_SortCandidates = FName(TEXT("SortCandidates"));
TArray<UDMVTargetComponent*> UDMVTargetFilter_Base::SortCandidates(TArray<UDMVTargetComponent*> const& PotentialTargets)
{
	UFunction* Func = FindFunctionChecked(NAME_UDMVTargetFilter_Base_SortCandidates);
	if (!Func->GetOwnerClass()->HasAnyClassFlags(CLASS_Native))
	{
		DMVTargetFilter_Base_eventSortCandidates_Parms Parms;
		Parms.PotentialTargets=PotentialTargets;
	ProcessEvent(Func,&Parms);
		return Parms.ReturnValue;
	}
	else
	{
		return SortCandidates_Implementation(PotentialTargets);
	}
}
struct Z_Construct_UFunction_UDMVTargetFilter_Base_SortCandidates_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** */" },
#endif
		{ "ModuleRelativePath", "Public/Filters/DMVTargetFilter_Base.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PotentialTargets_MetaData[] = {
		{ "EditInline", "true" },
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ReturnValue_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_PotentialTargets_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_PotentialTargets;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UDMVTargetFilter_Base_SortCandidates_Statics::NewProp_PotentialTargets_Inner = { "PotentialTargets", nullptr, (EPropertyFlags)0x0000000000080000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_UDMVTargetComponent_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UDMVTargetFilter_Base_SortCandidates_Statics::NewProp_PotentialTargets = { "PotentialTargets", nullptr, (EPropertyFlags)0x0010008008000182, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DMVTargetFilter_Base_eventSortCandidates_Parms, PotentialTargets), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PotentialTargets_MetaData), NewProp_PotentialTargets_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UDMVTargetFilter_Base_SortCandidates_Statics::NewProp_ReturnValue_Inner = { "ReturnValue", nullptr, (EPropertyFlags)0x0000000000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_UDMVTargetComponent_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UDMVTargetFilter_Base_SortCandidates_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010008000000588, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DMVTargetFilter_Base_eventSortCandidates_Parms, ReturnValue), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ReturnValue_MetaData), NewProp_ReturnValue_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDMVTargetFilter_Base_SortCandidates_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDMVTargetFilter_Base_SortCandidates_Statics::NewProp_PotentialTargets_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDMVTargetFilter_Base_SortCandidates_Statics::NewProp_PotentialTargets,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDMVTargetFilter_Base_SortCandidates_Statics::NewProp_ReturnValue_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDMVTargetFilter_Base_SortCandidates_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDMVTargetFilter_Base_SortCandidates_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDMVTargetFilter_Base_SortCandidates_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UDMVTargetFilter_Base, nullptr, "SortCandidates", Z_Construct_UFunction_UDMVTargetFilter_Base_SortCandidates_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDMVTargetFilter_Base_SortCandidates_Statics::PropPointers), sizeof(DMVTargetFilter_Base_eventSortCandidates_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x0C420C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDMVTargetFilter_Base_SortCandidates_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDMVTargetFilter_Base_SortCandidates_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(DMVTargetFilter_Base_eventSortCandidates_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UDMVTargetFilter_Base_SortCandidates()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDMVTargetFilter_Base_SortCandidates_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UDMVTargetFilter_Base::execSortCandidates)
{
	P_GET_TARRAY_REF(UDMVTargetComponent*,Z_Param_Out_PotentialTargets);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(TArray<UDMVTargetComponent*>*)Z_Param__Result=P_THIS->SortCandidates_Implementation(Z_Param_Out_PotentialTargets);
	P_NATIVE_END;
}
// ********** End Class UDMVTargetFilter_Base Function SortCandidates ******************************

// ********** Begin Class UDMVTargetFilter_Base Function SpawnActorToScan **************************
struct Z_Construct_UFunction_UDMVTargetFilter_Base_SpawnActorToScan_Statics
{
	struct DMVTargetFilter_Base_eventSpawnActorToScan_Parms
	{
		APlayerController* PlayerController;
		UDMVTargetComponent* Target;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** */" },
#endif
		{ "ModuleRelativePath", "Public/Filters/DMVTargetFilter_Base.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Target_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_PlayerController;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Target;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UDMVTargetFilter_Base_SpawnActorToScan_Statics::NewProp_PlayerController = { "PlayerController", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DMVTargetFilter_Base_eventSpawnActorToScan_Parms, PlayerController), Z_Construct_UClass_APlayerController_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UDMVTargetFilter_Base_SpawnActorToScan_Statics::NewProp_Target = { "Target", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DMVTargetFilter_Base_eventSpawnActorToScan_Parms, Target), Z_Construct_UClass_UDMVTargetComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Target_MetaData), NewProp_Target_MetaData) };
void Z_Construct_UFunction_UDMVTargetFilter_Base_SpawnActorToScan_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((DMVTargetFilter_Base_eventSpawnActorToScan_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UDMVTargetFilter_Base_SpawnActorToScan_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(DMVTargetFilter_Base_eventSpawnActorToScan_Parms), &Z_Construct_UFunction_UDMVTargetFilter_Base_SpawnActorToScan_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDMVTargetFilter_Base_SpawnActorToScan_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDMVTargetFilter_Base_SpawnActorToScan_Statics::NewProp_PlayerController,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDMVTargetFilter_Base_SpawnActorToScan_Statics::NewProp_Target,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDMVTargetFilter_Base_SpawnActorToScan_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDMVTargetFilter_Base_SpawnActorToScan_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDMVTargetFilter_Base_SpawnActorToScan_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UDMVTargetFilter_Base, nullptr, "SpawnActorToScan", Z_Construct_UFunction_UDMVTargetFilter_Base_SpawnActorToScan_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDMVTargetFilter_Base_SpawnActorToScan_Statics::PropPointers), sizeof(Z_Construct_UFunction_UDMVTargetFilter_Base_SpawnActorToScan_Statics::DMVTargetFilter_Base_eventSpawnActorToScan_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDMVTargetFilter_Base_SpawnActorToScan_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDMVTargetFilter_Base_SpawnActorToScan_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UDMVTargetFilter_Base_SpawnActorToScan_Statics::DMVTargetFilter_Base_eventSpawnActorToScan_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UDMVTargetFilter_Base_SpawnActorToScan()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDMVTargetFilter_Base_SpawnActorToScan_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UDMVTargetFilter_Base::execSpawnActorToScan)
{
	P_GET_OBJECT(APlayerController,Z_Param_PlayerController);
	P_GET_OBJECT(UDMVTargetComponent,Z_Param_Target);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->SpawnActorToScan(Z_Param_PlayerController,Z_Param_Target);
	P_NATIVE_END;
}
// ********** End Class UDMVTargetFilter_Base Function SpawnActorToScan ****************************

// ********** Begin Class UDMVTargetFilter_Base ****************************************************
void UDMVTargetFilter_Base::StaticRegisterNativesUDMVTargetFilter_Base()
{
	UClass* Class = UDMVTargetFilter_Base::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "Initialize", &UDMVTargetFilter_Base::execInitialize },
		{ "PerformFilter", &UDMVTargetFilter_Base::execPerformFilter },
		{ "SortCandidates", &UDMVTargetFilter_Base::execSortCandidates },
		{ "SpawnActorToScan", &UDMVTargetFilter_Base::execSpawnActorToScan },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
FClassRegistrationInfo Z_Registration_Info_UClass_UDMVTargetFilter_Base;
UClass* UDMVTargetFilter_Base::GetPrivateStaticClass()
{
	using TClass = UDMVTargetFilter_Base;
	if (!Z_Registration_Info_UClass_UDMVTargetFilter_Base.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			StaticPackage(),
			TEXT("DMVTargetFilter_Base"),
			Z_Registration_Info_UClass_UDMVTargetFilter_Base.InnerSingleton,
			StaticRegisterNativesUDMVTargetFilter_Base,
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
	return Z_Registration_Info_UClass_UDMVTargetFilter_Base.InnerSingleton;
}
UClass* Z_Construct_UClass_UDMVTargetFilter_Base_NoRegister()
{
	return UDMVTargetFilter_Base::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UDMVTargetFilter_Base_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "IncludePath", "Filters/DMVTargetFilter_Base.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/Filters/DMVTargetFilter_Base.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Threshold_MetaData[] = {
		{ "Category", "DMVTargetFilter_Base" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Compare value that can be distance, angle, health amount, etc. */" },
#endif
		{ "ModuleRelativePath", "Public/Filters/DMVTargetFilter_Base.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Compare value that can be distance, angle, health amount, etc." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ScanClass_MetaData[] = {
		{ "Category", "DMVTargetFilter_Base" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** */" },
#endif
		{ "ModuleRelativePath", "Public/Filters/DMVTargetFilter_Base.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Threshold;
	static const UECodeGen_Private::FClassPropertyParams NewProp_ScanClass;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UDMVTargetFilter_Base_Initialize, "Initialize" }, // 4048722646
		{ &Z_Construct_UFunction_UDMVTargetFilter_Base_PerformFilter, "PerformFilter" }, // 2334368244
		{ &Z_Construct_UFunction_UDMVTargetFilter_Base_SortCandidates, "SortCandidates" }, // 3187076426
		{ &Z_Construct_UFunction_UDMVTargetFilter_Base_SpawnActorToScan, "SpawnActorToScan" }, // 4015985734
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UDMVTargetFilter_Base>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UDMVTargetFilter_Base_Statics::NewProp_Threshold = { "Threshold", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDMVTargetFilter_Base, Threshold), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Threshold_MetaData), NewProp_Threshold_MetaData) };
const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_UDMVTargetFilter_Base_Statics::NewProp_ScanClass = { "ScanClass", nullptr, (EPropertyFlags)0x0014000000010015, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDMVTargetFilter_Base, ScanClass), Z_Construct_UClass_UClass, Z_Construct_UClass_ADMVScanForActors_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ScanClass_MetaData), NewProp_ScanClass_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UDMVTargetFilter_Base_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDMVTargetFilter_Base_Statics::NewProp_Threshold,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDMVTargetFilter_Base_Statics::NewProp_ScanClass,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UDMVTargetFilter_Base_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UDMVTargetFilter_Base_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UObject,
	(UObject* (*)())Z_Construct_UPackage__Script_DMV_TargetSystem,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UDMVTargetFilter_Base_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UDMVTargetFilter_Base_Statics::ClassParams = {
	&UDMVTargetFilter_Base::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_UDMVTargetFilter_Base_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_UDMVTargetFilter_Base_Statics::PropPointers),
	0,
	0x001010A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UDMVTargetFilter_Base_Statics::Class_MetaDataParams), Z_Construct_UClass_UDMVTargetFilter_Base_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UDMVTargetFilter_Base()
{
	if (!Z_Registration_Info_UClass_UDMVTargetFilter_Base.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UDMVTargetFilter_Base.OuterSingleton, Z_Construct_UClass_UDMVTargetFilter_Base_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UDMVTargetFilter_Base.OuterSingleton;
}
UDMVTargetFilter_Base::UDMVTargetFilter_Base(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UDMVTargetFilter_Base);
UDMVTargetFilter_Base::~UDMVTargetFilter_Base() {}
// ********** End Class UDMVTargetFilter_Base ******************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_WRH_proj_5_6_Plugins_DMV_TargetSystem_Source_DMV_TargetSystem_Public_Filters_DMVTargetFilter_Base_h__Script_DMV_TargetSystem_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UDMVTargetFilter_Base, UDMVTargetFilter_Base::StaticClass, TEXT("UDMVTargetFilter_Base"), &Z_Registration_Info_UClass_UDMVTargetFilter_Base, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UDMVTargetFilter_Base), 628188813U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_WRH_proj_5_6_Plugins_DMV_TargetSystem_Source_DMV_TargetSystem_Public_Filters_DMVTargetFilter_Base_h__Script_DMV_TargetSystem_2910528021(TEXT("/Script/DMV_TargetSystem"),
	Z_CompiledInDeferFile_FID_WRH_proj_5_6_Plugins_DMV_TargetSystem_Source_DMV_TargetSystem_Public_Filters_DMVTargetFilter_Base_h__Script_DMV_TargetSystem_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_WRH_proj_5_6_Plugins_DMV_TargetSystem_Source_DMV_TargetSystem_Public_Filters_DMVTargetFilter_Base_h__Script_DMV_TargetSystem_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
