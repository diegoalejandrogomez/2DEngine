#include <napi.h>
#include <iostream>

using namespace std;
namespace Core {
    class Engine;
}
namespace EngineInterop{
    void SetWindow(void* handler);
    Core::Engine* InitializeEngine();

    Napi::Boolean SetWindowWrapped(const Napi::CallbackInfo& info); //Export API
    Napi::BigInt SetInitializeEngineWrapped(const Napi::CallbackInfo& info); //Export API

    Napi::Object Init(Napi::Env env, Napi::Object exports);
    NODE_API_MODULE(windowInterop, Init);
}