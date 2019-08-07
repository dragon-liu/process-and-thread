
TARGETDIR=target
CC := gcc

APP=$(TARGETDIR)/main
SOUR=main.c my_thread.c

CFLAGS=-pthread

ifeq ($(DEBUG),1)
CFLAGS+=-g -O0
else
CFLAGS+=-O2
endif

CFLAGS+=-DTHREAD_NUM=$(THREAD_NUM)


all: prepare $(APP)

prepare:
	mkdir -p $(TARGETDIR)

$(APP): main.c my_thread.h my_thread.c
	gcc $(CFLAGS) -o $(APP) $(SOUR)

clean:
	rm -rf $(TARGETDIR)

