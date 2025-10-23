// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "DMVTargetSubsystem.h"

#ifdef DMV_TARGETSYSTEM_DMVTargetSubsystem_generated_h
#error "DMVTargetSubsystem.generated.h already included, missing '#pragma once' in DMVTargetSubsystem.h"
#endif
#define DMV_TARGETSYSTEM_DMVTargetSubsystem_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

class UDMVTargetComponent;
struct FGameplayTag;
struct FGameplayTagContainer;

// ********** Begin ScriptStruct FPlayerTargetList *************************************************
#define FID_WRH_proj_5_6_Plugins_DMV_TargetSystem_Source_DMV_TargetSystem_Public_DMVTargetSubsystem_h_19_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FPlayerTargetList_Statics; \
	DMV_TARGETSYSTEM_API static class UScriptStruct* StaticStruct();


struct FPlayerTargetList;
// ********** End ScriptStruct FPlayerTargetList ***************************************************

// ********** Begin Class UDMVTargetSubsystem ******************************************************
#define FID_WRH_proj_5_6_Plugins_DMV_TargetSystem_Source_DMV_TargetSystem_Public_DMVTargetSubsystem_h_60_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execUnregisterTargetForContexts); \
	DECLARE_FUNCTION(execUnregisterTargetForContext); \
	DECLARE_FUNCTION(execRegisterTargetForContexts); \
	DECLARE_FUNCTION(execRegisterTargetForContext);


DMV_TARGETSYSTEM_API UClass* Z_Construct_UClass_UDMVTargetSubsystem_NoRegister();

#define FID_WRH_proj_5_6_Plugins_DMV_TargetSystem_Source_DMV_TargetSystem_Public_DMVTargetSubsystem_h_60_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUDMVTargetSubsystem(); \
	friend struct Z_Construct_UClass_UDMVTargetSubsystem_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend DMV_TARGETSYSTEM_API UClass* Z_Construct_UClass_UDMVTargetSubsystem_NoRegister(); \
public: \
	DECLARE_CLASS2(UDMVTargetSubsystem, UGameInstanceSubsystem, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/DMV_TargetSystem"), Z_Construct_UClass_UDMVTargetSubsystem_NoRegister) \
	DECLARE_SERIALIZER(UDMVTargetSubsystem)


#define FID_WRH_proj_5_6_Plugins_DMV_TargetSystem_Source_DMV_TargetSystem_Public_DMVTargetSubsystem_h_60_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UDMVTargetSubsystem(); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UDMVTargetSubsystem(UDMVTargetSubsystem&&) = delete; \
	UDMVTargetSubsystem(const UDMVTargetSubsystem&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UDMVTargetSubsystem); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UDMVTargetSubsystem); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UDMVTargetSubsystem) \
	NO_API virtual ~UDMVTargetSubsystem();


#define FID_WRH_proj_5_6_Plugins_DMV_TargetSystem_Source_DMV_TargetSystem_Public_DMVTargetSubsystem_h_57_PROLOG
#define FID_WRH_proj_5_6_Plugins_DMV_TargetSystem_Source_DMV_TargetSystem_Public_DMVTargetSubsystem_h_60_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_WRH_proj_5_6_Plugins_DMV_TargetSystem_Source_DMV_TargetSystem_Public_DMVTargetSubsystem_h_60_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_WRH_proj_5_6_Plugins_DMV_TargetSystem_Source_DMV_TargetSystem_Public_DMVTargetSubsystem_h_60_INCLASS_NO_PURE_DECLS \
	FID_WRH_proj_5_6_Plugins_DMV_TargetSystem_Source_DMV_TargetSystem_Public_DMVTargetSubsystem_h_60_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UDMVTargetSubsystem;

// ********** End Class UDMVTargetSubsystem ********************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_WRH_proj_5_6_Plugins_DMV_TargetSystem_Source_DMV_TargetSystem_Public_DMVTargetSubsystem_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
