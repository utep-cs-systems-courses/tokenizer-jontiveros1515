#include "stdio.h"
#include "stdlib.h"
#include "tokenizer.h"

int space_char(char c){
  if(c == ' ' || c =='\t')
    return 1;
  else
    return 0;
}

int non_space_char(char c){
  if(c == '\0')
    return 0;
  else
    return (space_char(c) ^ 1); //Using exclusive or to guarantee opposite result of space_char
}

char *token_start(char *s){
  while(space_char(*s)){
    s++;
  }
  if(*s == '\0')
    return 0;
  else
     return s;
}

char *token_terminator(char *token){
  while(non_space_char(*token)){
    token++;
  }
  return token;
}

int count_tokens(char *str){
  int count = 0;
  str = token_start(str);
  count ++;
  while(*str != '\0'){
    if(non_space_char(*str)){
	str++;
   }else{
        count++;
        str = token_start(str);
    }
  }
  return count;
}

char *copy_str(char *inStr, short len){
  char *word = malloc(sizeof(char) * len);
  char *p = word;
  int count = 0;
  while(count != len){
    *p = *inStr;
    inStr++;
    p++;
    count++;
  }
  *p = '\0';
  p -= len;  
  return p;
}

char **tokenize(char *str){ //Going to make use of malloc here to be able to pass around the tokens
  /* int size = count_tokens(str) + 1;
  char **tokens = malloc(sizeof(char*) * size);
  int i = 0;
  int len = count_tokens(str);
  while(i < len){
    str = token_start(str);
    tokens[i] = copy_str(str, token_terminator(str) - str);
    str = token_terminator(str);
    i++;
  }
  tokens[i] = "\0";
  return tokens;
  This version used the array notation, not pointer arithmeitc
  */

  int size = count_tokens(str) +1;
  char ** tokens = malloc(sizeof(char*) * size);
  int len = count_tokens(str);
  int i = 0;
  while(i < len){
    str = token_start(str);
    *tokens = copy_str(str, token_terminator(str) - str);
    str = token_terminator(str);
    i++;
    tokens++;
  }
  *tokens = "\0";
  tokens -= len;
  return tokens;
}

void print_tokens(char **tokens){
  char **copy = tokens;
  while(**copy != '\0'){
    printf("%s\n", *copy);
    copy++;
  }
  
}

void free_tokens(char **tokens){
  int i = 0;
  while(**tokens != '\0'){
    free(*tokens);
    tokens++;
    i++;
  }
  tokens -= i;
  free(tokens);
}



      
      
 
