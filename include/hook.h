#pragma once

#include <functional>

namespace hook {
/**
 * @brief install all hook function to replace cuda runtime api
 */
void install_hook();

struct OriginalInfo {
    const char* libName = nullptr;
    void* basePtr = nullptr;
    void* oldFuncPtr = nullptr;
};

struct HookInstaller {
    std::function<bool(const char*)> isTargetLib;
    std::function<bool(const char*)> isTargetSymbol;
    std::function<void*(const OriginalInfo&)> newFuncPtr;
};

void install_hook(const HookInstaller& installer);

}  // namespace cuda_mock