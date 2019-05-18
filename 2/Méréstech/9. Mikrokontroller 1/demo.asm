 #include  <io430x16x.h>
 #include  <msp430x16x.h>
       rseg code:CODE,2000h
 
       extern  LCDUpdate, LCDStr,LCDChrXY, DelayN, LCDPixmove
#define R04 R4
#define R05 R5
       public asmmain



////////////////////////////////////////////////
asmmain:
     ; Ide írhatod az asm-programot!
     
     ;1.feladat - 8 bites összeadás
     
     ;mov.b #5, R04
     ;mov.b #6, R05
     ;add.b R05, R04
     
     ;túlcsordulással
     
     ;mov.b 255, R04
     ;mov.b 1, R05
     ;add.b R04, R05
     
     ;elõjellel
     
     ;mov.b #+9, R04
     ;mov.b #+19, R05
     ;add.b R04, R05
     
     ;elõjellel, túlcsordulással
     
     ;mov.b #+127,R04
     ;mov.b #+1,R05
     ;add.b R04,R05
     
     ;........
     
     ;2.feladat - 16bites összeadás
     
     ;mov.w #5, R04
     ;mov.w #6, R05
     ;add.w R05, R04
     
     ;túlcsordulással
     
     ;mov.w 65535, R04
     ;mov.w 3, R05
     ;add.w R04, R05
     
     ;elõjellel
     
     ;mov.w #+123, R04
     ;mov.w #+234, R05
     ;add.w R04, R05
     
     ;elõjellel, túlcsordulással
     
     ;mov.w #+32767, R04
     ;mov.w #+3, R05
     ;add.w R04, R05
     
     ;........
     
     ;3.feladat - 32bites összeadás
     
     ;mov.w #0x1234, R04
     ;mov.w #0x5678, R05
     ;mov.w #0x2345, R6
     ;mov.w #0x1357, R7
     
     ;add.w R04, R05
     ;addc.w R6, R7
     
     ;elõjellel
     
     ;mov.w #0xEFFF, R04
     ;mov.w #0x0003, R05
     ;mov.w #0x0001, R6
     ;mov.w #0xFFFE, R7
     ;add.w R05, R7
     ;add.w R04, R6
     
     ;........
     
     ;5.feladat - 8bites kivonás
     
     ;mov.b #8, R04
     ;mov.b #4, R05
     ;sub.b R04, R05
     
     ;elõjellel
     
     ;mov.b #-5, R04
     ;mov.b #+6, R05
     ;sub.b R04, R05
     
     ;........
     
     ;6.feladat - 16bites kivonás
     
     ;mov.w #25, R04
     ;mov.w #15, R05
     ;sub.w R04, R05
     
     ;elõjellel
     
     ;mov.w #-15, R04
     ;mov.w #16, R05
     ;sub.w R04, R05
     
     ;........
     
     ;7.feladat - 32bites kivonás
     
     ;mov.w #0x001, R04
     ;mov.w #0x002, R05
     ;mov.w #0x0001, R6
     ;mov.w #0x0000, R7
     ;sub.w R04, R6
     ;subc.w R05, R7
     
     ;elõjellel
     
     ;mov.w #-330, R04
     ;mov.w #-220, R05
     ;mov.w #-550, R6
     ;mov.w #-55, R7
     ;sub.w R6, R04
     ;sub.w R7, R05
     
     
      ret
     ; Innentõl, pedig nem módosíts semmit!
 
 
 
 
 
;ADC12 Inicializálás

initADC12:
       bis.b   #BIT0,&P6SEL            ; A0-ás AD csatorna engedélyezése
                                            ;
SetupADC12  mov     #REFON+REF2_5V+ADC12ON+SHT0_2,&ADC12CTL0
                                            ; 2,5v-s referencia belövése
            mov     #SHP,&ADC12CTL1         ; mintavételezési timer 
            mov.b   #SREF_1,&ADC12MCTL0     ; Vr+=Vref+
                                            ;http://digitus.itk.ppke.hu/~pocmi/MSP430-DLL%20drivers%201.021/
            mov     #03600h,R15             ; Start-up delay
L$1         dec     R15                   
            jnz     L$1                 
            bis     #ENC,&ADC12CTL0         ; konverzió engedélyezése
            ret





;ADC Startup

StartADC12:
            bis     #ADC12SC,&ADC12CTL0     ; konverzió kezdete
testIFG     bit     #BIT0,&ADC12IFG         ; konverzió ellenõrzése
            jz      testIFG                 ; nemleges vûlasz esetén újra tesztelés
            mov     &ADC12MEM0, R5          ; a konverzió eredménye az R5-ös regiszterbe
	    ret
divide:
        mov.w R14, R15
        mov.w R12, R13
        clr.w R14
        mov.w #0x1,R12
div_LO: rla.w R13
        rlc.w R14
        cmp.w R15, R14
        jnc div_1
        sub.w R15, R14
div_1:  rlc.w R12
        jnc div_LO
        ret
        
multiply:
        mov.w R12, &MPY
        mov.w R14, &OP2
        mov.w &RESLO, R12
        mov.w &RESHI, R13
        ret
            

      end
  