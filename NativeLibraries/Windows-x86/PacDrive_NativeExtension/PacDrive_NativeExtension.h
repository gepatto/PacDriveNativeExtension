/** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** *
 *
 *	 2013
 *	 Patrick Gutlich
 *	 Gepatto Interactive Media
 *
 ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** */

#include "FlashRuntimeExtensions.h"
 
extern "C" __declspec(dllexport) void ExtInitializer(void** extDataToSet, FREContextInitializer* ctxInitializerToSet, FREContextFinalizer* ctxFinalizerToSet);
extern "C" __declspec(dllexport) void ExtFinalizer(void* extData);
extern "C" __declspec(dllexport) FREObject setLedState(FREContext ctx, void* funcData, uint32_t argc, FREObject argv[]);
extern "C" __declspec(dllexport) FREObject setLedStates(FREContext ctx, void* funcData, uint32_t argc, FREObject argv[]);
extern "C" __declspec(dllexport) FREObject getDeviceType(FREContext ctx, void* funcData, uint32_t argc, FREObject argv[]);
extern "C" __declspec(dllexport) FREObject getVersionNumber(FREContext ctx, void* funcData, uint32_t argc, FREObject argv[]);
extern "C" __declspec(dllexport) FREObject getProductId(FREContext ctx, void* funcData, uint32_t argc, FREObject argv[]);
extern "C" __declspec(dllexport) FREObject getVendorId(FREContext ctx, void* funcData, uint32_t argc, FREObject argv[]);
extern "C" __declspec(dllexport) FREObject getSerialNumber(FREContext ctx, void* funcData, uint32_t argc, FREObject argv[]);
extern "C" __declspec(dllexport) FREObject getDevicePath(FREContext ctx, void* funcData, uint32_t argc, FREObject argv[]);
extern "C" __declspec(dllexport) FREObject getVendorName(FREContext ctx, void* funcData, uint32_t argc, FREObject argv[]);
extern "C" __declspec(dllexport) FREObject getProductName(FREContext ctx, void* funcData, uint32_t argc, FREObject argv[]);

extern "C" __declspec(dllexport) FREObject isSupported(FREContext ctx, void* funcData, uint32_t argc, FREObject argv[]);