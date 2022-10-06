/* ESP32 Servo Sweep */
const int servoPin = 23;

int dutyCycle = 0;

/* Setting PWM properties */
const int PWMFreq = 50;
const int PWMChannel = 0;
const int PWMResolution = 8;
//const int MAX_DUTY_CYCLE = ( int )( pow( 2, PWMResolution ) - 1 );

void setup()
{  
  Serial.begin( 115200 );
  ledcSetup( PWMChannel, PWMFreq, PWMResolution );
  /* Attach the LED PWM Channel to the GPIO Pin */
  ledcAttachPin( servoPin, PWMChannel );
  ledcWrite( PWMChannel, dutyCycle );
  pinMode( 2, OUTPUT );  
}
void loop()
{
  digitalWrite( 2, HIGH );   // turn the LED on (HIGH is the voltage level)
  for( dutyCycle = 5; dutyCycle <= 32; dutyCycle++ )
  {    
    ledcWrite( PWMChannel, dutyCycle );
    delay( 70 );    
  }
  delay( 3000 );
  digitalWrite( 2, LOW );    // turn the LED off by making the voltage LOW  
  for( dutyCycle = 32; dutyCycle >= 5; dutyCycle-- )
  {
    ledcWrite( PWMChannel, dutyCycle );
    delay( 70 );    
  }
  delay( 3000 );
}
