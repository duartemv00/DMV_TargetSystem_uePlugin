// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Filters/Scan/DMVScanForActors.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

void EmptyLinkFunctionForGeneratedCodeDMVScanForActors() {}

// ********** Begin Cross Module References ********************************************************
DMV_TARGETSYSTEM_API UClass* Z_Construct_UClass_ADMVScanForActors();
DMV_TARGETSYSTEM_API UClass* Z_Construct_UClass_ADMVScanForActors_NoRegister();
DMV_TARGETSYSTEM_API UClass* Z_Construct_UClass_UDMVTargetComponent_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_AActor();
ENGINE_API UClass* Z_Construct_UClass_APlayerController_NoRegister();
UPackage* Z_Construct_UPackage__Script_DMV_TargetSystem();
// ********** End Cross Module References **********************************************************

// ********** Begin Class ADMVScanForActors Function PerformScan ***********************************
struct DMVScanForActors_eventPerformScan_Parms
{
	APlayerController* PlayerController;
	UDMVTargetComponent* Target;
	bool ReturnValue;

	/** Constructor, initializes return property only **/
	DMVScanForActors_eventPerformScan_Parms()
		: ReturnValue(false)
	{
	}
};
static FName NAME_ADMVScanForActors_PerformScan = FName(TEXT("PerformScan"));
bool ADMVScanForActors::PerformScan(APlayerController* PlayerController, UDMVTargetComponent* Target)
{
	UFunction* Func = FindFunctionChecked(NAME_ADMVScanForActors_PerformScan);
	if (!Func->GetOwnerClass()->HasAnyClassFlags(CLASS_Native))
	{
		DMVScanForActors_eventPerformScan_Parms Parms;
		Parms.PlayerController=PlayerController;
		Parms.Target=Target;
	ProcessEvent(Func,&Parms);
		return !!Parms.ReturnValue;
	}
	else
	{
		return PerformScan_Implementation(PlayerController, Target);
	}
}
struct Z_Construct_UFunction_ADMVScanForActors_PerformScan_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Filters/Scan/DMVScanForActors.h" },
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
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ADMVScanForActors_PerformScan_Statics::NewProp_PlayerController = { "PlayerController", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DMVScanForActors_eventPerformScan_Parms, PlayerController), Z_Construct_UClass_APlayerController_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ADMVScanForActors_PerformScan_Statics::NewProp_Target = { "Target", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DMVScanForActors_eventPerformScan_Parms, Target), Z_Construct_UClass_UDMVTargetComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Target_MetaData), NewProp_Target_MetaData) };
void Z_Construct_UFunction_ADMVScanForActors_PerformScan_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((DMVScanForActors_eventPerformScan_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_ADMVScanForActors_PerformScan_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(DMVScanForActors_eventPerformScan_Parms), &Z_Construct_UFunction_ADMVScanForActors_PerformScan_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ADMVScanForActors_PerformScan_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ADMVScanForActors_PerformScan_Statics::NewProp_PlayerController,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ADMVScanForActors_PerformScan_Statics::NewProp_Target,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ADMVScanForActors_PerformScan_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ADMVScanForActors_PerformScan_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ADMVScanForActors_PerformScan_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_ADMVScanForActors, nullptr, "PerformScan", Z_Construct_UFunction_ADMVScanForActors_PerformScan_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ADMVScanForActors_PerformScan_Statics::PropPointers), sizeof(DMVScanForActors_eventPerformScan_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x0C020C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ADMVScanForActors_PerformScan_Statics::Function_MetaDataParams), Z_Construct_UFunction_ADMVScanForActors_PerformScan_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(DMVScanForActors_eventPerformScan_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ADMVScanForActors_PerformScan()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ADMVScanForActors_PerformScan_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ADMVScanForActors::execPerformScan)
{
	P_GET_OBJECT(APlayerController,Z_Param_PlayerController);
	P_GET_OBJECT(UDMVTargetComponent,Z_Param_Target);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->PerformScan_Implementation(Z_Param_PlayerController,Z_Param_Target);
	P_NATIVE_END;
}
// ********** End Class ADMVScanForActors Function PerformScan *************************************

// ********** Begin Class ADMVScanForActors ********************************************************
void ADMVScanForActors::StaticRegisterNativesADMVScanForActors()
{
	UClass* Class = ADMVScanForActors::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "PerformScan", &ADMVScanForActors::execPerformScan },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
FClassRegistrationInfo Z_Registration_Info_UClass_ADMVScanForActors;
UClass* ADMVScanForActors::GetPrivateStaticClass()
{
	using TClass = ADMVScanForActors;
	if (!Z_Registration_Info_UClass_ADMVScanForActors.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			StaticPackage(),
			TEXT("DMVScanForActors"),
			Z_Registration_Info_UClass_ADMVScanForActors.InnerSingleton,
			StaticRegisterNativesADMVScanForActors,
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
	return Z_Registration_Info_UClass_ADMVScanForActors.InnerSingleton;
}
UClass* Z_Construct_UClass_ADMVScanForActors_NoRegister()
{
	return ADMVScanForActors::GetPrivateStaticClass();
}
struct Z_Construct_UClass_ADMVScanForActors_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "Filters/Scan/DMVScanForActors.h" },
		{ "ModuleRelativePath", "Public/Filters/Scan/DMVScanForActors.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_ADMVScanForActors_PerformScan, "PerformScan" }, // 2838485039
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ADMVScanForActors>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_ADMVScanForActors_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AActor,
	(UObject* (*)())Z_Construct_UPackage__Script_DMV_TargetSystem,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ADMVScanForActors_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_ADMVScanForActors_Statics::ClassParams = {
	&ADMVScanForActors::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	0,
	0,
	0x009001A5u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ADMVScanForActors_Statics::Class_MetaDataParams), Z_Construct_UClass_ADMVScanForActors_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_ADMVScanForActors()
{
	if (!Z_Registration_Info_UClass_ADMVScanForActors.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ADMVScanForActors.OuterSingleton, Z_Construct_UClass_ADMVScanForActors_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_ADMVScanForActors.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR(ADMVScanForActors);
ADMVScanForActors::~ADMVScanForActors() {}
// ********** End Class ADMVScanForActors **********************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_WRH_proj_5_6_Plugins_DMV_TargetSystem_Source_DMV_TargetSystem_Public_Filters_Scan_DMVScanForActors_h__Script_DMV_TargetSystem_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ADMVScanForActors, ADMVScanForActors::StaticClass, TEXT("ADMVScanForActors"), &Z_Registration_Info_UClass_ADMVScanForActors, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ADMVScanForActors), 3183739234U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_WRH_proj_5_6_Plugins_DMV_TargetSystem_Source_DMV_TargetSystem_Public_Filters_Scan_DMVScanForActors_h__Script_DMV_TargetSystem_3569039041(TEXT("/Script/DMV_TargetSystem"),
	Z_CompiledInDeferFile_FID_WRH_proj_5_6_Plugins_DMV_TargetSystem_Source_DMV_TargetSystem_Public_Filters_Scan_DMVScanForActors_h__Script_DMV_TargetSystem_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_WRH_proj_5_6_Plugins_DMV_TargetSystem_Source_DMV_TargetSystem_Public_Filters_Scan_DMVScanForActors_h__Script_DMV_TargetSystem_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
