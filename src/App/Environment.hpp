#pragma once

#include "Core/Facades/Runtime.hpp"
#include <stdexcept>

namespace App::Env
{
inline std::filesystem::path ScriptsDir()
{
    return Core::Runtime::GetModuleDir() / L"Scripts";
}

inline std::filesystem::path PersistentDir()
{
    return Core::Runtime::GetModuleDir() / L"Persistent";
}

inline std::filesystem::path KnownHashesPath()
{
    return Core::Runtime::GetModuleDir() / L"Data" / L"KnownHashes.txt";
}

inline std::filesystem::path LegacyScriptsDir()
{
    return Core::Runtime::GetRootDir() / L"r6" / L"scripts" / L"Codeware";
}

inline std::filesystem::path GameDir()
{
    auto dir = Core::Runtime::GetRootDir();
    // Every directory this plugin touches must be absolute; a relative one would silently resolve against the cwd.
    if (dir.empty() || !dir.is_absolute())
        throw std::runtime_error("Codeware: refusing to use a non-absolute game directory: '" + dir.string() + "'");
    return dir;
}
}
