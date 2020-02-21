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
// Filename: ConsoleLogger.cxx
// Author:   Tim Sleddens
// Date:     21-02-2020
// 
// *********************************************************

#include "ConsoleLogger.hxx"

#include <windows.h>
#include <stdexcept>
#include <iostream>

namespace tsleddens {

enum class EConsoleColor : WORD
{
    Default = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE,
    Info = Default | FOREGROUND_INTENSITY,
    Warning = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY,
    Error = FOREGROUND_RED | FOREGROUND_INTENSITY,
    Success = FOREGROUND_GREEN | FOREGROUND_INTENSITY,
};

// -----------------------------------------------------------------------------------------------------
void SetConsoleColor(HANDLE handle, EConsoleColor color)
{
    SetConsoleTextAttribute(handle, WORD(color));
}

// -----------------------------------------------------------------------------------------------------
ConsoleLogger::ConsoleLogger()
{
    if(!AllocConsole())
    {
        throw std::runtime_error("Unable to allocate console.");
    }

    freopen_s(&m_outStream, "CONOUT$", "w", stdout);
    freopen_s(&m_outStream, "CONOUT$", "w", stderr);
    freopen_s(&m_inStream, "CONIN$", "r", stdin);

    std::ios::sync_with_stdio(true);

    std::wcout.clear();
    std::cout.clear();
    std::wcerr.clear();
    std::cerr.clear();
    std::wcin.clear();
    std::cin.clear();
    m_outputHandle = GetStdHandle(STD_OUTPUT_HANDLE);
}

// -----------------------------------------------------------------------------------------------------
ConsoleLogger::~ConsoleLogger()
{
    fclose(m_inStream);
    fclose(m_outStream);
}

// -----------------------------------------------------------------------------------------------------
void ConsoleLogger::Log(ELogType type, const char* msg) const
{
    switch(type)
    {
    case ELogType::Info:
        SetConsoleColor(m_outputHandle, EConsoleColor::Info);
        std::clog << msg << std::endl;
        break;
    case ELogType::Warning:
        SetConsoleColor(m_outputHandle, EConsoleColor::Warning);
        std::clog << msg << std::endl;
        break;
    case ELogType::Error:
        SetConsoleColor(m_outputHandle, EConsoleColor::Error);
        std::cerr << msg << std::endl;
        break;
    case ELogType::Success:
        SetConsoleColor(m_outputHandle, EConsoleColor::Success);
        std::clog << msg << std::endl;
        break;
    default:
        SetConsoleColor(m_outputHandle, EConsoleColor::Default);
        std::cout << msg << std::endl;
        break;
    }
    SetConsoleColor(m_outputHandle, EConsoleColor::Default);
}

// -----------------------------------------------------------------------------------------------------
void ConsoleLogger::Log(ELogType type, const wchar_t* msg) const
{
    switch(type)
    {
    case ELogType::Info:
        SetConsoleColor(m_outputHandle, EConsoleColor::Info);
        std::wclog << msg << std::endl;
        break;
    case ELogType::Warning:
        SetConsoleColor(m_outputHandle, EConsoleColor::Warning);
        std::wclog << msg << std::endl;
        break;
    case ELogType::Error:
        SetConsoleColor(m_outputHandle, EConsoleColor::Error);
        std::wcerr << msg << std::endl;
        break;
    case ELogType::Success:
        SetConsoleColor(m_outputHandle, EConsoleColor::Success);
        std::wclog << msg << std::endl;
        break;
    default:
        SetConsoleColor(m_outputHandle, EConsoleColor::Default);
        std::wcout << msg << std::endl;
        break;
    }
    SetConsoleColor(m_outputHandle, EConsoleColor::Default);
}

// -----------------------------------------------------------------------------------------------------
void ConsoleLogger::Logf(ELogType type, const char* msg, ...) const
{
    va_list argumentList;
    va_start(argumentList, msg);
    const int length = _vscprintf(msg, argumentList) + 1;
    const auto buffer = static_cast<char*>(malloc(length * sizeof(char)));
    if(buffer != nullptr)
    {
        vsprintf_s(buffer, length, msg, argumentList);
        Log(type, buffer);
        free(buffer);
    }
    va_end(argumentList);
}

// -----------------------------------------------------------------------------------------------------
void ConsoleLogger::Logf(ELogType type, const wchar_t* msg, ...) const
{
    va_list argumentList;
    va_start(argumentList, msg);
    const int length = _vscwprintf(msg, argumentList) + 1;
    const auto buffer = static_cast<wchar_t*>(malloc(length * sizeof(wchar_t)));
    if(buffer != nullptr)
    {
        vswprintf_s(buffer, length, msg, argumentList);
        Log(type, buffer);
        free(buffer);
    }
    va_end(argumentList);
}

}
