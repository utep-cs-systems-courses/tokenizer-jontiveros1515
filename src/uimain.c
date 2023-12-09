/*This is going to be the User Interface that just echoes input for now*/
#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"
#define MAX 100

int main(){
  char input[MAX];
  List *list = init_history();

  //Massive loop to keep ui going
  while(1){
  puts("Input 1 to enter free typing mode, Input 2 to enter command mode (get and print history)");
    putchar('>');
    fgets(input, MAX, stdin);
    char **tokens = tokenize(input);
    if(**tokens == '1'){
      puts("Entering free-typing mode");
      // print_tokens(tokens);
      free_tokens(tokens);
      puts("If you want to go back to the main menu, just input c");
      while(1){
	putchar('>');
	fgets(input, MAX, stdin);
	tokens = tokenize(input);
	if(*tokens[0] == 'c' && *(tokens[0]+1) != '\0'){
	  puts("Returning to main menu");
	  break;
	}
	else{
	  print_tokens(tokens);
	  add_history(list, input);
	  free_tokens(tokens);
	}
      }
    } //End of first split in decision
    
    else if(**tokens == '2'){
      puts("Type h to print out the history of your inputs, a number to attempt to retrieve that input history by ID, or c to go back to the first menu");
      free_tokens(tokens);
      while(1){
	putchar('>');
	fgets(input, MAX, stdin);
	tokens = tokenize(input);
	if(**tokens == 'h'){
	  print_history(list);
	}
	else if(**tokens == 'c'){
	  puts("Returning to main menus");
	  break;
	}
	else if((**tokens - '0') > 0){
	  printf("%s", get_history(list, **tokens - '0'));
	}
	 
      }
    } //End of second split in decision
    else if(**tokens == 'c'){
      free_history(list);
      return 0;
    }
    else{
      puts("This does not match any of the requested inputs");
    }
  }
}
