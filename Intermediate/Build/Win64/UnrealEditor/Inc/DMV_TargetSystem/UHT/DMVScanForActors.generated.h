// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Filters/Scan/DMVScanForActors.h"

#ifdef DMV_TARGETSYSTEM_DMVScanForActors_generated_h
#error "DMVScanForActors.generated.h already included, missing '#pragma once' in DMVScanForActors.h"
#endif
#define DMV_TARGETSYSTEM_DMVScanForActors_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

class APlayerController;
class UDMVTargetComponent;

// ********** Begin Class ADMVScanForActors ********************************************************
#define FID_WRH_proj_5_6_Plugins_DMV_TargetSystem_Source_DMV_TargetSystem_Public_Filters_Scan_DMVScanForActors_h_12_RPC_WRAPPERS_NO_PURE_DECLS \
	virtual bool PerformScan_Implementation(APlayerController* PlayerController, UDMVTargetComponent* Target); \
	DECLARE_FUNCTION(execPerformScan);


#define FID_WRH_proj_5_6_Plugins_DMV_TargetSystem_Source_DMV_TargetSystem_Public_Filters_Scan_DMVScanForActors_h_12_CALLBACK_WRAPPERS
DMV_TARGETSYSTEM_API UClass* Z_Construct_UClass_ADMVScanForActors_NoRegister();

#define FID_WRH_proj_5_6_Plugins_DMV_TargetSystem_Source_DMV_TargetSystem_Public_Filters_Scan_DMVScanForActors_h_12_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesADMVScanForActors(); \
	friend struct Z_Construct_UClass_ADMVScanForActors_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend DMV_TARGETSYSTEM_API UClass* Z_Construct_UClass_ADMVScanForActors_NoRegister(); \
public: \
	DECLARE_CLASS2(ADMVScanForActors, AActor, COMPILED_IN_FLAGS(CLASS_Abstract | CLASS_Config), CASTCLASS_None, TEXT("/Script/DMV_TargetSystem"), Z_Construct_UClass_ADMVScanForActors_NoRegister) \
	DECLARE_SERIALIZER(ADMVScanForActors)


#define FID_WRH_proj_5_6_Plugins_DMV_TargetSystem_Source_DMV_TargetSystem_Public_Filters_Scan_DMVScanForActors_h_12_ENHANCED_CONSTRUCTORS \
	/** Deleted move- and copy-constructors, should never be used */ \
	ADMVScanForActors(ADMVScanForActors&&) = delete; \
	ADMVScanForActors(const ADMVScanForActors&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ADMVScanForActors); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ADMVScanForActors); \
	DEFINE_ABSTRACT_DEFAULT_CONSTRUCTOR_CALL(ADMVScanForActors) \
	NO_API virtual ~ADMVScanForActors();


#define FID_WRH_proj_5_6_Plugins_DMV_TargetSystem_Source_DMV_TargetSystem_Public_Filters_Scan_DMVScanForActors_h_9_PROLOG
#define FID_WRH_proj_5_6_Plugins_DMV_TargetSystem_Source_DMV_TargetSystem_Public_Filters_Scan_DMVScanForActors_h_12_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_WRH_proj_5_6_Plugins_DMV_TargetSystem_Source_DMV_TargetSystem_Public_Filters_Scan_DMVScanForActors_h_12_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_WRH_proj_5_6_Plugins_DMV_TargetSystem_Source_DMV_TargetSystem_Public_Filters_Scan_DMVScanForActors_h_12_CALLBACK_WRAPPERS \
	FID_WRH_proj_5_6_Plugins_DMV_TargetSystem_Source_DMV_TargetSystem_Public_Filters_Scan_DMVScanForActors_h_12_INCLASS_NO_PURE_DECLS \
	FID_WRH_proj_5_6_Plugins_DMV_TargetSystem_Source_DMV_TargetSystem_Public_Filters_Scan_DMVScanForActors_h_12_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class ADMVScanForActors;

// ********** End Class ADMVScanForActors **********************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_WRH_proj_5_6_Plugins_DMV_TargetSystem_Source_DMV_TargetSystem_Public_Filters_Scan_DMVScanForActors_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
