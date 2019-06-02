.686
.model flat
public suma_liczb

; prototyp na poziomie jêzyka C
;int suma_liczb (int p, int q, int r);
.code
suma_liczb PROC
push ebp
mov ebp, esp
; wpisanie wartoœci parametru p do rejestru EAX
mov eax, [ebp+8]
; dodanie do rejestru EAX wartoœci parametru q
add eax, [ebp+12]
; dodanie do rejestru EAX wartoœci parametru r
add eax, [ebp+16]
; odtworzenie pierwotnej zawartoœci rejestru EBP
pop ebp
ret ; powrót do programu g³ównego
suma_liczb ENDP
END