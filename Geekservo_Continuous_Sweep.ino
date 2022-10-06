/*
 * Geekservo_Continuous_Sweep
 */

const int servoPin = 23;
const int PWMFreq = 50;
const int PWMChannel = 0;
const int PWMResolution = 8;
//const int MAX_DUTY_CYCLE = ( int )( pow( 2, PWMResolution ) - 1 );

int dutyCycle = 0;


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
	digitalWrite( 2, HIGH );
	for( dutyCycle = 5; dutyCycle <= 32; dutyCycle++ )
	{
		ledcWrite( PWMChannel, dutyCycle );
		delay( 70 );
	}
	delay( 3000 );

	digitalWrite( 2, LOW );
	for( dutyCycle = 32; dutyCycle >= 5; dutyCycle-- )
	{
		ledcWrite( PWMChannel, dutyCycle );
		delay( 70 );
	}
	delay( 3000 );
}
