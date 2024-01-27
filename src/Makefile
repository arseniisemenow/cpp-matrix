CC              := gcc
CXXFLAGS 		:= -std=c++17 #-Wall -Werror -Wextra -Wshadow -Wconversion
CXXCOV 			:= --coverage
FUNC_DIR        := ./functions
FUNC_TEST_DIR   := ../tests
OBJ_DIR         := ./functions
LIB_STATIC      := s21_matrix_oop.a
CXX 			:= g++

TEST_SOURCES = ${FUNC_TEST_DIR}/tests.cc

FUNC_SRCS       := 	$(addprefix $(FUNC_DIR)/, \
					s21_calc_complements.cc \
					s21_create_matrix.cc \
                    s21_determinant.cc \
                    s21_eq_matrix.cc \
                    s21_inverse_matrix.cc \
                    s21_minor.cc \
                    s21_mult_matrix.cc \
                    s21_mult_number.cc \
                    s21_remove_matrix.cc \
                    s21_sub_matrix.cc \
                    s21_sum_matrix.cc \
                    s21_transpose.cc)

FUNC_OBJS_WITHOUT_OBJECT_DIRNAME = $(FUNC_SRCS:.c=.o)
FUNC_OBJS = $(subst $(FUNC_DIR), $(OBJ_DIR), $(FUNC_OBJS_WITHOUT_OBJECT_DIRNAME))

$(LIB_STATIC):$(FUNC_SRCS)
	$(CXX) $(CXXFLAGS) -c $(FUNC_SRCS)
	ar rcs s21_matrix_oop.a $(FUNC_OBJS)

all: rebuild

build:
	make $(LIB_STATIC)

test:
ifeq ($(OS), Linux)
	$(CXX) $(CXXFLAGS) $(TEST_SOURCES) $(LIB_SOURCES) -o test -lgtest
else
	$(CXX) $(CXXFLAGS) $(TEST_SOURCES) $(LIB_SOURCES) -o test -lgtest
endif
	./test

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

#test:
#	gcc tests/main_test.c $(LIB_STATIC) $(CFLAGS) $(TEST_FLAGS)  -o ./test.out
#	./test.out

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
