; obliczenie sumy wyraz�w ci�gu 3 + 5 + 7 + 9 + 11
.686
.model flat
extern wyswietl_EAX : PROC
extern _ExitProcess@4 : PROC
public _main
.code
_main:
; obliczenie bez u�ycia p�tli rozkazowej
mov eax, 3 ; pierwszy element ci�gu
add eax, 5 ; dodanie drugiego elementu
add eax, 7 ; dodanie trzeciego elementu
add eax, 9 ; dodanie czwartego elementu
add eax, 11 ; dodanie pi�tego elementu
call wyswietl_EAX ; wy�wietlenie wyniku

; obliczenie z u�yciem p�tli rozkazowej
mov eax, 0 ; pocz�tkowa warto�� sumy
mov ebx, 3 ; pierwszy element ci�gu
mov ecx, 5 ; liczba obieg�w p�tli
ptl: add eax, ebx ; dodanie kolejnego elementu
add ebx, 2 ; obliczenie nast�pnego elementu
sub ecx, 1 ; zmniejszenie licznka obieg�w p�tli
jnz ptl ; skok, gdy licznik obieg�w r�ny od 0
call wyswietl_EAX ; wy�wietlenie wyniku
; zako�czenie wykonywania programu
push 0
call _ExitProcess@4
END