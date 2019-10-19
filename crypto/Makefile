BUILD_DIR = ./build
TARGET=hsh

SRCS=	crypto/sha256.c

OBJS = $(SRCS:%.c=$(BUILD_DIR)/%.o)
DEPS=$(OBJS:%.o=%.d)
CFLAGS=-Wall -Werror -Wextra, -pedantic -I. -I./crypto
LFLAGS=-lssl -lcrypto
RM=rm -f

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC)  $(CFLAGS) $(INCLUDES) -o $(TARGET) $(OBJS) $(LFLAGS) $(LIBS)

-include $(DEPS)

$(BUILD_DIR)/%.o : %.c
	mkdir -p $(@D)
	$(CC) $(CFLAGS) -MMD -c $< -o $@

.PHONY : clean
clean:
	$(RM) $(OBJS) $(DEPS) $(TARGET) vgcore*
	$(RM) -r $(BUILD_DIR)

.PHONY	: re
re	: clean all