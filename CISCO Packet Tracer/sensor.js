var oldt=0;
var url = "URL/sense.php?data=";
var http = new RealHTTPClient();

function setup() {
	pinMode(0, INPUT);
	pinMode(1, OUTPUT);
}

function loop() {
	var t = digitalRead(0)/1024*10;		//Sensor temperature convertions
	if(oldt!=t)							//Detect change in temperature
	{
		Serial.println("Temperature Changed "+t);
		oldt=t;
		var send=url+t;
		http.get(send);
		digitalWrite(1, HIGH);
		delay(1000);
	}
	digitalWrite(1, LOW);
}