TOPDIR = .
CROSS_COMPILE:=

CC = $(CROSS_COMPILE)gcc
CPP = $(CROSS_COMPILE)g++
AR = $(CROSS_COMPILE)ar

CFLAGS := -g -Wall -Wextra -fPIC -Ofast -O3 -ffast-math -std=c++11 -lpthread -Wunused-parameter
ARFLAGS := -rcs

ifeq ($(LIBTYPE), muclibc)
	CFLAGS += -muclibc
endif

INCLUDES := -I$(TOPDIR)/../pb_dst/ \
	    -I$(TOPDIR)/../../pb/include/ \
	    -I$(TOPDIR)/include/

OBJS := $(TOPDIR)/../pb_dst/box.pb.o \
	$(TOPDIR)/../pb_dst/cluster.pb.o \
	$(TOPDIR)/../pb_dst/cluster_query.pb.o \
	$(TOPDIR)/../pb_dst/cluster_reply.pb.o \
	$(TOPDIR)/../pb_dst/direction.pb.o \
	$(TOPDIR)/../pb_dst/face_attribute.pb.o \
	$(TOPDIR)/../pb_dst/face_file.pb.o \
	$(TOPDIR)/../pb_dst/face_reply.pb.o \
	$(TOPDIR)/../pb_dst/face_request.pb.o \
	$(TOPDIR)/../pb_dst/file_reply.pb.o \
	$(TOPDIR)/../pb_dst/file_request.pb.o \
	$(TOPDIR)/../pb_dst/frame_result.pb.o \
	$(TOPDIR)/../pb_dst/human_attribute.pb.o \
	$(TOPDIR)/../pb_dst/image.pb.o \
	$(TOPDIR)/../pb_dst/item.pb.o \
	$(TOPDIR)/../pb_dst/mask.pb.o \
 	$(TOPDIR)/../pb_dst/meg_reply.pb.o \
 	$(TOPDIR)/../pb_dst/meg_request.pb.o \
 	$(TOPDIR)/../pb_dst/meta_post.pb.o \
 	$(TOPDIR)/../pb_dst/meta_reply.pb.o \
 	$(TOPDIR)/../pb_dst/plate_attribute.pb.o \
 	$(TOPDIR)/../pb_dst/token_reply.pb.o \
 	$(TOPDIR)/../pb_dst/token_request.pb.o \
 	$(TOPDIR)/../pb_dst/trace_point.pb.o \
 	$(TOPDIR)/../pb_dst/vehicle_attribute.pb.o \
	$(TOPDIR)/src/Pb.Ingenic.Sputnik.FrameResult.o \
	$(TOPDIR)/src/Pb.Ingenic.Sputnik.MegRequest.o


ifeq ($(LIBTYPE), muclibc)
	TARGET := ./out/lib/uclibc/libPb.Ingenic.Sputnik.a
else
	TARGET := ./out/lib/glibc/libPb.Ingenic.Sputnik.a
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
