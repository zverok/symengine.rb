#ifndef SYMENGINE_H_
#define SYMENGINE_H_

#include "ruby.h"

//variable name for a module starts with m
VALUE m_symengine;

//variable names for classes begin with c
VALUE c_basic;
VALUE c_symbol;
VALUE c_integer;
VALUE c_rational;
VALUE c_constant;
VALUE c_add;
VALUE c_mul;
VALUE c_pow;
VALUE c_function;
VALUE c_trig_function;
VALUE c_hyperbolic_function;
VALUE c_lambertw;
VALUE c_dirichlet_eta;
VALUE c_zeta;
VALUE c_gamma;
VALUE c_sin;
VALUE c_cos;
VALUE c_tan;
VALUE c_csc;
VALUE c_sec;
VALUE c_cot;
VALUE c_asin;
VALUE c_acos;
VALUE c_atan;
VALUE c_acsc;
VALUE c_asec;
VALUE c_acot;
VALUE c_sinh;
VALUE c_cosh;
VALUE c_tanh;
VALUE c_csch;
VALUE c_sech;
VALUE c_coth;
VALUE c_asinh;
VALUE c_acosh;
VALUE c_atanh;
VALUE c_acsch;
VALUE c_asech;
VALUE c_acoth;


#endif //SYMENGINE_H_
