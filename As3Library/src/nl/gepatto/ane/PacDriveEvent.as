/** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** *
 *
 *	 2013
 *	 Patrick Gutlich
 *	 Gepatto Interactive Media
 *
 ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** */

package nl.gepatto.ane
{
	import flash.events.Event;
	
	public class PacDriveEvent extends Event
	{
		public static const DEVICE_ATTACHED:String = "deviceAttached";
		public static const DEVICE_REMOVED:String = "deviceRemoved";
		public static const DEVICES_CHANGED:String = "devicesChanged";
		
		public function PacDriveEvent(type:String, bubbles:Boolean=false, cancelable:Boolean=false)
		{
			super(type, bubbles, cancelable);
		}
	}
}