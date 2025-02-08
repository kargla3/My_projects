.data
byte_counter db 0
current_byte db 0

.CODE
; Funkcja ConvertASM

ConvertASM proc
    push rsi
    push rdi
    push rbx

    ;rsi - INPUTPTR
    ;rdi - OUTPUTPTR

    mov r11, r8        ; inputWidth
    mov rcx, r9         ; inputHeight
    
    mov r8, [rsp+64]   ; outputWidth (pi�ty argument)
    mov r9, [rsp+72]   ; outputHeight (sz�sty argument)
    mov r10, [rsp+80]    ; mode (si�dmy argument)

    cmp r9, 0
    je division_by_zero

    ; scaleX = inputWidth / outputWidth
    ; Zamie� inputWidth (rbx) na zmiennoprzecinkowy double i przechowaj w xmm0
    mov rax, r11                ; Przenie� inputWidth do rax
    cvtsi2sd xmm0, rax          ; Konwertuj inputWidth (int) do double w xmm0

    ; Zamie� outputWidth (rsi) na zmiennoprzecinkowy double i przechowaj w xmm1
    mov rax, r8                ; Przenie� outputWidth do rax
    cvtsi2sd xmm1, rax          ; Konwertuj outputWidth (int) do double w xmm1

    ; Wykonaj dzielenie: scaleX = inputWidth / outputWidth
    divsd xmm0, xmm1            ; xmm0 = xmm0 / xmm1 (inputWidth / outputWidth)

    ; Zachowaj wynik w xmm1 (scaleX)
    movsd xmm1, xmm0            ; Zachowaj scaleX

    ; scaleY = inputHeight / outputHeight
    ; Zamie� inputHeight (rcx) na zmiennoprzecinkowy double i przechowaj w xmm0
    mov rax, rcx                ; Przenie� inputHeight do rax
    cvtsi2sd xmm0, rax          ; Konwertuj inputHeight (int) do double w xmm0

    ; Zamie� outputHeight (rdi) na zmiennoprzecinkowy double i przechowaj w xmm2
    mov rax, r9                ; Przenie� outputHeight do rax
    cvtsi2sd xmm2, rax          ; Konwertuj outputHeight (int) do double w xmm2

    ; Wykonaj dzielenie: scaleY = inputHeight / outputHeight
    divsd xmm0, xmm2           ; xmm0 = xmm0 / xmm2 (inputHeight / outputHeight)

    ; Zachowaj wynik w xmm2 (scaleY)
    movsd xmm2, xmm0            ; Zachowaj scaleY
        
    jmp calculate


division_by_zero:
    ; Obs�ugujemy przypadek dzielenia przez zero
    mov r11, 0            ; Domy�lna warto��, np. 0

calculate:
    ; P�tla przez wiersze obrazu wyj�ciowego
    xor r12, r12           ; r12 = 0 (indeks wiersza)
    mov r14, rdi           ; wska�nik do obrazu wyj�ciowego

outer_loop:
    cmp r12, r9                 ; Sprawd�, czy osi�gni�to wysoko�� obrazu wyj�ciowego
    je done                    ; Je�li tak, zako�cz p�tl�

    xor r13, r13                ; r13 = 0 (indeks kolumny)
inner_loop:
    cmp r13, r8                 ; Sprawd�, czy osi�gni�to szeroko�� obrazu wyj�ciowego
    je next_row                ; Je�li tak, przejd� do nast�pnego wiersza


    ; Oblicz skalowane wsp�rz�dne wej�ciowe
    ; xInput = r13 * scaleX
    cvtsi2sd xmm0, r13          ; Konwertuj r13 (Xoutput) na double
    mulsd xmm0, xmm1            ; xmm0 = r13 * scaleX
    cvttsd2si rax, xmm0         ; Konwertuj wynik na int (xInput)

    ; yInput = r12 * scaleY
    cvtsi2sd xmm0, r12          ; Konwertuj r12 (Youtput) na double
    mulsd xmm0, xmm2            ; xmm0 = r12 * scaleY
    cvttsd2si rbx, xmm0         ; Konwertuj wynik na int (yInput)

    ; Oblicz pozycj� w obrazie wej�ciowym (zak�adaj�c 3 bajty na piksel)
    imul rbx, r11          ; rdi = yInput * inputWidth (indeks wiersza)
    add rbx, rax                ; rdi += xInput (dodaj kolumn�)

    imul rbx, 3            ; rdi *= 3 (przesuni�cie bajtowe dla RGB)
    
    cmp r10, 0
    je mono

    cmp r10, 565
    je _565

    ; Oblicz pozycj� w obrazie wyj�ciowym
    mov rdi, r12                ; rdi = Youtput (indeks wiersza)
    imul rdi, r8                ; rdi = Youtput * outputWidth
    add rdi, r13                ; rdi += Xoutput (indeks kolumny)
    imul rdi, rdi, 3            ; rdi *= 3 (przesuni�cie bajtowe dla RGB)

    ; Pobierz warto�ci RGB z obrazu wej�ciowego
    movzx rax, byte ptr [rsi + rbx + 0]       ; rbx = warto�� R
    movzx rcx, byte ptr [rsi + rbx + 1]   ; rcx = warto�� G
    movzx rdx, byte ptr [rsi + rbx + 2]   ; rdx = warto�� B

    ; Maluj piksel na odpowiedni kolor
    mov byte ptr [r14 + rdi + 2], al      ; R
    mov byte ptr [r14 + rdi + 1], cl   ; G 
    mov byte ptr [r14 + rdi + 0], dl   ; B 

    inc r13
    jmp inner_loop

