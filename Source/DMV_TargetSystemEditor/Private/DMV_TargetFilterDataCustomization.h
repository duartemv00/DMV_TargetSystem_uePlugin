// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "IDetailCustomization.h"

struct FPropertyAndParent;

/**
 * Registered for UDMVTargetFilter_Data. Enforces the DMV_TargetSystem convention (see the
 * plugin's README, "Convention: which properties should be per-usage tunable") on the filter
 * instances shown inline in its Instanced FilterList: hides every EditDefaultsOnly property on
 * those filters, regardless of the generic Data Asset editor's Details view defaulting to Show
 * (FDetailsViewArgs::DefaultsOnlyVisibility) rather than Hide/Automatic.
 *
 * This can't be done via a class layout customization registered for UDMVTargetFilter_Base
 * itself (which is what this file used to do): the property editor never queries registered
 * class customizations for EditInlineNew objects shown inline as a property's value -
 * DetailLayoutHelpers::UpdateSinglePropertyMapRecursive explicitly skips recursing into them
 * ("Edit inline new children are not supported for customization yet"), so a customization
 * registered for UDMVTargetFilter_Base is simply never invoked for a filter sitting inside
 * FilterList. Hooking the owning IDetailsView's IsPropertyVisible delegate instead works because
 * that delegate is consulted per-row for every property shown in the view, including rows
 * generated for nested instanced objects (see FDetailPropertyRow's use of
 * IDetailLayoutBuilder::IsPropertyVisible).
 */
class FDMVTargetFilterDataCustomization : public IDetailCustomization
{
public:
	static TSharedRef<IDetailCustomization> MakeInstance();

	//~ Begin IDetailCustomization interface
	virtual void CustomizeDetails(IDetailLayoutBuilder& DetailBuilder) override;
	//~ End IDetailCustomization interface

private:
	static bool IsFilterPropertyVisible(const FPropertyAndParent& PropertyAndParent);
};
