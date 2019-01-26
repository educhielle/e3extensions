#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>   /* File Control Definitions           */
#include <termios.h> /* POSIX Terminal Control Definitions */
#include <unistd.h>  /* UNIX Standard Definitions          */
#include <errno.h>   /* ERROR Number Definitions           */
#include <unistd.h>
#include "constants.h"

int* mod_mul (int argA[64], int argB[64], int port_descriptor);
int* mod_exp (int argA[64], int argB[64], int port_descriptor);
int* mod_inv (int argA[64], int argB[64], int port_descriptor);
int* gfunc (int argA[64], int argB[64], int port_descriptor);
int* read_serial_2x (int address, int port_descriptor);
int* read_serial_1x (int address, int port_descriptor);
int write_serial_2x (int address, int data[] , int port_descriptor );
int write_serial_1x (int address, int data[] , int port_descriptor );
int write_serial (int address, int data, int port_descriptor );
int read_serial (int address, int port_descriptor);
int func(int address, int port_descriptor);
int init_port ();

int init_port ()
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
        cfsetispeed(&SerialPortSettings,B9600); /* Set Read  Speed as 9600                       */
        cfsetospeed(&SerialPortSettings,B9600); /* Set Write Speed as 9600                       */

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
        SerialPortSettings.c_cc[VMIN] = 3 ; //3; /* Read at least 10 characters */
        SerialPortSettings.c_cc[VTIME] = 0; //0; /* Wait indefinetly   */
		SerialPortSettings.c_lflag = 0;


        if((tcsetattr(fd,TCSANOW,&SerialPortSettings)) != 0) /* Set the attributes to the termios structure*/
            printf("\n  ERROR ! in Setting attributes");
        else
            printf("\n  BaudRate = 9600 \n  StopBits = 1 \n  Parity   = none \n");

        tcflush(fd, TCIFLUSH);   /* Discards old data in the rx buffer            */
	return fd ;

}

int read_serial (int address, int port_descriptor)
{
	usleep (100) ;
	int bytes_written, bytes_read, read_buffer 	;
	int rdstring 		= 0x4D4D4D4D 		;

	int *ptr 		= &rdstring 		;
	int *addptr 		= &address	;
	int *rdptr 		= &read_buffer 		;
	bytes_written 	= write(port_descriptor, ptr, 4) 	;
	bytes_written 	= write(port_descriptor, addptr, 4) 	;
	bytes_read 	= read(port_descriptor, rdptr, 4) 	;

	return *rdptr ;

}

int* read_serial_1x (int address, int port_descriptor)
{
	int i = 0 ;
	static int arr[32] ;
	int addr_loc ;
	for (i = 0 ; i < 32 ; i++ )
	{
		addr_loc = address + i*0x4 ;
		arr[31-i] = read_serial(addr_loc, port_descriptor) ;
	}
	return arr;

}

int* read_serial_2x (int address, int port_descriptor)
{
	int i = 0 ;
	static int arr[64] ;
	int addr_loc ;
	for (i = 0 ; i < 64 ; i++ )
	{
		addr_loc = address + i*0x4 ;
		arr[63-i] = read_serial(addr_loc, port_descriptor) ;
	}
	return arr ;
}

int write_serial (int address, int data, int port_descriptor )
{
	int bytes_written 				;
	int write_buffer 	= data			;
	int wrstring 		= 0x34343434 		;

	int *ptr		= &wrstring		;
	int *addptr		= &address		  ;
	int *wrptr		= &data			 ;

	bytes_written 	= write(port_descriptor, ptr, 4) 	;
	bytes_written 	= write(port_descriptor, addptr, 4) 	;
	bytes_written 	= write(port_descriptor, wrptr, 4) 	;
	return 0 ;
}

int write_serial_1x (int address, int data[] , int port_descriptor )
{
	int i ;
	int addr_loc, data_loc ;

	for (i = 0 ; i < 32 ; i++ )
	{
		addr_loc = address + i*0x4 ;
		data_loc = data[31-i] ;
		write_serial (addr_loc, data_loc, port_descriptor) ;
	}
	return 0 ;
}


int write_serial_2x (int address, int data[] , int port_descriptor )
{
	int i ;
	int addr_loc, data_loc ;
	for (i = 0 ; i < 64 ; i++ )
	{
		addr_loc = address + i*0x4 ;
		data_loc = data[63-i] ;
		write_serial (addr_loc, data_loc, port_descriptor) ;
	}
	return 0 ;
}



