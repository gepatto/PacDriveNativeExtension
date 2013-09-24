/** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** *
 *
 *	 2013
 *	 Patrick Gutlich
 *	 Gepatto Interactive Media
 *
 ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** */

#include "stdafx.h"
#include <stdio.h>
#include <malloc.h>
#include <iostream>
#include <string>
#include <windows.h>
#include "PacDrive.h"
#include "FlashRuntimeExtensions.h"
#include "PacDrive_NativeExtension.h"

#ifdef _WIN32
  uint32_t isSupportedInOS = 1;
#else
  uint32_t isSupportedInOS = 0;
#endif

FREContext dllContext;

FREObject isSupported(FREContext ctx, void* funcData, uint32_t argc, FREObject argv[]){
	uint32_t isSupportedInOS=1;
	FREObject result;
	FRENewObjectFromBool( isSupportedInOS, &result);
	return result;
}

FREObject setLedState(FREContext ctx, void* funcData, uint32_t argc, FREObject argv[]) {
	
	uint32_t deviceNum;
	uint32_t deviceChannel;
	uint32_t channelState;

	FREGetObjectAsUint32(argv[0], &deviceNum);
	FREGetObjectAsUint32(argv[1], &deviceChannel);
	FREGetObjectAsUint32(argv[2], &channelState);
	
	FREObject result;
	FRENewObjectFromBool(PacSetLEDState(deviceNum,deviceChannel,channelState),&result);

	return result;
}

FREObject setLedStates(FREContext ctx, void* funcData, uint32_t argc, FREObject argv[]) {
	
	uint32_t deviceNum;
	uint32_t data;

	FREGetObjectAsUint32(argv[0], &deviceNum);
	FREGetObjectAsUint32(argv[1], &data);
	
	FREObject result;
	FRENewObjectFromBool(PacSetLEDStates(deviceNum,data),&result);

	return result;
}

FREObject getDeviceType(FREContext ctx, void* funcData, uint32_t argc, FREObject argv[]){

	uint32_t deviceNum;
	FREGetObjectAsUint32(argv[0], &deviceNum);

	uint32_t deviceType = PacGetDeviceType(deviceNum);

	FREObject result;
	FRENewObjectFromUint32(deviceType,&result);

	return result;
}

FREObject getVersionNumber(FREContext ctx, void* funcData, uint32_t argc, FREObject argv[]){
	
	uint32_t deviceNum;
	FREGetObjectAsUint32(argv[0], &deviceNum);

	uint32_t versionNum = PacGetVersionNumber(deviceNum);

	FREObject result;
	FRENewObjectFromUint32(versionNum,&result);

	return result;
}

FREObject getProductId(FREContext ctx, void* funcData, uint32_t argc, FREObject argv[]){
	uint32_t deviceNum;
	FREGetObjectAsUint32(argv[0], &deviceNum);

	uint32_t productID = PacGetProductId(deviceNum);

	FREObject result;
	FRENewObjectFromUint32(productID,&result);

	return result;
};

FREObject getVendorId(FREContext ctx, void* funcData, uint32_t argc, FREObject argv[]){
	uint32_t deviceNum;
	FREGetObjectAsUint32(argv[0], &deviceNum);

	uint32_t vendorID = PacGetVendorId(deviceNum);

	FREObject result;
	FRENewObjectFromUint32(vendorID,&result);

	return result;
};

FREObject getSerialNumber(FREContext ctx, void* funcData, uint32_t argc, FREObject argv[]){
	uint32_t deviceNum;
	FREGetObjectAsUint32(argv[0], &deviceNum);
	
	CHAR SerialNumber[256];
	PacGetSerialNumber(deviceNum,SerialNumber);
	
	printf("SerialNumber: %s\n",SerialNumber);

	FREObject result;
	FRENewObjectFromUTF8(strlen(SerialNumber)+1, (uint8_t*)SerialNumber,&result);

	return result;
};

