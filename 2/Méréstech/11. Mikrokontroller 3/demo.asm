 #include  <io430x16x.h>
 #include  <msp430x16x.h>
       rseg code:CODE,2000h
       extern  LCDUpdate, LCDStr,LCDChrXY, DelayN, LCDPixmove, hexdraw
#define BUTTON      BIT0,&P2IN
#define LEFT        BIT7,&P1IN
#define RIGHT       BIT4,&P1IN
#define UP          BIT6,&P1IN
#define DOWN        BIT5,&P1IN
#define STAT        BIT1,&P2OUT
#define STAT2       BIT1,&P2DIR
#define LeftValue   &ADC12MEM0
#define RightValue  &ADC12MEM1

      public asmmain



////////////////////////////////////////////////
asmmain:
; Ide írhatod az asm-programot!

;feladat1:
  ;   call #SetupADC12
  ;   mov.w LeftValue, R12
  ;   call #hexdraw
  ;   jmp feladat1

;feladat2:

  ;    call #SetupADC12
  ;    mov.w RightValue,R6     
  ;    call #hexdraw
  ;    mov #1, R14
  ;    mov R6, R12
  ;   call #multiply
      
  ;   mov R12, R14
  ;   add #0x30, R14
  ;   mov #0, R13
  ;   mov #13, R12
  ;   call #LCDChrXY
      
  ;   mov R6, R12
  ;   mov #8, R14
  ;   mov #0, R13
  ;   call #divide
      
  ;   mov R12, R6
  ;   mov #256, R14
  ;   mov R6, R12
  ;   call #multiply
      
  ;   mov R12, R14
  ;   add #0x30, R14
  ;   mov #0, R13
  ;   mov #12, R12
  ;   call #LCDChrXY
      
  ;   mov R6, R12
  ;   mov #10, R14
  ;   mov #0, R13
  ;   call #divide
      
  ;   mov R6, R12
  ;   mov R12, R14
  ;   add 0x30, R14
  ;   mov #0, R13
  ;   mov #11, R12
  ;   call #LCDChrXY
      
  ;   mov R6, R12
  ;   mov #10, R14
  ;   mov #0, R13
  ;   call #divide
      
  ;   mov R12, R6
  ;   mov R12, R14
  ;   add #0x30, R14
  ;   mov #0, R13
  ;   mov #10, R12
  ;   call #LCDChrXY
      
  ;   call #LCDUpdate
  ;   mov R5, R12
  ;   call #hexdraw

  ;   jmp feladat2
   
  ;   mov.b #2, R4
  ;   mov.b #7, R5
  ;   mov.b #0x4F, R6
      
;feladat3:
  ;   mov.b R6, R14
  ;   mow.w RightValue, R13
  ;   mov.w LeftValue, R12
  ;   call #LCDChrXY
  ;   call #LCDUpdate
  ;   mov.b #0x20, R14
  ;   mov.b R4, R13
  ;   mov.b R5, R12
  ;   call #LCDChrXY
  ;   jmp feladat3

ret
      
     ; Innentõl, pedig ne módosíts semmit!
                                            ;
SetupADC12  mov     #SHT0_8+MSC+ADC12ON,&ADC12CTL0
                                            ; Turn on ADC12, use int. osc.
                                            ; extend sampling time so won't
                                            ; get overflow
                                            ; Set MSC so conversions triggered
                                            ; automatically
            mov     #SHP+CONSEQ_3,&ADC12CTL1
                                            ; Use sampling timer, set mode
            mov     #BIT3,&ADC12IE          ; Enable ADC12IFG.3 for ADC12MEM3
            mov.b   #INCH_0,ADC12MCTL0      ; A0 goes to MEM0
            mov.b   #INCH_1,ADC12MCTL1      ; A1 goes to MEM1
            mov.b   #INCH_2,ADC12MCTL2      ; A2 goes to MEM2
            mov.b   #EOS+INCH_3,ADC12MCTL3  ; A3 goes to MEM3, end of sequence
                                            ;
            clr     R5                      ; Clear pointer
                                            ;
            bis     #ENC,&ADC12CTL0         ; Enable conversions
            bis     #ADC12SC,&ADC12CTL0     ; Start conversions
//            bis     #CPUOFF+GIE,SR          ; Hold in LPM0, Enable interrupts
//ki kell várni a konverzió végét
testIFG     bit     #BIT0,&ADC12IFG         ; konverzió ellenõrzése
            jz      testIFG                 ; nemleges válasz esetén újra tesztelés

            ret                     ; Need only for debug
                                            ;
 
            
divide: clr.w R15
        push.w R9
        push.w R10
        push.w R11
        clr.w R10
        clr.w R11
        mov.w #0x20,R9
divloop
        rla.w R12
        rlc.w R13
        rlc.w R10
        rlc.w R11
        sub.w R14,R10
        subc.w R15,R11
        jnc div001
        bis.w #0x1, R12
        
        add.w #0xFFFF,R9
        jne divloop
        jmp div002
div001
        add.w R14,R10
        addc.w R15,R11
        add.w #0xFFFF,R9
        jne divloop
div002
        mov.w R10,R14
        mov.w R11,R15
        pop.w R11
        pop.w R10
        pop.w R9
        ret
        
multiply:
        mov.w R12, &MPY
        mov.w R14, &OP2
        mov.w &RESLO, R12
        mov.w &RESHI, R13
        ret

            end