int* mod_mul (int argA[64], int argB[64], int port_descriptor)
{

	int* result ;

	write_serial	(GPCFG_CLCTLP_ADDR,0x00000100, port_descriptor)  ;
	write_serial_2x (GPCFG_ARGA_ADDR0, argA, port_descriptor) 	 ;
	write_serial_2x (GPCFG_ARGB_ADDR0, argB, port_descriptor) 	 ;
	result = read_serial_2x  (GPCFG_ARGA_ADDR0, port_descriptor) 		 ;
	write_serial    (GPCFG_CLCTLP_ADDR, 0x00000001, port_descriptor) ;

	sleep (1);
	// usleep(1000);

	result = read_serial_2x  (GPCFG_MUL_ADDR0, port_descriptor) 		 ;

    	write_serial   (GPCFG_GPIO0_PAD_CTL,0x0111001A, port_descriptor) ;

	return result  ;
}

int* mod_exp (int argA[64], int argB[64], int port_descriptor)
{

	int* result ;
	write_serial	(GPCFG_CLCTLP_ADDR,0x00000100, port_descriptor)  ;
	write_serial_2x (GPCFG_ARGA_ADDR0, argA, port_descriptor) 	 ;
	write_serial_2x (GPCFG_ARGB_ADDR0, argB, port_descriptor) 	 ;
	write_serial    (GPCFG_CLCTLP_ADDR, 0x00000002, port_descriptor) ;

	sleep (1);

	result = read_serial_2x  (GPCFG_EXP_ADDR0, port_descriptor) 		 ;

    	write_serial   (GPCFG_GPIO0_PAD_CTL,0x0111001A, port_descriptor) ;
	return result ;
}

int* mod_inv (int argA[64], int argB[64], int port_descriptor)
{

	int* result ;
	int error ;

	write_serial	(GPCFG_CLCTLP_ADDR,0x00000100, port_descriptor)  ;
	write_serial_2x (GPCFG_ARGA_ADDR0, argA, port_descriptor) 	 ;
	write_serial_2x (GPCFG_ARGB_ADDR0, argB, port_descriptor) 	 ;
	write_serial    (GPCFG_CLCTLP_ADDR, 0x00000004, port_descriptor) ;

	sleep (1);

	error = read_serial(GPCFG_CLSTATUS_ADDR, port_descriptor) ;

	printf("The error value is :%X", error) ;
	if (error == 0x1 )
	{
		result = 0 ;
	}
	else
	{
		result = read_serial_2x  (GPCFG_INV_ADDR0, port_descriptor) 		 ;
	}

	return result ;
}

int* gfunc (int argA[64], int argB[64], int port_descriptor)
{
	int* result ;

	write_serial	(GPCFG_CLCTLP_ADDR,0x00000100, port_descriptor)  ;
	write_serial_2x (GPCFG_ARGA_ADDR0, argA, port_descriptor) 	 ;
	write_serial_2x (GPCFG_ARGB_ADDR0, argB, port_descriptor) 	 ;
	write_serial    (GPCFG_CLCTLP_ADDR, 0x00000008, port_descriptor) ;

	sleep (1)							 ;
	// usleep(100000);

	result = read_serial_2x  (GPCFG_RES_ADDR0, port_descriptor)      ;

	return result ;
}

int initialize_chip ( pd )
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

int main ()
{
	int pd = init_port() ;
	printf("%08x\n",read_serial(0x400200CC,pd));
	int* result 	;
	int length = 64;
	int argA[length], argB[length];
	for ( int i=0 ; i<length; i++ )
	{
		argA[i] = 0;
		argB[i] = 0;
	}
	argA[0]=5;
	argB[0]=4;

	printf("Initializing the chip\n") ;
	initialize_chip (pd) ;
	printf("after\n");

	result = mod_mul(argA,argB,pd) ;
	printf("end of mul\n");
	for ( int i=0; i<length; i++ ) printf("%08x ", result[i]);
	printf("\n");
	// result = mod_inv(argA,cleq_NSQ,pd) ;
	// result = mod_inv(argB,cleq_NSQ,pd) ;
	result = gfunc(argA,argB,pd) ;
	//printf("end of gfun\n");
	//for ( int i=0; i<length; i++ ) printf("%08x ", result[i]);
	//printf("\n");

	close(pd) ;
	return 0 ;
}
