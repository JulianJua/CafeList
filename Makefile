CXX = g++

CXXFLAGS = -Wall -std=c++11

TARGET = main

SOURCES = Bartista.cpp Beverage.cpp Cashier.cpp Employee.cpp Food.cpp \
          Manager.cpp Menu.cpp MenuItem.cpp Node.cpp Person.cpp main.c++

OBJECTS = $(patsubst %.cpp,%.o,$(filter %.cpp,$(SOURCES))) \
          $(patsubst %.c++,%.o,$(filter %.c++,$(SOURCES)))

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o $(TARGET)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

%.o: %.c++
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(TARGET)

run: $(TARGET)
	./$(TARGET)

.PHONY: clean run