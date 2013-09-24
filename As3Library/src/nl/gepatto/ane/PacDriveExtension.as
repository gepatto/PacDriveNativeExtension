/** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** *
 *
 *	 2013
 *	 Patrick Gutlich
 *	 Gepatto Interactive Media
 *
 ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** */

package nl.gepatto.ane
{
	import flash.events.EventDispatcher;
	import flash.events.StatusEvent;
	import flash.external.ExtensionContext;

	public class PacDriveExtension extends EventDispatcher
	{
		
		private static var isInstantiated:Boolean = false;
		private static var context:ExtensionContext;
		private static var deviceTypes:Vector.<String> = new <String>['unknown','PacDrive','U-HID','PacLED64'];
		
		public function PacDriveExtension()
		{
			super();
			
			if (isInstantiated)
				return;
			
			try
			{
				context = ExtensionContext.createExtensionContext("nl.gepatto.ane.PacDriveExtension", ""); 
				context.addEventListener(StatusEvent.STATUS, gotEvent);	
				isInstantiated = true;
			}
			catch (e:Error)
			{
				trace("[PacDriveExtension] Unable to load the .DLL! PacDrive.dll is available. \n" +
					  "Try Copying to windows/system32 or equivalent on 64bit windows");
				trace("[PacDriveExtension] ANE Not loaded properly.  Future calls will fail.");
			}
		}
		
		/**
		 * @private
		 * 
		 * This is the event that is fired by the DLL when devices are attached or removed
		 *  
		 * @param event Event Payload.
		 * 
		 */
		private function gotEvent(event:StatusEvent):void
		{
			var e:PacDriveEvent;
			switch(event.code){
				case "deviceRemoved":
					e = new PacDriveEvent(PacDriveEvent.DEVICE_REMOVED);
				break;
				case "deviceAttached":
					e = new PacDriveEvent(PacDriveEvent.DEVICE_ATTACHED);
				break;
			}
			dispatchEvent(e);
		}
		
		public function isSupported():*
		{
			return context.call("isSupported");
		}
				
		public function setLedState(device:uint, channel:uint, state:uint):*
		{
			return context.call("setLedState", device, channel, state);
		}
		
		public function setLedStates(device:uint, data:uint):*
		{
			return context.call("setLedStates", device,  data);
		}
		
		public function getDeviceType(device:uint):*
		{
			var dType:* = context.call("getDeviceType", device);
			return (deviceTypes[uint(dType)]);
		}
		
		public function getSerialNumber(device:uint):*
		{
			return context.call("getSerialNumber", device);
		}
	
		public function getDevicePath(device:uint):*
		{
			return context.call("getDevicePath", device);
		}
		
		public function getDeviceTypeAsUint(device:uint):uint
		{
			var dType:* = context.call("getDeviceType", device);
			return uint(dType);
		}
		
		public function getVersionNumber(device:uint):*
		{
			return context.call("getVersionNumber", device);
		}
		
		public function getVendorName(device:uint):*
		{
			return context.call("getVendorName", device);
		}
		
		public function getProductName(device:uint):*
		{
			return context.call("getProductName", device);
		}
	}
}