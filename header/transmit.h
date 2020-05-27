//define local variable(s) here.  Use static keyword to keep local, e.g:
//   static int i;  // defines a local int named i



/*complete the state machine*/

void Transmit()
{
    	switch(transmit_state)
    	{
        	case TInit:
			PORTB = value_ping | value_detect_eq | value_detect_max | value_detect_zc;
            		break;
        	default:
			PORTB = 0x00;
            		transmit_state = TInit;
            		break;
    	}
    	switch(transmit_state)
    	{
    	    case TInit:
            		break;
        	default:
            		break;
    	}

}
