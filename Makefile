SOURCEDIR = src
BUILDDIR  = build

HEADERS = $(shell find . -name '*.h')
SOURCES = $(shell find . -name '*.c')
# OBJFILES = $(patsubst $(SOURCEDIR)/%.c,$(BUILDDIR)/%.o,$(SOURCES))
OBJECTS = $(patsubst %.c, %.o, $(SOURCES))

CC       = gcc
CFLAGS   = -c -Wall
LDFLAGS  =
OBJFILES = main.o fileReader.o interface.o logger.o
TARGET   = tp3

all: $(TARGET)

$(TARGET): $(OBJFILES)
	$(CC) $(CFLAGS) $(HEADERS) $(SOURCES) -o $(TARGET) $(OBJFILES) $(LDFLAGS)
clean:
	rm -f $(OBJFILES) $(TARGET) *~

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
