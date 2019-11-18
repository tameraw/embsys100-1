#define PERIPHERAL_BASE 0x40000000
#define PERIPHERAL_RCC_OFFSET 0x00023800
#define RCC_BASE (PERIPHERAL_BASE + PERIPHERAL_RCC_OFFSET) 
#define RCC_AHB1ENR_OFFSET 0x30

#define PERIPHERAL_GPIOX_OFFSET 0x00020000
#define GPIOX_BASE (PERIPHERAL_BASE + PERIPHERAL_GPIOX_OFFSET)
#define GPIOX_A_OFFSET 0x0
#define GPIOA_BASE (GPIOX_BASE + GPIOX_A_OFFSET)
#define GPIOA_MODER_OFFSET 0x00
#define GPIOA_ODR_OFFSET 0x14

#define GPIOA (1<<5)

#define PERIPHERAL_ALIAS_BASE 0x42000000
#define DELAY_PERIOD 1000000

volatile int counter=0;

void delay(int for_i_cycles) {
    counter=0;
    while (counter < for_i_cycles) {
      counter++;
    }
}

void main(void)
{


    // 1. Enable clock to Peripheral
    //    RCC Base Address: 0x40023800
    //    RCC AHB1 peripheral clock enable register (RCC_AHB1ENR)
    //    Address offset: 0x30
    //    Set bit[0] to 1
    // Read-modify-write:
    //    #define RCC_AHB1ENR (*((unsigned int*)(RCC_BASE + RCC_AHB1ENR_OFFSET)))
    //    RCC_AHB1ENR |= 0x1;


  (*((unsigned int*)(PERIPHERAL_ALIAS_BASE + ((PERIPHERAL_RCC_OFFSET + RCC_AHB1ENR_OFFSET)*32) + (0*4)))) = 1;
    //*((unsigned int*)((0x42000000) +(0x23830 *32)+0*4));
  
    // 2. Set GPIOx to Output mode where x = A
    //    GPIOA Base Address: 0x40020000
    //    GPIO port mode register (GPIOx_MODER) (x = A..E and H)
    //    Address offset: 0x00
    //    Set bit[11:10] to 0x01  so --> 0x400 // To enable Port5 as output
    // Read-modify-write:
    //    #define GPIOA_MODER (*((unsigned int*)(GPIOA_BASE + GPIOA_MODER_OFFSET)))
    //    GPIOA_MODER |= 0x400;

(*((unsigned int*)(PERIPHERAL_ALIAS_BASE + (PERIPHERAL_GPIOX_OFFSET*32) + (10*4)))) = 1;
    // 3. Set GPIO data register to toggle bit[5]
    //    GPIOA Base Address: 0x40020000
    //    GPIO port output data register (GPIOx_ODR) (x = A..E and H)
    //    Address offset: 0x14
    //    Set bit[5] to 1 --> 0x20; // Turn LED ON
    //    Set bit[5] to 0 --> 0x00; // Turn LED OFF
    // Read-modify-write:
    //    #define GPIOA_ODR (*((unsigned int*)(GPIOA_BASE + GPIOA_ODR_OFFSET)))
    //    GPIOA_ODR |= GPIOA; // Turn LED ON
    //    GPIOA_ODR &= ~GPIOA;  // Turn LED OFF
     
    while(1)
    {
(*((unsigned int*)(PERIPHERAL_ALIAS_BASE + ((PERIPHERAL_GPIOX_OFFSET + GPIOA_ODR_OFFSET)*32) + (5*4)))) = 1;
      delay(DELAY_PERIOD);
(*((unsigned int*)(PERIPHERAL_ALIAS_BASE + ((PERIPHERAL_GPIOX_OFFSET + GPIOA_ODR_OFFSET)*32) + (5*4)))) = 0;
      delay(DELAY_PERIOD);

    }
}
