var url = "URL/data";
var http = new RealHTTPClient();
 
function setup() {
	pinMode(1, OUTPUT);
}

function loop() {
	http.onDone = function(status, data) {
		Serial.println("status: " + status);        //Printing HTTP Status to Console
		Serial.println("data: " + data);            //Printing HTTP message to Console
		if(data>0)
		    digitalWrite(1, HIGH);
		else
		    digitalWrite(1, LOW);
	};
	http.get(url);
	delay(15000);           //Set delay based on Cloud Provider statistics
}
