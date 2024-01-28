CC              := gcc
CXXFLAGS 		:= -std=c++17 #-Wall -Werror -Wextra -Wshadow -Wconversion
CXXCOV 			:= --coverage
FUNC_DIR        := ./functions
FUNC_TEST_DIR   := ../tests
OBJ_DIR         := temp_obj
LIB_STATIC      := s21_matrix_oop.a
CXX 			:= g++

TEST_SOURCES = ${FUNC_TEST_DIR}/tests.cc

FUNC_SRCS := $(wildcard $(FUNC_DIR)/*.cc)

FUNC_OBJS_WITHOUT_OBJECT_DIRNAME = $(FUNC_SRCS:.c=.o)

FUNC_OBJS := $(patsubst $(FUNC_DIR)/%.cc,$(OBJ_DIR)/%.o,$(FUNC_SRCS))

$(LIB_STATIC): ${FUNC_OBJS}
	ar rcs $@ $^
	rm -rf ${OBJ_DIR}


all: rebuild

build:
	make $(LIB_STATIC)

rebuild: clean build

${OBJ_DIR}/%.o: ${FUNC_DIR}/%.cc
	-@mkdir  ${OBJ_DIR}
	${CXX} ${CXXFLAGS} -c $< -o $@

test:
ifeq ($(OS), Linux)
	$(CXX) $(CXXFLAGS) $(TEST_SOURCES) $(LIB_STATIC) -o test.out -lgtest
else
	$(CXX) $(CXXFLAGS) $(TEST_SOURCES) $(LIB_STATIC) -o test.out -lgtest
endif
	./test.out

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
	rm -f test
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
