#pragma once

#include <iostream>
#include "AvatarAssetDefinintions.h"

using std::string;

class AssetHelpers
{
public:
	static string AssetSubcategoryToString(AssetSubcategory category);

	static string AssetGenderToString(AssetGender gender);

	static string BinaryAssetTypeToString(BinaryAssetType type);

	static string SkeletonVersionToString(SkeletonVersion version);

	static string BlockIDToString(STRRBBlockId id);
};

