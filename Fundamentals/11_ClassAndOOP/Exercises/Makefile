# Makefile for C++ OOP Examples
# Usage: make          - builds all programs
#        make clean    - removes all executables
#        make run-all  - builds and runs all programs

CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -O2

# List of programs to build
PROGRAMS = student inheritance_polymorphism advanced_oop composition_aggregation

# Default target: build all programs
all: $(PROGRAMS)
	@echo "All programs built successfully!"
	@echo ""
	@echo "To run the examples:"
	@for prog in $(PROGRAMS); do \
		echo "  ./$$prog"; \
	done

# Pattern rule for building programs
%: %.cpp
	@echo "Compiling $@..."
	$(CXX) $(CXXFLAGS) -o $@ $<

# Individual targets (optional, for explicit building)
student: student.cpp
	$(CXX) $(CXXFLAGS) -o student student.cpp

inheritance_polymorphism: inheritance_polymorphism.cpp
	$(CXX) $(CXXFLAGS) -o inheritance_polymorphism inheritance_polymorphism.cpp

advanced_oop: advanced_oop.cpp
	$(CXX) $(CXXFLAGS) -o advanced_oop advanced_oop.cpp

composition_aggregation: composition_aggregation.cpp
	$(CXX) $(CXXFLAGS) -o composition_aggregation composition_aggregation.cpp

# Clean target: remove all executables
clean:
	@echo "Cleaning up..."
	rm -f $(PROGRAMS)
	@echo "Clean complete!"

# Run all programs
run-all: all
	@echo ""
	@echo "======================================"
	@echo "Running student example..."
	@echo "======================================"
	@./student
	@echo ""
	@echo "======================================"
	@echo "Running inheritance_polymorphism example..."
	@echo "======================================"
	@./inheritance_polymorphism
	@echo ""
	@echo "======================================"
	@echo "Running advanced_oop example..."
	@echo "======================================"
	@./advanced_oop
	@echo ""
	@echo "======================================"
	@echo "Running composition_aggregation example..."
	@echo "======================================"
	@./composition_aggregation

# Run individual programs
run-student: student
	./student

run-inheritance: inheritance_polymorphism
	./inheritance_polymorphism

run-advanced: advanced_oop
	./advanced_oop

run-composition: composition_aggregation
	./composition_aggregation

# Help target
help:
	@echo "C++ OOP Examples Makefile"
	@echo "========================="
	@echo ""
	@echo "Available targets:"
	@echo "  make              - Build all programs"
	@echo "  make clean        - Remove all executables"
	@echo "  make run-all      - Build and run all programs"
	@echo "  make student      - Build only student example"
	@echo "  make inheritance_polymorphism - Build only inheritance example"
	@echo "  make advanced_oop - Build only advanced OOP example"
	@echo "  make composition_aggregation - Build only composition example"
	@echo "  make run-student  - Run student example"
	@echo "  make run-inheritance - Run inheritance example"
	@echo "  make run-advanced - Run advanced OOP example"
	@echo "  make run-composition - Run composition example"
	@echo "  make help         - Show this help message"

# Phony targets (not actual files)
.PHONY: all clean run-all run-student run-inheritance run-advanced run-composition help
