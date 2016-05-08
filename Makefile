PROGNAME=benchmagic

CXX = g++
INSTALL = install -o root -g root -m 755
INSTALL_DIR = install -p -d -o root -g root -m 755
INSTALL_DATA = install -p -o root -g root -m 644
CFLAGS += 
CPPFLAGS +=
CXXFLAGS += -g -Wall
LDFLAGS += 
GIT_INFO_REV = $(shell git rev-parse --short HEAD)
GIT_DEFINE =-DGIT_HASH=\"\"

ifneq (,$(GIT_INFO_REV))
    GIT_DEFINE=-DGIT_HASH=\"$(GIT_INFO_REV)\"
endif

ifneq (,$(filter noopt,$(DEB_BUILD_OPTIONS)))
	CXXFLAGS += -O0
else
	CXXFLAGS += -O2
endif
ifeq (,$(filter nostrip,$(DEB_BUILD_OPTIONS)))
	INSTALL += -s
endif
ifneq (,$(filter parallel=%,$(DEB_BUILD_OPTIONS)))
	NUMJOBS = $(patsubst parallel=%,%,$(filter parallel=%,$(DEB_BUILD_OPTIONS)))
	MAKEFLAGS += -j$(NUMJOBS)
endif

OBJFILES := $(patsubst src/%.cpp,obj/%.o,$(wildcard src/*.cpp))
OBJFILES_CARDS := $(patsubst src/cards/%.cpp,obj/cards/%.o,$(wildcard src/cards/*.cpp))

all: $(PROGNAME)

$(PROGNAME): $(OBJFILES) $(OBJFILES_CARDS)
	$(CXX) -o $(PROGNAME) $(INCLUDE_DIR) $(OBJFILES) $(OBJFILES_CARDS) $(LDFLAGS)

obj/%.o: src/%.cpp 
	@mkdir -p obj
	@mkdir -p obj/cards
	$(CXX) -c $< -o $@ $(CFLAGS) $(CPPFLAGS) $(CXXFLAGS) $(GIT_DEFINE)

clean:
	rm -f $(OBJFILES) $(OBJFILES_CARDS) $(PROGNAME)

rebuild: clean all

install:
	$(INSTALL_DIR) $(DESTDIR)/usr/bin
	$(INSTALL) $(PROGNAME) $(DESTDIR)/usr/bin

uninstall:
	rm -f $(DESTDIR)/usr/bin/$(PROGNAME)

.PHONY: install uninstall

