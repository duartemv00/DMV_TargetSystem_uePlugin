// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "DMVTargetComponent.h"

#ifdef DMV_TARGETSYSTEM_DMVTargetComponent_generated_h
#error "DMVTargetComponent.generated.h already included, missing '#pragma once' in DMVTargetComponent.h"
#endif
#define DMV_TARGETSYSTEM_DMVTargetComponent_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

// ********** Begin Class UDMVTargetComponent ******************************************************
#define FID_WRH_proj_5_6_Plugins_DMV_TargetSystem_Source_DMV_TargetSystem_Public_DMVTargetComponent_h_16_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execResetInterest);


DMV_TARGETSYSTEM_API UClass* Z_Construct_UClass_UDMVTargetComponent_NoRegister();

#define FID_WRH_proj_5_6_Plugins_DMV_TargetSystem_Source_DMV_TargetSystem_Public_DMVTargetComponent_h_16_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUDMVTargetComponent(); \
	friend struct Z_Construct_UClass_UDMVTargetComponent_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend DMV_TARGETSYSTEM_API UClass* Z_Construct_UClass_UDMVTargetComponent_NoRegister(); \
public: \
	DECLARE_CLASS2(UDMVTargetComponent, USceneComponent, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/DMV_TargetSystem"), Z_Construct_UClass_UDMVTargetComponent_NoRegister) \
	DECLARE_SERIALIZER(UDMVTargetComponent)


#define FID_WRH_proj_5_6_Plugins_DMV_TargetSystem_Source_DMV_TargetSystem_Public_DMVTargetComponent_h_16_ENHANCED_CONSTRUCTORS \
	/** Deleted move- and copy-constructors, should never be used */ \
	UDMVTargetComponent(UDMVTargetComponent&&) = delete; \
	UDMVTargetComponent(const UDMVTargetComponent&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UDMVTargetComponent); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UDMVTargetComponent); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UDMVTargetComponent) \
	NO_API virtual ~UDMVTargetComponent();


#define FID_WRH_proj_5_6_Plugins_DMV_TargetSystem_Source_DMV_TargetSystem_Public_DMVTargetComponent_h_13_PROLOG
#define FID_WRH_proj_5_6_Plugins_DMV_TargetSystem_Source_DMV_TargetSystem_Public_DMVTargetComponent_h_16_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_WRH_proj_5_6_Plugins_DMV_TargetSystem_Source_DMV_TargetSystem_Public_DMVTargetComponent_h_16_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_WRH_proj_5_6_Plugins_DMV_TargetSystem_Source_DMV_TargetSystem_Public_DMVTargetComponent_h_16_INCLASS_NO_PURE_DECLS \
	FID_WRH_proj_5_6_Plugins_DMV_TargetSystem_Source_DMV_TargetSystem_Public_DMVTargetComponent_h_16_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UDMVTargetComponent;

// ********** End Class UDMVTargetComponent ********************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_WRH_proj_5_6_Plugins_DMV_TargetSystem_Source_DMV_TargetSystem_Public_DMVTargetComponent_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
