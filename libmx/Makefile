# Визначення змінних
CC = clang
CFLAGS = -std=c11 -Wall -Wextra -Werror -Wpedantic
OBJ_DIR = obj
LIB_NAME = libmx.a

# Створення директорії obj
$(shell mkdir -p $(OBJ_DIR))

# Список вихідних файлів (.c) у каталозі src
SRCS = $(wildcard src/*.c)

# Створення імен .o файлів з .c файлів
OBJS = $(patsubst src/%.c,$(OBJ_DIR)/%.o,$(SRCS))

# Ціль за замовчуванням
all: $(LIB_NAME)

# Ціль для створення статичної бібліотеки
$(LIB_NAME): $(OBJS)
	ar rcs $@ $^

# Правило для компіляції .c файлів у .o файли
$(OBJ_DIR)/%.o: src/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c -o $@ $<

# Створення директорії obj
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Видалення всіх згенерованих файлів
.PHONY: clean
clean:
	rm -f $(LIB_NAME) $(OBJ_DIR)/*.o
	rmdir $(OBJ_DIR) || true  # Удаление каталога obj, если он пустой
