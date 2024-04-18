#include <stdio.h>
#include <string.h>


void parse(char *s){
    int index = 0;
    int in = 0;
    for (int i = 0; i < strlen(s); i++)
    {
        if(s[i] == '<'){
            in = 1;
            continue;
        }else if(s[i] == '>'){
            in = 0;
            continue;
        }
        if(in == 0){
            if(s[i] == ' ' && index == 0){
                continue;
            }else{
                s[index] = s[i];
                index++;
            }
        }
    }
    s[index] = '\0'; 
    while (s[index-1] == ' ')
    {
        s[index-1] = s[index];
        index--;
    }  
}

int main(){
    char string[] = "<h1> This is Heading </h1>";

    parse(string);

    printf("%s.\n",string);

    return 0;
}