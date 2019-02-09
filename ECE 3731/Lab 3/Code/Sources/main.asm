;*****************************************************************
;* Lab3.ASM
;* 
;*****************************************************************
; export symbols
            XDEF Entry, _Startup            ; export 'Entry' symbol
            ABSENTRY Entry        ; for absolute assembly: mark this as application entry point

; Include derivative-specific definitions 
		INCLUDE 'derivative.inc' 
		
;-------------------------------------------------- 
; Equates Section  
;----------------------------------------------------  
ROMStart    EQU  $2000  ; absolute address to place my code

;---------------------------------------------------- 
; Variable/Data Section
;----------------------------------------------------  
            ORG RAMStart   ; loc $1000  (RAMEnd = $3FFF)
; Insert here your data definitions here

PROMPT      dc.b    $0A, $0D   ; CR LF
            dc.b    "Type a character:  V W A D 4 2 P:  "
            dc.b    0    ; using zero terminated strings
            
VPROMPT     dc.b   "   Enter an 8 bit integer:   "
            dc.b    0
            
VENDPROMPT  dc.b   "   OP1 = "
            dc.b    0

WPROMPT      dc.b   "   Enter an 8 bit integer:   "
            dc.b    0
            
WENDPROMPT  dc.b   "   OP2 = "
            dc.b    0

UNSINVALID   dc.b  "   UNSIGNED INVALID  "
             dc.b   0
             
SIGINVALID   dc.b  "   SIGNED INVALID  "
             dc.b   0
             
             
             ORG $1500
OP1         dc.b  0
OP2         dc.b  0

TENS_VAL    dc.b    $0   ;Temperary storage for the tens place decimal value in DEC_PRINT
ONES_VAL    dc.b    $0   ;Temperary storage for the once place decimal value in DEC_PRINT


       INCLUDE 'utilities.inc'
       INCLUDE 'LCD.inc'

;---------------------------------------------------- 
; Code Section
;---------------------------------------------------- 
            ORG   ROMStart  ; loc $2000
Entry:
_Startup:
            ; remap the RAM &amp; EEPROM here. See EB386.pdf
 ifdef _HCS12_SERIALMON
            ; set registers at $0000
            CLR   $11                  ; INITRG= $0
            ; set ram to end at $3FFF
            LDAB  #$39
            STAB  $10                  ; INITRM= $39

            ; set eeprom to end at $0FFF
            LDAA  #$9
            STAA  $12                  ; INITEE= $9
            JSR   PLL_init      ; initialize PLL  
  endif

;---------------------------------------------------- 
; Insert your code here
;---------------------------------------------------- 
         LDS   #ROMStart ; load stack pointer
         JSR   TermInit  ; needed for Simulator only
         JSR   led_enable   ; enable PORTB for LED's
LOOP     LDD   #PROMPT; pass the adr of the string
         JSR   printf	; print the string         
         JSR   getchar  ; call getchar function -result is: character in B
         JSR   ClearLeds  ; clear LED's when starting over
VCASE    CMPB  #'V'   ; is it a V ?
	       BNE   WCASE  ; jump ahead if not
	       JSR   VFCN   ; else do corresponding function for V  -----
WCASE    CMPB  #'W'   ; is it a W ?
         BNE   ACASE  ; jump ahead if not
         JSR   WFCN   ;  else do corresponding function for W
ACASE    CMPB  #'A'   ; is it a A ?
         BNE   DCASE  ; jump ahead if not
	       JSR   AFCN   ; else do corresponding function for A
DCASE    CMPB  #'D'   ; is it a D ?
         BNE   FOURCASE; jump ahead if not
	       JSR   DFCN   ; else do corresponding function for D
FOURCASE CMPB  #'4'   ; is it a 4 ?
         BNE   TWOCASE; jump ahead if not
	       JSR   FOURFCN; else do corresponding function for 4	
TWOCASE CMPB  #'2'    ; is it a 2 ?
         BNE   PCASE   ; jump ahead if not
	       JSR   TWOFCN ; else do corresponding function for 2
PCASE CMPB  #'P'      ; is it a 2 ?
         BNE   NEXT   ; jump ahead if not
	       JSR   PFCN ; else do corresponding function for 2       
NEXT     JMP   LOOP  ; loop for more input

; Note: main program is an endless loop and subroutines follow
; (Must press reset to quit.)

;===================================================================
; FUNCTIONS CALLED BY MAIN LOOP
;-------------------------------------------------------------------
VFCN    PSHD
      	LDD   	#VPROMPT   ; pass the address of the string
        JSR     printf	    ; print the string
        BSET    PORTB,$01   ; light LED0
        PULD
        JSR getchar         ;get first digit
        SUBB    #$30        ;Subtract 30
        LDAA    #0          ;Load A as a temporary count
        
        CMPB #$09           ;Check if Value is above $09, hex value of 9
        BLS NOTOVR          ;brach if value is Below $09, go to NOTOVR
        SUBB #$10           ;If its a letter subtract 5 and add 9 to make it appear so in hex
        ADDB #$09
NOTOVR
        STAB OP1            ;Store B for the upcoming mulitiplication
        LDAB #$0            ;Load 0 as B
MULT_16 
        ADDB OP1            ;Add OP1 to B until the value becomes the first digit
        CMPA #$F
        INCA
        BLO MULT_16
        
        
        STAB OP1            ;Store First Digit
        JSR getchar         ;Get second Digit
        SUBB    #$30        ;Subtract 30
UNDER9_2
        CMPB #$09           ;Check if Value is above $09, hex value of 9
        BLS NOTOVR_2          ;brach if value is Below $09, go to NOTOVR_2
        SUBB #$10           ;If its a letter subtract 5 and add 9 to make it appear so in hex
        ADDB #$09
