CC              := gcc
CXXFLAGS 		:= -std=c++17 -Wall -Werror -Wextra -Wshadow -Wconversion
CXXCOV 			:=  --coverage
FUNC_DIR        := ./functions
FUNC_TEST_DIR   := ../tests
OBJ_DIR         := temp_obj
LIB_STATIC      := s21_matrix_oop.a
CXX 			:= g++
CHECK_FLAGS		:=

TEST_OUT		:= test.out
TEST_SOURCES = ${FUNC_TEST_DIR}/tests.cc

GCOV_OUT		:= gcov_report.out

ifeq ($(OS), Linux)
	CHECK_FLAGS=-lgtest -lgtest_main -lrt -lm -lstdc++ -pthread -fprofile-arcs -ftest-coverage
else
	CHECK_FLAGS=-lgtest -lgtest_main -lm -lpthread -fprofile-arcs -ftest-coverage -lstdc++
endif


FUNC_SRCS := $(wildcard $(FUNC_DIR)/*.cc)

FUNC_OBJS_WITHOUT_OBJECT_DIRNAME = $(FUNC_SRCS:.c=.o)

FUNC_OBJS := $(patsubst $(FUNC_DIR)/%.cc,$(OBJ_DIR)/%.o,$(FUNC_SRCS))

all: rebuild test gcov_report

$(LIB_STATIC): ${FUNC_OBJS}
	ar rcs $@ $^

build:
	make $(LIB_STATIC)
	@make clean_after_building

rebuild: clean build

${OBJ_DIR}/%.o: ${FUNC_DIR}/%.cc
	@mkdir -p ${OBJ_DIR}
	${CXX} ${CXXFLAGS} -c $< -o $@

test:
ifeq ($(OS), Linux)
	$(CXX) $(CXXFLAGS) $(TEST_SOURCES) $(LIB_STATIC) ${CHECK_FLAGS} --gcov -o ${TEST_OUT}
else
	$(CXX) $(CXXFLAGS) $(TEST_SOURCES) $(LIB_STATIC) ${CHECK_FLAGS}  -o ${TEST_OUT}
endif
	./${TEST_OUT}

test_valgrind:
ifeq ($(OS), Linux)
	$(CXX) $(CXXFLAGS) $(TEST_SOURCES) $(LIB_STATIC) ${CHECK_FLAGS} --gcov -o ${TEST_OUT}
else
	$(CXX) $(CXXFLAGS) $(TEST_SOURCES) $(LIB_STATIC) ${CHECK_FLAGS}  -o ${TEST_OUT}
endif
	valgrind --log-file=valgrind.log ./${TEST_OUT}

gcov_report:
ifeq ($(OS), Linux)
	$(CXX) $(TEST_SOURCES) $(CXXFLAGS) $(CXXCOV) $(FUNC_SRCS) -o ./${GCOV_OUT} -lgtest
else
	$(CXX) $(TEST_SOURCES) $(CXXFLAGS) $(CXXCOV) $(FUNC_SRCS) -o ./${GCOV_OUT} -lgtest
endif
	./${GCOV_OUT}
	lcov -t "gcov_report" --ignore-errors mismatch -c -d . -o report.info
	genhtml report.info -o report
	@open ./report/index.html
	@make clean_gcov
	@make clean_lcov

cppcheck:
	@find .. -type f -name "*.cc" -exec cppcheck --enable=all --suppress=missingIncludeSystem {} \;
	@find .. -type f -name "*.c" -exec cppcheck --enable=all --suppress=missingIncludeSystem {} \;
	@find .. -type f -name "*.h" -exec cppcheck --enable=all --suppress=missingIncludeSystem {} \;
	@echo "Cppcheck is finished"
style:
	@find .. -type f -name "*.cc" -exec clang-format -i -style=Google {} \;
	@echo "Clang format style apply is finished"
style_check:
	@find .. -type f -name "*.cc" -exec clang-format -n -style=Google {} \;
	@echo "Clang format style check is finished"

install_brew:
	@sh ../scripts/install_brew.sh

install_brew_goinfre:
	@sh ../scripts/install_brew_goinfre.sh

clean: clean_project clean_static_lib clean_log clean_exec clean_obj clean_gcov clean_lcov clean_lcov_report
	@echo "Clean finished"

clean_project:

clean_after_building:
	@rm -rf ${OBJ_DIR}
clean_static_lib:
	@find . -type f -name "*.a" -exec rm {} \;
clean_log:
	@find . -type f -name "*.log" -exec rm {} \;
clean_exec:
	@find . -type f -name "*.out" -exec rm {} \;
clean_obj:
	@find . -type f -name "*.o" -exec rm {} \;
clean_gcov:
	@find . -type f -name "*.gcda" -exec rm {} \;
	@find . -type f -name "*.gcno" -exec rm {} \;
clean_lcov:
	@find . -type f -name "*.info" -exec rm {} \;
clean_lcov_report:
	@rm -rf report