// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Filters/DMVTargetFilter_Base.h"

#ifdef DMV_TARGETSYSTEM_DMVTargetFilter_Base_generated_h
#error "DMVTargetFilter_Base.generated.h already included, missing '#pragma once' in DMVTargetFilter_Base.h"
#endif
#define DMV_TARGETSYSTEM_DMVTargetFilter_Base_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

class APlayerController;
class UDMVTargetComponent;

// ********** Begin Class UDMVTargetFilter_Base ****************************************************
#define FID_WRH_proj_5_6_Plugins_DMV_TargetSystem_Source_DMV_TargetSystem_Public_Filters_DMVTargetFilter_Base_h_16_RPC_WRAPPERS_NO_PURE_DECLS \
	virtual TArray<UDMVTargetComponent*> SortCandidates_Implementation(TArray<UDMVTargetComponent*> const& PotentialTargets); \
	virtual TArray<UDMVTargetComponent*> PerformFilter_Implementation(TArray<UDMVTargetComponent*> const& PotentialTargets, APlayerController* PlayerController); \
	DECLARE_FUNCTION(execSortCandidates); \
	DECLARE_FUNCTION(execPerformFilter); \
	DECLARE_FUNCTION(execSpawnActorToScan); \
	DECLARE_FUNCTION(execInitialize);


#define FID_WRH_proj_5_6_Plugins_DMV_TargetSystem_Source_DMV_TargetSystem_Public_Filters_DMVTargetFilter_Base_h_16_CALLBACK_WRAPPERS
DMV_TARGETSYSTEM_API UClass* Z_Construct_UClass_UDMVTargetFilter_Base_NoRegister();

#define FID_WRH_proj_5_6_Plugins_DMV_TargetSystem_Source_DMV_TargetSystem_Public_Filters_DMVTargetFilter_Base_h_16_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUDMVTargetFilter_Base(); \
	friend struct Z_Construct_UClass_UDMVTargetFilter_Base_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend DMV_TARGETSYSTEM_API UClass* Z_Construct_UClass_UDMVTargetFilter_Base_NoRegister(); \
public: \
	DECLARE_CLASS2(UDMVTargetFilter_Base, UObject, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/DMV_TargetSystem"), Z_Construct_UClass_UDMVTargetFilter_Base_NoRegister) \
	DECLARE_SERIALIZER(UDMVTargetFilter_Base)


#define FID_WRH_proj_5_6_Plugins_DMV_TargetSystem_Source_DMV_TargetSystem_Public_Filters_DMVTargetFilter_Base_h_16_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UDMVTargetFilter_Base(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UDMVTargetFilter_Base(UDMVTargetFilter_Base&&) = delete; \
	UDMVTargetFilter_Base(const UDMVTargetFilter_Base&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UDMVTargetFilter_Base); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UDMVTargetFilter_Base); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UDMVTargetFilter_Base) \
	NO_API virtual ~UDMVTargetFilter_Base();


#define FID_WRH_proj_5_6_Plugins_DMV_TargetSystem_Source_DMV_TargetSystem_Public_Filters_DMVTargetFilter_Base_h_13_PROLOG
#define FID_WRH_proj_5_6_Plugins_DMV_TargetSystem_Source_DMV_TargetSystem_Public_Filters_DMVTargetFilter_Base_h_16_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_WRH_proj_5_6_Plugins_DMV_TargetSystem_Source_DMV_TargetSystem_Public_Filters_DMVTargetFilter_Base_h_16_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_WRH_proj_5_6_Plugins_DMV_TargetSystem_Source_DMV_TargetSystem_Public_Filters_DMVTargetFilter_Base_h_16_CALLBACK_WRAPPERS \
	FID_WRH_proj_5_6_Plugins_DMV_TargetSystem_Source_DMV_TargetSystem_Public_Filters_DMVTargetFilter_Base_h_16_INCLASS_NO_PURE_DECLS \
	FID_WRH_proj_5_6_Plugins_DMV_TargetSystem_Source_DMV_TargetSystem_Public_Filters_DMVTargetFilter_Base_h_16_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UDMVTargetFilter_Base;

// ********** End Class UDMVTargetFilter_Base ******************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_WRH_proj_5_6_Plugins_DMV_TargetSystem_Source_DMV_TargetSystem_Public_Filters_DMVTargetFilter_Base_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
