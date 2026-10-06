#pragma once
// macOS stand-in for the `clip` library (clipboard text only), implemented with pbpaste/pbcopy.
#include <cstdio>
#include <string>

namespace clip
{
inline bool get_text(std::string& aOut)
{
    FILE* pipe = popen("/usr/bin/pbpaste", "r");
    if (!pipe)
        return false;
    char buffer[4096];
    aOut.clear();
    size_t n;
    while ((n = fread(buffer, 1, sizeof(buffer), pipe)) > 0)
        aOut.append(buffer, n);
    pclose(pipe);
    return true;
}

inline bool set_text(const std::string& aText)
{
    FILE* pipe = popen("/usr/bin/pbcopy", "w");
    if (!pipe)
        return false;
    fwrite(aText.data(), 1, aText.size(), pipe);
    return pclose(pipe) == 0;
}
}
