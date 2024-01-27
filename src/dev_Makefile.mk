DEV_FLAGS			:= -Wall -Werror -Wextra -std=c11 -pedantic \
 						-Wnested-externs -Wcast-qual -Wshadow \
 						-Wstrict-prototypes
DEBUG_FLAGS 		:= -g
VALGRIND_FLAGS  	:= --leak-check=full --show-leak-kinds=all --track-origins=yes --log-file=valgrind.log
CC					:= gcc
CFLAGS				:= -Wall -Werror -Wextra -std=c11 -pedantic

FUNC_DIR        := functions
FUNC_COMMON_DIR := ${FUNC_DIR}/common

FUNC_TEST_DIR   	:= tests/
OBJ_DIR        		:= ./
BUILD_DIR			:= ../build/
LIB_HEADER      	:= s21_matrix.h
ifeq ($(shell uname), Linux)
#UBUNTU_FLAGS      	:= -lrt -lsubunit $(shell pkg-config --cflags check) $(shell pkg-config --libs check)
endif
TEST_FLAGS			:= -lcheck -lm -lpthread $(UBUNTU_FLAGS)
GCOV_FLAGS      	:= -fprofile-arcs -ftest-coverage
TEST_DIR_BUILD		:= tests/build/
LIB_STATIC      	:= s21_matrix.a


FUNC_SRCS       := 	$(addprefix $(FUNC_COMMON_DIR)/, s21_common.c ) \
					$(addprefix $(FUNC_DIR)/, s21_calc_complements.c \
					s21_create_matrix.c \
                    s21_determinant.c \
                    s21_eq_matrix.c \
                    s21_inverse_matrix.c \
                    s21_minor.c \
                    s21_mult_matrix.c \
                    s21_mult_number.c \
                    s21_remove_matrix.c \
                    s21_sub_matrix.c \
                    s21_sum_matrix.c \
                    s21_transpose.c)


dev_test_valgrind:
	$(CC) $(FUNC_TEST_DIR)main_test.c -L. $(FUNC_SRCS) $(TEST_FLAGS) $(EXTRA_LIB_FLAGS) $(DEBUG_FLAGS) -o $(TEST_DIR_BUILD)$@.out
	valgrind $(VALGRIND_FLAGS) ./$(TEST_DIR_BUILD)$@.out

dev_manual_test_valgrind:
	$(CC) main.c -L. $(FUNC_SRCS) $(TEST_FLAGS) $(EXTRA_LIB_FLAGS) $(DEBUG_FLAGS) -o $(TEST_DIR_BUILD)$@.out
	valgrind $(VALGRIND_FLAGS) ./$(TEST_DIR_BUILD)$@.out

dev_calc_complements_test:
	$(CC) $(FUNC_TEST_DIR)s21_calc_complements_test.c -L. $(LIB_STATIC) $(TEST_FLAGS) -o $(TEST_DIR_BUILD)$@.out
	./$(TEST_DIR_BUILD)$@.out

dev_calc_complements_test_valgrind:
	$(CC) $(FUNC_TEST_DIR)s21_calc_complements_test.c -L. $(FUNC_SRCS) $(TEST_FLAGS) $(EXTRA_LIB_FLAGS) $(DEBUG_FLAGS) -o $(TEST_DIR_BUILD)$@.out
	valgrind $(VALGRIND_FLAGS) ./$(TEST_DIR_BUILD)$@.out

dev_create_matrix_test:
	$(CC) $(FUNC_TEST_DIR)s21_create_matrix_test.c -L. $(LIB_STATIC) $(TEST_FLAGS) -o $(TEST_DIR_BUILD)$@.out
	./$(TEST_DIR_BUILD)$@.out

dev_create_matrix_test_valgrind:
	$(CC) $(FUNC_TEST_DIR)s21_create_matrix_test.c -L. $(FUNC_SRCS) $(TEST_FLAGS) $(EXTRA_LIB_FLAGS) $(DEBUG_FLAGS) -o $(TEST_DIR_BUILD)$@.out
	valgrind $(VALGRIND_FLAGS) ./$(TEST_DIR_BUILD)$@.out

dev_determinant_test:
	$(CC) $(FUNC_TEST_DIR)s21_determinant_test.c -L. $(LIB_STATIC) $(TEST_FLAGS) -o $(TEST_DIR_BUILD)$@.out
	./$(TEST_DIR_BUILD)$@.out

dev_determinant_test_valgrind:
	$(CC) $(FUNC_TEST_DIR)s21_determinant_test.c -L. $(FUNC_SRCS) $(TEST_FLAGS) $(EXTRA_LIB_FLAGS) $(DEBUG_FLAGS) -o $(TEST_DIR_BUILD)$@.out
	valgrind $(VALGRIND_FLAGS) ./$(TEST_DIR_BUILD)$@.out

dev_eq_matrix_test:
	$(CC) $(FUNC_TEST_DIR)s21_eq_matrix_test.c -L. $(LIB_STATIC) $(TEST_FLAGS) -o $(TEST_DIR_BUILD)$@.out
	./$(TEST_DIR_BUILD)$@.out

