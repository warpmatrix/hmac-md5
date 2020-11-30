BIN_DIR = bin
SRC_DIR = src
INC_DIR = include
BUILD_DIR = build

TARGET = $(BIN_DIR)/md5
SRC = $(wildcard $(SRC_DIR)/*.c)
INCLUDE = -I ./$(INC_DIR)
OBJ = $(SRC:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)
CC = gcc

$(TARGET): $(OBJ)
	@mkdir -p $(BIN_DIR)
	$(CC) $^ -o $(TARGET) -lm

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(BUILD_DIR)
	$(CC) $(INCLUDE) -c $< -o $@

.PHONY: clean
clean:
	@rm -rf $(BUILD_DIR) $(BIN_DIR)
