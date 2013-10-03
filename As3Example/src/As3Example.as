package
{
	import flash.display.Sprite;
	import flash.events.Event;
	import flash.events.MouseEvent;
	import flash.events.TimerEvent;
	import flash.utils.Timer;
	
	import nl.gepatto.ane.PacDriveEvent;
	import nl.gepatto.ane.PacDriveExtension;
	
	[SWF(frameRate="60",width="1204",height="768")]
	public class As3Example extends Sprite
	{
		private var ext:PacDriveExtension;
		private var ledState:uint = 0;
		private var leds:Vector.<Led> = new Vector.<Led>();
		private var flashtimer:Timer;
		private var ledContainer:Sprite;

	
		public function As3Example()
		{
			ext = new PacDriveExtension();
			ext.setLedStates(0,0x0000);
			ext.addEventListener(PacDriveEvent.DEVICE_REMOVED, handleDeviceChange);
			ext.addEventListener(PacDriveEvent.DEVICE_ATTACHED, handleDeviceChange);
				
			ledContainer = new Sprite();
			ledContainer.x = 30;
			ledContainer.y = 30;
			for(var n:uint = 0; n< 16; n++){
				var l:Led = new Led(n,0xff0000);
				leds.push(l);
				l.x = n*(l.width + 1);
				ledContainer.addChild(l);
			}
			
			ledContainer.addEventListener(MouseEvent.MOUSE_UP, handleLedClick);
			addChild(ledContainer);
		}
		
		protected function handleLedClick(event:MouseEvent):void
		{			
			trace("!!!");
			var l:Led = event.target as Led;
			l.turnedOn = !l.turnedOn;
			ext.setLedState(0,l.id, l.turnedOn?1:0);
		}
		
		protected function flashLeds(event:MouseEvent):void{
			resetTimer();
			flashtimer = new Timer(50,20);
			flashtimer.addEventListener(TimerEvent.TIMER, onTimer);
			flashtimer.reset();
			flashtimer.start();
		}
		
		private function resetTimer():void{
			if(flashtimer!=null){
				flashtimer.stop()
				flashtimer.removeEventListener(TimerEvent.TIMER, onTimer);
				flashtimer = null;
			}
		}
		
		protected function onTimer(event:TimerEvent):void
		{
			ledState = ledState==0?1:0;
			ext.setLedState(0,0,ledState);
		}
		
		protected function handleDeviceChange(event:Event):void
		{			
			trace("Devices Changed:" + event.type);
		}
		
	}
}