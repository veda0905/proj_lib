
CXX = g++-12
CXXFLAGS = -std=c++14 -Wall  


TARGET = program
SRCS = main.cpp library.cpp book.cpp member.cpp
OBJS = $(SRCS:.cpp=.o)


$(TARGET): $(OBJS)
	$(CXX) $(OBJS) -o $(TARGET)  


%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@  


clean:
	rm -f $(OBJS) $(TARGET) 