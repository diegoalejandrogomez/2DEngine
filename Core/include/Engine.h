#pragma once
namespace Core {
class Engine {
    public:
        ~Engine();

        void Initialize();
        void InitializeSubSystems();
        void MainLoop();

        static Engine* const GetInstance();

    private:
        Engine();
        struct Settings* mSettings;
        static Engine* mEngineInstance;
    };
}