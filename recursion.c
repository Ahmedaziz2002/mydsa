/*recursion is a process in which a function calls itself*/
#include<stdio.h>
int fun(int n)
{
    if(n==0)/*base case*/{
        return 1;
    }
    else
    return 7 + fun(n-2);/*recursive case*/
}
int main(){
    printf("%d", fun(4));/*indirect recursion where function B calls function A*/
    return 0;
}
/*
fun 4 returns 7 +fun (4-2=2)
fun 2 returns 7 +fun (2-2=0)
fun 0 returns 1
so fun 0=1
fun 2=7+fun 0>1=8
fun 4=7 +fun 2 which is 8=15
therefore fun 4 =15


*/

int fun(int n)
{
    if(n==1)
    return 1;
    else
    return 1 + fun(n-1);
}
int main(){
    int n=3;
    printf("%d",fun(n));
    return 0;
}#include<stdio.h>
int hey(int h){
    if(h==1){
        return 1;
    }
    else{
        return h * hey(h-1);
    }
}
int main(){
    int h=5;
    printf("%d",hey(h));
    return 0;
}#include<stdio.h>
void print_original(char*str){
    if(*str=='\0')
    return;
    else
    print_original(str +1);
    printf("%c",*str);
}
int main(){
    char test_string[]="sally";
    print_original(test_string);
    return 0;
}