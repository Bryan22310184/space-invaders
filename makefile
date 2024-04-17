bin/test : src/tui_test.cpp
	g++ src/tui_test.cpp -o bin/test -std=c++2a -lftxui-screen -lftxui-component -ftxui-dom

bin/space : src/main.cpp
	g++ src/main.cpp -o bin/space -std=c++2a -lftxui-screen -lftxui-component -ftxui-dom

run : bin/space
	./bin/space

runTest : bin/test
	./bin/test