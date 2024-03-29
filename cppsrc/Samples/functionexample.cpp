#include <functionexample.h>

std::string functionexample::hello() {
    return "Hello world!";
}

Napi::String functionexample::Hellowrapped(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::String returnValue = Napi::String::New(env, functionexample::hello());
    return returnValue;
}

Napi::Object functionexample::Init(Napi::Env env, Napi::Object exports) {
    exports.Set("hello", Napi::Function::New(env, functionexample::HelloWrapped));
    return exports;
}
