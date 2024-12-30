// Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
// SPDX-License-Identifier: Apache-2.0

#pragma once

#if !PLATFORM_MAC
#error Only Mac platform is supported
#endif

#include "IGameLiftCoreProc.h"

class GameLiftCoreProc : public IGameLiftCoreProc
{
public:
	bool LaunchProcess(const FString& path, TArray<FString> arguments) override;
};
