#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>   /* File Control Definitions           */
#include <termios.h> /* POSIX Terminal Control Definitions */
#include <unistd.h>  /* UNIX Standard Definitions          */
#include <errno.h>   /* ERROR Number Definitions           */
#include <unistd.h>
#include "constants.hpp"
#include "timer.h"

unsigned long long timeRead = 0, countRead = 0;
unsigned long long timeWrite = 0, countWrite = 0;
unsigned long long timeMul = 0, countMul = 0;
unsigned long long timeExp = 0, countExp = 0;
unsigned long long timeGfun = 0, countGfun = 0;
unsigned long long timeInv = 0, countInv = 0;
// unsigned long long discount = 0, countDiscount = 0;
int arduinoHandler;
bool usingArduino = false;
bool fastUART = false;
unsigned interruptCounter = 0;

unsigned* mod_mul (unsigned argA[64], unsigned argB[64], unsigned port_descriptor);
unsigned* mod_exp (unsigned argA[64], unsigned argB[64], unsigned port_descriptor);
unsigned* mod_inv (unsigned argA[64], unsigned argB[64], unsigned port_descriptor);
unsigned* gfunc (unsigned argA[64], unsigned argB[64], unsigned port_descriptor);
unsigned* read_serial_2x (unsigned address, unsigned port_descriptor);
unsigned* read_serial_1x (unsigned address, unsigned port_descriptor);
unsigned write_serial_2x (unsigned address, unsigned data[] , unsigned port_descriptor );
unsigned write_serial_1x (unsigned address, unsigned data[] , unsigned port_descriptor );
unsigned write_serial (unsigned address, unsigned data, unsigned port_descriptor );
unsigned read_serial (unsigned address, unsigned port_descriptor);
int func(int address, int port_descriptor);
int init_port ();

int initArduino()
{
	int fd;
	printf("\nInit Arduino");
	fd = open("/dev/ttyACM3",O_RDWR | O_NOCTTY);
	if(fd == -1)                                            /* Error Checking */
	   printf("\n  Error! : Not able to open Serial Port of Arduino ");
	else
	   printf("\n  Connection to Serial Port of Arduino successful ");

	   struct termios SerialPortSettings;      /* Create the structure                          */

   	tcgetattr(fd, &SerialPortSettings);     /* Get the current attributes of the Serial port */

   	/* Setting the Baud rate */
   	// cfsetispeed(&SerialPortSettings,B9600); /* Set Read  Speed as 9600                       */
   	// cfsetospeed(&SerialPortSettings,B9600); /* Set Write Speed as 9600                       */
	cfsetospeed(&SerialPortSettings,2000000); /* Set Write Speed as 9600                       */
	cfsetispeed(&SerialPortSettings,2000000); /* Set Read  Speed as 9600                       */

   	/* 8N1 Mode */
   	SerialPortSettings.c_cflag &= ~PARENB;   /* Disables the Parity Enable bit(PARENB),So No Parity   */
   	SerialPortSettings.c_cflag &= ~CSTOPB;   /* CSTOPB = 2 Stop bits,here it is cleared so 1 Stop bit */
   	SerialPortSettings.c_cflag &= ~CSIZE;    /* Clears the mask for setting the data size             */
   	SerialPortSettings.c_cflag |=  CS8;      /* Set the data bits = 8                                 */

   	SerialPortSettings.c_cflag &= ~CRTSCTS;       /* No Hardware flow Control                         */
   	SerialPortSettings.c_cflag |= CREAD | CLOCAL; /* Enable receiver,Ignore Modem Control lines       */


   	SerialPortSettings.c_iflag &= ~(IXON | IXOFF | IXANY);          /* Disable XON/XOFF flow control both i/p and o/p */
   	SerialPortSettings.c_iflag &= ~(ICANON | ECHO | ECHOE | ISIG);  /* Non Cannonical mode                            */

   	SerialPortSettings.c_oflag &= ~OPOST;/*No Output Processing*/

   	/* Setting Time outs */
   	SerialPortSettings.c_cc[VMIN] = 1 ; //3; /* Read at least 10 characters */
   	SerialPortSettings.c_cc[VTIME] = 0; //0; /* Wait indefinetly   */
   	SerialPortSettings.c_lflag = 0;


   	if((tcsetattr(fd,TCSANOW,&SerialPortSettings)) != 0) /* Set the attributes to the termios structure*/
   		printf("\n  ERROR ! in Setting attributes");
   	else
   		printf("\n  BaudRate = 2000000 \n  StopBits = 1 \n  Parity   = none \n");

   	tcflush(fd, TCIFLUSH);   /* Discards old data in the rx buffer            */
   arduinoHandler = fd;
   return arduinoHandler;
}

