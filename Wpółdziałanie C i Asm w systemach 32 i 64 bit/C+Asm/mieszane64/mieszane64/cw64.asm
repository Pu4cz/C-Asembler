public suma_liczb64
.code
suma_liczb64 PROC

push rbp
mov rbp, rsp

; za�adowanie do rejestru RAX warto�ci pierwszego argumentu

; funkcji
mov rax, rcx

; dodanie do rejestru RAX warto�ci drugiego argumentu funkcji
add rax, rdx

; dodanie do rejestru RAX warto�ci trzeciego argumentu funkcji
add rax, r8

add rax, r9
mov rax, [ebp+48]
mov rax, [ebp+56]
mov rax, [ebp+64] 

; wynik sumowania znajduje si� w rejestrze RAX

; odtworzenie pierwotnej zawarto�ci rejestru RBP
pop rbp

ret ; powr�t do programu g��wnego
suma_liczb64 ENDP
END