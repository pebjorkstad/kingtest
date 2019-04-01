include_path=-Iinc/
sources=$(wildcard src/*.cpp)
options = -g -Wall -Wextra -pedantic -std=c++14


default: king_test
.PHONY: king_test
king_test: $(sources)
	rm -rf bin && mkdir bin && g++ $(options) $(include_path) -o bin/$@ $^

.PHONY: clean
clean:
	rm -rf bin
