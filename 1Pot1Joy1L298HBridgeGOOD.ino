//The_fabiolous@hotmail.com
//December 2020
// Motor A

int enA = 10;
int in1 = 4;
int in2 = 5;

// Motor B

int enB = 3;
int in3 = 6;
int in4 = 7;

// Speed control potentiometers

int SpeedControl = A2;


// Joystick Input

int joyVert = A0; // Vertical
int joyHorz = A1; // Horizontal

// Motor Speed Values - Start at zero

int MotorSpeed1 = 0;
int MotorSpeed2 = 0;

// Joystick Values - Start at 512 (middle position)

int joyposVert = 512;
int joyposHorz = 512;


void setup()

{
  Serial.begin(9600);
  // Set all the motor control pins to outputs

  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);


  // Start with motors disabled and direction forward

  // Motor A

  digitalWrite(enA, LOW);
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);

  // Motor B

  digitalWrite(enB, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);

}


void loop() {

  // Read the Joystick X and Y positions

  joyposVert = analogRead(joyVert);
  joyposHorz = analogRead(joyHorz);
  MotorSpeed1 = analogRead(SpeedControl);
  MotorSpeed2 = analogRead(SpeedControl);

  if (joyposHorz < 460)
  {
    // This is left

    // Set Motor A backward

    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);

    // Set Motor B forward

    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);

    // Read the values from the potentiometers


    MotorSpeed1 = map(MotorSpeed1, 0, 1023, 0, 255);
    MotorSpeed2 = map(MotorSpeed2, 0, 1023, 0, 255);

  }

  else if (joyposHorz > 564)
  {
    //this is right
    // Set Motor A forward

    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);

    // Set Motor B backward

    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);

    MotorSpeed1 = map(MotorSpeed1, 0, 1023, 0, 255);
    MotorSpeed2 = map(MotorSpeed2, 0, 1023, 0, 255);

  }

  else if (joyposVert > 564)
  {
    // This is Forward

    // Set Motor A forward

    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);

    // Set Motor B forward

    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);

    //Determine Motor Speeds

    MotorSpeed1 = map(MotorSpeed1, 0, 1023, 0, 255);
    MotorSpeed2 = map(MotorSpeed2, 0, 1023, 0, 255);

  }
  else if (joyposVert < 460)
  {
    // This is Backward

    // Set Motor A backward

    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);

    // Set Motor B backward

    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);


    MotorSpeed1 = map(MotorSpeed1, 0, 1023, 0, 255);
    MotorSpeed2 = map(MotorSpeed2, 0, 1023, 0, 255);

  }


  else
  {
    // This is Stopped

    MotorSpeed1 = 0;
    MotorSpeed2 = 0;

  }



  // Adjust to prevent "buzzing" at very low speed

  if (MotorSpeed1 < 8)MotorSpeed1 = 0;
  if (MotorSpeed2 < 8)MotorSpeed2 = 0;

  // Set the motor speeds

  analogWrite(enA, MotorSpeed1);
  analogWrite(enB, MotorSpeed2);


}
