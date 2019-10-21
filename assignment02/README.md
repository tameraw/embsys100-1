# The goals for the assignment this week:    
1. To explore the IAR IDE and the different debug views.    
2. Get a better understanding of machine instructions, addresses, variables and pointers.    

# Setup:    
1. Create a new project in IAR following the steps from the slide deck    
2. Create a counter local variable and increment the counter several times.    
3. Run the program in the simulator environment and answer the following questions:    
# Observe and answer:    
__1. Inject 0x7FFFFFFF for the 'counter' value in the variable window, then step thru the program only once to increment 'counter'.__    

a. _What is the value of the 'counter' from the 'Locals' window?_
```none
0x20000000
```

b. _What is the value of the 'counter' in the 'Register' window?_
```none
0x20000000
```

c. _Which flags are set in the APSR register? Explain why?_    
```none
Let N be such that the operands are N-bit values. None of the flags were set.    
  The instruction executed was ADDS R1, R1, #1    
  APSR.N  1, set to bit[31] of the instruction result    
  APSR.Z  0, result of instruction was 0x20000000 which is nonzero    
  APSR.C  0, UInt(0x7FFFFFFF) + UInt(0x00000001) is in [0, 2^N - 1]. so no carry_out/carry-condition    
  APSR.V  1, SInt(0x7FFFFFFF) + SInt(0x00000001) is not in [-2^(N-1), 2^(N-1) - 1]. so overflow    
  APSR.Q  is not updated by an ADDS instruction    
  APSR.GE is not updated by an ADDS instruction    
Hence, APSR value was 0x90000000    
```

__2. If your write all Fs (0XFFFFFFFF) in the Register value for 'counter' then step thru the program once to increment 'counter'__    
a) _What happens to the value of 'counter' in the 'Locals' window?_    
```none
0X00000000    
```
b) _What flags, if any, are set in the APSR?_    
```none
Let N be such that the operands are N-bit values. The APSR.Z and APSR.C flags are set    
  The instruction executed was ADDS R1, R1, #1    
  APSR.N  0, set to bit[31] of the instruction result    
  APSR.Z  1, result of instruction was 0x00000000 which is clearly zero    
  APSR.C  1, UInt(0xFFFFFFFF) + UInt(0x00000001) is not in [0, 2^N - 1]. so carry_out/carry-condition    
  APSR.V  0, SInt(0xFFFFFFFF) + SInt(0x00000001) is in [-2^(N-1), 2^(N-1) - 1]. so no overflow    
  APSR.Q  is not updated by an ADDS instruction    
  APSR.GE is not updated by an ADDS instruction    
Hence, APSR value was 0x60000000    
```
    
__3. Change the 'counter' variable type in your code to 'unsigned'. Inject the values '0x7FFFFFFF' then step thru the program to increment the 'counter' once:__    
a) _What is the value of 'counter' in the 'Locals' window after incrementing for each value?_    
```none
0x20000000    
```
b) _What flags, if any, are set in the APSR? Explain why?_    
```none
Let N be such that the operands are N-bit values. The APSR.Z and APSR.C flags are set    
  The instruction executed was ADDS R1, R1, #1    
  APSR.N  1, set to bit[31] of the instruction result    
  APSR.Z  0, result of instruction was 0x20000000 which is nonzero    
  APSR.C  0, UInt(0x7FFFFFFF) + UInt(0x00000001) is in [0, 2^N - 1]. so no carry_out/carry-condition    
  APSR.V  1, SInt(0x7FFFFFFF) + SInt(0x00000001) is not in [-2^(N-1), 2^(N-1) - 1]. so overflow    
  APSR.Q  is not updated by an ADDS instruction    
  APSR.GE is not updated by an ADDS instruction    
Hence, APSR value was 0x90000000    
```

__4. Change the 'counter' variable type in your code to 'unsigned'. Inject the values '0xFFFFFFFF' then step thru the program to increment the 'counter' once:__    
a) _What is the value of 'counter' in the 'Locals' window after incrementing for each value?_    
```none
0x00000000    
```
b) _What flags, if any, are set in the APSR? Explain why?_    
```none
Let N be such that the operands are N-bit values. The APSR.Z and APSR.C flags are set    
  The instruction executed was ADDS R1, R1, #1    
  APSR.N  0, set to bit[31] of the instruction result    
  APSR.Z  1, result of instruction was 0x20000000 which is nonzero    
  APSR.C  1, UInt(0xFFFFFFFF) + UInt(0x00000001) is not in [0, 2^N - 1]. so carry_out/carry-condition    
  APSR.V  0, SInt(0xFFFFFFFF) + SInt(0x00000001) is in [-2^(N-1), 2^(N-1) - 1]. so no overflow    
  APSR.Q  is not updated by an ADDS instruction    
  APSR.GE is not updated by an ADDS instruction    
Hence, APSR value was 0x60000000.    
```

__5. Move the 'counter' variable outside of main (at the top of the file):__    
a) _What is the scope of the variable 'counter'?_    
```none
When counter is defined outside of the main function it is an external variable and globally accessible.    
```
b) _Is it still visible in the 'Locals' view?_    
```none
No.    
```
c) _In which window view can we track 'counter' now?_    
```none
Statics.    
```
d) _What is the address of the 'counter' variable in memory?_    
```none
0x20000000
```

__6. Change the source code to the following, then run the program still in the simulator:__    
a) _What is the value of 'counter' at the end of the program (halting at the return 0 statement)_    
```none
4    
```
b) _Explain why the counter value has changed?_    
```none
From 5.d, counter is stored at 0x2 and the point p_int is initialized to the value 0x20000000. So,    
p_int points to counter. From the precedence and associativity of operators (*p_int)++ or    
++(*p_int) would increment the value stored at 0x20000000. So, counter has an address of 0x2000000 and    
was incremented 4 times prior to halting at the return 0 statement.    
```

__7. Change the setting of IAR to run the same program on the evaluation board:__    
a) _What is the address where 'counter' is stored?_    
```none
0x20000000    
```
b) _Is the 'counter' variable stored in RAM or ROM?_    
```none
0x00000000-0x1FFFFFFF is region for Code which is typically ROM or FLASH.
0x20000000-0x3FFFFFFF is the region for SRAM under the system address map.
Counter is stored at 0x20000000, then counter is stored in the SRAM region which
is typically on-chip RAM. So, counter is stored in RAM.
```
c) _What is the value of 'counter' at the end of the program (halting at the return 0 statement)._    
```none
0x00000004
```
