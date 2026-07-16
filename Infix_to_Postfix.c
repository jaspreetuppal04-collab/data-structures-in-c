#include <stdio.h>
#include <string.h>
#define MAX 50

char s[MAX]; 
int top = -1;

void push(char c){ 
    s[++top] = c; 
}

char pop(){ 
    return s[top--]; 
}

// Function to return precedence of operators
int precedence(char op) {
    if(op=='+' || op=='-') return 1;
    if(op=='*' || op=='/') return 2;
    if(op=='^') return 3;
    return 0;
}

int main(){
    char in[MAX], post[MAX] = "", st[MAX]; 
    int step = 1; 
    
    printf("Enter infix expression: ");
    scanf("%s", in);

    printf("\nStep Symbol Stack   Postfix\n");
    printf("-----------------------------\n");

    for(int i = 0; i < strlen(in); i++){
        char c = in[i];

        // Case 1: Operand
        if((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9')){
            int l = strlen(post); 
            post[l] = c; 
            post[l+1] = '\0';
        }
        // Case 2: Left parenthesis
        else if(c == '(') {
            push(c);
        }
        // Case 3: Right parenthesis
        else if(c == ')'){
            while(top != -1 && s[top] != '('){
                int l = strlen(post); 
                post[l] = pop(); 
                post[l+1] = '\0';
            }
            pop(); // remove '('
        }
        // Case 4: Operator
        else {
            while(top != -1 && precedence(s[top]) >= precedence(c)){
                int l = strlen(post);
                post[l] = pop();
                post[l+1] = '\0';
            }
            push(c);
        }

        // prepare stack snapshot
        int k = 0;
        if(top == -1){ 
            st[0] = '-'; st[1] = '\0'; 
        }
        else{ 
            for(int j = 0; j <= top; j++) st[k++] = s[j]; 
            st[k] = '\0'; 
        }

        printf("%-4d %-6c %-7s %-7s\n", step++, c, st, post);
    }

    // Pop any remaining operators
    while(top != -1){
        int l = strlen(post);
        post[l] = pop();
        post[l+1] = '\0';
    }

    printf("\nPostfix: %s\n", post);
    return 0;
}
