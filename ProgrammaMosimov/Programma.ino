#include <SPI.h> // Included for SFE_LSM9DS0 library
#include <Wire.h>
#include <SFE_LSM9DS0.h>


#define LSM9DS0_XM  0x1D // Would be 0x1E if SDO_XM is LOW
#define LSM9DS0_G   0x6B // Would be 0x6A if SDO_G is LOW

LSM9DS0 dof(MODE_I2C, LSM9DS0_G, LSM9DS0_XM);


#define PRINT_CALCULATED
//#define PRINT_RAW

#define PRINT_SPEED 500 // 500 ms between prints


#define START 168
#define START2 192

#define STOP  255
//------------------------------------------------------------------PROGRAMMA DI INVIO------------------------------------------------------------------
#define valvolaDx  10   // pin valvola dx MODULO
#define valvolaSx  11   // pin valvola sx MODULO
#define ultrasuonoDx 5 // pin ultrasuono dx MODULO
#define ultrasuonoSx 6 // pin ultrasuono sx MODULO
#define distanzaOstacolo 10 // distanza a cui suonano gli ultrasuoni MODULO
#define buzzer 2      // pin buzzer MODULO
#define tastoDx 10 // pin tasto destro
#define tastoSx 11 // pin tasto sinistro

char segnale;
byte r = 0;
byte asse = 1;
byte x_robot = 0;
byte y_robot = 0;
byte z_robot = 0;


union packed { // pacchetto dati
  struct frame {
    unsigned char start_byte_tx;
    unsigned char start2_byte_tx;//1
    unsigned char x_robot_tx;//1
    unsigned char y_robot_tx;//1
    unsigned char z_robot_tx;//1
    unsigned char stop_byte_rx;

  }
  struc;
  unsigned char bytes[6];
}
SerialPacked;


void setup() {

    Serial.begin(57600);
  uint16_t status = dof.begin();

  Serial1.begin(57600);
  init_debug();
}

void loop() {

      
  printGyro();
  printAccel();
  printMag();
  printHeading((float) dof.mx, (float) dof.my);
  printOrientation(dof.calcAccel(dof.ax), dof.calcAccel(dof.ay),dof.calcAccel(dof.az));
      
  debug();

  invio_pacchetto ();   //invio_pacchetto();

  
  delay(1);

}


