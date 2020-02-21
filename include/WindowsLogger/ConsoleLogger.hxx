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
// Filename: ConsoleLogger.hxx
// Author:   Tim Sleddens
// Date:     21-02-2020
// 
// *********************************************************

#pragma once
#include "ILogger.hxx"
#include <cstdio>
#include <Windows.h>

namespace tsleddens {

class ConsoleLogger : public ILogger
{
public:
    ConsoleLogger();
    ~ConsoleLogger();

    virtual void Log(ELogType type, const char* msg) const override;
    virtual void Log(ELogType type, const wchar_t* msg) const override;
    virtual void Logf(ELogType type, const char* msg, ...) const override;
    virtual void Logf(ELogType type, const wchar_t* msg, ...) const override;

private:
    FILE* m_outStream{};
    FILE* m_inStream{};
    HANDLE m_outputHandle{};
};

}
