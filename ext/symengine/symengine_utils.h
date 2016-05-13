#ifndef SYMENGINE_MACROS_H_
#define SYMENGINE_MACROS_H_

#include "ruby.h"
#include "ruby_basic.h"
#include "symengine/cwrapper.h"

//Returns the pointer wrapped inside the Ruby VALUE
void sympify(VALUE operand2, basic_struct *cbasic_operand2);
//Returns the Ruby class of the corresponding basic_struct pointer
VALUE Klass_of_Basic(const basic_struct *basic_ptr);
//Returns the result from the function pointed by cwfunc_ptr: for one argument functions
VALUE function_onearg(void (*cwfunc_ptr)(basic_struct*, const basic_struct*), VALUE operand1);
//Returns the result from the function pointed by cwfunc_ptr: for two argument functions
VALUE function_twoarg(void (*cwfunc_ptr)(basic_struct*, const basic_struct*, const basic_struct*),
                      VALUE operand1, VALUE operand2);

//Obtains the value from Ruby Fixnum or Bignum to an already allocated basic_struct
#define GET_SYMINTFROMVAL(num_value, this) { \
    if ( ! RB_TYPE_P(num_value, T_FIXNUM) && ! RB_TYPE_P(num_value, T_BIGNUM) ) { \
        rb_raise(rb_eTypeError, "Invalid Type: Fixnum or Bignum required"); \
    } \
    VALUE Rb_Temp_String = rb_funcall(num_value, rb_intern("to_s"), 0, NULL); \
    integer_set_str(this, StringValueCStr(Rb_Temp_String)); \
    }

#endif //SYMENGINE_MACROS_H_
