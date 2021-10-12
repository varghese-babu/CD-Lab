#include<stdio.h>

#include<stdlib.h>

#include<string.h>

char * input;
//int i=0;
char lasthandle[6], stack[50], handles[][7] = {
  ")E(",
  "E*E",
  "E+E",
  "i",
  "E^E",
  "E/E",
  "E-E"
};
//(E) becomes )E( when pushed to stack
int top = -1;
char prec[9][9] = {
                           /*input*/

            /*stack    +    -   *   /   ^   i   (   )   $  */

            /*  + */  '>', '>','<','<','<','<','<','>','>',

            /*  - */  '>', '>','<','<','<','<','<','>','>',

            /*  * */  '>', '>','>','>','<','<','<','>','>',

            /*  / */  '>', '>','>','>','<','<','<','>','>',

            /*  ^ */  '>', '>','>','>','<','<','<','>','>',

            /*  i */  '>', '>','>','>','>','e','e','>','>',

            /*  ( */  '<', '<','<','<','<','<','<','>','e',

            /*  ) */  '>', '>','>','>','>','e','e','>','>',

            /*  $ */  '<', '<','<','<','<','<','<','<','>',

};

int getindex(char c) {
  int i = 1;
  while (c == 'E') {
    c = stack[top - i];
    i++;
  }
  switch (c) {
  case '+':
    return 0;
  case '-':
    return 1;
  case '*':
    return 2;
  case '/':
    return 3;
  case '^':
    return 4;
  case 'i':
    return 5;
  case '(':
    return 6;
  case ')':
    return 7;
  case '$':
    return 8;
  }
}

//int shift()
//{
//stack[++top]=*(input+i++);
//stack[top+1]='\0';
//}

int reduce() {
  int i, len, found, t;
  for (i = 0; i < 7; i++) //selecting handles
  {
    len = strlen(handles[i]);
    if (stack[top] == handles[i][0] && top + 1 >= len) {
      found = 1;
      for (t = 0; t < len; t++) {
        if (stack[top - t] != handles[i][t]) {
          found = 0;
          break;
        }
      }
      if (found == 1) {
        stack[top - t + 1] = 'E';
        top = top - t + 1;
        strcpy(lasthandle, handles[i]);
        stack[top + 1] = '\0';
        return 1; //successful reduction
      }
    }
  }
  return 0;
}

//void dispstack()
//{
//int j;
//for(j=0;j<=top;j++)
//   printf("%c",stack[j]);
//}

void dispinput(int i, int len) {
  int j;
  for (j = i; j < len; j++)
    printf("%c", input[j]);
}

void main() {
  //int j;

  input = (char * ) malloc(50 * sizeof(char));

  int len, i = 0;
  printf("\nEnter the string\n");
  scanf("%s", input);
  strcat(input, "$");
  len = strlen(input);
  //strcpy(stack,"$");
  stack[++top] = '$';
  printf("\nSTACK\tINPUT\tACTION\n");
//   printf("\n%10s %28s %27s", "STACK", "INPUT", "ACTION\n");
  while (i <= len) {
    //shift();
    //printf("\n");
    //dispstack();
    //printf("\t");
    stack[++top] = input[i];
    stack[top + 1] = '\0';
    printf("%s\t", stack);
    dispinput(i + 1, len);
    printf("\tShift\n");
    while (prec[getindex(stack[top])][getindex(input[i + 1])] == '>') {
      if (reduce() == 1) {
        //rintf("\n");
        //dispstack();
        //printf("\t");
        printf("%s\t", stack);
        dispinput(i + 1, len);
        printf("\tReduced: E->%s\n", lasthandle);
      } else {
        break;
      }
    }
    i++;
  }

  if (strcmp(stack, "$E$") == 0)
    printf("\nAccepted");
  else
    printf("\nNot Accepted;");

  printf("\n");
}
