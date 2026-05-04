/*
 * FWC IITH – ARM Processor (QuickLogic EOS-S3 / VAMAN board M4 core)
 * GATE Question: F(X,Y,Z,W) = Σm(0,1,3,11,14) — MUX-based combinational logic
 * Platform: VAMAN board (ARM Cortex-M4 core, pygmy-sdk + FreeRTOS)
 * Toolchain: arm-none-eabi-gcc + TinyFPGA-Programmer (--mode m4)
 * Author: Tirumala Sai Nithin | Employee ID: FWC22187
 * IIT Hyderabad – Future Wireless Communications
 *
 * Build: make -j4  (inside GCC_Project/)
 * Flash: sudo python3 tinyfpga-programmer-gui.py --port /dev/ttyACM0
 *        --m4app output/bin/blink.bin --mode m4
 *
 * Truth table minterms: F(X,Y,Z,W) = XYZW' + XY'ZW + X'Y'Z' + X'Y'W
 *   Canonical: Σm(0, 1, 3, 11, 14)
 */

#include "Fw_global_config.h"
#include <stdio.h>
#include "FreeRTOS.h"
#include "task.h"
#include "semphr.h"
#include "timers.h"
#include "RtosTask.h"
#include "eoss3_hal_gpio.h"
#include "dbg_uart.h"

extern const struct cli_cmd_entry my_main_menu[];
const char *SOFTWARE_VERSION_STR;
extern void qf_hardwareSetup();
static void nvic_init(void);

#define GPIO_OUTPUT_MODE (1)
void PyHal_GPIO_SetDir(uint8_t gpionum, uint8_t iomode);
int  PyHal_GPIO_Set(uint8_t gpionum, uint8_t gpioval);

int main(void) {
    SOFTWARE_VERSION_STR = "fwc-iith/arm-truth-table-demo";
    qf_hardwareSetup();
    nvic_init();

    dbg_str("\n\n##########################\n");
    dbg_str("FWC IITH – ARM Truth Table Demo\n");
    dbg_str("F(X,Y,Z,W) = Sm(0,1,3,11,14)\n");
    dbg_str("##########################\n\n");

    CLI_start_task(my_main_menu);
    HAL_Delay_Init();

    /* LED GPIO directions */
    PyHal_GPIO_SetDir(18, GPIO_OUTPUT_MODE);  /* Blue  LED */
    PyHal_GPIO_SetDir(21, GPIO_OUTPUT_MODE);  /* Green LED */
    PyHal_GPIO_SetDir(22, GPIO_OUTPUT_MODE);  /* Red   LED */

    /* Minterms: 0, 1, 3, 11, 14 */
    int truth_table[]  = {0, 1, 3, 11, 14};
    int num_entries    = sizeof(truth_table) / sizeof(truth_table[0]);

    while (1) {
        for (int i = 0; i < num_entries; i++) {
            int X = (truth_table[i] >> 3) & 0x1;
            int Y = (truth_table[i] >> 2) & 0x1;
            int Z = (truth_table[i] >> 1) & 0x1;
            int W =  truth_table[i]       & 0x1;

            PyHal_GPIO_Set(18, X);
            PyHal_GPIO_Set(21, Y);
            PyHal_GPIO_Set(22, Z || W);

            HAL_DelayUSec(2000000);  /* 2 s per entry */
        }
    }

    vTaskStartScheduler();
    while (1);
}

static void nvic_init(void) { /* Set interrupt priorities */ }
void SystemInit(void)        { /* System initialisation    */ }

void PyHal_GPIO_SetDir(uint8_t gpionum, uint8_t iomode) { /* Set direction */ }
int  PyHal_GPIO_Set(uint8_t gpionum, uint8_t gpioval)   { return 0; }
