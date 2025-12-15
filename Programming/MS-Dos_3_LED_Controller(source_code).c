#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

    /* Declare functions */
void bufferclear()                                    /* Clear the Buffer */
void get_port_name();                                 /* Get Com Port # */
int open_serialCom();                                 /* Open the serial port */
int close_serialCom();                                /* Close the serial port */
void toggle_led();                                    /* Toggle LED on/off */

#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define RESET   "\033[0m"

    /* Declare variables and structures */
char inputChar;                                       /* Used for commands */
char port_name[3];                                    /* Used for port name */
int serial_port;                                      /* Used to open port */
int serialport_good = 0;                              /* Used in toggle LED */
char bufferIn[3];
int bufferIn_Count;
int bufferInMax = 4;
int signal_received = 0;                              /* Used for shutdown */
int led_1_on = 1;                                     /* Used for DTR LED toggle */
int led_2_on = 1;                                     /* Used for RTS LED toggle */
int led_3_on = 0;                                     /* Used for TXD LED toggle */
HANDLE hSerial;
 
int main()
{
    get_port_name();                                  /* Get Com Port # */
    open_serialCom();                                 /* Open the serial port */
    toggle_led();                                     /* Toggle LED on/off */
    close_serialCom();                                /* Close the serial port */
    return 0;                                         /* exit normally */
}

void bufferclear()                                    /* Clear the Buffer */
{
    for (bufferIn_Count = 0; bufferIn_Count <= bufferInMax; bufferIn_Count++)
        {
            bufferIn[bufferIn_Count] = 0;
        }
    bufferIn_Count = 0;
}

void get_port_name()                                  /* Get Com Port # */
{
    system("cls");                                    /* Clear the screen */
    bufferclear();                                    /* Clear the keyboard buffer */
    printf("\nEnter the Com Port # you are using\n");
    printf("Only Com ports between 1 and 25 are supported in this program.\n");

    while((inputChar = getchar()) != '\n')
    {
        if (!isdigit(inputChar))                      /* Check if a digit */
        {
            printf("\nInvalid input, Only digits are allowed.\n");
            printf("  Press Enter");
            getchar();
            getchar();                                /* Add delay to display error message */
            exit(0);                                  /* Exit program */
        }

        if (bufferIn_Count < bufferInSize)            /* If there is room in the buffer? */
        {
            bufferIn[bufferIn_Count] = inputChar;     /* load character into the buffer */
            bufferIn_Count++;                         /* Increment the buffer counter for the next character */
        }
    }
    if ((bufferIn[0]) == '\0')                        /* Check if string is empty */
    {

    }
    else
    {
        strcpy(port_name, bufferIn);                  /* Copy bufferIn to port_name */
    }
    int num = atoi(port_name);
    if (num <= 0 || num >= 26)                        /* Check if a valid port # between 1 and 25 */
    {
        printf("\nInvalid input, Only Com ports between 1 and 25 are supported in this program.\n");
        printf("  Press Enter");
        getchar();                                    /* Add delay to display error message */
        exit(0);                                      /* Exit program */
    }
    serial_port = num;                                /* Copy int num to variable for opening port */
    return;
}

