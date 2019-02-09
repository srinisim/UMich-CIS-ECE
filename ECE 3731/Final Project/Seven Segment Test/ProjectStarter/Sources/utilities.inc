                   ORG   $3A00
; Utility functions for terminal I/O and LED enable

;-------------------------TermInit------------------------
; Initialize Serial port SCI1
; Input: baudRate is tha baud rate in bits/sec
; Output: none

TermInit 

  ; 24 MHz bus frequency (PLL is used, SYNR = 2, REFDV = 0 -> factor 6)
  ;   Baud rate generator: SCI1BDL/H = (24e6/16)/baudrate = 1.5e6/baudrate
   
   movb  #0,SCI1BDH  ;   // br=MCLK/(16*baudRate) 
   movb  #156,SCI1BDL  ;
   movb  #0,SCI1CR1 ;
   movb  #$0C,SCI1CR2  ; 
   rts
   
;-------------------------getchar------------------------
; Wait for new serial port input, busy-waiting synchronization
; Input: none
; Output: ASCII code for key typed

getchar
   brclr SCI1SR1,$20,*
   ldab  SCI1DRL  ; return char in B
   rts
        
;-------------------------putchar------------------------
; Wait for buffer to be empty, output 8-bit to serial port
; busy-waiting synchronization
; Input: 8-bit data to be transferred --> passed in B reg.
; Output: none

putchar
   brclr SCI1SR1,$80,*  ;
   stab  SCI1DRL ; write char in B to output
   rts

;-------------------------printf------------------------
; Output String (NULL termination), busy-waiting synchronization
; Input: pointer to a NULL-terminated string to be transferred
; ---> D reg. is ptr.
; Output: none
; NOTE: not full implementation for printf
 
printf
   pshx
   tfr  D,X
PUTLP
   ldab 0,X ; load B from ptr.
   tstb
   beq  QTPRTF
   jsr putchar  ; print char in B
   inx
   bra  PUTLP
QTPRTF
   pulx
   rts
;-------------------------out2hex------------------------
; -print out the two hex digits in B register 
; -value passsed in B --output to terminal
out2hex
     pshb
     andb  #$F0  ; get leading digit
     lsrb        ; shift to low position
     lsrb
     lsrb
     lsrb
     addb  #$30  ; make ascii
     cmpb  #$39  ; adjust for A-F digits
     bls   ahead ;  ....
     addb  #7
ahead
     jsr  putchar  ; output the char
     pulb          ; get original operand
     pshb          ; adjust stack
     andb  #$0F   ; get low digit
     addb  #$30   ; make ascii
     cmpb  #$39
     bls   ahead2  ; adjust for A-F digits
     addb  #7      ; .....
ahead2
     jsr  putchar  ; output the char
     pulb          ; restore stack
     rts

led_enable:  ; enable individual LEDs and disable seven-segment            
      ldaa  #$FF
      staa  DDRB  ; make port B an output port
      staa  DDRJ  ; make port J an output port
      staa  DDRP  ; make port P an output port
      bset  PTP,$0F     ;  disable 7-seg digits PTP[0:3] = 1111  
      bclr  PTJ,$02     ;  enable leds PJ1 = 0
      clr   PORTB
      rts

seg7_enable:  ; enable 7-Segment Displays and disable LED's
            movb  #$FF,DDRB   ;	 DataDirB -->all outputs
            movb  #$FF,DDRP   ;	 DataDirP -->all outputs
            bclr  PTP,$0F     ;  enable 7-seg digits PTP[0:3] = 0000
            movb  #$FF,DDRJ   ;	 DataDirJ -->all outputs
            bset  PTJ,$02    ; disable LED's
            clr   PORTB       ;  Turn-off all 7-seg digits
            rts

PLL_init:
          movb    #$02,SYNR         ;PLLOSC = 48 MHz
          movb    #$00,REFDV
          clr     CLKSEL
          movb    #$F1,PLLCTL
pll1:     brclr   CRGFLG,#$08,pll1  ;wait for PLL to lock
          movb    #$80,CLKSEL       ;select PLLCLK
          rts
