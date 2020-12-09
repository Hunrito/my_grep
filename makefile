my_grep: main.o argument_handler.o file_and_stdin_handler.o grep_command_picker.o string_list_handler.o regular_expression_handler.o
		gcc main.o argument_handler.o file_and_stdin_handler.o grep_command_picker.o string_list_handler.o regular_expression_handler.o -o my_grep

main.o: main.c argument_handler.h file_and_stdin_handler.h
		gcc -c main.c

argument_handler.o: argument_handler.c argument_handler.h
		gcc -c argument_handler.c

string_list_handler.o: string_list_struct.c string_list_handler.h string_list_handler.h
		gcc -c string_list_handler.c

regular_expression_handler.o: regular_expression_handler.c regular_expression_handler.h
		gcc -c regular_expression_handler.c

file_and_stdin_handler.o: file_and_stdin_handler.c file_and_stdin_handler.h grep_command_picker.h
		gcc -c file_and_stdin_handler.c

grep_command_picker.o: grep_command_picker.c grep_command_picker.h
		gcc -c grep_command_picker.c