void clearInterrupt()
{
	std::cout << "Clear Interrupt IN\n";
	int count;
	char buf[101] = {0};
	do
	{
		count = read(arduinoHandler, buf, 100);
		std::cout << "|" << buf << "| " << count << "\n";
	} while (count > 0);
	// interruptCounter = 0;
	std::cout << "Clear Interrupt OUT\n";
}

void readArduino ()
{
	// unsigned bytes_written, bytes_read, read_buffer 	;
	// unsigned rdstring 		= 0x4D4D4D4D 		;
	//
	// unsigned *ptr 		    = &rdstring 		;
	// unsigned *addptr 		= &address	;
	// unsigned *rdptr 		= &read_buffer 		;
	// bytes_written 	= write(port_descriptor, ptr, 4) 	;
	// bytes_written 	= write(port_descriptor, addptr, 4) 	;
	// bytes_read 	= read(port_descriptor, rdptr, 4) 	;
	//
	// return *rdptr ;
	// std::cout << "Read IN\n";
	char buf[2] = {0};
	unsigned count;
	do
	{
		count = read(arduinoHandler, buf, 1);
	} while (count == 0);
	// std::cout << "|" << buf << "| " << count << "\n";
	// std::cout << "Read OUT\n";
}

int init_port_number (unsigned portNumber)
{

	int fd;/*File Descriptor*/

        printf("\n +----------------------------------+");
        printf("\n |        Serial Port Read          |");
        printf("\n +----------------------------------+");

        /*------------------------------- Opening the Serial Port -------------------------------*/

        /* Change /dev/ttyUSB0 to the one corresponding to your system */

        printf("\n  INFO: Connecting to Serial Port of Cryptoleq Hardware ");
		fd = open("/dev/ttyUSB0",O_RDWR | O_NOCTTY);
        // fd = open("/dev/cu.usbserial-FT162CZ2",O_RDWR | O_NOCTTY);    /* ttyUSB0 is the FT232 based USB2SERIAL Converter   */
                                                        /* O_RDWR   - Read/Write access to serial port       */
                                                        /* O_NOCTTY - No terminal will control the process   */
                                                        /* Open in blocking mode,read will wait              */



        if(fd == -1)                                            /* Error Checking */
           printf("\n  Error! : Not able to open Serial Port of Cryptoleq Hardware ");
        else
           printf("\n  Connection to Serial Port of Cryptoleq Hardware successful ");


        /*---------- Setting the Attributes of the serial port using termios structure --------- */

        struct termios SerialPortSettings;      /* Create the structure                          */

        tcgetattr(fd, &SerialPortSettings);     /* Get the current attributes of the Serial port */

        /* Setting the Baud rate */
		switch ( portNumber )
		{
		case 9600:
			cfsetispeed(&SerialPortSettings,B9600); /* Set Read  Speed as 9600                       */
	        cfsetospeed(&SerialPortSettings,B9600); /* Set Write Speed as 9600                       */
			break;
		case 115200:
			cfsetispeed(&SerialPortSettings,B115200); /* Set Read  Speed as 9600                       */
			cfsetospeed(&SerialPortSettings,B115200); /* Set Write Speed as 9600                       */
			break;
		case 921600:
			cfsetispeed(&SerialPortSettings,B921600); /* Set Read  Speed as 9600                       */
			cfsetospeed(&SerialPortSettings,B921600); /* Set Write Speed as 9600                       */
			break;
		default:
			cfsetispeed(&SerialPortSettings,portNumber); /* Set Read  Speed as 9600                       */
	        cfsetospeed(&SerialPortSettings,portNumber); /* Set Write Speed as 9600                       */
		}


        /* 8N1 Mode */
        SerialPortSettings.c_cflag &= ~PARENB;   /* Disables the Parity Enable bit(PARENB),So No Parity   */
        SerialPortSettings.c_cflag &= ~CSTOPB;   /* CSTOPB = 2 Stop bits,here it is cleared so 1 Stop bit */
        SerialPortSettings.c_cflag &= ~CSIZE;    /* Clears the mask for setting the data size             */
        SerialPortSettings.c_cflag |=  CS8;      /* Set the data bits = 8                                 */

        SerialPortSettings.c_cflag &= ~CRTSCTS;       /* No Hardware flow Control                         */
        SerialPortSettings.c_cflag |= CREAD | CLOCAL; /* Enable receiver,Ignore Modem Control lines       */


        SerialPortSettings.c_iflag &= ~(IXON | IXOFF | IXANY);          /* Disable XON/XOFF flow control both i/p and o/p */
        SerialPortSettings.c_iflag &= ~(ICANON | ECHO | ECHOE | ISIG);  /* Non Cannonical mode                            */

        SerialPortSettings.c_oflag &= ~OPOST;/*No Output Processing*/

        /* Setting Time outs */
        SerialPortSettings.c_cc[VMIN] = 4 ; //3; /* Read at least 10 characters */
        SerialPortSettings.c_cc[VTIME] = 0; //0; /* Wait indefinetly   */
		SerialPortSettings.c_lflag = 0;


        if((tcsetattr(fd,TCSANOW,&SerialPortSettings)) != 0) /* Set the attributes to the termios structure*/
            printf("\n  ERROR ! in Setting attributes");
        else
            printf("\n  BaudRate = %u \n  StopBits = 1 \n  Parity   = none \n", portNumber);

        tcflush(fd, TCIFLUSH);   /* Discards old data in the rx buffer            */
	return fd ;

}

