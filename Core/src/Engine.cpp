#include "Engine.h"
#include "Settings.h"
using namespace Core;

Engine* Engine::mEngineInstance;

Engine::Engine()
{
    // I will do a memory manager... eventually...
    mSettings = new Settings();
}

Engine::~Engine()
{
}


void Engine::InitializeSubSystems()
{
}

void Engine::Initialize()
{
    // Read settings from a file
}


void Engine::MainLoop()
{
    while(true)
    {
        // do logic here
    }
}

Engine* const Engine::GetInstance()
{
    if (mEngineInstance == nullptr)
    {
        mEngineInstance = new Engine();
    }

    return mEngineInstance;
}
