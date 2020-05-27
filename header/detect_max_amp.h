//define local variable(s) here.  Use static keyword to keep local, e.g:
//   static int i;  // defines a local int named i

/* complete the state machine. */
unsigned char reading = 0x00;
void Detect_Max_Amp()
{
    	switch(detect_max_amp_state)
    	{
        	case DMAInit:
			if ((PORTB & 0x02) == 0x02) { //active earthquake
				if ((~PINA & 0xF8) > reading) { //determine maximum
					reading = (~PINA & 0xF8); //update maximum
				}
			} else { //inactive earthquake			
				reading = 0x00;
			}
            		break;
        
        	default:
            		break;
    	}
    	switch(detect_max_amp_state)
    	{
        	case DMAInit:
			value_detect_max = reading;
            		break;
        	default:
			value_detect_max = 0x00;
            		break;
    	}
}
