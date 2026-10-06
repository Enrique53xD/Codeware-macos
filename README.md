# Codeware-macos (macOS port)

Apple Silicon port of the upstream project, built on [RED4ext-macos](https://github.com/Enrique53xD/RED4ext-macos). See [cp2077-macos-tools](https://github.com/Enrique53xD/cp2077-macos-tools) for the full install guide.

**Build:** clone next to `RED4ext-macos` and `ArchiveXL-macos`, then `mkdir build && cd build && cmake .. && make -j8`, `codesign -f -s - Codeware.dylib`.
**Install:** copy the dylib to `<game>/red4ext/plugins/Codeware/` with an empty `rtti_experiment` file beside it.
**Status:** reduced script subset (UI, Scripting, Utils, Reflection, Base) compiles and loads; some native game systems are not available yet.
Original README below.

---

# Codeware

Codeware is a library and framework for creating redscript and Cyber Engine Tweaks mods.

## Getting Started

### Compatibility

- Cyberpunk 2077 2.31
- [redscript](https://github.com/jac3km4/redscript) 0.5.31+
- [Cyber Engine Tweaks](https://github.com/yamashi/CyberEngineTweaks) 1.37.0+

### Installation

1. Install requirements:
   - [RED4ext](https://docs.red4ext.com/getting-started/installing-red4ext) 1.29.0+
2. Extract the release archive `Codeware-x.x.x.zip` into the Cyberpunk 2077 directory.

## Documentation

- [Lifecycle](https://github.com/psiberx/cp2077-codeware/wiki#lifecycle)
- [World](https://github.com/psiberx/cp2077-codeware/wiki#world)
- [Entities](https://github.com/psiberx/cp2077-codeware/wiki#entities)
- [Player](https://github.com/psiberx/cp2077-codeware/wiki#player)
- [User Interface](https://github.com/psiberx/cp2077-codeware/wiki#user-interface)
- [Resources](https://github.com/psiberx/cp2077-codeware/wiki#resources)
- [Localization](https://github.com/psiberx/cp2077-codeware/wiki#localization)
- [Reflection](https://github.com/psiberx/cp2077-codeware/wiki#reflection)
- [Utilities](https://github.com/psiberx/cp2077-codeware/wiki#utilities)
