;*****************************************************************
;* ParsingLoop.ASM
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
            dc.b    "Type a character:  Y N M  "
            dc.b    0    ; using zero terminated strings
            
YESSTRG     dc.b   "   YES  "
            dc.b    0

NOSTRG      dc.b   "   NO   "
            dc.b    0

MAYBESTRG    dc.b  "   MAYBE  "
             dc.b   0


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
LOOP     LDD   #PROMPT   ; pass the adr of the string
         JSR   printf	; print the string         
         JSR   getchar  ; call getchar function -result is: character in B
         JSR   ClearLeds  ; clear LED's when starting over
YCASE    CMPB  #'Y'  ; is it a Y ?
	       BNE   NCASE  ; jump ahead if not
	       JSR   YFCN   ; else do corresponding function for Y
NCASE    CMPB  #'N'  ; is it a N ?
         BNE   MCASE ; jump ahead if not
         JSR   NFCN ;  else do corresponding function for N
MCASE    CMPB  #'M'  ; is it a M ?
         BNE   NEXT   ; jump ahead if not
	       JSR   MFCN ; else do corresponding function for M
NEXT     JMP   LOOP  ; loop for more input

; Note: main program is an endless loop and subroutines follow
; (Must press reset to quit.)

;===================================================================
; FUNCTIONS CALLED BY MAIN LOOP

YFCN    PSHD
      	LDD   	#YESSTRG   ; pass the address of the string
        JSR     printf	    ; print the string
        BSET    PORTB,$01   ; light LED0
        PULD
        RTS
        
NFCN   
        PSHD
      	LDD    #NOSTRG     ; pass adr. of string
        JSR    printf	   ; call printf
        BSET   PORTB,$02   ; light LED1
        PULD
        RTS
        
MFCN    
        PSHD
      	LDD    #MAYBESTRG  ; pass adr. of string
        JSR    printf	   ; print the string
        BSET   PORTB,$04   ; light LED2
        PULD
        RTS
        
ClearLeds
        CLR   PORTB      ; clear all LED's
        RTS                                  
                         
;**************************************************************
;*                 Interrupt Vectors                          *
;**************************************************************
            ORG   Vreset
            DC.W  Entry         ; Reset Vector
 