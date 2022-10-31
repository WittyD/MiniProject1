#define TRANSMIT_LED A1
//#define BUTTON 3
#define SAMPLING_TIME 20

char* text = "WELCOME TO ADC PROJECT * ";

//Declaration
bool led_state = false;
bool button_state = false;
bool transmit_data = true;
int bytes_counter = 20;
int total_bytes;
void setup() {
  // put your setup code here, to run once:
  pinMode(TRANSMIT_LED,OUTPUT);
  //pinMode(BUTTON,INPUT_PULLUP);
  total_bytes = strlen(text);
}

void loop() 
{
  for(int i = 0; i < total_bytes; i++)
  {
    transmit_byte(text[i]);
  }
  delay(1000);
}

void transmit_byte(char data_byte)
{
  digitalWrite(TRANSMIT_LED,LOW); 
  delay(SAMPLING_TIME);
  for(int i = 0; i < 8; i++)
  {
    digitalWrite(TRANSMIT_LED,(data_byte >> i) & 0x01); 
    delay(SAMPLING_TIME);
  }
 digitalWrite(TRANSMIT_LED,HIGH); //Return to IDLE state
 delay(SAMPLING_TIME);
}
