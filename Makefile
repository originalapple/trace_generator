##C++ file compile
#filename=$1
#output=$(echo "$filename" | cut -f 1 -d '.')
#
#compile : 
#	g++ -o $(output) $(filename)

# 컴파일러 및 플래그 설정
CXX = g++
CXXFLAGS = -Iinclude -std=c++14

# 디렉토리 및 파일
SRCDIR = src
INCDIR = include
OBJDIR = obj
BINDIR = bin

SOURCES = $(wildcard $(SRCDIR)/*.cpp)
OBJECTS = $(patsubst $(SRCDIR)/%.cpp, $(OBJDIR)/%.o, $(SOURCES))
TARGET = $(BINDIR)/main

# 빌드 규칙
$(TARGET): $(OBJECTS)
	@mkdir -p $(BINDIR)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	@mkdir -p $(OBJDIR)
	$(CXX) $(CXXFLAGS) -c -o $@ $<

# 정리 규칙
clean:
	rm -rf $(OBJDIR) $(BINDIR)

# 실행 규칙
run: $(TARGET)
	./$(TARGET)

# 기본 규칙
.PHONY: all clean run
all: $(TARGET)

