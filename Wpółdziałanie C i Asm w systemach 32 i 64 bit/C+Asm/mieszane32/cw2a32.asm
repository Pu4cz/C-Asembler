.686
.model flat
public suma_liczb

; prototyp na poziomie j�zyka C
;int suma_liczb (int p, int q, int r);
.code
suma_liczb PROC
push ebp
mov ebp, esp
; wpisanie warto�ci parametru p do rejestru EAX
mov eax, [ebp+8]
; dodanie do rejestru EAX warto�ci parametru q
add eax, [ebp+12]
; dodanie do rejestru EAX warto�ci parametru r
add eax, [ebp+16]
; odtworzenie pierwotnej zawarto�ci rejestru EBP
pop ebp
ret ; powr�t do programu g��wnego
suma_liczb ENDP
END