inline unsigned read_serial (unsigned address, unsigned port_descriptor)
{
	interruptCounter++;
	countRead++;
	usleep (100) ;
	unsigned bytes_written, bytes_read, read_buffer 	;
	unsigned rdstring 		= 0x4D4D4D4D 		;

	unsigned *ptr 		    = &rdstring 		;
	unsigned *addptr 		= &address	;
	unsigned *rdptr 		= &read_buffer 		;
	bytes_written 	= write(port_descriptor, ptr, 4) 	;
	bytes_written 	= write(port_descriptor, addptr, 4) 	;
	bytes_read 	= read(port_descriptor, rdptr, 4) 	;

	return *rdptr ;

}

inline unsigned* read_serial_1x (unsigned address, unsigned port_descriptor)
{
	unsigned i = 0 ;
	static unsigned arr[32] ;
	unsigned addr_loc ;
	for (i = 0 ; i < 32 ; i++ )
	{
		addr_loc = address + i*0x4 ;
		// arr[31-i] = read_serial(addr_loc, port_descriptor) ;
		arr[i] = read_serial(addr_loc, port_descriptor) ;
	}
	return arr;

}

inline unsigned* read_serial_2x (unsigned address, unsigned port_descriptor)
{
	unsigned i = 0 ;
	static unsigned arr[64] ;
	unsigned addr_loc ;
	for (i = 0 ; i < 64 ; i++ )
	{
		addr_loc = address + i*0x4 ;
		// arr[63-i] = read_serial(addr_loc, port_descriptor) ;
		arr[i] = read_serial(addr_loc, port_descriptor) ;
	}
	return arr ;
}

