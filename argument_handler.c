#include "argument_handler.h"
#include <string.h>
#include <stdlib.h>

const char A_OPERATOR[] = "-A";
const char B_OPERATOR[] = "-b";
const char C_OPERATOR[] = "-c";
const char I_OPERATOR[] = "-i";
const char N_OPERATOR[] = "-n";
const char X_OPERATOR[] = "-x";
const char V_OPERATOR[] = "-v";
const char E_OPERATOR[] = "-E";
const int NUMBER_OF_OPERATORS = 10;

int convertToInt(char *stringToConvert)
{
    int  i;
    int result=0;
    
    for(i=0; i< (int)strlen(stringToConvert); i++)
    {
        result = result * 10 + (stringToConvert[i] - '0');
        
    }
    return(result);
}

char* expression_finder(int argc,const char* argv[])
{
	int index;
	for (index = 1; index < argc; index++) 
	{
		if (strcmp(argv[index], E_OPERATOR) == 0) 
		{
			index++;
			return strdup(argv[index]);
		}
		if (argv[index][0] != 45)
		{
			return strdup(argv[index]);
		}
		if (strcmp(argv[index], A_OPERATOR) == 0)
		{
			index++;
		}
	}
	printf("No expression given.\n");
	return NULL;
}

int* find_operators(int argc,const char* argv[]) 
{
	int index;
	int non_command_counter = 0;
	static int argument_array[] = {0,0,0,0,0,0,0,0,0,0};
	for (index = 1; index < argc; index++) 
	{
		if (strcmp(argv[index], A_OPERATOR) == 0) 
		{
			argument_array[A] = 1;
			index++;
			argument_array[A_NUM] = convertToInt((char *)argv[index]);
		}
		else if ((argv[index][0] != 45))
		{
			//printf("non command\n");
			non_command_counter++;
		}
		else if (strcmp(argv[index], B_OPERATOR) == 0) 
		{
			argument_array[b] = 1;
		}
		else if (strcmp(argv[index], C_OPERATOR) == 0) 
		{
			argument_array[c] = 1;
		}
		else if (strcmp(argv[index], I_OPERATOR) == 0) 
		{
			argument_array[i] = 1;
		}
		else if (strcmp(argv[index], N_OPERATOR) == 0) 
		{
			argument_array[n] = 1;
		}
		else if (strcmp(argv[index], X_OPERATOR) == 0) 
		{
			argument_array[x] = 1;
		}
		else if (strcmp(argv[index], V_OPERATOR) == 0) 
		{

			argument_array[v] = 1;
		}
		else if (strcmp(argv[index], E_OPERATOR) == 0) 
		{
			argument_array[E] = 1;
		}
	}
	if(non_command_counter == 2)
	{
		argument_array[file_exist] = 1;
	}
	return argument_array;
}