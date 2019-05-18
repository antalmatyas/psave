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

; Ez a program a jobb oldali potméter értékét írja ki bal felsõ kijelzõre 
; Hexadeciumális formában
      call #SetupADC12
      
      
      
      mov.w LeftValue,R14
      
      mov.w R14,R6
      And.w #0xF000,R6
      mov.w R14,R7
      And.w #0x0F00,R7
      mov.w R14,R8
      And.w #0x00F0,R8
      mov.w R14,R9
      And.w #0x000F,R9 
            ;;;;
      mov #0, R13
      mov R6, R12
      mov #0x1000,R14
      call #divide 
      mov #10, R4
      mov R12,R15
      sub R4, R12
      jn n1
      Add #7, R15
      n1:      
      mov R15,R6      
      add.w #'0',R6
      mov.w R6,R14
      mov.w #0x0001,R13
      mov.w #0x0002,R12
      call #LCDChrXY
            ;;;;
      mov #0, R13
      mov R7, R12
      mov #0x0100,R14
      call #divide
      mov #10, R4
      mov R12,R15
      sub R4, R12
      jn n2
      Add #7, R15
      n2:            
      mov R15,R7       
      add.w #'0',R7
      mov.w R7,R14
      mov.w #0x0001,R13
      mov.w #0x0003,R12
      call #LCDChrXY
            ;;;;
      mov #0, R13
      mov R8, R12
      mov #0x0010,R14
      call #divide 
      mov R12, R15
      sub R4, R12
      jn n3
      Add #7, R15
      n3:      
      mov R15,R8
      add.w #'0',R8
      mov.w R8,R14
      mov.w #0x0001,R13
      mov.w #0x0004,R12
      call #LCDChrXY
            ;;;;
      mov #10, R4
      mov R9, R12
      mov R9, R15
      sub R4, R12
      jn n4
      Add #7, R15
      n4:
      mov R15,R9
      add.w #'0',R9
      mov.w R9,R14
      mov.w #0x0001,R13
      mov.w #0x0005,R12
      call #LCDChrXY
      
      mov.w RightValue,R14
      
      mov.w R14,R6
      And.w #0xF000,R6
      mov.w R14,R7
      And.w #0x0F00,R7
      mov.w R14,R8
      And.w #0x00F0,R8
      mov.w R14,R9
      And.w #0x000F,R9 
            ;;;;
      mov #0, R13
      mov R6, R12
      mov #0x1000,R14
      call #divide 
      mov #10, R4
      mov R12,R15
      sub R4, R12
      jn n5
      Add #7, R15
      n5:      
      mov R15,R6      
      add.w #'0',R6
      mov.w R6,R14
      mov.w #0x0001,R13
      mov.w #0x0008,R12
      call #LCDChrXY
            ;;;;
      mov #0, R13
      mov R7, R12
      mov #0x0100,R14
      call #divide
      mov #10, R4
      mov R12,R15
      sub R4, R12
      jn n6
      Add #7, R15
      n6:            
      mov R15,R7       
      add.w #'0',R7
      mov.w R7,R14
      mov.w #0x0001,R13
      mov.w #0x0009,R12
      call #LCDChrXY
            ;;;;
      mov #0, R13
      mov R8, R12
      mov #0x0010,R14
      call #divide 
      mov R12, R15
      sub R4, R12
      jn n7
      Add #7, R15
      n7:      
      mov R15,R8
      add.w #'0',R8
      mov.w R8,R14
      mov.w #0x0001,R13
      mov.w #0x000A,R12
      call #LCDChrXY
            ;;;;
      mov #10, R4
      mov R9, R12
      mov R9, R15
      sub R4, R12
      jn n8
      Add #7, R15
      n8:
      mov R15,R9
      add.w #'0',R9
      mov.w R9,R14
      mov.w #0x0001,R13
      mov.w #0x000B,R12
      call #LCDChrXY
      
     ; mov.w RightValue,R14
      ;mov.w #0x0001,R13
      ;mov.w #0x0008,R12
      ;call #LCDChrXY
      call #LCDUpdate
      jmp asmmain
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