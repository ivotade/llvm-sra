#include "PythonInterface.h"
#include "llvm/Passes/PassBuilder.h"
#include "llvm/Passes/PassPlugin.h"

void registerAnalyses(ModuleAnalysisManager &MAM) {
    MAM.registerPass([] { return PythonAnalysis(); });
}

PassPluginLibraryInfo getPythonPluginInfo() {
    return {LLVM_PLUGIN_API_VERSION, "Python", LLVM_VERSION_STRING,
            [](PassBuilder &PB) {
                PB.registerAnalysisRegistrationCallback(registerAnalyses);
            }};
}

extern "C" LLVM_ATTRIBUTE_WEAK PassPluginLibraryInfo llvmGetPassPluginInfo() {
    return getPythonPluginInfo();
}
