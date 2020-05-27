//define local variable(s) here.  Use static keyword to keep local, e.g:
//   static int i;  // defines a local int named i



/*complete the state machine*/
unsigned char detect_count = 0x00;
void Detect_EQ()
{
    	switch(detect_eq_state)
    	{
        	case DEQInit:
        	//init variable(s) here.
			detect_count = 0x00;
			
			//if an earthquake is detected
			if ( (~PINA & 0xF8) == 0x00) {
				detect_eq_state = DEQInit;
			} else {
				detect_eq_state = d1_detect;
			}
            		break;
		case d1_detect:
			//if the earthquake stopped, go to the count
			if ( (~PINA & 0xF8) == 0x00) {
				detect_eq_state = d2_count;
			} else {
				detect_eq_state = d1_detect;
			}
			break;
		case d2_count:
			if ( (~PINA & 0xF8) == 0x00 ) {
				detect_count++;
				if (detect_count == 10) {
					detect_eq_state = DEQInit;
				} else {
					detect_eq_state = d2_count;
				}
			} else { //if the earthquake is back
				detect_count = 0x00;
				detect_eq_state = d1_detect;
			}
			break;
        	default:
            		detect_eq_state = DEQInit;
            		break;
    	}
    	switch(detect_eq_state)
    	{
        	case DEQInit:
			value_detect_eq = 0x00;
            		break;
		case d1_detect:
			value_detect_eq = 0x55;
			break;
		case d2_count:
			value_detect_eq = 0x55;
			break;
        	default:
			value_detect_eq = 0x00;
            		break;
    	}
}
