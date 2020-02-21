// *********************************************************
// 
// Copyright (c) 2020 Tim Sleddens
// This code is licensed under the MIT License (MIT).
// THIS CODE IS PROVIDED *AS IS* WITHOUT WARRANTY OF
// ANY KIND, EITHER EXPRESS OR IMPLIED, INCLUDING ANY
// IMPLIED WARRANTIES OF FITNESS FOR A PARTICULAR
// PURPOSE, MERCHANTABILITY, OR NON-INFRINGEMENT.
// 
// *********************************************************
// 
// Filename: ILogger.hxx
// Author:   Tim Sleddens
// Date:     21-02-2020
// 
// *********************************************************

#pragma once

namespace tsleddens {

enum class ELogType : unsigned short
{
    Info,
    Warning,
    Error,
    Success,
};

struct ILogger
{
    virtual ~ILogger() = default;
    virtual void Log(ELogType type, const char* msg) const = 0;
    virtual void Log(ELogType type, const wchar_t* msg) const = 0;
    virtual void Logf(ELogType type, const char* msg, ...) const = 0;
    virtual void Logf(ELogType type, const wchar_t* msg, ...) const = 0;
};

}