inline unsigned write_serial (unsigned address, unsigned data, unsigned port_descriptor )
{
	interruptCounter++;
	countWrite++;
	unsigned bytes_written 				;
	unsigned write_buffer 	= data			;
	unsigned wrstring 		= 0x34343434 		;

	unsigned *ptr		= &wrstring		;
	unsigned *addptr		= &address		  ;
	unsigned *wrptr		= &data			 ;

	bytes_written 	= write(port_descriptor, ptr, 4) 	;
	bytes_written 	= write(port_descriptor, addptr, 4) 	;
	bytes_written 	= write(port_descriptor, wrptr, 4) 	;
	return 0 ;
}

inline unsigned write_serial_1x (unsigned address, unsigned data[] , unsigned port_descriptor )
{
	unsigned i ;
	unsigned addr_loc, data_loc ;

	for (i = 0 ; i < 32 ; i++ )
	{
		addr_loc = address + i*0x4 ;
		// data_loc = data[31-i] ;
		data_loc = data[i] ;
		write_serial (addr_loc, data_loc, port_descriptor) ;
	}
	return 0 ;
}


inline unsigned write_serial_2x (unsigned address, unsigned data[] , unsigned port_descriptor )
{
	unsigned i ;
	unsigned addr_loc, data_loc ;
	for (i = 0 ; i < 64 ; i++ )
	{
		addr_loc = address + i*0x4 ;
		// data_loc = data[63-i] ;
		data_loc = data[i] ;
		write_serial (addr_loc, data_loc, port_descriptor) ;
	}
	return 0 ;
}



inline unsigned* mod_mul (unsigned argA[64], unsigned argB[64], unsigned port_descriptor)
{
	unsigned* result ;
	Timer2 tmrWrite1;
	write_serial	(GPCFG_CLCTLP_ADDR,0x00000100, port_descriptor)  ;
	write_serial_2x (GPCFG_ARGA_ADDR0, argA, port_descriptor) 	 ;
	write_serial_2x (GPCFG_ARGB_ADDR0, argB, port_descriptor) 	 ;
	write_serial    (GPCFG_CLCTLP_ADDR, 0x00000001, port_descriptor) ;
	timeWrite += tmrWrite1.get();

	Timer2 tmrOp;
	countMul++;

	if (usingArduino) readArduino();
	else sleep (1); // replace by loop reading interrupt
	// usleep(1000);
	timeMul += tmrOp.get();

	Timer2 tmrRead1;
	result = read_serial_2x  (GPCFG_MUL_ADDR0, port_descriptor) 		 ;
	timeRead += tmrRead1.get();

	Timer2 tmrWrite2;
	write_serial   (GPCFG_GPIO0_PAD_CTL,0x0111001A, port_descriptor) ;
	timeWrite += tmrWrite2.get();

	return result  ;
}

inline unsigned* mod_exp (unsigned argA[64], unsigned argB[64], unsigned port_descriptor)
{

	unsigned* result ;
	Timer2 tmrWrite1;
	write_serial	(GPCFG_CLCTLP_ADDR,0x00000100, port_descriptor)  ;
	write_serial_2x (GPCFG_ARGA_ADDR0, argA, port_descriptor) 	 ;
	write_serial_2x (GPCFG_ARGB_ADDR0, argB, port_descriptor) 	 ;
	write_serial    (GPCFG_CLCTLP_ADDR, 0x00000002, port_descriptor) ;
	timeWrite += tmrWrite1.get();

	Timer2 tmrOp;
	countExp++;
	if (usingArduino) readArduino();
	else sleep (1); // replace by loop reading interrupt
	// usleep(1000);
	timeExp += tmrOp.get();

	Timer2 tmrRead1;
	result = read_serial_2x  (GPCFG_EXP_ADDR0, port_descriptor) 		 ;
	timeRead += tmrRead1.get();

	Timer2 tmrWrite2;
	write_serial   (GPCFG_GPIO0_PAD_CTL,0x0111001A, port_descriptor) ;
	timeWrite += tmrWrite2.get();

	return result ;
}

