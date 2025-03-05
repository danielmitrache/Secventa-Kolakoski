.data
    NRMAX: .long 100
    seq: .space 400
    pointer: .long 1
    elem: .long 2

    formatPrintf: .asciz "%d "
.text
.global main
main:
    lea seq, %eax

    movl $1, (%eax)
    movl $2, 4(%eax)
    movl $2, 8(%eax)

    movl $3, %ecx
    generate_seq: ;//while (i < NRMAX)
        cmpl %ecx, NRMAX
        je exit_generate_seq

        ;//elem = 3 - elem
        movl $3, %edx
        subl elem, %edx
        movl %edx, elem

        ;//j = seq[pointer]
        movl pointer, %edx
        movl (%eax, %edx, 4), %ebx

        loop_add_elements: ;// while (j > 0 && i < NRMAX)  
            cmpl $0, %ebx
            je exit_loop_add_elements
            cmpl %ecx, NRMAX
            je exit_loop_add_elements

            movl elem, %esi
            movl %esi, (%eax, %ecx, 4) 
            incl %ecx ;//seq[i ++] = elem;
            decl %ebx ;//j --
            jmp loop_add_elements
        exit_loop_add_elements:
        incl pointer ;// pointer ++
        jmp generate_seq
    exit_generate_seq:

    lea seq, %eax
    xorl %ecx, %ecx
    print_loop:
        cmpl %ecx, NRMAX
        je exit_print_loop

        pushl %ecx
        pushl %eax
        movl (%eax, %ecx, 4), %ebx
        pushl %ebx
        pushl $formatPrintf
        call printf
        addl $8, %esp
        popl %eax
        popl %ecx

        incl %ecx
        jmp print_loop
    exit_print_loop:

    pushl $0
    call fflush
    addl $4, %esp

    movl $1, %eax
    xorl %ebx, %ebx
    int $0x80
