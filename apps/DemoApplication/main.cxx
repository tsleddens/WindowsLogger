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
// Filename: main.cxx
// Author:   Tim Sleddens
// Date:     21-02-2020
// 
// *********************************************************
#include <cstdlib>
#include <WindowsLogger/ConsoleLogger.hxx>

int WINAPI wWinMain(_In_ HINSTANCE /*hInstance*/, _In_opt_ HINSTANCE, _In_ LPWSTR, _In_ int /*nCmdShow*/)
{
    const tsleddens::ConsoleLogger logger;

    logger.Logf(tsleddens::ELogType::Info, "Info test");
    logger.Logf(tsleddens::ELogType::Warning, "Warning test");
    logger.Logf(tsleddens::ELogType::Error, "Error test");
    logger.Logf(tsleddens::ELogType::Success, "Success test");
    logger.Logf(tsleddens::ELogType::Info, L"Wide info test");
    logger.Logf(tsleddens::ELogType::Warning, L"Wide warning test");
    logger.Logf(tsleddens::ELogType::Error, L"Wide error test");
    logger.Logf(tsleddens::ELogType::Success, L"Wide success test");

    system("pause");

    return 0;
}
