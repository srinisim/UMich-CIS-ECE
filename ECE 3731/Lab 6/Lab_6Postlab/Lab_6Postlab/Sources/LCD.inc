;**************************************************************
;* Dragon12_Plus_Rev4                                     *
;* Assembly language routines for LCD calls            *                                       
;**************************************************************

;* The following fuctions are available for the LCD
   
; lcd_init      -initialize LCD   
; clear_lcd     -clear LCD
; set_lcd_addr  -set LCD address to B
; hex2lcd       -display hex digit in B to LCD
; lcd_prtstrg   -print string pointed to by D to LCD             

; variable/data section
ONE_MS:		equ	4000	; 4000 x 250ns = 1 ms at 24 MHz bus speed
FIVE_MS:	equ	20000
TEN_MS:		equ	40000
FIFTY_US:	equ	200
DB2		    equ     4       ; 00000100
DB3:		  equ	8       ; 00001000
REG_SEL:	equ	DB3	; 0=reg, 1=data
NOT_REG_SEL:	equ	$F7     ; 11110111
ENABLE:		equ     DB2
NOT_ENABLE: 	equ     $FB     ; 11111011
LCD:		  equ    $00000250 ; PTM 
LCD_RS:		equ    $00000250  
LCD_EN:		equ    $00000250  
REGBLK:		equ	$0
bas10:    equ	10

temp:     rmb 1
pmimg:		rmb	1
temp1:		rmb	1
bas:      rmb 2
dnum:	    rmb	4
buff:	    rmb	12
pad:	    rmb	1
TC1old:   rmb 2
LO_time1  rmb 2
HI_time1  rmb 2

; Initialization codes for 4-bit mode
; uses only data in high nibble
init_codes
        fcb	12		; number of high nibbles
	fcb	$30		; 1st reset code, must delay 4.1ms after sending
        fcb	$30		; 2nd reste code, must delay 100us after sending
        ;  following 10 nibbles must  delay 40us each after sending
	fcb $30   ; 3rd reset code,
	fcb	$20		; 4th reste code,
        fcb	$20   ; 4 bit mode, 2 line, 5X7 dot
	fcb	$80   ; 4 bit mode, 2 line, 5X7 dot
        fcb	$00		; cursor increment, disable display shift
	fcb	$60		; cursor increment, disable display shift
        fcb	$00		; display on, cursor off, no blinking
	fcb	$C0		; display on, cursor off, no blinking
	fcb	$00		; clear display memory, set cursor to home pos
	fcb	$10		; clear display memory, set cursor to home pos

LCDimg:		equ	pmimg
LCD_RSimg:	equ	pmimg
LCD_ENimg:	equ	pmimg

;**************************************************************

;       ms_delay
;       input: D = no. of milliseconds to delay
;       clock = 24 MHz
ms_delay:
          pshx
          pshy
          tfr     D,Y
md1:      ldx     #5999   ; N = (24000 - 5)/4
md2:      dex             ; 1 ccycle
          bne     md2     ; 3 ccycle
          dey
          bne     md1     ; Y ms
          puly
          pulx
          rts
          
; write instruction upper nibble
write_instr_nibble
        anda    #$F0
        lsra
        lsra            ; nibble in PK2-PK5
        oraa    #$02    ; E = 1 in PK1; RS = 0 in PK0
        staa    PORTK
        ldy     #10
win     dey
        bne     win
        anda    #$FC    ; E = 0 in PK1; RS = 0 in PK0
        staa    PORTK
        rts

;  Initialize LCD
lcd_init:
	ldaa	#$ff
	staa	DDRK		        ; port K = output
       	ldx	#init_codes 	        ; point to init. codes.
	pshb            	          ; output instruction command.
       	ldab   	1,x+                ; no. of codes
lcdi1:	ldaa   	1,x+                ; get next code
       	jsr    	write_instr_nibble 	; initiate write pulse.
       	pshd
       	ldd     #5
       	jsr     ms_delay		;delay 5 ms
       	puld
       	decb                    ; in reset sequence to simplify coding
       	bne    	lcdi1
       	pulb
       	rts


; write data upper nibble
write_data_nibble:
        anda    #$F0
        lsra
        lsra            ; nibble in PK2-PK5
        oraa    #$03    ; E = 1 in PK1; RS = 1 in PK0
        staa    PORTK
        ldy     #10
wdn     dey
        bne     wdn
        anda    #$FD    ; E = 0 in PK1; RS = 1 in PK0
        staa    PORTK
        rts

; write instruction byte
write_instr_byte:
        psha
        jsr     write_instr_nibble
        pula
        asla
        asla
        asla
        asla
        jsr     write_instr_nibble
        rts

;write data byte
write_data_byte:
        psha
        jsr     write_data_nibble
        pula
        asla
        asla
        asla
        asla
        jsr     write_data_nibble
        rts

;   write instruction byte B to LCD
instr8:
            tba
;            jsr   sel_inst
            jsr   write_instr_byte
            ldd     #10
            jsr     ms_delay
            rts

;   write data byte B to LCD
data8:
            tba
            jsr   write_data_byte
            ldd     #10
            jsr     ms_delay
            rts

