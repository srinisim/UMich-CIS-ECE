TITLE Program2
INCLUDE Irvine32.inc
.data
.386
.model flat,stdcall
.stack 4096
ExitProcess proto,dwExitCode:dword

RAW WORD 8, 19, 14, 27, 6, 20, 18, 12,23, 27, 31, 22, 17, 26, 7
DIFFSQ WORD 15 DUP(?)
SQUARE WORD 15 DUP(?)
MEAN WORD ?
m BYTE "MEAN: ", 0
v BYTE "VAR: ", 0
.code
main proc

mov edi, OFFSET RAW
mov ecx, LENGTHOF RAW
mov eax, 0

L1: 
	add ax, [edi]
	add edi, TYPE RAW
	loop L1

mov ecx, LENGTHOF RAW
mov dx, 0
div cx
mov MEAN, ax
mov edx, OFFSET m
call WriteString
call WriteDec
call CRLF

mov edi, OFFSET RAW
mov esi, OFFSET DIFFSQ
mov ecx, LENGTHOF RAW
mov eax, 0
L2:
	mov ax, [edi]
	sub ax, MEAN
	mov bx, ax
	mul bx
	mov [esi], eax
	add edi, TYPE RAW
	add esi, TYPE DIFFSQ
	loop L2

mov edi, OFFSET DIFFSQ
mov ecx, LENGTHOF DIFFSQ
mov eax, 0
L3:
	add ax, [edi]
	add edi, TYPE DIFFSQ
	loop L3

mov ecx, LENGTHOF RAW
mov dx, 0
div cx
mov edx, OFFSET v
call WriteString
call WriteDec
call CRLF

invoke ExitProcess, 0
main endp
end main