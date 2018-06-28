CROSS_COMPILE ?= 
PLATFORM_TYPE ?= Linux

CC := $(CROSS_COMPILE)gcc
CPP := $(CROSS_COMPILE)g++
LD := $(CROSS_COMPILE)ld
AR := $(CROSS_COMPILE)ar

CFLAGS := -g -O2 -Wall -lpthread -lrt -ldl -std=c++11 -pthread

ifeq ($(LIBTYPE), muclibc)
	LIBS := -L../pb/lib -lprotobuf \
		-L./c/out/lib/uclibc -lPb.Ingenic.Sputnik

else
	LIBS := -L./c/out/lib/glibc -lPb.Ingenic.Sputnik\
		-L../pb/lib -lprotobuf
endif

INCLUDE := -I./c/include

OBJS := ./display_plate.o \

TARGET := display_plate

All: $(TARGET)

%.o:%.c
	$(CPP) $(CFLAGS) $(INCLUDE) $(LIBS) -o $@ -c $^

%.o:%.cc
	$(CPP) $(CFLAGS) $(INCLUDE) $(LIBS) -o $@ -c $^

$(TARGET):$(OBJS)
	$(CPP) $(CFLAGS) $(OBJS) -o $@ $(INCLUDES) $(LIBS)

clean:
	rm -f $(TARGET) $(OBJS)
