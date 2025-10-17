#include "Redefinition.h"
#include "llvm/Passes/PassBuilder.h"
#include "llvm/Passes/PassPlugin.h"

bool registerPipeline(StringRef Name, FunctionPassManager &FPM,
                      ArrayRef<PassBuilder::PipelineElement>) {
  if (Name == "redef") {
    FPM.addPass(redef::RedefAnalysis());
    return true;
  }
   
  return false;
}

PassPluginLibraryInfo getRedefPluginInfo() {
    return {LLVM_PLUGIN_API_VERSION, "Redef", LLVM_VERSION_STRING,
            [](PassBuilder &PB) {
                PB.registerPipelineParsingCallback(registerPipeline);
            }};
}

extern "C" LLVM_ATTRIBUTE_WEAK PassPluginLibraryInfo llvmGetPassPluginInfo() {
    return getRedefPluginInfo();
}
