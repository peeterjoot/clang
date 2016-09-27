# compilation options are actually specified in compile_commands.json.  This makefile is just a dummy to invoke the tool.

#tool=/home/peeterj/toolchain492.clang.debug/bin/tooling_sample
include ../makefile.$(HOSTNAME)
TOOL=$(CLANGPATH)/bin/tooling_sample

compile_commands.json : ./mkjson
	./mkjson > $@

withstdio.o : withstdio.cpp
	$(TOOL) withstdio.cpp

clean : 
	rm -f lzmutexx.cpp
