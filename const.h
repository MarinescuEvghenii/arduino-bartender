/* Assign an ID to each ingredient */
#define RUM           1
#define COKE          2
#define GIN           3
#define TONIC         4
#define VODCA         5
#define ORANGE_JUICE  6
#define TEQUILA       7
#define WHISKEY       8
#define MARGARITA_MIX 9

/* Define pumps */
#define PUMP_COUNT 6
#define PUMP_1_PIN 22
#define PUMP_2_PIN 23
#define PUMP_3_PIN 24
#define PUMP_4_PIN 25
#define PUMP_5_PIN 26
#define PUMP_6_PIN 27

/* Assign ingredient for yeach pump */
#define PUMP_1_ING RUM
#define PUMP_2_ING COKE
#define PUMP_3_ING GIN
#define PUMP_4_ING TONIC
#define PUMP_5_ING VODCA
#define PUMP_6_ING ORANGE_JUICE


/* Define pumps flow rate */
#define FLOW_RATE 60.0/500.0

/* Encoder config */
#define ENCODER_CLK_PIN 48
#define ENCODER_DT_PIN  50
#define ENCODER_SW_PIN  52

/* Display config */
#define DISPLAY_COLS 16
#define DISPLAY_ROWS 2
#define DISPLAY_ADDR 0x27

/* Define app statuses */
#define STATUS_READY 1
#define STATUS_BUSY  0

/* Status led config */
#define STATUS_LED_PIN 13
