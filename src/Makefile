CC              := gcc
CFLAGS 			:= -Wall -Werror -Wextra -std=c11
FUNC_DIR        := functions
FUNC_COMMON_DIR := ${FUNC_DIR}/common
FUNC_TEST_DIR   := tests/
OBJ_DIR         := ./
BUILD_DIR		:= ../build/
LIB_HEADER      := s21_decimal.h
GCOV_FLAGS      := -fprofile-arcs -ftest-coverage
TEST_DIR_BUILD	:= tests/build/
LIB_STATIC      := s21_matrix.a

ifeq ($(shell head -n 1 /etc/lsb-release), DISTRIB_ID=Ubuntu)
UBUNTU_FLAGS      	:= -lrt -lsubunit $(shell pkg-config --cflags check) $(shell pkg-config --libs check)
endif

TEST_FLAGS      := -lcheck -lm -lpthread $(UBUNTU_FLAGS)



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

FUNC_OBJS_WITHOUT_OBJECT_DIRNAME = $(FUNC_SRCS:.c=.o)
FUNC_OBJS = $(subst $(FUNC_DIR), $(OBJ_DIR), $(FUNC_OBJS_WITHOUT_OBJECT_DIRNAME))

$(LIB_STATIC):$(FUNC_SRCS)
	mkdir tests/build
	$(CC) $(CFLAGS) -c $(FUNC_SRCS)
	ar -rcs $@ *.o
	make clean_obj

all: rebuild

build:
	make $(LIB_STATIC)

rebuild: clean build

cppcheck_check:
	cppcheck --enable=all --suppress=missingIncludeSystem *.c *.h ./*/*.c ./*/*.h ./*/*/*.c ./*/*/*.h
check:
	clang-format -n -style=Google  *.c *.h ./*/*.c ./*/*.h ./*/*/*.c ./*/*/*.h
clang_format:
	clang-format -i -style=Google  *.cpp *.h ./*/*.cpp ./*/*.h ./*/*/*.cpp ./*/*/*.h


gcov_report:
	mkdir report
	gcc tests/main_test.c $(FUNC_SRCS) $(CFLAGS) $(TEST_FLAGS) $(GCOV_FLAGS) -o ./$@.out
	./$@.out
	lcov -t "test" -o test.info -c -d .
	genhtml -o report/ test.info
	open ./report/index.html

test:
	gcc tests/main_test.c $(LIB_STATIC) $(CFLAGS) $(TEST_FLAGS)  -o ./test.out
	./test.out

install_brew:
	cd ~
	curl -fsSL https://rawgit.com/kube/42homebrew/master/install.sh | zsh

install_brew_goinfre: # be careful with this!
	cd ~/goinfre
	mkdir homebrew && curl -L https://github.com/Homebrew/brew/tarball/master | tar xz --strip 1 -C homebrew

install_lcov:
	brew install lcov

clean:
	make clean_silent --silent

clean_silent:
	rm -rf "__.SYMDEF SORTED"
	rm -rf ../*/*.o
	rm -rf ../*/*.out
	rm -rf ../*/*.info
	rm -rf ../*/*.a
	rm -rf ../*/*.g*
	rm -rf ../*/*/*.o
	rm -rf ../*/*/*.out
	rm -rf ../*/*/*.info
	rm -rf ../*/*/*.a
	rm -rf ../*/*/*.g*
	rm -rf ../*/*/*/*.o
	rm -rf ../*/*/*/*.out
	rm -rf ../*/*/*/*.info
	rm -rf ../*/*/*/*.a
	rm -rf ../*/*/*/*.g*
	rm -rf ./object_files
	rm -rf ./tests/build
	rm -rf ./report
	rm -rf ./*.log

dev_%:
	make -f dev_Makefile.mk $@

clean_obj :
	rm -f *.o

clean_after_gcov:
	rm -rf ../*.g*
	rm -rf ../*/*.g*
	rm -rf ../*/*/*.g*
	rm -rf ../*/*/*/*.g*
