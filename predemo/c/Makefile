TOPDIR = .
CROSS_COMPILE:=

CC = $(CROSS_COMPILE)gcc
CPP = $(CROSS_COMPILE)g++
AR = $(CROSS_COMPILE)ar

CFLAGS := -g -Wall -Wextra -fPIC -Ofast -O3 -ffast-math -std=c++11 -lpthread
ARFLAGS := -rcs

ifeq ($(LIBTYPE), muclibc)
	CFLAGS += -muclibc
endif

INCLUDES := -I$(TOPDIR)/../pb_dst/ \
	    -I$(TOPDIR)/../../pb/include/

OBJS := $(TOPDIR)/../pb_dst/Ingenic.Potato.Demo.People.pb.o \
	$(TOPDIR)/src/Pb.Ingenic.Potato.Demo.People.o

ifeq ($(LIBTYPE), muclibc)
	TARGET := ./out/lib/uclibc/libPb.Ingenic.Potato.Demo.People.a
else
	TARGET := ./out/lib/glibc/libPb.Ingenic.Potato.Demo.People.a
endif

%.o:%.c
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ -c $^

%.o:%.cc
	$(CPP) $(CFLAGS) $(INCLUDES) -o $@ -c $^

all:$(TARGET)
	cp -rf include/ out/

$(TARGET):$(OBJS)
	$(shell if [ ! -d "out/lib/glibc" ]; then mkdir -p out/lib/glibc; fi;)
	$(shell if [ ! -d "out/lib/uclibc" ]; then mkdir -p out/lib/uclibc; fi;)
	$(AR) $(ARFLAGS) $@ $^

clean:
	rm -rf $(OBJS) $(TARGET) out/
	find $(TOPDIR) -name "*.[o,a]" | xargs rm -vf