lcd_putchar
            pshb
            jsr    data8
            pulb
            rts

;   set address to B
set_lcd_addr:
            orab    #$80
            tba
            jsr     write_instr_byte
            ldd     #10
            jsr     ms_delay
            rts

;   clear LCD
clear_lcd:
            pshd
            clrb
            jsr     set_lcd_addr 
            ldaa    #$01
            jsr     write_instr_byte
            ldd     #10
            jsr     ms_delay
            puld
            rts
                        
;	display hex value in B on LCD 
hex2lcd:
	          bsr	hex2asc		  ;convert to ascii
	          jsr	data8		    ;display it
	          rts

;       Hex to ascii subroutine
;       input: B = hex value
;       output: B = ascii value of lower nibble of input
hex2asc:
     	      andb    #$0f    	;mask upper nibble
            cmpb    #$9     	;if B > 9
            bls     ha1
          	addb    #$37    	; add $37
           	rts             	  ;else
ha1     	  addb    #$30    	; add $30
            rts

;	display asciiz string on LCD
;	D -> asciiz string 
lcd_prtstrg:
            pshx              ;save X
            tfr     D,X       ;X -> asciiz string
next_char   ldaa	  1,X+		  ;get next char
	          beq	    done		  ;if null, quit
	          jsr	    write_data_byte	;else display it
            ldd     #10
            jsr     ms_delay
	          bra	    next_char	;and repeat
done	      pulx              ;restore X
            rts

;   write an integer to the LCD display
;   write_int_lcd(int);
write_int_lcd:
            pshd              ;save D
            bsr     blank_pad ;fill pad with blanks
            puld              ;get D
            std     dnum+2
            clr     dnum
            clr     dnum+1
            ldx     #pad
            jsr     sharps
            ldx     #pad-5
wl1	        ldab	  1,x+
	          jsr	    data8		;display the ascii string
	          cpx	    #pad
	          blo	    wl1
	          rts


;   blank pad
blank_pad:
            ldx     #buff
            ldab    #13
            ldaa    #$20    ;ascii blank
bp1:        staa    1,x+
            decb
            bne     bp1
            rts

;	double division  32 / 16 = 32  16 rem
;	numH:numL / denom = quotH:qoutL  remL
;	Y:D / X = Y:D  rem X
;	use EDIV twice  Y:D / X = Y   rem D
ddiv:
	          pshd		        ;save numL
	          tfr	  y,d	      ;d = numH
	          ldy	  #0	      ;0:numH / denom
	          ediv		        ;y = quotH, d = remH
	          bcc	  dd1	      ;if div by 0
	          puld
	          ldd	  #$FFFF	  ;quot = $FFFFFFFF
	          tfr	  d,y
	          tfr	  d,x	      ;rem = $FFFF
	          rts
dd1	        sty	  2,-sp	    ;save quotH on stack
	          tfr	  d,y	      ;y = remH
	          ldd	  2,sp	    ;d = numL
	          ediv		        ;remH:numL/denom  Y = quotL  D = remL
	          tfr	  d,x	      ;x = remL
	          tfr	  y,d	      ;d = quotL
	          puly		        ;y = quotH
	          leas	2,sp	    ;fix stack
	          rts


 ;   Binary number to ASCII string conversion
;	  x -> ascii buffer
sharp:
	          pshd			      ;save regs
	          pshy
	          pshx			      ;save ptr
	          ldy	  dnum
	          ldd	  dnum+2
	          ldx	  #bas10
	          jsr	  ddiv		  ;dnum/base rem in X
	          sty	  dnum		  ; => dnum
	          std	  dnum+2
	          tfr	  x,d		    ;b = rem
	          cmpb	#9		    ;if rem > 9
	          bls	  shp1
	          addb	#7		    ; add 7
shp1	      addb	#$30		  ;conv to ascii
	          pulx			      ;restore ptr
	          stab	1,-x		  ;store digit
	          puly			      ;restore regs
	          puld
	          rts

;	input: x -> pad (ascii buffer)
;	output: x -> first char in ascii string
sharps:
	          bsr	  sharp		  ;do next digit
	          ldd	  dnum		  ;repeat until
          	bne	  sharps		; quot = 0
	          ldd	  dnum+2
	          bne	  sharps
	          rts


;	input: A = ascii code of char
;	output: if carry=0 A=valid hex value of char
;	        if carry=1 A=invalid char in current base
digit:
	          pshb
	          psha
	          suba	#$30		  ;ascii codes < 30
	          blo	  dgt2		  ; are invalid
	          cmpa	#9		    ;char between
	          bls	  dgt1		  ; 9 and A
	          cmpa	#17		    ; are invalid
	          blo	  dgt2		  ;fill gap
	          suba	#7		    ; between 9&A
dgt1	      cmpa	bas+1		;digit must be
	          bhs	  dgt2		  ; < base
	          andcc	#$FE		  ;clear carry (valid)
	          pulb			      ;pop old A
          	pulb			      ;restore B
	          rts
dgt2	      pula			      ;restore A
	          pulb			      ;restore B
	          orcc	#$01		  ;set carry (invalid)
	          rts

