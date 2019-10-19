# -----------------------------------------------------------------------------
# COMMON
# -----------------------------------------------------------------------------

CFLAGS=-Wall -Werror -Wextra -pedantic -I. -g3

LFLAGS=-lssl -lcrypto

RM=rm -f

BUILD_DIR      = ./build

$(BUILD_DIR)/%.o : %.c
	mkdir -p $(@D)
	$(CC) $(CFLAGS) -MMD -c $< -o $@

# ------------------------------------------
# Shared library
# ------------------------------------------
TARGET= blockchain
SRCS = sha256.c

OBJS = $(SRCS:%.c=$(BUILD_DIR)/%.o)
DEPS = $(OBJS:%.o=%.d)

-include $(DEPS)

$(TARGET): $(OBJS)
	ar -rc lib$@.a $(OBJS)

# ------------------------------------------
# Tests
# ------------------------------------------

SRCS_TESTS=$(wildcard test/*.c)
OBJS_TESTS=$(SRCS_TESTS:%.c=$(BUILD_DIR)/%.o)
DEPS_TESTS=$(OBJS_TESTS:%.o=%.d)

-include $(DEPS_TESTS)


$(OBJS_TESTS): $(SRCS_TESTS)
	mkdir -p $(@D)
	gcc $^ $(CFLAGS) -l$(TARGET) -L. -o $@


all: $(OBJS_TESTS) $(TARGET) 



.PHONY : clean
clean:
	$(RM) $(OBJS) $(DEPS) $(TARGET) $(TESTS) vgcore*
	$(RM) -r $(BUILD_DIR)

.PHONY	: re
re	: clean all