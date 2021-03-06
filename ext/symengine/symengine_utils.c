#include "symengine_utils.h"
#include "symengine.h"

void sympify(VALUE operand2, basic_struct *cbasic_operand2) {
    basic_struct *temp;
    VALUE new_operand2, num, den;

    switch(TYPE(operand2)) {
        case T_FIXNUM:
        case T_BIGNUM:
            GET_SYMINTFROMVAL(operand2, cbasic_operand2);
            break;

        case T_RATIONAL:
            num = rb_funcall(operand2, rb_intern("numerator"), 0, NULL);
            den = rb_funcall(operand2, rb_intern("denominator"), 0, NULL);

            basic num_basic, den_basic;
            basic_new_stack(num_basic);
            basic_new_stack(den_basic);

            GET_SYMINTFROMVAL(num, num_basic);
            GET_SYMINTFROMVAL(den, den_basic);

            rational_set(cbasic_operand2, num_basic, den_basic);

            basic_free_stack(num_basic);
            basic_free_stack(den_basic);
            break;

        case T_DATA:
            Data_Get_Struct(operand2, basic_struct, temp);
            basic_assign(cbasic_operand2, temp);
            break;
    }
}

VALUE Klass_of_Basic(const basic_struct *basic_ptr) {
    switch(basic_get_type(basic_ptr)) {
        case SYMENGINE_SYMBOL:
            return c_symbol;
        case SYMENGINE_INTEGER:
            return c_integer;
        case SYMENGINE_RATIONAL:
            return c_rational;
        case SYMENGINE_CONSTANT:
            return c_constant;
        case SYMENGINE_ADD:
            return c_add;
        case SYMENGINE_MUL:
            return c_mul;
        case SYMENGINE_POW:
            return c_pow;
        case SYMENGINE_SIN:
            return c_sin;
        case SYMENGINE_COS:
            return c_cos;
        case SYMENGINE_TAN:
            return c_tan;
        case SYMENGINE_CSC:
            return c_csc;
        case SYMENGINE_SEC:
            return c_sec;
        case SYMENGINE_COT:
            return c_cot;
        case SYMENGINE_ASIN:
            return c_asin;
        case SYMENGINE_ACOS:
            return c_acos;
        case SYMENGINE_ATAN:
            return c_atan;
        case SYMENGINE_ACSC:
            return c_acsc;
        case SYMENGINE_ASEC:
            return c_asec;
        case SYMENGINE_ACOT:
            return c_acot;
        case SYMENGINE_SINH:
            return c_sinh;
        case SYMENGINE_COSH:
            return c_cosh;
        case SYMENGINE_TANH:
            return c_tanh;
        case SYMENGINE_CSCH:
            return c_csch;
        case SYMENGINE_SECH:
            return c_sech;
        case SYMENGINE_COTH:
            return c_coth;
        case SYMENGINE_ASINH:
            return c_asinh;
        case SYMENGINE_ACOSH:
            return c_acosh;
        case SYMENGINE_ATANH:
            return c_atanh;
        case SYMENGINE_ACSCH:
            return c_acsch;
        case SYMENGINE_ASECH:
            return c_asech;
        case SYMENGINE_ACOTH:
            return c_acoth;
        case SYMENGINE_LAMBERTW:
            return c_lambertw;
        case SYMENGINE_DIRICHLET_ETA:
            return c_dirichlet_eta;
        case SYMENGINE_ZETA:
            return c_zeta;
        case SYMENGINE_GAMMA:
            return c_gamma;
        default:
            return c_basic;
    }
}

VALUE function_onearg(void (*cwfunc_ptr)(basic_struct*, const basic_struct*), VALUE operand1) {
    basic_struct *cresult;
    VALUE result;

    basic cbasic_operand1;
    basic_new_stack(cbasic_operand1);
    sympify(operand1, cbasic_operand1);

    cresult = basic_new_heap();
    cwfunc_ptr(cresult, cbasic_operand1);
    result = Data_Wrap_Struct(Klass_of_Basic(cresult), NULL , cbasic_free_heap, cresult);
    basic_free_stack(cbasic_operand1);

    return result;
}

VALUE function_twoarg(void (*cwfunc_ptr)(basic_struct*, const basic_struct*, const basic_struct*),
                      VALUE operand1, VALUE operand2) {
    basic_struct *cresult;
    VALUE result;

    basic cbasic_operand1;
    basic_new_stack(cbasic_operand1);
    sympify(operand1, cbasic_operand1);

    basic cbasic_operand2;
    basic_new_stack(cbasic_operand2);
    sympify(operand2, cbasic_operand2);

    cresult = basic_new_heap();
    cwfunc_ptr(cresult, cbasic_operand1, cbasic_operand2);
    result = Data_Wrap_Struct(Klass_of_Basic(cresult), NULL , cbasic_free_heap, cresult);
    basic_free_stack(cbasic_operand1);
    basic_free_stack(cbasic_operand2);

    return result;
}
