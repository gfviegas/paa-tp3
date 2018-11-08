SOURCEDIR = src
BUILDDIR  = build/

HEADERS = $(shell find . -name '*.h')
SOURCES = $(shell find . -name '*.c')
# OBJFILES = $(patsubst $(SOURCEDIR)/%.c,$(BUILDDIR)/%.o,$(SOURCES))
OBJFILES = $(patsubst %.c, %.o, $(SOURCES))

CC       = gcc
CFLAGS   = -c -Wall
LDFLAGS  =
# OBJFILES = main.o fileReader.o interface.o logger.o
TARGET   = tp3

all: $(TARGET)

$(TARGET): $(OBJFILES)
	$(CC) $(CFLAGS) $(HEADERS) $(SOURCES) $(LDFLAGS)
	$(CC) -o $(BUILDDIR)$(TARGET) $(OBJFILES)
	make cleanO

cleanO:
	rm -f $(shell find . -name '*.o') $(shell find . -name '*.h.gch') *~
clean:
	rm -f $(OBJFILES) $(TARGET) $(shell find . -name '*.h.gch') *~
run:
	./build/tp3
analysis:
	./build/tp3 -a

# LIBRARIES=
# INC=
# EXECUTABLE=tp3
# VPATH=src build
#
# all: $(SOURCES) $(EXECUTABLE)
#
# $(EXECUTABLE): $(OBJECTS)
# 	$(CC) $(LDFLAGS) $(OBJECTS) $(LIBRARIES)  -o ./dist/$@
#
# $(BUILDDIR)/%.o : $(SOURCEDIR)/%.c
# 	$(CC) $(INC) $(CFLAGS) $< -o $@