inline unsigned* mod_inv (unsigned argA[64], unsigned argB[64], unsigned port_descriptor)
{

	unsigned* result ;
	unsigned error ;
	Timer2 tmrWrite1;
	write_serial	(GPCFG_CLCTLP_ADDR,0x00000100, port_descriptor)  ;
	write_serial_2x (GPCFG_ARGA_ADDR0, argA, port_descriptor) 	 ;
	write_serial_2x (GPCFG_ARGB_ADDR0, argB, port_descriptor) 	 ;
	write_serial    (GPCFG_CLCTLP_ADDR, 0x00000004, port_descriptor) ;
	timeWrite += tmrWrite1.get();

	Timer2 tmrOp;
	countInv++;
	if (usingArduino) readArduino();
	else sleep (1); // replace by loop reading interrupt
	// usleep(1000);
	timeInv += tmrOp.get();

	Timer2 tmrRead1;
	error = read_serial(GPCFG_CLSTATUS_ADDR, port_descriptor) ;
	timeRead += tmrRead1.get();

	// printf("The error value is :%X", error) ;
	if (error == 0x1 )
	{
		result = 0 ;
	}
	else
	{
		Timer2 tmrRead2;
		result = read_serial_2x  (GPCFG_INV_ADDR0, port_descriptor) 		 ;
		timeRead += tmrRead2.get();
	}

	return result ;
}

inline unsigned* gfunc (unsigned argA[64], unsigned argB[64], unsigned port_descriptor)
{
	unsigned* result ;
	Timer2 tmrWrite1;
	write_serial	(GPCFG_CLCTLP_ADDR,0x00000100, port_descriptor)  ;
	write_serial_2x (GPCFG_ARGA_ADDR0, argA, port_descriptor) 	 ;
	write_serial_2x (GPCFG_ARGB_ADDR0, argB, port_descriptor) 	 ;
	write_serial    (GPCFG_CLCTLP_ADDR, 0x00000008, port_descriptor) ;
	timeWrite += tmrWrite1.get();

	Timer2 tmrOp;
	countGfun++;
	if (usingArduino) readArduino();
	else sleep (1); // replace by loop reading interrupt
	timeGfun += tmrOp.get();							 ;

	Timer2 tmrRead1;
	result = read_serial_2x  (GPCFG_RES_ADDR0, port_descriptor)      ;
	timeRead += tmrRead1.get();

	return result ;
}

inline int initialize_chip ( int pd )
{
	int* result ;
	int i ;
	write_serial    (GPCFG_HOSTIRQ_PAD_CTL, 0x0012001A ,pd)		;
	write_serial    (GPCFG_CLCTL_ADDR,cleq_ctl,pd)			;
	write_serial    (GPCFG_CLEQCTL2,cleq_ctl2,pd)			;

	write_serial_1x (GPCFG_N_ADDR0, cleq_N, pd)			;
	write_serial_1x (GPCFG_RAND0_ADDR0,cleq_rand0,pd)		;
	write_serial_1x (GPCFG_RAND1_ADDR0,cleq_rand1,pd)		;
	write_serial_2x (GPCFG_NSQ_ADDR0,cleq_NSQ,pd)			;
	write_serial_2x (GPCFG_FKF_ADDR0,cleq_fkf,pd)			;

	write_serial	(GPCFG_CLCTLP_ADDR,0x00000200, pd)  ;

	return 0 ;
}


int init_port()
{
	unsigned baud = 9600;
	auto fd = init_port_number(baud);
	printf("%08x\n",read_serial(0x400200CC,fd));
	if (usingArduino) initArduino();
	if (fastUART)
	{
		unsigned baud = 921600; //115200;
		unsigned divider = 24000000 / baud;
		write_serial(GPCFG_UARTM_BAUD_CTL, divider, fd);
		// write_serial(GPCFG_UARTM_BAUD_CTL, 0x0000001A, fd);
		sleep(2);
		close(fd);
		sleep(1);
		fd = init_port_number(baud);
		printf("%08x\n",read_serial(0x400200CC,fd));
	}
	return fd;
}
