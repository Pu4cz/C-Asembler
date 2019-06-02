; obliczenie sumy wyrazów ci¹gu 3 + 5 + 7 + 9 + 11
.686
.model flat
extern wyswietl_EAX : PROC
extern _ExitProcess@4 : PROC
public _main
.code
_main:
; obliczenie bez u¿ycia pêtli rozkazowej
mov eax, 3 ; pierwszy element ci¹gu
add eax, 5 ; dodanie drugiego elementu
add eax, 7 ; dodanie trzeciego elementu
add eax, 9 ; dodanie czwartego elementu
add eax, 11 ; dodanie pi¹tego elementu
call wyswietl_EAX ; wyœwietlenie wyniku

; obliczenie z u¿yciem pêtli rozkazowej
mov eax, 0 ; pocz¹tkowa wartoœæ sumy
mov ebx, 3 ; pierwszy element ci¹gu
mov ecx, 5 ; liczba obiegów pêtli
ptl: add eax, ebx ; dodanie kolejnego elementu
add ebx, 2 ; obliczenie nastêpnego elementu
sub ecx, 1 ; zmniejszenie licznka obiegów pêtli
jnz ptl ; skok, gdy licznik obiegów ró¿ny od 0
call wyswietl_EAX ; wyœwietlenie wyniku
; zakoñczenie wykonywania programu
push 0
call _ExitProcess@4
END