FREObject getDevicePath(FREContext ctx, void* funcData, uint32_t argc, FREObject argv[]){
	uint32_t deviceNum;
	FREGetObjectAsUint32(argv[0], &deviceNum);
	
	CHAR devicePath[256];
	PacGetDevicePath(deviceNum,devicePath);
	
	printf("devicePath: %s\n",devicePath);

	FREObject result;
	FRENewObjectFromUTF8(strlen(devicePath)+1, (uint8_t*)devicePath,&result);

	return result;
};

FREObject getVendorName(FREContext ctx, void* funcData, uint32_t argc, FREObject argv[]){
	uint32_t deviceNum;
	FREGetObjectAsUint32(argv[0], &deviceNum);
	
	CHAR vendorName[256];
	PacGetVendorName(deviceNum,vendorName);
	
	printf("vendorName: %s\n",vendorName);

	FREObject result;
	FRENewObjectFromUTF8(strlen(vendorName)+1, (uint8_t*)vendorName,&result);

	return result;
};

FREObject getProductName(FREContext ctx, void* funcData, uint32_t argc, FREObject argv[]){
	uint32_t deviceNum;
	FREGetObjectAsUint32(argv[0], &deviceNum);
	
	CHAR productName[256];
	PacGetProductName(deviceNum,productName);
	
	printf("productName: %s\n",productName);

	FREObject result;
	FRENewObjectFromUTF8(strlen(productName)+1, (uint8_t*)productName,&result);

	return result;
};


void __stdcall pacDeviceAttached(INT deviceID){
	 FREDispatchStatusEventAsync(dllContext, (uint8_t*) "deviceAttached", (const uint8_t*) "INFO");
	 printf("pacAttached");
}

void __stdcall pacDeviceRemoved(INT deviceID){
	 FREDispatchStatusEventAsync(dllContext, (uint8_t*) "deviceRemoved", (const uint8_t*) "INFO");
	 printf("pacRemoved");
}

void ContextInitializer(void* extData, const uint8_t* ctxType, FREContext ctx,
                                                uint32_t* numFunctionsToTest, const FRENamedFunction** functionsToSet) {
        *numFunctionsToTest = 9;

        FRENamedFunction* func = (FRENamedFunction*)malloc(sizeof(FRENamedFunction)*(*numFunctionsToTest));
        func[0].name = (const uint8_t*)"isSupported";
		func[0].functionData = NULL;
        func[0].function = &isSupported;

		func[1].name = (const uint8_t*)"setLedState";
		func[1].functionData = NULL;
        func[1].function = &setLedState;

		func[2].name = (const uint8_t*)"setLedStates";
		func[2].functionData = NULL;
        func[2].function = &setLedStates;

		func[3].name = (const uint8_t*)"getDeviceType";
		func[3].functionData = NULL;
        func[3].function = &getDeviceType;

		func[4].name = (const uint8_t*)"getVersionNumber";
		func[4].functionData = NULL;
        func[4].function = &getVersionNumber;

		func[5].name = (const uint8_t*)"getSerialNumber";
		func[5].functionData = NULL;
        func[5].function = &getSerialNumber;

		func[6].name = (const uint8_t*)"getDevicePath";
		func[6].functionData = NULL;
        func[6].function = &getDevicePath;

		func[7].name = (const uint8_t*)"getVendorName";
		func[7].functionData = NULL;
        func[7].function = &getVendorName;

		func[8].name = (const uint8_t*)"getProductName";
		func[8].functionData = NULL;
        func[8].function = &getProductName;


		*functionsToSet = func;

		 dllContext = ctx;
}

void ContextFinalizer(FREContext ctx) {
        printf("inside ContextFinalizer method \n");
        
		return;
}

void ExtInitializer(void** extDataToSet, FREContextInitializer* ctxInitializerToSet,FREContextFinalizer* ctxFinalizerToSet) {
        printf("inside extension initializer method\n");
        
		*extDataToSet = NULL;
        *ctxInitializerToSet = &ContextInitializer;
        *ctxFinalizerToSet = &ContextFinalizer;
		PacInitialize();	
		PacSetCallbacks(&pacDeviceAttached,&pacDeviceRemoved);
}

void ExtFinalizer(void* extData) {
        printf("inside extension finalizer method\n");
		
		PacShutdown();
        return;
}
