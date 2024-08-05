// defines pins numbers
const int usout = 3;
const int usin = 2;
const int bzr = 4;
const int rled = 5;
const int yled = 6;
const int gled = 7;


// defines variables
float d1=0;
float d=0;
float eta=0;

void setup() {
pinMode(usout, OUTPUT); // Sets the trigPin as an Output
pinMode(usin, INPUT); // Sets the echoPin as an Input
pinMode(bzr, OUTPUT);
pinMode(rled, OUTPUT);
pinMode(yled, OUTPUT);
pinMode(gled, OUTPUT);
Serial.begin(9600); // Starts the serial communication
}


void loop()
{
  	noTone(bzr);
  	digitalWrite(rled, LOW);
  	digitalWrite(yled, LOW);
  	digitalWrite(gled, LOW);
  
// Clears the trigPin
	digitalWrite(usout, LOW);
  	delayMicroseconds(2);
// Sets the trigPin on HIGH state for 10 micro seconds
	digitalWrite(usout, HIGH);
	delayMicroseconds(10);
	digitalWrite(usout, LOW);
	d1 = pulseIn(usin, HIGH)*0.034/2;
  
  	delay(1000);//giving a time gap of 1 sec
  	
	digitalWrite(usout, HIGH);
	delayMicroseconds(10);
	digitalWrite(usout, LOW);
	d = pulseIn(usin, HIGH)*0.034/2;
  	eta=d/(d1-d);
  	Serial.print(" ETA= ");
  	Serial.print(eta);
  	
	if (d <= 5)
    {
  		Serial.print(" ||--- VALVE OFF ---|| ");
      	//digitalWrite(bzr, HIGH);
      	delay(500);
      	tone(bzr,261);
  		digitalWrite(rled, HIGH);
      	digitalWrite(gled, HIGH);
  		delay(500);
      	Serial.print(" 1 ");
  		//digitalWrite(bzr, LOW);
  		//digitalWrite(led, LOW);
  		//delayMicroseconds(100);
	}
	if (d<=10 && d>=5)
    {
  		//digitalWrite(bzr, HIGH);
  		digitalWrite(rled, HIGH);
      	Serial.print(" 2 ");
  		//delayMicroseconds(2000);
  		//digitalWrite(bzr, LOW);
  		//digitalWrite(rled, LOW);
  		//delayMicroseconds(2000);
	}
	if (d<=50 && d>=10)
    {
  		//digitalWrite(bzr, HIGH);
  		digitalWrite(yled, HIGH);
      	Serial.print(" 3 ");
  		//delayMicroseconds(4000);
  		//digitalWrite(bzr, LOW);
  		//digitalWrite(yled, LOW);
  		//delayMicroseconds(4000);
	}
	if (d>50)
	{
  		//digitalWrite(bzr, LOW);
  		digitalWrite(gled, HIGH);
      	Serial.print(" 4 ");
  		//delayMicroseconds(100);
	}

// Prints the distance on the Serial Monitor
	Serial.print(" Distance: ");
	Serial.println(d);
}