dev_eq_matrix_test_valgrind:
	$(CC) $(FUNC_TEST_DIR)s21_eq_matrix_test.c -L. $(FUNC_SRCS) $(TEST_FLAGS) $(EXTRA_LIB_FLAGS) $(DEBUG_FLAGS) -o $(TEST_DIR_BUILD)$@.out
	valgrind $(VALGRIND_FLAGS) ./$(TEST_DIR_BUILD)$@.out

dev_inverse_matrix_test:
	$(CC) $(FUNC_TEST_DIR)s21_inverse_matrix_test.c -L. $(LIB_STATIC) $(TEST_FLAGS) -o $(TEST_DIR_BUILD)$@.out
	./$(TEST_DIR_BUILD)$@.out

dev_inverse_matrix_test_valgrind:
	$(CC) $(FUNC_TEST_DIR)s21_inverse_matrix_test.c -L. $(FUNC_SRCS) $(TEST_FLAGS) $(EXTRA_LIB_FLAGS) $(DEBUG_FLAGS) -o $(TEST_DIR_BUILD)$@.out
	valgrind $(VALGRIND_FLAGS) ./$(TEST_DIR_BUILD)$@.out

dev_mult_matrix_test:
	$(CC) $(FUNC_TEST_DIR)s21_mult_matrix_test.c -L. $(LIB_STATIC) $(TEST_FLAGS) -o $(TEST_DIR_BUILD)$@.out
	./$(TEST_DIR_BUILD)$@.out

dev_mult_matrix_test_valgrind:
	$(CC) $(FUNC_TEST_DIR)s21_mult_matrix_test.c -L. $(FUNC_SRCS) $(TEST_FLAGS) $(EXTRA_LIB_FLAGS) $(DEBUG_FLAGS) -o $(TEST_DIR_BUILD)$@.out
	valgrind $(VALGRIND_FLAGS) ./$(TEST_DIR_BUILD)$@.out

dev_mult_number_test:
	$(CC) $(FUNC_TEST_DIR)s21_mult_number_test.c -L. $(LIB_STATIC) $(TEST_FLAGS) -o $(TEST_DIR_BUILD)$@.out
	./$(TEST_DIR_BUILD)$@.out

dev_mult_number_test_valgrind:
	$(CC) $(FUNC_TEST_DIR)s21_mult_number_test.c -L. $(FUNC_SRCS) $(TEST_FLAGS) $(EXTRA_LIB_FLAGS) $(DEBUG_FLAGS) -o $(TEST_DIR_BUILD)$@.out
	valgrind $(VALGRIND_FLAGS) ./$(TEST_DIR_BUILD)$@.out

dev_remove_matrix_test:
	$(CC) $(FUNC_TEST_DIR)s21_remove_matrix_test.c -L. $(LIB_STATIC) $(TEST_FLAGS) -o $(TEST_DIR_BUILD)$@.out
	./$(TEST_DIR_BUILD)$@.out

dev_remove_matrix_test_valgrind:
	$(CC) $(FUNC_TEST_DIR)s21_remove_matrix_test.c -L. $(FUNC_SRCS) $(TEST_FLAGS) $(EXTRA_LIB_FLAGS) $(DEBUG_FLAGS) -o $(TEST_DIR_BUILD)$@.out
	valgrind $(VALGRIND_FLAGS) ./$(TEST_DIR_BUILD)$@.out

dev_sub_matrix_test:
	$(CC) $(FUNC_TEST_DIR)s21_sub_matrix_test.c -L. $(LIB_STATIC) $(TEST_FLAGS) -o $(TEST_DIR_BUILD)$@.out
	./$(TEST_DIR_BUILD)$@.out

dev_sub_matrix_test_valgrind:
	$(CC) $(FUNC_TEST_DIR)s21_sub_matrix_test.c -L. $(FUNC_SRCS) $(TEST_FLAGS) $(EXTRA_LIB_FLAGS) $(DEBUG_FLAGS) -o $(TEST_DIR_BUILD)$@.out
	valgrind $(VALGRIND_FLAGS) ./$(TEST_DIR_BUILD)$@.out

dev_sum_matrix_test:
	$(CC) $(FUNC_TEST_DIR)s21_sum_matrix_test.c -L. $(LIB_STATIC) $(TEST_FLAGS) -o $(TEST_DIR_BUILD)$@.out
	./$(TEST_DIR_BUILD)$@.out

dev_sum_matrix_test_valgrind:
	$(CC) $(FUNC_TEST_DIR)s21_sum_matrix_test.c -L. $(FUNC_SRCS) $(TEST_FLAGS) $(EXTRA_LIB_FLAGS) $(DEBUG_FLAGS) -o $(TEST_DIR_BUILD)$@.out
	valgrind $(VALGRIND_FLAGS) ./$(TEST_DIR_BUILD)$@.out

dev_transpose_test:
	$(CC) $(FUNC_TEST_DIR)s21_transpose_test.c -L. $(LIB_STATIC) $(TEST_FLAGS) -o $(TEST_DIR_BUILD)$@.out
	./$(TEST_DIR_BUILD)$@.out

dev_transpose_test_valgrind:
	$(CC) $(FUNC_TEST_DIR)s21_transpose_test.c -L. $(FUNC_SRCS) $(TEST_FLAGS) $(EXTRA_LIB_FLAGS) $(DEBUG_FLAGS) -o $(TEST_DIR_BUILD)$@.out
	valgrind $(VALGRIND_FLAGS) ./$(TEST_DIR_BUILD)$@.out