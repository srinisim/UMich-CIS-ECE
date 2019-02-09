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

;***********************************************************************************************
DispTab     dc.b $76,$0E
            dc.b $79,$0D
            dc.b $38,$0B
            dc.b $38,$07

;***********************************************************************************************            
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
; Insert your code here ***THIS IS THE MAINLOOP***
;---------------------------------------------------- 
         LDS   #ROMStart ; load stack pointer
;***********************************************************************************************
         jsr led_enable
         JSR   TermInit  ; needed for Simulator only
          
start:  lds #$1500
        movb #$FF, DDRB
        movb #$0F, DDRP
forever:
        ldx #DispTab
loop1:
        movb 1,x+, PORTB
        movb 1,x+, PTP
        ldd #1
        jsr ms_delay
        
        cpx #DispTab+8
        bne loop1
        bra forever        
;***********************************************************************************************
;------------------------------------------------------------------- 
;*<This function will run a simple program 60 times to delay for .01 millisecond>    

DELAY_.01_MS                  
          LDY #$003C        ;load in 60
LOOP_.01_MS                   
          DEY               ;Decrement y
          CPY #$0
          BNE LOOP_.01_MS     ;
          RTS
;-------------------------------------------------------------------
DELAY_.7_MS
          LDX #$0046        ;load in 70
LOOP_.7_MS
          JSR DELAY_.01_MS    ;call delay .01 milisecond
          DEX               ;decrease X
          CPX #$0
          BNE LOOP_.7_MS     ;branch until X = 0
          RTS               ;return
;-------------------------------------------------------------------
DELAY_.65_MS
          LDX #$0041        ;load in 65
LOOP_.65_MS
          JSR DELAY_.01_MS    ;call delay .01 milisecond
          DEX               ;decrease X
          CPX #$0
          BNE LOOP_.65_MS     ;branch until X = 0
          RTS               ;return
;-------------------------------------------------------------------
DELAY_.59_MS
          LDX #$003B        ;load in 59
LOOP_.59_MS
          JSR DELAY_.01_MS    ;call delay .01 milisecond
          DEX               ;decrease X
          CPX #$0
          BNE LOOP_.59_MS     ;branch until X = 0
          RTS               ;return
;-------------------------------------------------------------------   
                  
;ClearLeds
        ;CLR   PORTB      ; clear all LED's
        ;RTS 
;-------------------------------------------------------------------                                 
                         
;**************************************************************
;*                 Interrupt Vectors                          *
;**************************************************************
            ORG   Vreset
            DC.W  Entry         ; Reset Vecto