///////////////////////////////////////////////////
//////////////////////////////////////////////////
//
//                                   VEX Cortex UART Test
//
// Simple program to test user c<t_8b>trol over the VEX Cortex UART ports. 
//
// 1. The two ports are looped back - to - back.
//
// 2. One port sim ply outputs characters with hex values 0, 1, 2, ... 255, 0, 1, 2, ...
//
// 3. The "UARTReceive" task grabs the characters from the receive UART and verifies that they are
//    in the above sequence.
//
// Various peg counts are used to accumulate total c haracters transmitted, received and "out of
// sequence" counts. These can be viewed in the ROBOTC debugger.
//
// NOTE: Internally the firmware uses interrupt handlers to buffer the characters transmitted and
//       received. The buffers are about 25 ch aracters in length. If user program does not extract
//       the characters fast enough the older characters are simply discarded.
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

task UARTReceive();
int nRcvIndex = 0;
long nTotalXmitChars = 0;
long nTotalRcvChars = 0;
long nTotalRcvOutOfSequence = 0;
unsigned char xmitChar;
int rcvChar;
unsigned char rcvChars[23];

// Keep buffer of last 23 characters received.
task main() {
	// Setup the two UA RT ports
	configureSerialPort(uartOne, uartUserControl);
	configureSerialPort(uartTwo, uartUserControl);
	setBaudRate(uartOne, baudRate115200);
	// setBaudRate(uartTwo, baudRate115200);
	while (getChar(uartTwo) != -1)
		// Purge existing chars from buffer
	{}
	// StartTask(UARTReceive);
	while (true) {
		// Loop forever transmitting the characters 0, 1, 2, ..., 255, 0, 1, 2, ....
		++nTotalXmitChars;
		xmitChar = nTotalXmitChars % 256;
		sendChar(uartOne, xmitChar);
		while (!bXmitComplete(uartOne))
		{
			wait1Msec(1);
		}
	}
}

task UARTReceive() {
	while (true)
	{
		// Loop forever getting characters from the "receive" UART. Validate that they arrive in the expected
		// sequence.
		static int nLastRcvChar = 0;
		rcvChar = getChar(uartTwo);
		if (rcvChar == -1)
		{
			// No character available
			wait1Msec(3);
			// D<t_8b>'t want to c<t_8b>sume too much CPU time. Waiting eliminates CPU c<t_8b>sumpti<t_8b> for this task.
			continue ;
		}
		++nLastRcvChar;
		nLastRcvChar %= 256;
		if (nLastRcvChar != rcvChar)
			++nTotalRcvOutOfSequence;
		nLastRcvChar = rcvChar;
		rcvChars[nRcvIndex] = rcvChar;
		++nTotalRcvChars;
		++nRcvIndex;
		if (nRcvIndex >= sizeof(rcvChars))
			nRcvIndex = 0;
	}
}
