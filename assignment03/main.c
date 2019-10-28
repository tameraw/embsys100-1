#define RCC_BASE 0x40023800
#define RCC_AHB1ENR (*((unsigned int*)(RCC_BASE + 0x30)))

#define GPIOA_BASE 0x40020000
#define GPIOA_MODER (*((unsigned int*)(GPIOA_BASE + 0x00)))
#define GPIOA_ODR (*((unsigned int*)(GPIOA_BASE + 0x14)))
#define GPIOA (1<<5)

#define HIGH 0xF | GPIOA
#define LOW 0xF
#define UNIT 0x1
#define DOT (UNIT & HIGH)
#define DASH ((UNIT * 3) & HIGH)
#define NB_SPACE (UNIT & LOW)
#define CHAR_SPACE ((UNIT * 3) & LOW)
#define WORD_SPACE ((UNIT * 7) & LOW)


const unsigned int J[8] = {DOT, NB_SPACE, DASH, NB_SPACE, DASH, NB_SPACE, DASH, 0x0};
const unsigned int A[4] = {DOT, NB_SPACE, DASH, 0x0};
const unsigned int M[4] = {DASH, NB_SPACE, DASH, 0x0};
const unsigned int E[2] = {DOT, 0x0};
const unsigned int S[6] = {DOT, NB_SPACE, DOT, NB_SPACE, DOT, 0x0};
const unsigned int CHAR_SPACE_ARR[2] = {CHAR_SPACE, 0x0};
const unsigned int WORD_SPACE_ARR[2] = {WORD_SPACE, 0x0};
const unsigned int *NAME[6] = {J, A, M, E, S, 0x0};


int counter = 0;
const int COUNTER_CYCLES = 1000000;


void wait_unit(const unsigned int n) {
    volatile int counter;
    counter = 0;
    while (counter < n * COUNTER_CYCLES) {
      counter++;
    }
}

void enable_peripheral_clock() {
    // RCC Base Address: 0x40023800
    // RCC AHB1 peripheral clock enable register (RCC_AHB1ENR)
    // Address offset: 0x30
    // Write: 0x1
    // 1. Enable clock to Peripheral
    RCC_AHB1ENR |= 0x1;
}

void set_gpio5_output() {
    // GPIOA Base Address: 0x40020000
    // GPIO port mode register (GPIOx_MODER) (x = A..E and H)
    // Address offset: 0x00
    // Write: 0x400
    // 2. Set GPIO5 to Output
    GPIOA_MODER |= 0x400;
}

void set_gpioa_high() {
    // GPIOA Base Address: 0x40020000
    // GPIO port output data register (GPIOx_ODR) (x = A..E and H)
    // Address offset: 0x14
    // Write LED ON: 0x20
    GPIOA_ODR |= GPIOA;  // 0x00000020;
}

void set_gpioa_low() {
    // GPIOA Base Address: 0x40020000
    // GPIO port output data register (GPIOx_ODR) (x = A..E and H)
    // Address offset: 0x14
    // Write LED OFF: ~0x20
    GPIOA_ODR &= ~GPIOA;  // 0xFFFFFFDF;
}

void morse_from_arr(const unsigned int *arr) {
    unsigned int *narr = (unsigned int *)arr;
    while (*narr != 0x0) {
      if (((*narr) & GPIOA) == GPIOA) {
        set_gpioa_high();
      } else {
        set_gpioa_low();
      }
      wait_unit((*narr) & ~GPIOA);
      narr++;
    }
}

void morse_word_from_arr(const unsigned int **word_arr){
    unsigned int const **word_char = ((unsigned int const**) word_arr);
    while((*word_char) != 0x0){
        // morse each character of word
        morse_from_arr(*word_char);
        word_char++;
        // if not end of word char space, otherwise word space
        if ((*word_char) != 0x0) {
            morse_from_arr(CHAR_SPACE_ARR);
        } else {
            // more word space unit for end of word
            morse_from_arr(WORD_SPACE_ARR);
        } 
    }
}

int main() {
    volatile int counter;
    enable_peripheral_clock();
    set_gpio5_output();
    morse_word_from_arr(NAME);
    return 0;
}