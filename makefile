CFLAGS+=-g -std=c11
# CFLAGS+=-Idependencies/include

# LDFLAGS+=-Ldependencies/lib
# LDLIBS+=


all_comfy=$(wildcard sources/*.comfy)
all_c=$(patsubst sources/%.comfy, build/c/%.c, $(all_comfy))
all_objs=$(patsubst sources/%.comfy, build/o/%.o, $(all_comfy))
all_headers=$(patsubst sources/%.comfy, build/headers/%.h, $(all_comfy))

lib=build/lib/libcomfyregex.a

all: prepare $(all_headers) $(lib)

$(lib): $(all_objs) $(all_headers)
	$(AR) rcs $@ $(all_objs)

build/headers/%.h: sources/%.comfy
	comfy $(?F) --source sources --target build/headers --headers

build/o/%.o: build/c/%.c
	$(CC) -c $(CFLAGS) -Ibuild/headers -o $@ $?

build/c/%.c: sources/%.comfy | $(all_headers)
	comfy $(?F) --source sources --target build/c --c-files

prepare:
	mkdir -p build/c
	mkdir -p build/o
	mkdir -p build/lib
	mkdir -p build/headers


clean:
	$(RM) -r build

.PHONY: clean

.SECONDARY:
