public suma_liczb64
.code
suma_liczb64 PROC

push rbp
mov rbp, rsp

; za³adowanie do rejestru RAX wartoœci pierwszego argumentu

; funkcji
mov rax, rcx

; dodanie do rejestru RAX wartoœci drugiego argumentu funkcji
add rax, rdx

; dodanie do rejestru RAX wartoœci trzeciego argumentu funkcji
add rax, r8

add rax, r9
mov rax, [ebp+48]
mov rax, [ebp+56]
mov rax, [ebp+64] 

; wynik sumowania znajduje siê w rejestrze RAX

; odtworzenie pierwotnej zawartoœci rejestru RBP
pop rbp

ret ; powrót do programu g³ównego
suma_liczb64 ENDP
END