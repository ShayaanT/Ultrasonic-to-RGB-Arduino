//Shayaan Tanvir
//11 - 10 - 2020
//ultrasonic sensor that turns on an rgb led
#define trigpin 13
#define echopin 12
#define R 7

#define G 8

#define B 9

void setup()

{ //serial monitor and pin setup.
  Serial.begin(9600);
  pinMode(trigpin, OUTPUT); //set trigpin as output
  pinMode(echopin, INPUT); //set echopin as input
  pinMode(R, OUTPUT); // set R,G and B as outputs
  pinMode(G, OUTPUT);
  pinMode(B, OUTPUT);



}

void loop()

{

  //the trigpin sends out a signal, which bounces off an obstacle and comes back, the
  //echopin recieves this signal and gives out +5v setting the arduino pin on which it is connected to high.
  //distance= time*speed, but this distnce is divided by 2 because signal sent out returns
  //so distance= (the time it takes for the signal to leave and return)/2.
  //i.e if the time is 6s the distance = (6s/2) = 3m or cm.

  int duration, distance;//declare distance and duration as integers
  digitalWrite(trigpin, HIGH); // trigin send out signal
  _delay_ms(1000);//coninously for 1000ms
  digitalWrite(trigpin, LOW);// then goes low

  duration = pulseIn(echopin, HIGH); // duration is the pulseIn to the echopin
  distance = (duration / 2) / 29.1; //  the 29.1 is used to convert the distnce to cm, the value varies for other units.

  if (distance > 1 && distance <= 10) { //distcance is greater than 0 and less than 20cm
    digitalWrite(R, HIGH); //Red led is on
    digitalWrite(G, LOW); //Green led is off
    digitalWrite(B, LOW); //Blue led is off

  }
  else if (distance > 10 && distance <= 60) { //distcance is greater than 20 and less than 80cm
    digitalWrite(R, LOW); //Red led is off
    digitalWrite(G, HIGH); //Green led is on
    digitalWrite(B, LOW); //Blue led is off

  }

  else if (distance > 60 && distance <= 120 ) { //distcance is greater than 80 and less than 120cm
    digitalWrite(R, LOW); //Red led is off
    digitalWrite(G, LOW); //Green led is off
    digitalWrite(B, HIGH); //Blue led is on

  }
  Serial.print("cm");
  Serial.println(distance);//print values on serial monitor

}
