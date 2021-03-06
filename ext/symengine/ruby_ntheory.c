#include "ruby_ntheory.h"

VALUE cntheory_nextprime(VALUE self, VALUE operand1) {
    return function_onearg(ntheory_nextprime, operand1);
}

VALUE cntheory_gcd(VALUE self, VALUE operand1, VALUE operand2) {
    return function_twoarg(ntheory_gcd, operand1, operand2);
}

VALUE cntheory_lcm(VALUE self, VALUE operand1, VALUE operand2) {
    return function_twoarg(ntheory_lcm, operand1, operand2);
}

VALUE cntheory_mod(VALUE self, VALUE operand2) {
    VALUE ans = function_twoarg(ntheory_mod, self, operand2);
    VALUE ans1 = cbasic_add(ans, operand2);
    return function_twoarg(ntheory_mod, ans1, operand2);
}

VALUE cntheory_quotient(VALUE self, VALUE operand1, VALUE operand2) {
    return function_twoarg(ntheory_quotient, operand1, operand2);
}

VALUE cntheory_fibonacci(VALUE self, VALUE operand1){
    basic_struct *cresult;
    VALUE result;

    unsigned long cbasic_operand1;
    cbasic_operand1 = NUM2ULONG(operand1);

    cresult = basic_new_heap();
    ntheory_fibonacci(cresult, cbasic_operand1);
    result = Data_Wrap_Struct(Klass_of_Basic(cresult), NULL , cbasic_free_heap, cresult);

    return result;
}

VALUE cntheory_lucas(VALUE self, VALUE operand1){
    basic_struct *cresult;
    VALUE result;

    unsigned long cbasic_operand1;
    cbasic_operand1 = NUM2ULONG(operand1);

    cresult = basic_new_heap();
    ntheory_lucas(cresult, cbasic_operand1);
    result = Data_Wrap_Struct(Klass_of_Basic(cresult), NULL , cbasic_free_heap, cresult);

    return result;
}

VALUE cntheory_binomial(VALUE self, VALUE operand1, VALUE operand2){
    basic_struct *cresult;
    VALUE result;

    basic cbasic_operand1;
    basic_new_stack(cbasic_operand1);
    sympify(operand1, cbasic_operand1);

    unsigned long cbasic_operand2;
    cbasic_operand2 = NUM2ULONG(operand2);

    cresult = basic_new_heap();
    ntheory_binomial(cresult, cbasic_operand1, cbasic_operand2);
    result = Data_Wrap_Struct(Klass_of_Basic(cresult), NULL , cbasic_free_heap, cresult);
    basic_free_stack(cbasic_operand1);

    return result;
}
