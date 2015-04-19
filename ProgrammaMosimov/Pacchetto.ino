void init_debug(){
        SerialPacked.struc.start_byte_tx = START;
        SerialPacked.struc.start2_byte_tx = START2;
        SerialPacked.struc.stop_byte_rx = STOP;
}

void debug()
{
/*
      x_robot = 0;
      y_robot = 0;
      z_robot = 0;
      
      if(r  > 253) {
        r = 0;
        if (asse == 4)asse = 0;
        else  ++asse;

      }
      else r=r+10;
      
      if (asse == 1) x_robot = r;
      if (asse == 2) y_robot = r;
      if (asse == 3) z_robot = r;

*/
      SerialPacked.struc.x_robot_tx           = x_robot;      
      SerialPacked.struc.y_robot_tx           = y_robot;
      SerialPacked.struc.z_robot_tx           = z_robot;
      

for(int i=0;i < 6 ; i++){
      Serial1.write(SerialPacked.bytes[i]);
      }
    delay(100);
  }
  //UNIONE_E_STRUTTURA_DEBUG_STATION___________________________________________________________________________



void invio_pacchetto (){ 
  for(int c = 0; c < 6 ;c++)
  {
  Serial1.write(SerialPacked.bytes[c]);
  }
}



