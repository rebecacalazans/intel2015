EXEC = intel.out
SRCS = src/main.cpp \
			 src/utils/point.cpp \
			 src/utils/statemachine.cpp \
			 src/core/skills/kick.cpp \
			 src/core/skills/attack.cpp
FLAGS = -std=c++11

debug: $(SRCS)
	g++ $(FLAGS) -DDEBUG -o $(EXEC) $(SRCS)

release: $(SRCS)
	g++ $(FLAGS) -o $(EXEC) $(SRCS)

clean:
	@rm $(EXEC)
