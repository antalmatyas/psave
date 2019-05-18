 #include  <io430x16x.h>
 #include  <msp430x16x.h>
       rseg code:CODE,2000h
 
A0result      EQU     0200h                 ; Channel A0 results
A1result      EQU     0210H                 ; Channel A1 results
A2result      EQU     0220H                 ; Channel A2 results
A3result      EQU     0230H                 ; Channel A3 results
 
       extern  LCDUpdate, LCDStr,LCDChrXY, DelayN, LCDPixmove, hexdraw
       #define R04 R4
       #define R05 R5
       #define R06 R6
       #define R07 R7
       #define BUTTON BIT0,&P2IN
       #define LEFT BIT7,&P1IN
       #define RIGHT BIT4,&P1IN
       #define UP BIT6,&P1IN
       #define DOWN BIT5,&P1IN
       #define STAT BIT1,&P2OUT
       #define STAT2 BIT1,&P2DIR
       public asmmain



////////////////////////////////////////////////
asmmain:
     ; Ide írhatod az asm-programot!
     mov.b 7, R5 ; x coordinate
     mov.b 2, R4 ; y coordinate
     mov.b #0x4F, R6 ; O char
     call #draw
feladat3:
        call #clear
        bit.b #LEFT
        jnc movel
        bit.b #RIGHT
        jnc mover
        bit.b #UP
        jnc moveu
        bit.b #DOWN
        jnc moved
        jmp feladat3
        
movel:
        dec R5
        call #draw
        break1:
        bit.b #LEFT
        jnc break1
        jmp feladat3
        
mover:
        inc R5
        call #draw
        break2:
        bit.b #RIGHT
        jnc break2
        jmp feladat3
        
moveu:
        dec R4
        call #draw
        break3:
        bit.b #UP
        jnc break3
        jmp feladat3
        
moved:
        inc R4
        call #draw
        break4:
        bit.b #DOWN
        jnc break4
        jmp feladat3
      ret
      
      
draw:
      mov.b R5, R12
      mov.b R4, R13
      mov.b R6, R14
      call #LCDChrXY
      call #LCDUpdate
      ret
 
clear:
      mov.b #0x20, R14
      mov.b R4, R13
      mov.b R5, R12
      call #LCDChrXY
      ret
      
      
     ; Innentõl, pedig nem módosíts semmit!
  
  
  
  
  
StopWDT     mov     #WDTPW+WDTHOLD,&WDTCTL  ; Stop watchdog
            bis.b   #BIT0+BIT1+BIT2+BIT3,&P6SEL ; Enable A/D inputs
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
Mainloop    bis     #ENC,&ADC12CTL0         ; Enable conversions
            bis     #ADC12SC,&ADC12CTL0     ; Start conversions
            bis     #CPUOFF+GIE,SR          ; Hold in LPM0, Enable interrupts
            ret                     ; Need only for debug
                                            ;
;------------------------------------------------------------------------------
ADC12ISR    ; Interrupt Service Routine for ADC12
;------------------------------------------------------------------------------
            mov     &ADC12MEM0,A0result(R5) ; Move results to RAM
            mov     &ADC12MEM1,A1result(R5) ; Move results to RAM
            mov     &ADC12MEM2,A2result(R5) ; Move results to RAM
            mov     &ADC12MEM3,A3result(R5) ; Move results to RAM, IFG reset
            incd    R5                      ; Increment results table pointer
            and     #0Eh,R5                 ; Modulo pointer
            reti
            
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