#ifndef MAIN_H
#define MAIN_H

//Function Declaration
void output_values(uint32_t time, bool testRunning);
long map(long x, long in_min, long in_max, long out_min, long out_max);
void command_handler(int ch);
void on_uart1_rx();
void core1_main();
bool get_command(struct repeating_timer *t);
void state_machine();

//Definitions
#define HARD_UART_TX_PIN 4
#define HARD_UART_RX_PIN 5

#define STEP_PULSE_PIN 7
#define STEP_DIR_PIN 8
#define STEP_EN_PIN 9
#define STEP_PULSE_PWN_WIDTH 10 //The width of the pwm pulse, this will need to be updated if clock frequency is changed
#define STEP_PULSE_PWM_CLKDIV 32 //The clock divider for the PWM, Higher value means longer overall cycle time.
#define STEP_PWM_SLICE 3 //GPIO7 is PWM Slice 3
#define STEP_PWM_CHANNEL 1 ////GPIO7 is PWM Channel B

#define ENCODER_PIN_AB 11
#define ENCODER_SM 0
#define ENCODER_PIO pio0

#define PRELOAD_DELAY 10000
#define LOAD_DELAY 2000

//Global Variable 
extern char g_force_string[8];
extern float g_force;
extern int g_zero_position_counts;
extern int g_step_pwm_cycle_time; //This will be varied for motor speed control
extern double g_preload;
extern double g_load;
extern uint32_t g_start_time_ms;
extern uint32_t g_preload_start_time;
extern uint32_t g_load_start_time;

enum states {STATE_IDLE, 
            STATE_STARTING, 
            STATE_PRELOADING, 
            STATE_PRELOAD_DELAY, 
            STATE_LOADING, 
            STATE_LOAD_DELAY, 
            STATE_FINISHING, 
            STATE_QUITTING};
extern enum states state;

extern struct repeating_timer get_commands_timer;

#endif /* MAIN_H */





