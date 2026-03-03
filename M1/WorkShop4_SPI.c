#include <stdio.h>
// TODO add correct include

#include "system.h" // allows access to the components
#include "io.h"     // macros to access PIOs

// Gyro write Registers
#define BW_RATE 0x2c
#define POWER_CONTROL 0x2d
#define DATA_FORMAT 0x31
#define INT_ENABLE 0x2E
#define INT_MAP 0x2F
#define THRESH_ACT 0x24
#define THRESH_INACT 0x25
#define TIME_INACT 0x26
#define ACT_INACT_CTL 0x27
#define THRESH_FF 0x28
#define TIME_FF 0x29
#define TAP_AXES 0x2a
#define TAP_THRES 0x1d
#define LATENT 0x22
#define DUR 0x21
#define WINDOW 0x23

// Gyro read Registers
#define INT_SOURCE 0x30
#define X_LB 0x32
#define X_HB 0x33
#define Y_LB 0x34
#define Y_HB 0x35
#define Z_LB 0x36
#define Z_HB 0x37

#define CONFIG_LENGHT 16 * 2 // number of config details to send to initlise gyro

#define MAX_COUNT 500000 // cycles to count to before printing

#define READ_X_AXIS 0xc0 | X_LB // enable read bit and multi byte
#define READ_Y_AXIS 0xc0 | Y_LB // enable read bit and multi byte
#define READ_Z_AXIS 0xc0 | Z_LB // enable read bit and multi byte

// define desired setup settings with write location then value to write
alt_u8 gyro_config[CONFIG_LENGHT] = {
    DATA_FORMAT, 0x0b, // 4-wire SPI, full resolution, +/- 16g
    THRESH_ACT, 0x04,
    THRESH_INACT, 0x02,
    TIME_INACT, 0x02,
    ACT_INACT_CTL, 0xff,
    THRESH_FF, 0x09,
    TIME_FF, 0x46,
    TAP_THRES, 0x1f,
    TAP_AXES, 0x07,
    LATENT, 0x85,
    DUR, 0x40,
    WINDOW, 0xc0,
    BW_RATE, 0x0a,
    INT_ENABLE, 0x00,
    INT_MAP, 0x20,
    POWER_CONTROL, 0x08};

int main()
{
    printf("Hello from Nios II!\n"); // basic print statement to ensure UART is working
    // ---- Initialize Gyro ----

    alt_u8 gyro_data_out; // variable to store output data

    for (int i = 0; i < CONFIG_LENGHT; i += 2) // load config with address then value
    {
        alt_avalon_spi_command(SPI_0_BASE, 0, 2, gyro_config + i, 0, &gyro_data_out, 0);
    }

    int counter = 0; // initlise counter for printing delay
    alt_16 xData;    // halfwords for the orientation data
    alt_16 yData;
    alt_16 zData;

    // read locations
    alt_u8 readX = READ_X_AXIS;
    alt_u8 readY = READ_Y_AXIS;
    alt_u8 readZ = READ_Z_AXIS;
    while (1)
    {
        if (counter >= MAX_COUNT)
        {
            // TODO get xData
            // TODO get yData
            // TODO get zData

            printf("X axis: %4d\t Y axis: %4d\t Z axis %4d\n", xData, yData, zData);
            counter = 0; // reset counter
        }
        else
        {
            counter++;
        }
    }

    return 0;
}
