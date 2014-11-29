#CFLAGS += -ferror-limit=200
CFLAGS += -g
LLVM_LIBS := core mc

HOSTNAME := $(shell hostname)

include makefile.$(HOSTNAME)

CFLAGS += $(shell $(LLVM_BIN_PATH)llvm-config --cxxflags)
#CFLAGS := $(filter-out -fno-exceptions,$(CFLAGS))
LDFLAGS += $(shell $(LLVM_BIN_PATH)llvm-config --ldflags)

LLVMSRC := $(shell $(LLVM_BIN_PATH)/llvm-config --src-root)
LLVMPREFIX := $(shell $(LLVM_BIN_PATH)/llvm-config --prefix)

# HACK: llvm-config doesn't get along with clearcase as an install path and appears to be picking out my view storage dir.
#
# http://stackoverflow.com/questions/13650862/result-from-proc-self-exe-is-unfriendly-in-a-clearcase-view/13651141#13651141
#
# (dealt with this by avoiding an install in /vbs/ for now).
#
#LLVM_CONFIG_OUT := $(subst /home/hotellnx99/peeterj/views/peeterj_clang-7.vws/.s,$(CLANGPATH),$(LLVM_CONFIG_OUT))

#-------------------------------------------------
# for debugging:

# for Release+Asserts config:
CFLAGS := $(subst -O3,,$(CFLAGS))
#-------------------------------------------------

LDFLAGS += -lclangFrontendTool -lclangFrontend -lclangDriver 
LDFLAGS += -lclangSerialization -lclangCodeGen -lclangParse 
LDFLAGS += -lclangSema -lclangStaticAnalyzerFrontend 
LDFLAGS += -lclangStaticAnalyzerCheckers -lclangStaticAnalyzerCore 
LDFLAGS += -lclangAnalysis -lclangARCMigrate 
LDFLAGS += -lclangRewriteCore 
LDFLAGS += -lclangEdit -lclangAST -lclangLex -lclangBasic
LDFLAGS += -lLLVMMCParser
LDFLAGS += -lLLVMBitReader
LDFLAGS += -lLLVMOption
LDFLAGS += -lLLVMTransformUtils

LDFLAGS += $(shell $(LLVM_BIN_PATH)llvm-config --libs $(LLVM_LIBS))

EXES += tooling_sample
#EXES += $(LLVMPREFIX)/bin/stripGmblkVoidPPcast
#EXES += $(LLVMPREFIX)/bin/gblkToGmblk

CFLAGS += -std=c++11

#CFLAGS += -I$(LLVMSRC)/tools/clang/include

all: $(EXES)

tooling_sample.o : depmap.h dumper.h

%.o : %.cpp
	$(CXX) -c $< $(CFLAGS)

#$(LLVMPREFIX)/bin/stripGmblkVoidPPcast : stripGmblkVoidPPcast.o
#	$(CXX) $< -o $@ $(LDFLAGS) -lclangFrontend -lclangSerialization -lclangDriver -lclangTooling -lclangParse -lclangSema -lclangAnalysis -lclangRewriteFrontend -lclangRewriteCore -lclangEdit -lclangAST -lclangLex -lclangBasic -lLLVMSupport -lclangASTMatchers
#
#$(LLVMPREFIX)/bin/gblkToGmblk : gblkToGmblk.o
#	$(CXX) $< -o $@ $(LDFLAGS) -lclangFrontend -lclangSerialization -lclangDriver -lclangTooling -lclangParse -lclangSema -lclangAnalysis -lclangRewriteFrontend -lclangRewriteCore -lclangEdit -lclangAST -lclangLex -lclangBasic -lLLVMSupport -lclangASTMatchers
#
tooling_sample: tooling_sample.o
	$(CXX) $< -o $@ $(LDFLAGS)

#stripGmblkVoidPPcast.o : RenameMethod.cpp
#	$(CXX) -c $< $(CFLAGS) -DGMBLK_VOIDPP_MODE -DGBLK_TO_GMBLK -o $@
#
#gblkToGmblk.o : RenameMethod.cpp
#	$(CXX) -c $< $(CFLAGS) -o $@
#
#isystem.h : isystem.pl
#	$< $(CXX) > $@

clean:
	rm -rf *.o *.ll $(EXES) $(CLEAN_EXES) isystem.h
