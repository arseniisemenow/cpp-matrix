CC              := gcc
CXXFLAGS 		:= -std=c++17 #-Wall -Werror -Wextra -Wshadow -Wconversion
CXXCOV 			:= --coverage
FUNC_DIR        := ./functions
FUNC_TEST_DIR   := ../tests
OBJ_DIR         := temp_obj
LIB_STATIC      := s21_matrix_oop.a
CXX 			:= g++
CHECK_FLAGS		:=

ifeq ($(OS), Linux)
	CHECK_FLAGS=-lgtest -lgtest_main -lrt -lm -lstdc++ -pthread -fprofile-arcs -ftest-coverage
else
	CHECK_FLAGS=-lgtest -lgtest_main -lm -lpthread -fprofile-arcs -ftest-coverage -lstdc++
endif

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
	@mkdir -p ${OBJ_DIR}
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
	$(CC) $(CXXFLAGS) $(FUNC_SRCS) $(CHECK_FLAGS) -lgcov --coverage -o ./gcov_report.out
	./gcov_report.out
	lcov -t "gcov_report" --ignore-errors mismatch --no-external -c -d . -o report.info
	genhtml report.info -o report
	open ./report/index.html

install_brew:
	cd ~ # cd command can't be executed inside Makefile!
	curl -fsSL https://rawgit.com/kube/42homebrew/master/install.sh | zsh

install_brew_goinfre:
	cd ~/goinfre # cd command can't be executed inside Makefile!
	mkdir homebrew && curl -L https://github.com/Homebrew/brew/tarball/master | tar xz --strip 1 -C homebrew

install_lcov:
	brew install lcov


clean:
	rm -rf report
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
