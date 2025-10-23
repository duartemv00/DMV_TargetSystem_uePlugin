// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "DMVTargetEvaluator.h"

#ifdef DMV_TARGETSYSTEM_DMVTargetEvaluator_generated_h
#error "DMVTargetEvaluator.generated.h already included, missing '#pragma once' in DMVTargetEvaluator.h"
#endif
#define DMV_TARGETSYSTEM_DMVTargetEvaluator_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

class AActor;
class UDMVTargetComponent;
class UXM_TargetEvaluationContext;
struct FFilterInformation;
struct FGameplayTag;

// ********** Begin ScriptStruct FTargetInputContext ***********************************************
#define FID_WRH_proj_5_6_Plugins_DMV_TargetSystem_Source_DMV_TargetSystem_Public_DMVTargetEvaluator_h_15_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FTargetInputContext_Statics; \
	DMV_TARGETSYSTEM_API static class UScriptStruct* StaticStruct();


struct FTargetInputContext;
// ********** End ScriptStruct FTargetInputContext *************************************************

// ********** Begin Delegate FFilteringFinished ****************************************************
#define FID_WRH_proj_5_6_Plugins_DMV_TargetSystem_Source_DMV_TargetSystem_Public_DMVTargetEvaluator_h_31_DELEGATE \
DMV_TARGETSYSTEM_API void FFilteringFinished_DelegateWrapper(const FScriptDelegate& FilteringFinished, UDMVTargetComponent* Targets);


// ********** End Delegate FFilteringFinished ******************************************************

// ********** Begin Delegate FValidPlayerAutoTargetFound *******************************************
#define FID_WRH_proj_5_6_Plugins_DMV_TargetSystem_Source_DMV_TargetSystem_Public_DMVTargetEvaluator_h_33_DELEGATE \
DMV_TARGETSYSTEM_API void FValidPlayerAutoTargetFound_DelegateWrapper(const FScriptDelegate& ValidPlayerAutoTargetFound, AActor* Actor);


// ********** End Delegate FValidPlayerAutoTargetFound *********************************************

// ********** Begin Delegate FPlayerAutoTargetsCleared *********************************************
#define FID_WRH_proj_5_6_Plugins_DMV_TargetSystem_Source_DMV_TargetSystem_Public_DMVTargetEvaluator_h_35_DELEGATE \
DMV_TARGETSYSTEM_API void FPlayerAutoTargetsCleared_DelegateWrapper(const FScriptDelegate& PlayerAutoTargetsCleared);


// ********** End Delegate FPlayerAutoTargetsCleared ***********************************************

// ********** Begin Class UXM_TargetEvaluationContext **********************************************
DMV_TARGETSYSTEM_API UClass* Z_Construct_UClass_UXM_TargetEvaluationContext_NoRegister();

#define FID_WRH_proj_5_6_Plugins_DMV_TargetSystem_Source_DMV_TargetSystem_Public_DMVTargetEvaluator_h_43_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUXM_TargetEvaluationContext(); \
	friend struct Z_Construct_UClass_UXM_TargetEvaluationContext_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend DMV_TARGETSYSTEM_API UClass* Z_Construct_UClass_UXM_TargetEvaluationContext_NoRegister(); \
public: \
	DECLARE_CLASS2(UXM_TargetEvaluationContext, UObject, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/DMV_TargetSystem"), Z_Construct_UClass_UXM_TargetEvaluationContext_NoRegister) \
	DECLARE_SERIALIZER(UXM_TargetEvaluationContext)


#define FID_WRH_proj_5_6_Plugins_DMV_TargetSystem_Source_DMV_TargetSystem_Public_DMVTargetEvaluator_h_43_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UXM_TargetEvaluationContext(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UXM_TargetEvaluationContext(UXM_TargetEvaluationContext&&) = delete; \
	UXM_TargetEvaluationContext(const UXM_TargetEvaluationContext&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UXM_TargetEvaluationContext); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UXM_TargetEvaluationContext); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UXM_TargetEvaluationContext) \
	NO_API virtual ~UXM_TargetEvaluationContext();


#define FID_WRH_proj_5_6_Plugins_DMV_TargetSystem_Source_DMV_TargetSystem_Public_DMVTargetEvaluator_h_40_PROLOG
#define FID_WRH_proj_5_6_Plugins_DMV_TargetSystem_Source_DMV_TargetSystem_Public_DMVTargetEvaluator_h_43_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_WRH_proj_5_6_Plugins_DMV_TargetSystem_Source_DMV_TargetSystem_Public_DMVTargetEvaluator_h_43_INCLASS_NO_PURE_DECLS \
	FID_WRH_proj_5_6_Plugins_DMV_TargetSystem_Source_DMV_TargetSystem_Public_DMVTargetEvaluator_h_43_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UXM_TargetEvaluationContext;

