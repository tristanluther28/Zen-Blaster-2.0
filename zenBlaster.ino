/*
 Lil' BASTARD ZEN BLASTER
WARNING! THIS DRIVES PEOPLE NUTS! DON'T DO IT TO ANYBODY WHO IS LIKELY TO PUNCH YOU IN THE FACE.
Makes annoying beeps at random intervals. The random pitch and interval makes it very difficult to pin-point the source of the beeping. 

Modified by:
Tristan Luther on,
November 27, 2017 
*/
 const int speaker = 6; // this sets the pin on the MSP430 that sends a beep to the speaker. 
 int duration = 1000; // this is a variable that stores the value of length of the tone
  int frequency = 600; // this is a variable that stores the value of the frequency of the tone
  int beeps = 2; // this is a variable that stores how many beeps in a sequence
  
// the setup routine runs once when you press reset:
void setup() {                
 Serial.begin(9600);
 tone(speaker, 2500, 800);
delay (200);
 tone(speaker, 500, 800);
delay (200);
 tone(speaker, 2500, 800);
delay (200);
// this runs through a few tones when you first start to let you know it's working.

 
}

// the loop routine runs over and over again forever:
void loop() {
  Serial.print(beeps);
  for(beeps; beeps >= 0; beeps--)
  {
    duration = random (200, 2000); // sets the length of time for each beep in milliseconds 
    frequency = random (2500, 6000); // sets the frequency in Hertz of the square wave signal to the speaker
    tone (speaker, frequency, duration); // sends a beep square wave signal to the speaker according to the values of frequency and duration
    delay (duration/2); // sets a short delay pause to allow the beep prior to executing the next command
  }
  delay(duration*6);
  beeps = random (2, 5); // sets the number of beeps for the next time
}
