//Function Declaration
void start_test(double preload, double load);
void outputValues(uint32_t time, bool testRunning);
long map(long x, long in_min, long in_max, long out_min, long out_max);
void commandHandler(int ch);
void on_uart1_rx();
void core1_main();

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

//Global Variable 
extern char force_string[8];
extern float force;
extern int zero_position_counts;
extern int step_pwm_cycle_time; //This will be varied for motor speed control






