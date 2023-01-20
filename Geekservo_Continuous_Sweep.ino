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
	Serial.println( "New loop.\n" );
	digitalWrite( 2, HIGH );
	Serial.printf( "LED is %d\n", digitalRead( 2 ) );
	for( dutyCycle = 5; dutyCycle <= 32; dutyCycle++ )
	{
		ledcWrite( PWMChannel, dutyCycle );
		delay( 150 );
	}
	Serial.printf( "Currently at: %d\n", dutyCycle );
	delay( 3000 );

	Serial.println( "Middle of loop.\n" );

	digitalWrite( 2, LOW );
	Serial.printf( "LED is %d\n", digitalRead( 2 ) );
	for( dutyCycle = 32; dutyCycle >= 5; dutyCycle-- )
	{
		ledcWrite( PWMChannel, dutyCycle );
		delay( 70 );
	}
	Serial.printf( "Currently at: %d\n", dutyCycle );
	delay( 3000 );

	Serial.println( "End of loop...\n" );
}
