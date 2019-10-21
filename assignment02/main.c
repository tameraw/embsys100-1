/*
 * The goals for the assignment this week:
 *     1. To explore the IAR IDE and the different debug views.
 *     2. Get a better understanding of machine instructions, addresses, variables and pointers.
 * Setup:
 *     1. Create a new project in IAR following the steps from the slide deck
 *     2. Create a counter local variable and increment the counter several times.
 *     3. Run the program in the simulator environment and answer the following questions:
 * Observe and answer:
 *     1. Inject 0x1FFFFFFF for the 'counter' value in the variable window, then step thru the program only once to increment 'counter'.
 *         a) What is the value of the 'counter' from the 'Locals' window?
 *              0x20000000
 *         b) What is the value of the 'counter' in the 'Register' window?
 *              0x20000000
 *         c) Which flags are set in the APSR register? Explain why?
 *              None of the flags were set.
 *                The instruction executed was 0x1c49 ADDS R1, R1, #1
 *                APSR.N  0, set to bit[31] of the instruction is 0x1c49
 *                APSR.Z  0, result of instruction was 0x20000000 which is nonzero
 *                APSR.C  0, UInt(0x1FFFFFFF) + UInt(0x00000001) is in [0, 2^15 - 1]. so no carry_out/carry-condition
 *                APSR.V  0, SInt(0x1FFFFFFF) + SInt(0x00000001) is in [-2^7, 2^7 - 1]. so no overflow
 *                APSR.Q  is not updated by an ADDS instruction
 *                APSR.GE is not updated by an ADDS instruction
 *              Hence, APSR value was 0x00000000
 *     2. If your write all Fs (0XFFFFFFFF) in the Register value for 'counter' then step thru the program once to increment 'counter'
 *         a) What happens to the value of 'counter' in the 'Locals' window?
 *              0X00000000
 *         b) What flags, if any, are set in the APSR?
 *              The APSR.Z and APSR.C flags are set
 *                The instruction executed was 0x1c49 ADDS R1, R1, #1
 *                APSR.N  0, set to bit[31] of the instruction is 0x1c49
 *                APSR.Z  1, result of instruction was 0x00000000 which is clearly zero
 *                APSR.C  1, UInt(0xFFFFFFFF) + UInt(0x00000001) is not in [0, 2^15 - 1]. so carry_out/carry-condition
 *                APSR.V  0, SInt(0xFFFFFFFF) + SInt(0x00000001) is in [-2^7, 2^7 - 1]. so no overflow
 *                APSR.Q  is not updated by an ADDS instruction
 *                APSR.GE is not updated by an ADDS instruction
 *              Hence, APSR value was 0x60000000

 *     3. Change the 'counter' variable type in your code to 'unsigned'. Inject the values '0x1FFFFFFF' then step thru the program to increment the 'counter' once:
 *         a) What is the value of 'counter' in the 'Locals' window after incrementing for each value?
 *              0x20000000
 *         b) What flags, if any, are set in the APSR? Explain why?
 *              The APSR.Z and APSR.C flags are set
 *                The instruction executed was 0x1c49 ADDS R1, R1, #1
 *                APSR.N  0, set to bit[31] of the instruction is 0x1c49
 *                APSR.Z  0, result of instruction was 0x20000000 which is nonzero
 *                APSR.C  0, UInt(0x1FFFFFFF) + UInt(0x00000001) is in [0, 2^15 - 1]. so no carry_out/carry-condition
 *                APSR.V  0, SInt(0x1FFFFFFF) + SInt(0x00000001) is in [-2^7, 2^7 - 1]. so no overflow
 *                APSR.Q  is not updated by an ADDS instruction
 *                APSR.GE is not updated by an ADDS instruction
 *              Hence, APSR value was 0x60000000
 *     4. Change the 'counter' variable type in your code to 'unsigned'. Inject the values '0xFFFFFFFF' then step thru the program to increment the 'counter' once:
 *         a) What is the value of 'counter' in the 'Locals' window after incrementing for each value?
 *              0x00000000
 *         b) What flags, if any, are set in the APSR? Explain why?
 *              The APSR.Z and APSR.C flags are set
 *                The instruction executed was 0x1c49 ADDS R1, R1, #1
 *                APSR.N  0, set to bit[31] of the instruction is 0x1c49
 *                APSR.Z  1, result of instruction was 0x20000000 which is nonzero
 *                APSR.C  1, UInt(0xFFFFFFFF) + UInt(0x00000001) is not in [0, 2^15 - 1]. so carry_out/carry-condition
 *                APSR.V  0, SInt(0xFFFFFFFF) + SInt(0x00000001) is in [-2^7, 2^7 - 1]. so no overflow
 *                APSR.Q  is not updated by an ADDS instruction
 *                APSR.GE is not updated by an ADDS instruction
 *              Hence, APSR value was 0x60000000.
 *         - Suppose '0x7FFFFFFF' was injected instead, then APSR.V is suddenly more interesting
 *     5. Move the 'counter' variable outside of main (at the top of the file):
 *         a) What is the scope of the variable 'counter'?
 *              When counter is defined outside of the main function it is an external variable and globally accessible.
 *         b) Is it still visible in the 'Locals' view?
 *              No.
 *         c) In which window view can we track 'counter' now?
 *              Statics.
 *         d) What is the address of the 'counter' variable in memory?
 *              0x20000000              
 *     6. Change the source code to the following, then run the program still in the simulator:
 *         a) What is the value of 'counter' at the end of the program (halting at the return 0 statement)
 *              4
 *         b) Explain why the counter value has changed?
 *              From 5.d, counter is stored at 0x2 and the point p_int is initialized to the value 0x20000000. So,
 *              p_int points to counter. From the precedence and associativity of operators (*p_int)++ or
 *              ++(*p_int) would increment the value stored at 0x20000000. So, counter has an address of 0x2000000 and
 *              was incremented 4 times prior to halting at the return 0 statement.
 *     7. Change the setting of IAR to run the same program on the evaluation board:
 *         a) What is the address where 'counter' is stored?
 *              0x20000000
 *         b) Is the 'counter' variable stored in RAM or ROM?
 *              0x00000000-0x1FFFFFFF is region for Code which is typically ROM or FLASH.
 *              0x20000000-0x3FFFFFFF is the region for SRAM under the system address map.
 *              Counter is stored at 0x20000000, then counter is stored in the SRAM region which
 *              is typically on-chip RAM. 
 *         c) What is the value of 'counter' at the end of the program (halting at the return 0 statement).
 *              0x00000004
 * What to turn in and how:
 *  - Check in all your homework in your repo under the folder 'assignment02'.
 *  - Your folder should contain the following:
 *      o An MD file with the answers to the questions above.
 *      o Source code of your final counter project.
 * - Submit a link to your GitHub repo assignment:
 *      o Ex: 'https://github.com/<account_id>/embsys100/assignment02'
 */

/*
 * int counter = 1;  // define and initialize counter
 * int main() {
 *     extern int counter; // explicitly declare counter
 *     counter++;
 *     counter++;
 *     counter++;
 *     return 0;
 * }
 */
unsigned int counter = 0x0;
int main() {
    unsigned int *p_int = (unsigned int *)0x20000000;
    ++(*p_int);
    ++(*p_int);
    ++(*p_int);
    counter ++;
    return 0;
}
