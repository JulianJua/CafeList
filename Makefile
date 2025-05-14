CXX = g++

CXXFLAGS = -Wall -std=c++11

TARGET = main

SOURCES = Bartista.cpp Beverage.cpp Cashier.cpp Employee.cpp Food.cpp \
          Manager.cpp Menu.cpp MenuItem.cpp Node.cpp Person.cpp main.c++

OBJECTS = $(patsubst %.cpp,%.o,$(filter %.cpp,$(SOURCES))) \
          $(patsubst %.c++,%.o,$(filter %.c++,$(SOURCES)))

TEST_SOURCES = LinkedListTest.cpp MenuItemTest.cpp
TEST_OBJECTS = $(TEST_SOURCES:.cpp=.o)
TEST_TARGETS = LinkedListTest MenuItemTest

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o $(TARGET)

# Rule for .cpp files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Rule for .c++ files
%.o: %.c++
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean rule
clean:
	rm -f $(OBJECTS) $(TARGET) $(TEST_OBJECTS) $(TEST_TARGETS)

# Run rule
run: $(TARGET)
	./$(TARGET)

# Build all tests
tests: $(TEST_TARGETS)

# Rules for building test executables
LinkedListTest: LinkedListTest.o MenuItem.o Beverage.o Food.o Node.o
	$(CXX) $(CXXFLAGS) $^ -o $@

MenuItemTest: MenuItemTest.o MenuItem.o Beverage.o Food.o
	$(CXX) $(CXXFLAGS) $^ -o $@

# Run all tests
run-tests: tests
	@echo "Running all tests..."
	@for test in $(TEST_TARGETS); do \
		echo "\nRunning $$test"; \
		./$$test; \
	done

# Phony targets
.PHONY: clean run tests run-tests