// ********** End Class UXM_TargetEvaluationContext ************************************************

// ********** Begin ScriptStruct FEvaluationContexts ***********************************************
#define FID_WRH_proj_5_6_Plugins_DMV_TargetSystem_Source_DMV_TargetSystem_Public_DMVTargetEvaluator_h_69_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FEvaluationContexts_Statics; \
	DMV_TARGETSYSTEM_API static class UScriptStruct* StaticStruct();


struct FEvaluationContexts;
// ********** End ScriptStruct FEvaluationContexts *************************************************

// ********** Begin ScriptStruct FFilterInformation ************************************************
#define FID_WRH_proj_5_6_Plugins_DMV_TargetSystem_Source_DMV_TargetSystem_Public_DMVTargetEvaluator_h_78_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FFilterInformation_Statics; \
	DMV_TARGETSYSTEM_API static class UScriptStruct* StaticStruct();


struct FFilterInformation;
// ********** End ScriptStruct FFilterInformation **************************************************

// ********** Begin ScriptStruct FEvaluationFilters ************************************************
#define FID_WRH_proj_5_6_Plugins_DMV_TargetSystem_Source_DMV_TargetSystem_Public_DMVTargetEvaluator_h_99_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FEvaluationFilters_Statics; \
	DMV_TARGETSYSTEM_API static class UScriptStruct* StaticStruct();


struct FEvaluationFilters;
// ********** End ScriptStruct FEvaluationFilters **************************************************

// ********** Begin Class UDMVTargetEvaluator ******************************************************
#define FID_WRH_proj_5_6_Plugins_DMV_TargetSystem_Source_DMV_TargetSystem_Public_DMVTargetEvaluator_h_115_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execGetCurrentTargetComponent); \
	DECLARE_FUNCTION(execGetCurrentTarget); \
	DECLARE_FUNCTION(execRemoveTargetEvaluationContext); \
	DECLARE_FUNCTION(execAddTargetEvaluationContext);


DMV_TARGETSYSTEM_API UClass* Z_Construct_UClass_UDMVTargetEvaluator_NoRegister();

#define FID_WRH_proj_5_6_Plugins_DMV_TargetSystem_Source_DMV_TargetSystem_Public_DMVTargetEvaluator_h_115_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUDMVTargetEvaluator(); \
	friend struct Z_Construct_UClass_UDMVTargetEvaluator_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend DMV_TARGETSYSTEM_API UClass* Z_Construct_UClass_UDMVTargetEvaluator_NoRegister(); \
public: \
	DECLARE_CLASS2(UDMVTargetEvaluator, UActorComponent, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/DMV_TargetSystem"), Z_Construct_UClass_UDMVTargetEvaluator_NoRegister) \
	DECLARE_SERIALIZER(UDMVTargetEvaluator)


#define FID_WRH_proj_5_6_Plugins_DMV_TargetSystem_Source_DMV_TargetSystem_Public_DMVTargetEvaluator_h_115_ENHANCED_CONSTRUCTORS \
	/** Deleted move- and copy-constructors, should never be used */ \
	UDMVTargetEvaluator(UDMVTargetEvaluator&&) = delete; \
	UDMVTargetEvaluator(const UDMVTargetEvaluator&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UDMVTargetEvaluator); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UDMVTargetEvaluator); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UDMVTargetEvaluator) \
	NO_API virtual ~UDMVTargetEvaluator();


#define FID_WRH_proj_5_6_Plugins_DMV_TargetSystem_Source_DMV_TargetSystem_Public_DMVTargetEvaluator_h_112_PROLOG
#define FID_WRH_proj_5_6_Plugins_DMV_TargetSystem_Source_DMV_TargetSystem_Public_DMVTargetEvaluator_h_115_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_WRH_proj_5_6_Plugins_DMV_TargetSystem_Source_DMV_TargetSystem_Public_DMVTargetEvaluator_h_115_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_WRH_proj_5_6_Plugins_DMV_TargetSystem_Source_DMV_TargetSystem_Public_DMVTargetEvaluator_h_115_INCLASS_NO_PURE_DECLS \
	FID_WRH_proj_5_6_Plugins_DMV_TargetSystem_Source_DMV_TargetSystem_Public_DMVTargetEvaluator_h_115_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UDMVTargetEvaluator;

// ********** End Class UDMVTargetEvaluator ********************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_WRH_proj_5_6_Plugins_DMV_TargetSystem_Source_DMV_TargetSystem_Public_DMVTargetEvaluator_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
