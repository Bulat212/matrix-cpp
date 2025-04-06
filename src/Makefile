CC = g++
CFLAGS = -std=c++20 -Wall -Wextra -Werror -pedantic
LDFLAGS = -lgtest -lgtest_main -lpthread
GCOV_FLAGS = --coverage

SRC_DIR = .
TEST_DIR = tests
OBJ_DIR = obj
LIB_NAME = s21_matrix_oop.a

SRC = $(wildcard $(SRC_DIR)/*.cc)
OBJ = $(patsubst $(SRC_DIR)/%.cc,$(OBJ_DIR)/%.o,$(SRC))
TEST_SRC = $(wildcard $(TEST_DIR)/*.cc)
TEST_NAME = s21_matrix_test

.PHONY: all clean test gcov_report

all: $(LIB_NAME)

$(LIB_NAME): $(OBJ)
	ar rcs $@ $^
	ranlib $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cc
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

test: $(LIB_NAME) $(TEST_NAME)
	./$(TEST_NAME)

$(TEST_NAME): $(TEST_SRC) $(LIB_NAME)
	$(CC) $(CFLAGS) $(TEST_SRC) $(LIB_NAME) -o $@ $(LDFLAGS)

gcov_report: $(TEST_SRC) $(SRC)
	$(CC) $(CFLAGS) $(GCOV_FLAGS) $(SRC) $(TEST_SRC) -o $(TEST_NAME) $(LDFLAGS)
	./$(TEST_NAME)
	lcov --capture --directory . --output-file coverage.info --no-external --ignore-errors mismatch
	lcov --remove coverage.info '*/tests/*' '*/usr/*' -o filtered.info --ignore-errors unused
	genhtml filtered.info --output-directory coverage_report

clean:
	rm -rf $(OBJ_DIR) $(LIB_NAME) $(TEST_NAME) coverage* gcov_test *.gcda *.gcno *.info a.out