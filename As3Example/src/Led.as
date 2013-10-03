package
{
	import flash.display.Graphics;
	import flash.display.Sprite;
	import flash.events.Event;
	
	public class Led extends Sprite
	{
		private var _turnedOn:Boolean = false;
		private var g:Graphics;
		private var _color:uint;
		private var _id:uint;
		
		public function get id():uint{
			return _id;
		}
			
		public function set turnedOn(p_turnedOn:Boolean):void{
			_turnedOn = p_turnedOn;
			draw();
		}
		
		public function get turnedOn():Boolean{
			return _turnedOn;
		}
		
		public function Led(id:uint,color:uint = 0xff0000)
		{
			super();
			_color = color;
			_id = id;
			g= this.graphics;
			draw();
			addEventListener(Event.ADDED_TO_STAGE, onAddedToStage);
		}
		
		protected function onAddedToStage(event:Event):void
		{
			removeEventListener(Event.ADDED_TO_STAGE, onAddedToStage);
		}
		
		protected function draw():void{
			g.clear();
			if(_turnedOn){
				g.beginFill(_color);
			}else{
				g.beginFill(0x999999);
			}
			g.drawCircle(10,10,20);
			g.endFill();
		}
			
		
	}
}