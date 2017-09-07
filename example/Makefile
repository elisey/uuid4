CC = gcc
CFLAGS = -Wall -Wextra $(INCLUDE_DIR)
LDFLAGS =
RM = rm -f

SRCS = 		example.c \
			../src/uuid4.c

OBJS = $(SRCS:.c=.o)

INCLUDE_DIR=	-I../src/ \

APP = example.out

.PHONY: all
all: $(OBJS)
	$(CC) $(INCLUDE_DIR) -Wall -o $(APP) $(SRCS)

$(SRCS:.c=.d):%.d:%.c
	$(CC) $(CFLAGS) -MM $< >$@

.PHONY: run
run: all
	./$(APP)

.PHONY: clean
clean:
	$(RM) $(OBJS) $(APP)