int open_serialCom()                                  /* Open the serial port */
{
    printf("\n Opening Serial Port...");

        switch (serial_port)                          /* Holds the COM port # */
        {
            case 1:                                   /* Comport 1 */
            hserial = CreateFile("\\\\.\\COM1", GENERIC_READ|GENERIC_WRITE, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
            break;

            case 2:                                   /* Comport 2 */
            hserial = CreateFile("\\\\.\\COM2", GENERIC_READ|GENERIC_WRITE, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
            break;

            case 3:                                   /* Comport 3 */
            hserial = CreateFile("\\\\.\\COM3", GENERIC_READ|GENERIC_WRITE, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
            break;

            case 4:                                   /* Comport 4 */
            hserial = CreateFile("\\\\.\\COM4", GENERIC_READ|GENERIC_WRITE, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
            break;

            case 5:                                   /* Comport 5 */
            hserial = CreateFile("\\\\.\\COM5", GENERIC_READ|GENERIC_WRITE, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
            break;

            case 6:                                   /* Comport 6 */
            hserial = CreateFile("\\\\.\\COM6", GENERIC_READ|GENERIC_WRITE, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
            break;

            case 7:                                   /* Comport 7 */
            hserial = CreateFile("\\\\.\\COM7", GENERIC_READ|GENERIC_WRITE, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
            break;

            case 8:                                   /* Comport 8 */
            hserial = CreateFile("\\\\.\\COM8", GENERIC_READ|GENERIC_WRITE, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
            break;

            case 9:                                   /* Comport 9 */
            hserial = CreateFile("\\\\.\\COM9", GENERIC_READ|GENERIC_WRITE, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
            break;

            case 10:                                  /* Comport 10 */
            hserial = CreateFile("\\\\.\\COM10", GENERIC_READ|GENERIC_WRITE, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
            break;

            case 11:                                  /* Comport 11 */
            hserial = CreateFile("\\\\.\\COM11", GENERIC_READ|GENERIC_WRITE, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
            break;

            case 12:                                  /* Comport 12 */
            hserial = CreateFile("\\\\.\\COM12", GENERIC_READ|GENERIC_WRITE, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
            break;

            case 13:                                  /* Comport 13 */
            hserial = CreateFile("\\\\.\\COM13", GENERIC_READ|GENERIC_WRITE, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
            break;

            case 14:                                  /* Comport 14 */
            hserial = CreateFile("\\\\.\\COM14", GENERIC_READ|GENERIC_WRITE, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
            break;

            case 15:                                  /* Comport 15 */
            hserial = CreateFile("\\\\.\\COM15", GENERIC_READ|GENERIC_WRITE, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
            break;

            case 16:                                  /* Comport 16 */
            hserial = CreateFile("\\\\.\\COM16", GENERIC_READ|GENERIC_WRITE, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
            break;

            case 17:                                  /* Comport 17 */
            hserial = CreateFile("\\\\.\\COM17", GENERIC_READ|GENERIC_WRITE, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
            break;

            case 18:                                  /* Comport 18 */
            hserial = CreateFile("\\\\.\\COM18", GENERIC_READ|GENERIC_WRITE, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
            break;

            case 19:                                  /* Comport 19 */
            hserial = CreateFile("\\\\.\\COM19", GENERIC_READ|GENERIC_WRITE, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
            break;

            case 20:                                  /* Comport 20 */
            hserial = CreateFile("\\\\.\\COM20", GENERIC_READ|GENERIC_WRITE, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
            break;

            case 21:                                  /* Comport 21 */
            hserial = CreateFile("\\\\.\\COM21", GENERIC_READ|GENERIC_WRITE, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
            break;

            case 22:                                  /* Comport 22 */
            hserial = CreateFile("\\\\.\\COM22", GENERIC_READ|GENERIC_WRITE, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
            break;

            case 23:                                  /* Comport 23 */
            hserial = CreateFile("\\\\.\\COM23", GENERIC_READ|GENERIC_WRITE, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
            break;

            case 24:                                  /* Comport 24 */
            hserial = CreateFile("\\\\.\\COM24", GENERIC_READ|GENERIC_WRITE, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
            break;

            case 25:                                  /* Comport 25 */
            hserial = CreateFile("\\\\.\\COM25", GENERIC_READ|GENERIC_WRITE, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
            break;

            default:                                  /* Capture anything else here */
            break;
        }

    if (hserial == INVALID_HANDLE_VALUE)
    {
        printf("Serial Port does not exist.\n");
        serialport_good = 0;                          /* Port closed */
        printf("  Press Enter");
        getchar();                                    /* Add delay to display error message */

    }
    else
    {
        printf("OK, Serial Port open.\n");
        serialport_good = 1;                          /* Port open */
    }
    return 0;
}

int close_serialCom()                                 /* Close the serial port */
{
    printf(" Closing Serial Port...");
    CloseHandle(hserial);                             /* Close Serial port */
    if(CloseHandle(hserial) == 1)
    {
        printf("Error Closing Serial Port\n");
    }
    else printf(" OK, Serial Port closed.\n");

    return 0;
}

void toggle_led()                                     /* Toggle LED's on/off */
{
    if (serialport_good == 0)
    {
        return;
    }
            /* Onscreen Instructions */
    printf("\n ******************************\n");
    printf(" *  Use d to toggle DTR LED   *\n");
    printf(" *  Use r to toggle RTS LED   *\n");
    printf(" *  Use t to toggle TXD LED   *\n");
    printf(" *  Use x to exit             *\n");
    printf(" ******************************\n");

     while (signal_received == 0)
     {
        inputChar = getchar();                        /* Read user input into 'inputChar' */
        if ((inputChar) == 120)                       /* Check for x character */
        {
            signal_received = 1;
        }
        if ((inputChar) == 100)                       /* Check for d character */
        {
            if (led_1_on == 1)
            {
                EscapeCommFunction(hSerial, CLRDTR);
                led_1_on = 0;
                printf("%s DTR LED Off%s\n", GREEN, RESET);
            }
            else
            {
                EscapeCommFunction(hSerial, SETDTR);
                led_1_on = 1;
                printf("%s DTR LED On%s\n", RED, RESET);
            }
        }
         if ((inputChar) == 114)                       /* Check for r character */
        {
            if (led_2_on == 1)
            {
                EscapeCommFunction(hSerial, CLRRTS);
                led_2_on = 0;
                printf("%s RTS LED Off%s\n", GREEN, RESET);
            }
            else
            {
                EscapeCommFunction(hSerial, SETRTS);
                led_2_on = 1;
                printf("%s RTS LED On%s\n", RED, RESET);
            }
        }
        if ((inputChar) == 116)                       /* Check for t character */
        {
            if (led_3_on == 1)
            {
                EscapeCommFunction(hSerial, CLRBREAK);
                led_3_on = 0;
                printf("%s TXD LED Off%s\n", GREEN, RESET);
            }
            else
            {
                EscapeCommFunction(hSerial, SETBREAK);
                led_3_on = 1;
                printf("%s TXD LED On%s\n", RED, RESET);
            }
        }
    }
}