mono:
    movzx rax, byte ptr [rsi + rbx + 0]       ; rbx = warto�� R
    movzx rcx, byte ptr [rsi + rbx + 1]   ; rcx = warto�� G
    movzx rdx, byte ptr [rsi + rbx + 2]   ; rdx = warto�� B

    movzx eax, al       ; Przenie� pierwszy bajt do EAX i wyzeruj g�rne bity
    add eax, ecx
    add eax, edx
    mov edx, 0          ; Wyzeruj g�rne bity (przygotowanie dla div)
    mov ecx, 3          ; Dzielnik = 3
    div ecx             ; EAX / ECX, wynik w EAX, reszta w EDX

    ;oblicz pozycje w obrazie wyjsciowym
    mov rdi, r12
    imul rdi, r8
    add rdi, r13

    xor rdx, rdx
    mov rdx, rdi                ; Skopiuj pozycj� bitow�
    shr rdi, 3                  ; rdi = rdi / 8 (pozycja bajtu)
    and rdx, 7                  ; rdx = rdi % 8 (pozycja bitu)

    ;mov rcx, 7
    ;sub rcx, rdx                ; Odwr�� pozycj� bitu
    ;mov rdx, rcx                ; Zapisz now� pozycj� bitu w rdx


    mov ecx, 127
    cmp eax, ecx
    jg average_greater

    btr [r14 + rdi], rdx
    jmp next_step

average_greater:
    bts [r14 + rdi], rdx
    jmp next_step

_565:
    mov rdi, r12
    imul rdi, r8
    add rdi, r13
    imul rdi, rdi, 2

    movzx rax, byte ptr [rsi + rbx + 0]   ; rbx = warto�� R
    movzx rcx, byte ptr [rsi + rbx + 1]   ; rcx = warto�� G
    movzx rdx, byte ptr [rsi + rbx + 2]   ; rdx = warto�� B

    ; Przekszta�cenie R na 5 bit�w (R[4:0])
    shr rax, 3                            ; rax = R >> 3 (5 bit�w)

    ; Przekszta�cenie G na 6 bit�w (G[5:0])
    shr rcx, 2                            ; rcx = G >> 2 (6 bit�w)
    shl rcx, 5                            ; rcx = (G[5:0] << 5)

    ; Przekszta�cenie B na 5 bit�w (B[4:0])
    shr rdx, 3                            ; rdx = B >> 3
    shl rax, 11                           ; rax = (R[4:0] << 11)

    ; Po��cz R, G, B w jeden 16-bitowy kolor RGB565
    or rax, rcx                           ; rax = R | G
    or rax, rdx                           ; rax = R | G | B (16-bitowy kolor)

    ; Zapisz wynik w pami�ci
    mov word ptr [r14 + rdi], ax           ; Zapisz RGB565 jako 2 bajty

next_step:
    inc r13                          ; Przejd� do nast�pnej kolumny
    jmp inner_loop                   ; Powt�rz dla kolejnego piksela

next_row:
    inc r12                     ; Przejd� do nast�pnego wiersza
    jmp outer_loop              ; Powt�rz dla kolejnego wiersza

done:
    ; Zako�czenie
    movsd xmm0, xmm2
    pop rbx
    pop rdi
    pop rsi


    ret
ConvertASM endp
END