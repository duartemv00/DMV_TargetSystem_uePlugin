// Copyright DuarteMV. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "IDetailCustomization.h"

struct FPropertyAndParent;

/**
 * Registered for UDMVTargetFilter_Data. 
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
