#include <stdio.h>

#define MAX_TERMS 101    // 다항식 최대차수+1

typedef struct {
    float coef;     // 다항식 항의 계수를 저장
    int expon;      // 다항식 항의 지수를 저장
} term;

typedef struct {
    int num_terms;    // 다항식의 항의 개수
    term terms[MAX_TERMS];  // 다항식의 항 저장
} polynomial;

void print_poly(polynomial p);
polynomial poly_mult(polynomial a, polynomial b);

int main(void) {
    polynomial a = { 4, {{7.0, 6}, {5.0, 3}, {9.0, 2}, {1.0, 0}} }; // 첫번째 항: 7x^6 + 5x^3 + 9x^2 + 1
    polynomial b = { 4, {{5.0, 3}, {2.0, 2}, {1.0, 1}, {10.0, 0}} }; // 두번째 항: 5x^3 + 2x^2 + x^1 + 10
    polynomial c;

 
    print_poly(a);
    print_poly(b);
    printf("--------------------------------------\n");

    c = poly_mult(a, b);   // 곱셈 후 결괏값을 c에 넣음
    print_poly(c);

    return 0;
}

void print_poly(polynomial p) {             // 다항식 출력
    for (int i = 0; i < p.num_terms; i++) {
        if (i == 0)
            printf("%3.1fx^%d", p.terms[i].coef, p.terms[i].expon);
        else
            printf(" + %3.1fx^%d", p.terms[i].coef, p.terms[i].expon);
    }
    printf("\n");
}
//구조체 반환
polynomial poly_mult(polynomial a, polynomial b) {    
    polynomial result = { 0, {0} }; // 결과 다항식 초기화

    for (int i = 0; i < a.num_terms; i++) {
        for (int j = 0; j < b.num_terms; j++) {
            int expon = a.terms[i].expon + b.terms[j].expon;
            float coef = a.terms[i].coef * b.terms[j].coef;

            int k;
            for (k = 0; k < result.num_terms; k++) {
                if (expon == result.terms[k].expon) {
                    result.terms[k].coef += coef;
                    break;
                }
            }
            if (k == result.num_terms) {
                result.terms[result.num_terms].coef = coef;
                result.terms[result.num_terms].expon = expon;
                result.num_terms++;
            }
        }
    }

    return result;
}