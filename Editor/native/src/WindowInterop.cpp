#include "WindowInterop.h"
#include <iostream>
#include "Engine.h"
using namespace std;

namespace EngineInterop
{
    void SetWindow(void* handler){
        cout << "\nHandler " << handler << std::endl;
    }

    Core::Engine* InitializeEngine()
    {
        return Core::Engine::GetInstance();
    }

    Napi::Boolean SetWindowWrapped(const Napi::CallbackInfo& info)
    {
        cout << "SetWindowWrapped" << std::endl;
        Napi::Env env = info.Env(); //check if arguments are integer only.
        if (info.Length() != 1 || !info[0].IsObject())
        {
            cout << "\nBefore Casting " << info[0].Type() << std::endl;
            Napi::TypeError::New(env, "arg1::Pointer expected").ThrowAsJavaScriptException();
        }
        
        Napi::BigInt windowHandler = info[0].As<Napi::BigInt>();
        SetWindow(windowHandler);
        Napi::Boolean returnValue = Napi::Boolean::New(env, true);
        return returnValue;
    }

    Napi::BigInt SetInitializeEngineWrapped(const Napi::CallbackInfo& info)
    {
        cout << "SetInitializeEngineWrapped" << std::endl;
        Napi::Env env = info.Env(); //check if arguments are integer only.
        if (info.Length() != 0)
        {
            Napi::TypeError::New(env, "I am not expecting parameters here").ThrowAsJavaScriptException();
        }
        
        cout << "Engine Initialized at: " << InitializeEngine() << endl;
        Napi::BigInt returnValue = Napi::BigInt::New(env, (uint64_t)1);
        return returnValue;
    }
    

    Napi::Object Init(Napi::Env env, Napi::Object exports) 
    {
        //export Napi function
        exports.Set("setWindow", Napi::Function::New(env, EngineInterop::SetWindowWrapped));  
        exports.Set("initializeEngine", Napi::Function::New(env, EngineInterop::SetInitializeEngineWrapped));  
        return exports;
    }
}
