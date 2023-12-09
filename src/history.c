#include "stdio.h"
#include "stdlib.h"
#include "history.h"
#include "tokenizer.h"

List *init_history(){
  Item root;             //Creating the root of the linked list and giving it ID 0
  root.id = 0;
  root.str = "Start of Linked List\n";
  Item *pointer = malloc(sizeof(struct s_Item));
  *pointer = root;        //Creating a pointer to the root
  List list;
  list.root = pointer; //Initializing list by giving it the pointer to the root
  List *linkedlist = malloc(sizeof(struct s_List));
  *linkedlist = list;
  return linkedlist;
}

void add_history(List *list, char *str){
  Item *copy = list->root;
  Item node;
  int id;
  while(copy->next != NULL){
    copy = copy->next;
  }
  node.id = copy->id +1;
  //segment for counting length of string
  int i = 0;
  while(*str != '\0'){
    i++;
    str++;
  }
  str -= i;
  //segment for counting length of string
  node.str = copy_str(str, i);
  copy->next = malloc(sizeof(struct s_Item));
  *(copy->next) = node;
  // printf("Successfully created ID Number %d for string %s", node.id, node.str);
}


char *get_history(List *list, int id){
  //puts("Entering get_history");
  Item *copy = list->root;
  while(copy->id != id){
    if(copy->next != NULL){
      copy = copy->next;
    }
    else {
      return "Not a valid ID";
    }
  }
  return copy->str;
}

void print_history(List *list){
  Item *copy = list->root;
  copy = copy->next;
  if(copy == NULL){
    puts("There is nothing in the history");
  }
  else{
    while(copy->next != NULL){
      printf("ID %d: %s", copy->id, copy->str);
      copy = copy->next;
    }
    printf("ID %d: %s", copy->id, copy->str);
  }
}

void free_history(List *list){
  while(list->root->next != NULL){
   Item *next = list->root->next;
   free(list->root);
   list->root = next;
  }
  free(list);
}
