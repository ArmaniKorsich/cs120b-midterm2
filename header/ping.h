//define local variable(s) here.  Use static keyword to keep local, e.g:
//   static int i;  // defines a local int named i



/*complete the state machine*/
unsigned char pingCount = 0;

void Ping()
{
    	switch(ping_state)
   	{
        	case PInit:
         		if (pingCount == 9) {
				ping_state = p1;   
				pingCount = 0;
			} else {
				ping_state = PInit;
				pingCount++;
			}
			break;
		case p1:
			if (pingCount == 1) {
				ping_state = PInit;
				pingCount = 0;
			} else {
				ping_state = p1;
				pingCount++;
			}
			break;
        	default:
            		ping_state = PInit;
            		break;
    	}
    	switch(ping_state)
    	{
        	case PInit:
			value_ping = 0x00;
            		break;
		case p1:
			value_ping = 0x01;
			break;
        	default:
			value_ping = 0x00;
            		break;
    	}
}
