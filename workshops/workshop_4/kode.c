#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int isPrime(int x);
int isGcd1(int x);
int is2mod5(int x);
int modulo_pow(int base, int exponent, int modulo);
void swap(int* a, int* b);
int gcd(int a, int b);

int main(void){
    int x;
    int p, q, r;

    /*printf("Hvilket heltal vil du tjekke?\n");
    scanf("%d", &x);
    printf("x er %d\n", x);*/

    for (x = 100000; x <= 1000000; x++) {
        p = isPrime(x);
        q = isGcd1(x);
        r = is2mod5(x);

        if ((p && !r) || !(p || !q || r) || (!p && !q && r)){
            printf("Du fandt et x\n");
            printf("p er %d, q er %d, and r er %d og x er %d\n", p,q,r,x);
        }
    }

    return 0;
}

/* Denne funktion skal returnere 1 hvis x er et primtal og 0 ellers */
int isPrime(int x){
    int res = 1;
    int max = (int) sqrt(x);
    if (x % 2 == 0) {
        res = 0;
    } else {
        int i;
        for (i = 3; i <= max; i+=2) {
            if (x % i == 0) res = 0;
        }
    }
    return res;
}

/* Denne funktion skal returnere 1 hvis gcd(x,2)=1 og 0 ellers */
int isGcd1(int x){
    return gcd(x, 2) == 1 ? 1 : 0;
}

/* swap the values of a and b with pointers */
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

/* find the gcd of a and b */
int gcd(int a, int b) {
    int remainder;

    /* if a is bigger than b then swap their values */
    if (a > b) {
        swap(&a, &b);
    }

    /* run the algorithm to find gcd */
    while (a > 0){
        remainder = b % a;
        b = a;
        a = remainder;
    }
    
    /* return gcd */
    return b;
}

/* Denne funktion skal returnere 1 hvis 9^x-2 mod 5 = 2 og 0 ellers */ 
int is2mod5(int x){
    return (modulo_pow(9, x, 5) == 4) ? 1 : 0; 
}

int modulo_pow(int base, int exponent, int modulo) {
    if (modulo == 1) return 0;
    int c = 1;
    int e_prime = 0;
    for (;;) {
        e_prime++;
        c = (base * c) % modulo;
        if (e_prime >= exponent) return c;
    }
}
