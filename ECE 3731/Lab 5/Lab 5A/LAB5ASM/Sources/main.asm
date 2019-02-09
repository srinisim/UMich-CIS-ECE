;*****************************************************************
;* LAB5.ASM
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
RED:        EQU     $10    ; PP4
BLUE:       EQU     $20    ; PP5
GREEN:      EQU     $40    ; PP6       

;---------------------------------------------------- 
; Variable/Data Section
;----------------------------------------------------  
            ORG RAMStart   ; loc $1000  (RAMEnd = $3FFF)
; Insert here your data definitions here
SEED        dc.b   0

SW0PROMPT      dc.b    $0A, $0D   ; CR LF
            dc.b    "SW0 is Pressed "
            dc.b    0    ; using zero terminated strings 
            
SW1PROMPT      dc.b    $0A, $0D   ; CR LF
            dc.b    "SW1 is Pressed "
            dc.b    0    ; using zero terminated strings 
            
SW2PROMPT      dc.b    $0A, $0D   ; CR LF
            dc.b    "SW2 is Pressed "
            dc.b    0    ; using zero terminated strings                  
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
 ;*Note: Make sure DIP sw’s are all up
             JSR    led_enable    ; init. PORTB for LED’s
             bset    DDRP,  RED+GREEN+BLUE  ; make pp4-pp6  outputs
             bset    DDRM, 4    ; make PM2 an output
             bclr    PTM, 4   ; make PM2 low to enable RGB
             JSR lcd_init         ;Initialize LCD

MAIN
*Check for PTH pin 0 SW press  (SW5)  if not check next one
CHECKPH0  BRSET   PTH, $01,CHECKPH1
 		JSR   PH0FCN  ; if button pressed call function for button
 		JSR   DELAY_200_MS
*Check for PTH pin 1 SW press (SW4)  if not check next one
CHECKPH1  BRSET   PTH, %00000010,CHECKPH2
 		JSR   PH1FCN  ; if button pressed call function for button
 		JSR   DELAY_200_MS
*Check for PTH pin 2 SW press  (SW3) if not check next one
CHECKPH2  BRSET   PTH, %00000100, NEXT
 		JSR   PH2FCN  ; if button pressed call function for button
 		JSR   DELAY_200_MS
NEXT	JMP   MAIN


; Note: main program is an endless loop and subroutines follow
; (Must press reset to quit.)

;===================================================================
; FUNCTIONS CALLED BY MAIN LOOP
;* <This function will simply call the ELECTION function and then delay for 1 second before restarting the program>
PH0FCN     
           
          bclr   PTP,  RED+GREEN+BLUE  ; clear all
          
          LDD #SW0PROMPT    ;Load LCD Prompt
          JSR clear_lcd  ;Clear anything else off of LCD
          JSR lcd_prtstrg;Print LCD prompt
          
          JSR ELECTION
          jsr    DELAY_1_S   ; delay for 1 second
 RTS
;------------------------------------------------------------------- 
;*<This function will load the PORTB value and increment it by 1>
PH1FCN     

          bclr   PTP,  RED+GREEN+BLUE  ; clear all
          
          LDD #SW1PROMPT    ;Load LCD Prompt
          JSR clear_lcd  ;Clear anything else off of LCD
          JSR lcd_prtstrg;Print LCD prompt
          
          LDAA PORTB
          INCA
          CMPA #%00010000
          BNE NOTSET
          LDAA #%00000000 
NOTSET
          STAA PORTB
          bset   PTP,  BLUE   ; turn on blue
          jsr    DELAY_200_MS   ; delay for .2 second
          bclr   PTP,  RED+GREEN+BLUE  ; clear all
          jsr    DELAY_200_MS   ; delay for .2 second
          bset   PTP,  BLUE   ; turn on blue
          jsr    DELAY_200_MS   ; delay for .2 second
          bclr   PTP,  RED+GREEN+BLUE  ; clear all
          jsr    DELAY_200_MS   ; delay for .2 second
          RTS

;------------------------------------------------------------------- 
;*<This function will load in the seed value and shift it left by one bit, it will then blink the blue LED 3 times with a 1 second delay> 
PH2FCN     
          bclr   PTP,  RED+GREEN+BLUE  ; clear all
          bset   PTP,  RED   ; turn on RED
          
          LDD #SW2PROMPT    ;Load LCD Prompt
          JSR clear_lcd  ;Clear anything else off of LCD
          JSR lcd_prtstrg;Print LCD prompt
          
          LDAA PORTB
          DECA
          CMPA #%11111111
          BNE NOTSET2
          LDAA #%00001111 
NOTSET2
          STAA PORTB
          bset   PTP,  RED   ; turn on blue
          jsr    DELAY_200_MS   ; delay for .2 second
          bclr   PTP,  RED+GREEN+BLUE  ; clear all
          jsr    DELAY_200_MS   ; delay for .2 second
          bset   PTP,  RED   ; turn on blue
          jsr    DELAY_200_MS   ; delay for .2 second
          bclr   PTP,  RED+GREEN+BLUE  ; clear all
          jsr    DELAY_200_MS   ; delay for .2 second  
          rts
;------------------------------------------------------------------- 
;*<This function will call the 1 millisecond delay to delay for 200 milliseconds>  
DELAY_200_MS
          LDX #$00C8        ;load in 200
LOOP_200_MS
          JSR DELAY_1_MS    ;call delay 1 milisecond
          DEX               ;decrease X
          CPX #$0
          BNE LOOP_200_MS     ;branch until X = 0
          RTS               ;return
;------------------------------------------------------------------- 
;*<This function will call the 1 millisecond delay to delay for 1000 milliseconds>  
DELAY_1_S
          LDX #$03E8        ;load in 1000
LOOP_1_S
          JSR DELAY_1_MS    ;call delay 1 milisecond
          DEX               ;decrease X
          CPX #$0
          BNE LOOP_1_S     ;branch until X = 0
          RTS               ;return
;------------------------------------------------------------------- 
;*<This function will run a simple program 6000 times to delay for 1 millisecond>    

DELAY_1_MS                  
          LDY #$1770        ;load in 6000
LOOP_1_MS                   
          DEY               ;Decrement y
          CPY #$0
          BNE LOOP_1_MS     ;
          RTS
;------------------------------------------------------------------- 
;*<This function will check the dip switches and set turn on either the red or green LED depending on whether more are high or low>             
ELECTION  

          LDAA #0
          STAA PORTB
          BRCLR PTH,%10000000,L1
          INCA
          BSET PORTB, %00001000
L1
          BRCLR PTH,%01000000,L2
          INCA
          BSET PORTB, %00000100
L2
          BRCLR PTH,%00100000,L3
          INCA
          BSET PORTB, %00000010
L3
          BRCLR PTH,%00010000,L4
          INCA
          BSET PORTB, %00000001
L4
          CMPA #$3
          BHI RESULTS
          bset   PTP,  RED   ; turn on red
          RTS
RESULTS
          bset   PTP,  GREEN   ; turn on green
          RTS          
;------------------------------------------------------------------- 
;END OF FUNCTIONS              
          

                  
                         
;**************************************************************
;*                 Interrupt Vectors                          *
;**************************************************************
            ORG   Vreset
            DC.W  Entry         ; Reset Vector
 