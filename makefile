my_grep: main.o argument_handler.o file_and_stdin_handler.o grep_command_picker.o
		gcc main.o argument_handler.o file_and_stdin_handler.o grep_command_picker.o -o my_grep

main.o: main.c argument_handler.h file_and_stdin_handler.h
		gcc -c main.c

argument_handler.o: argument_handler.c argument_handler.h
		gcc -c argument_handler.c

file_and_stdin_handler.o: file_and_stdin_handler.c file_and_stdin_handler.h grep_command_picker.h
		gcc -c file_and_stdin_handler.c

grep_command_picker.o: grep_command_picker.c grep_command_picker.h
		gcc -c grep_command_picker.c
