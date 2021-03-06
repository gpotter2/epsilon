SFLAGS += -Ipoincare/include

#include poincare/src/simplify/Makefile

objs += $(addprefix poincare/src/,\
  absolute_value.o\
  addition.o\
  arc_cosine.o\
  arc_sine.o\
  arc_tangent.o\
  binary_operation.o\
  binomial_coefficient.o\
  ceiling.o\
  complex.o\
  complex_argument.o\
  complex_matrix.o\
  confidence_interval.o\
  conjugate.o\
  cosine.o\
  derivative.o\
  determinant.o\
  division_quotient.o\
  division_remainder.o\
  evaluation.o\
  expression.o\
  expression_lexer.o\
  expression_parser.o\
  factorial.o\
  floor.o\
  frac_part.o\
  fraction.o\
  function.o\
  expression_matrix.o\
  global_context.o\
  great_common_divisor.o\
  hyperbolic_arc_cosine.o\
  hyperbolic_arc_sine.o\
  hyperbolic_arc_tangent.o\
  hyperbolic_cosine.o\
  hyperbolic_sine.o\
  hyperbolic_tangent.o\
  imaginary_part.o\
  integer.o\
  integral.o\
  list_data.o\
  leaf_expression.o\
  least_common_multiple.o\
  logarithm.o\
  matrix.o\
  matrix_data.o\
  matrix_dimension.o\
  matrix_inverse.o\
  matrix_trace.o\
  matrix_transpose.o\
  multiplication.o\
  naperian_logarithm.o\
  nth_root.o\
  opposite.o\
  parenthesis.o\
  permute_coefficient.o\
  power.o\
  prediction_interval.o\
  preferences.o\
  product.o\
  real_part.o\
  round.o\
  sequence.o\
  sine.o\
  square_root.o\
  store.o\
  subtraction.o\
  sum.o\
  symbol.o\
  tangent.o\
  variable_context.o\
)
objs += $(addprefix poincare/src/layout/,\
  baseline_relative_layout.o\
  bracket_layout.o\
  condensed_sum_layout.o\
  conjugate_layout.o\
  expression_layout.o\
  fraction_layout.o\
  grid_layout.o\
  horizontal_layout.o\
  integral_layout.o\
  nth_root_layout.o\
  parenthesis_layout.o\
  product_layout.o\
  sequence_layout.o\
  string_layout.o\
  sum_layout.o\
)

tests += $(addprefix poincare/test/,\
  addition.cpp\
  complex.cpp\
  fraction.cpp\
  function.cpp\
  helper.cpp\
  integer.cpp\
  matrix.cpp\
  parser.cpp\
  product.cpp\
  power.cpp\
  subtraction.cpp\
  symbol.cpp\
  trigo.cpp\
)

# tests += $(addprefix poincare/test/,\
  addition.cpp\
  float.cpp\
  fraction.cpp\
  identity.cpp\
  integer.cpp\
  matrix.cpp\
  product.cpp\
  power.cpp\
  simplify_utils.cpp\
  simplify_addition.cpp\
  simplify_product.cpp\
  subtraction.cpp\
  trigo.cpp\
)

ifdef POINCARE_TESTS_PRINT_EXPRESSIONS
tests += poincare/src/expression_debug.o
SFLAGS += -DPOINCARE_TESTS_PRINT_EXPRESSIONS=1
endif

# Even though flex and bison will generate both implementation and headers at
# once, we don't declare it in the Makefile. If we did, "make -jN" with N>1 may
# call bison or flex twice.

lexer_files = $(addprefix poincare/src/, expression_lexer.cpp expression_lexer.hpp)
poincare/src/expression_lexer.hpp: poincare/src/expression_lexer.cpp
poincare/src/expression_lexer.cpp: poincare/src/expression_lexer.l
	@echo "FLEX    $(lexer_files)"
	@flex -P poincare_expression_yy --header-file=poincare/src/expression_lexer.hpp -o poincare/src/expression_lexer.cpp $<

poincare/src/expression_lexer.o: CXXFLAGS += -Wno-deprecated-register -Wno-unused-value -Wno-unused-function

parser_files = $(addprefix poincare/src/, expression_parser.cpp expression_parser.hpp)
poincare/src/expression_parser.hpp: poincare/src/expression_parser.cpp
poincare/src/expression_parser.cpp: poincare/src/expression_parser.y
	@echo "BISON   $(parser_files)"
	@bison -d -p poincare_expression_yy -o poincare/src/expression_parser.cpp $<

poincare/src/expression.cpp: $(lexer_files) $(parser_files)

products += $(lexer_files) $(parser_files)
