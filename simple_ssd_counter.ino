/* Simple  mono counter using MAN6710 SSD, by weld */

/* 0 entry
 * 1 - 7 segments
 * 8 dot
 */
 
int ssd[9] = {22, 28, 30, 32, 34, 36, 38, 40, 42};

// state matrix
int state[8] = {0, 0, 0, 0, 0, 0, 0, 0};

// counter
int count = 0;

void setup(){
  for(int i = 0; i < 9; i++)
    pinMode(ssd[i], OUTPUT);
}

// reset the state matrix
void reset_state(){
  state[0] = 0;
  state[1] = 0;
  state[2] = 0;
  state[3] = 0;
  state[4] = 0;
  state[5] = 0;
  state[6] = 0;
  state[7] = 0;
}

/*
 * Light up the Segment
 * Btw i'm using pins as ground, cause my SSD has a common anode 
 */
void light_segments(){
  
  for(int i = 0; i < 8; i++){
    if(state[i] == 1)
      digitalWrite(ssd[i+1], LOW);
    else
      digitalWrite(ssd[i+1], HIGH);
  }
  
}

void loop(){
  
  digitalWrite(ssd[0], HIGH); 
  switch (count) {
     case 0:
       state[0] = 1;
       state[1] = 1;
       state[2] = 1;
       state[3] = 1;
       state[4] = 1;
       state[5] = 1;
      break;
    case 1:
      state[1] = 1;
      state[2] = 1;
      break;
    case 2:
      state[0] = 1;
      state[1] = 1;
      state[6] = 1;
      state[4] = 1;
      state[3] = 1;
     break;
    case 3:
      state[0] = 1;
      state[1] = 1;
      state[2] = 1;
      state[3] = 1;
      state[6] = 1;
     break;
    case 4:
      state[1] = 1;
      state[2] = 1;
      state[6] = 1;
      state[5] = 1;
     break;
    case 5:
      state[0] = 1;
      state[5] = 1;
      state[6] = 1;
      state[2] = 1;
      state[3] = 1;
     break;
    case 6:
      state[0] = 1;
      state[5] = 1;
      state[6] = 1;
      state[2] = 1;
      state[3] = 1;
      state[4] = 1;
     break;
    case 7:
      state[0] = 1;
      state[1] = 1;
      state[2] = 1;
     break;
    case 8:
       state[0] = 1;
       state[1] = 1;
       state[2] = 1;
       state[3] = 1;
       state[4] = 1;
       state[5] = 1;
       state[6] = 1;
      break;
    case 9:
       state[0] = 1;
       state[1] = 1;
       state[2] = 1;
       state[3] = 1;
       state[5] = 1;
       state[6] = 1;
       break;
    default:
      reset_state();
      break;
  }
  
  // reset counter
  if(count == 9)
    count = 0;
  else
    count++;
    
  light_segments();
  reset_state();

  delay(1000);
}
