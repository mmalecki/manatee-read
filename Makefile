OBJS += src/main.o

CFLAGS += -g -Wall -Ideps/manatee `GraphicsMagick++-config --cppflags --cxxflags`
LDFLAGS += deps/manatee/libBarcodeScanner.a `GraphicsMagick++-config --ldflags --libs`

all: manatee-read

src/%.o: src/%.cpp
	g++ $(CFLAGS) -c $< -o $@

manatee-read: $(OBJS)
	g++ $^ $(LDFLAGS) -o $@

clean:
	rm -f manatee-read
	rm -f src/*.o

.PHONY: all clean
