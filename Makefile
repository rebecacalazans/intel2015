EXEC = intel.out
SRCS = main.cpp
FLAGS = -std=c++11

debug: $(SRCS)
	g++ $(FLAGS) -DDEBUG -o $(EXEC) $(SRCS)

release: $(SRCS)
	g++ $(FLAGS) -o $(EXEC) $(SRCS)

clean:
	@rm $(EXEC)
