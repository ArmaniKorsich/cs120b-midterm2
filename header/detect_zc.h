//define local variable(s) here.  Use static keyword to keep local, e.g:
//   static int i;  // defines a local int named i



/*complete the state machine*/
unsigned char direction = 0x00;
void Detect_ZC()
{
    	switch(detect_zc_state)
    	{
        	case DZCInit:
			direction = 0x00;
			if ((PORTB & 0x02) == 0x02) { //active earthquake
				direction = (~PINA & 0x07);
				detect_zc_state = z1_nextTick;
			} else { //inactive earthquake
				detect_zc_state = DZCInit; 
			}			        		
	    		break;
        	case z1_nextTick:
			if ((direction == 0x00) && ((~PINA & 0x07) == 0x04)) { //east -> west
				value_detect_zc = 0x04;	
			} else if ((direction == 0x01) && ((~PINA & 0x07) == 0x05)) { //NE -> SW
				value_detect_zc = 0x04;
			} else if ((direction == 0x02) && ((~PINA & 0x07) == 0x06)) { //north -> south
				value_detect_zc = 0x04;
			} else if ((direction == 0x03) && ((~PINA & 0x07) == 0x07)) { //NW -> SE
				value_detect_zc = 0x04;
			} else if ((direction == 0x04) && ((~PINA & 0x07) == 0x00)) { //west -> east
				value_detect_zc = 0x04;
			} else if ((direction == 0x05) && ((~PINA & 0x07) == 0x01)) { //SW -> NE
				value_detect_zc = 0x04;
			} else if ((direction == 0x06) && ((~PINA & 0x07) == 0x02)) { //south -> north
				value_detect_zc = 0x04;
			} else if ((direction == 0x07) && ((~PINA & 0x07) == 0x03)) { //SE -> NW
				value_detect_zc = 0x04;
			} else { //no zero crossing, any other combination.
				value_detect_zc = 0x00;
			}
			direction = (~PINA & 0x07);
			detect_zc_state = z1_nextTick; //at this point, if it detected a zero crossing, itll go back to this state. if there isnt a second zero crossing, then b2 will reset, otherwise, b2 will stay lit, if a second zero crossing is detected.

			break;
        	default:
            		detect_zc_state = DZCInit;
            		break;
    	}
    	switch(detect_zc_state)
    	{
        	case DZCInit:
            		break;
		case z1_nextTick:
			break;
        	default:
            		break;
    	}
}
