// Copyright Epic Games, Inc. All Rights Reserved.

#include "DMVTargetFilterDataCustomization.h"
#include "DetailLayoutBuilder.h"
#include "Filters/DMVTargetFilter_Base.h"
#include "IDetailsView.h"
#include "PropertyEditorDelegates.h"

TSharedRef<IDetailCustomization> FDMVTargetFilterDataCustomization::MakeInstance()
{
	return MakeShared<FDMVTargetFilterDataCustomization>();
}

void FDMVTargetFilterDataCustomization::CustomizeDetails(IDetailLayoutBuilder& DetailBuilder)
{
	if (const TSharedPtr<IDetailsView> DetailsView = DetailBuilder.GetDetailsViewSharedPtr())
	{
		DetailsView->SetIsPropertyVisibleDelegate(
			FIsPropertyVisible::CreateStatic(&FDMVTargetFilterDataCustomization::IsFilterPropertyVisible));
	}
}

bool FDMVTargetFilterDataCustomization::IsFilterPropertyVisible(const FPropertyAndParent& PropertyAndParent)
{
	const FProperty& Property = PropertyAndParent.Property;
	if (!Property.HasAnyPropertyFlags(CPF_DisableEditOnInstance))
	{
		return true;
	}

	// Only hide EditDefaultsOnly properties declared on filters - if this details view ever shows
	// anything else, leave its own EditDefaultsOnly properties (if any) alone.
	const UClass* OwnerClass = Property.GetOwnerClass();
	return !OwnerClass || !OwnerClass->IsChildOf(UDMVTargetFilter_Base::StaticClass());
}
