#include <napi.h>

// https://github.com/nodejs/node-addon-examples/blob/main/src/1-getting-started/2_function_arguments/node-addon-api/addon.cc
// add(2, 3)
Napi::Value Add(const Napi::CallbackInfo &info) {
  Napi::Env env = info.Env();
  if (info.Length() < 2) {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();

    return env.Null();
  }
  if (!info[0].IsNumber() || !info[1].IsNumber()) {
    Napi::TypeError::New(env, "Wrong arguments").ThrowAsJavaScriptException();
    return env.Null();
  }

  double arg0 = info[0].As<Napi::Number>().DoubleValue();
  double arg1 = info[1].As<Napi::Number>().DoubleValue();
  Napi::Number num = Napi::Number::New(env, arg0 + arg1);

  return num;
}

// https://github.com/nodejs/node-addon-examples/blob/main/src/1-getting-started/3_callbacks/node-addon-api/addon.cc
void RunCallback(const Napi::CallbackInfo &info) {
  Napi::Env env = info.Env();
  Napi::Function cb = info[0].As<Napi::Function>();
  cb.Call(env.Global(), {Napi::String::New(env, "hello world")});
}

Napi::String Method(const Napi::CallbackInfo &info) {
  Napi::Env env = info.Env();
  return Napi::String::New(env, "world2");
}

Napi::Object Init(Napi::Env env, Napi::Object exports) {
  exports.Set(Napi::String::New(env, "First"),
              Napi::Function::New(env, Method));

  exports.Set(Napi::String::New(env, "add"), Napi::Function::New(env, Add));

  exports.Set(Napi::String::New(env, "runCallback"),
              Napi::Function::New(env, RunCallback));

  return exports;
}

NODE_API_MODULE(addon, Init)
