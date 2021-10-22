g++ -c src/*.cpp -g -Wall -m64  -IC:/SDL2-w64/include/SDL2 -Iinclude -Ires && g++ *.o -o bin/debug/main -Llib -lmingw32 -l SDL2main -l SDL2 -l SDL2_image && start bin/debug/main
