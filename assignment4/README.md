# EMBSYS100 - AU19, ASSIGNMENT 04
## Goal
**1.** Practice the use of bit-banding region.  
**2.** Examine the assembly code generated for a function with multiple parameters.  
**3.** Go thru a design problem exercising key concepts we viewed so far (pointers, arrays, functions, design, API, testing…etc.)  
**4.** Bonus: Apply usage of pointers and the understanding of Endianness.  

## Problems
### Using bit-band region for peripherals:
**a.** Convert the Blinking Led demo to use the corresponding bit-band address instead of the register address used in the peripheral region.  
**b.** What instructions does the compiler produce in assembly for the “writing” to the GPIO bit when using bit-band address?  
The compiler only produces a store when using the bit-band address---in some cases it may need to move the value being stored.
```
   0x800'0052: 0x2301         MOVS      R3, #1
   0x800'0054: 0x6013         STR       R3, [R2]
...skipping...
   0x800'0068: 0x6014         STR       R4, [R2]
```
**c.** What were the instructions produced when writing to the GPIOx_ODR bit[5] directly?  
Before the instructions were ready-modify-write.
```
   0x800'0056: 0x681c         LDR       R4, [R3]
   0x800'0058: 0xf044 0x0420  ORR.W     R4, R4, #32             ; 0x20
   0x800'005c: 0x601c         STR       R4, [R3]
   0x800'005e: 0xf024 0x0420  BIC.W     R4, R4, #32             ; 0x20
   0x800'0062: 0x601c         STR       R4, [R3]
```
### Create a function
Create a function with multiple arguments (5 arguments for example) and call that function from within another function. Trace thru the assembler and note:  
**a.** How does the calling function pass the values to the called function?  
The calling functions will pass values by moving them into the registers until they are full. Once
the registers are full the values will be l on the stack.  
**b.** What extra code did the compiler generate before calling the function with the multiple arguments?  
Before calling a function with 4 arguments the values are moved to registers R0-R3,
```
         0x64: 0x464b         MOV       R3, R9  // Moves source register R9 to destination R3
         0x66: 0x4642         MOV       R2, R8  // Moves source register R2 to destination R8
         0x68: 0x0039         MOVS      R1, R7  // Moves source register R1 to destination R7
         0x6a: 0x0030         MOVS      R0, R6  // Moves source register R0 to destination R6
         0x6c: 0xf000 0xf802  BL        expand4                 ; 0x74
```
**c.** What extra code did the compiler generate inside the called function with the multiple list of arguments?  
Since all of the values cannot be stored in R0-R13, values are st
```
         0x84: 0x9007         STR       R0, [SP, #0x1c] // Store the contents of R0 from offset #0x1c of SP
...skipping...
         0xb2: 0x9b04         LDR       R3, [SP, #0x10] // Load into register R3 a value from offset #0x10 of SP
...skipping...
         0xba: 0xf000 0xf803  BL        sum8                    ; 0xc4
```
**d.** Any other observations?  
Instructions will reuse registers when possible to reduce added latency from loading and storing on stack.

### Create a data structure
Following the queue data structure approach, design, implement and test a stack data structure:  
**a.** The following is the list of requirements:  
  1. The stack should have a predefined size  
  2. The stack supports “int” data types.  
  3. Provide a function to initialize the stack internals.  
  4. Provide a function to push an element onto the stack  
  5. Provide a function to pop an element off the stack.  
  6. Provide a function that returns 1 if stack is empty.  
  7. Provide a function that returns 1 if stack is full.  

**b.** Provide a list of the test cases and their implementation inside of main.c  
**c.** Separate the stack code from the rest of the test code (create stack.h & stack.c)  

### Bonus
Using the power of pointers and type casting, create a function that can determine if a computer is big-endian or little-endian. Test your function in the simulator and modify the Project Options (as shown in the figure below) against:  
**a.** Device STM32F401RE  
**b.** Cortex M4 (Little endian option)  
**c.** Cortex M4 (Big Endian option)  

