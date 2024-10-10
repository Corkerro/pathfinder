CC = clang
CFLAGS = -std=c11 -Wall -Wextra -Werror -Wpedantic -I./libmx/inc

LIBS = ./libmx/libmx.a

SRC_DIR = src
OBJ_DIR = obj
SRC = $(shell find $(SRC_DIR) -name '*.c')
OBJ = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC))

TARGET = pathfinder

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

all: libmx $(TARGET)

$(TARGET): $(OBJ)
	$(CC) -o $@ $^ $(LIBS)

libmx:
	$(MAKE) -C libmx

clean: libmx_clean
	rm -rf $(OBJ_DIR) $(TARGET)

libmx_clean:
	$(MAKE) -C libmx clean

.PHONY: all clean libmx libmx_clean
