#include "Application.hpp"
#include "App/Entity/PersistencyService.hpp"
#include "App/Environment.hpp"
#include "App/Localization/LocalizationService.hpp"
#include "App/Migration.hpp"
#include "App/Project.hpp"
#include "App/Quest/QuestPhaseRegistry.hpp"
#include "App/Scripting/ScriptingService.hpp"
#include "App/Shared/ResourcePathRegistry.hpp"
#include "App/UI/WidgetBuildingService.hpp"
#include "App/UI/WidgetInputService.hpp"
#include "App/UI/WidgetSpawningService.hpp"
#include "App/World/OpenWorldTracker.hpp"
#include "Core/Foundation/LocaleProvider.hpp"
#include "Core/Foundation/RuntimeProvider.hpp"
#ifndef __APPLE__
#include "Support/MinHook/MinHookProvider.hpp"
#endif
#include "Support/RED4ext/RED4extProvider.hpp"
#include "Support/RedLib/RedLibProvider.hpp"
#include "Support/Spdlog/SpdlogProvider.hpp"

App::Application::Application(HMODULE aHandle, const RED4ext::v1::Sdk* aSdk)
{
    Register<Core::LocaleProvider>();
    Register<Core::RuntimeProvider>(aHandle)
#ifdef __APPLE__
        ->SetBaseImagePathDepth(3); // <game>/Cyberpunk2077.app/Contents/MacOS/Cyberpunk2077 -> <game>
#else
        ->SetBaseImagePathDepth(2);
#endif

#ifndef __APPLE__
    Register<Support::MinHookProvider>();
#endif
    Register<Support::SpdlogProvider>()
        ->AppendTimestampToLogName()
        ->CreateRecentLogSymlink();
    Register<Support::RED4extProvider>(aHandle, aSdk)
#ifdef __APPLE__
        ->EnableHooking() // no MinHook on macOS: hooks go through the RED4ext host
#endif
        ->EnableAddressLibrary()
        ->RegisterScripts(Env::ScriptsDir());
    Register<Support::RedLibProvider>();

#ifndef __APPLE__
    Register<App::ScriptingService>(Env::PersistentDir());
    Register<App::LocalizationService>();
    Register<App::PersistencyService>();
    Register<App::ResourcePathRegistry>(Env::KnownHashesPath());
    Register<App::QuestPhaseRegistry>();
    Register<App::OpenWorldTracker>();
    Register<App::WidgetBuildingService>();
    Register<App::WidgetSpawningService>();
    Register<App::WidgetInputService>();
#endif
    // macOS port, stage 1: services are enabled one by one as the game functions they need are located.
}

void App::Application::OnStarting()
{
    LogInfo("{} {} is initializing...", Project::Name, Project::Version.to_string());

    Migration::CleanUp(Env::LegacyScriptsDir());
}

void App::Application::OnStarted()
{
    LogInfo("{} is initialized.", Project::Name);
}