NOTOVR_2

        ADDB OP1            ;Add first digit to second digit
        STAB OP1            ;Store Value in OP1
        LDAA OP1            ;Load A as the value of OP1 so it can be returned to the main
        PSHD
        LDD  #VENDPROMPT    ;Print out end prompt
        JSR     printf
        PULD
        LDAB OP1            ;Load and print OP1
        LDX #OP1           ;Load location of OP1 into x
        JSR out2hex         ;Final output of OP1
        LDAB #$0
        RTS
;------------------------------------------------------------------- 
  
WFCN   
        PSHD
      	LDD   	#WPROMPT   ; pass the address of the string
        JSR     printf	    ; print the string
        BSET    PORTB,$02   ; light LED1
        PULD
        JSR getchar         ;get first digit
        SUBB    #$30        ;Subtract 30
        LDAA    #0          ;Load A as a temporary count
        
        CMPB #$09           ;Check if Value is above $09, hex value of 9
        BLS NOTOVRW          ;brach if value is Below $09, go to NOTOVR
        SUBB #$10           ;If its a letter subtract 5 and add 9 to make it appear so in hex
        ADDB #$09
NOTOVRW
        STAB OP2            ;Store B for the upcoming mulitiplication
        LDAB #$0            ;Load 0 as B

MULT_16W 
        ADDB OP2            ;Add OP1 to B until the value becomes the first digit
        CMPA #$F
        INCA
        BLO MULT_16W
        
        
        STAB OP2            ;Store First Digit
        JSR getchar         ;Get second Digit
        SUBB    #$30        ;Subtract 30
UNDER9W_2
        CMPB #$09           ;Check if Value is above $09, hex value of 9
        BLS NOTOVRW_2          ;brach if value is Below $09, go to NOTOVR_2
        SUBB #$10           ;If its a letter subtract 5 and add 9 to make it appear so in hex
        ADDB #$09
NOTOVRW_2

        ADDB OP2            ;Add first digit to second digit
        STAB OP2            ;Store Value in OP2
        LDAA OP2            ;Load A as the value of OP2 so it can be returned to the main
        PSHD
        LDD  #WENDPROMPT    ;Print out end prompt
        JSR     printf
        PULD
        LDAB OP2            ;Load and print OP2
        LDX #OP2           ;Load Location of OP2 into X
        JSR out2hex         ;Print Final OP2  
        LDAB #$0 
        RTS
;-------------------------------------------------------------------        
AFCN    
        BSET   PORTB,$04   ; light LED2
        LDAB  #$24       ;Load and print a $
        JSR putchar
        LDAB OP1         ;Load and print OP1
        JSR out2hex
        LDAB #$2B        ;Load and print a +
        JSR putchar
        LDAB  #$24       ;Load and print a $
        JSR putchar
        LDAB OP2         ;Load and print OP2
        JSR out2hex
        LDAB #$3D        ;Load and Print =
        JSR putchar
        LDAB  #$24       ;Load and print a $
        JSR putchar
        LDAB OP1         ;add OP1 to OP2 and print
        ADDB OP2
        JSR out2hex      ;Output value
        
        LDAA OP1
        ADDA OP2
        BCC L1
        LDD   	#UNSINVALID   ; pass the address of the string
        JSR     printf	    ; print the string
L1
        LDAA OP1
        ADDA OP2
        BVC  L2
        LDD   	#SIGINVALID   ; pass the address of the string
        JSR     printf	    ; print the string
L2
        RTS
;-------------------------------------------------------------------         
DFCN
        BSET   PORTB,$08   ; light LED3
        LDAB  #$24       ;Load and print a $
        JSR putchar
        LDAB OP1         ;Load and print OP1
        JSR out2hex
        LDAB #$3D        ;Load and Print =
        JSR putchar
        LDAB OP1          ;Load OP1
        
        ;Start of Hex to decimal algorithm (uses ONES_VAL and TENS_VAL)
        LDAA #0        ;load zero in for the tens place
HEXLOOP
        CMPB #$0A      ;check if value is already less than 10
        BLO DEC_PRINT  ;if so go to dec_print
        SUBB #$A      ;subtract 10
        INCA           ;increase tens place
        CMPB #$0A      ;check if its below 10 now
        BHS HEXLOOP    ;if not go back to loop
        
        
DEC_PRINT        
        STAB ONES_VAL  ;store ones value
        STAA TENS_VAL  ;store tens value
        LDAB TENS_VAL  ;obtain tens value
        ADDB #$30      ;add $30 so the ascii value lines up
        JSR putchar    ;print tens value
        LDAB ONES_VAL  ;load ones value
        ADDB #$30      ;add $30 so the ascii value lines up
        JSR putchar    ;print ones value
        ;End of Hex to decimal algorithm
        
        LDAB #$0
        
        RTS
;-------------------------------------------------------------------        
FOURFCN
        BSET   PORTB,$20; light LED4
        LDAB  #$24      ;Load and print a $
        JSR putchar
        LDAB  OP1
        JSR out2hex     ;Load and print OP1
        LDAB  OP2
        JSR out2hex     ;Load and print OP2
        RTS             
;-------------------------------------------------------------------        
TWOFCN
        BSET   PORTB,$10; light LED5
        LDAA 0,X
        ADDA 0,X
        STAA 0,X
        LDAB 0,X
        JSR out2hex

        
        RTS
;-------------------------------------------------------------------        
PFCN    LDAA OP1
        STAA PORTB       ;Set value as portb
        RTS
        
ClearLeds
        CLR   PORTB      ; clear all LED's
        RTS 
;-------------------------------------------------------------------                                 
                         
;**************************************************************
;*                 Interrupt Vectors                          *
;**************************************************************
            ORG   Vreset
            DC.W  Entry         ; Reset Vector
 