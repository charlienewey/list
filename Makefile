CC=gcc
DEVFLAGS=-m64 -std=c99 -pedantic -Wall -Wshadow -Wpointer-arith -Wcast-qual \
        -Wstrict-prototypes -Wmissing-prototypes -Wdeclaration-after-statement \
        -Wformat=2 -Wswitch-default -Wcast-align -Wcast-qual -Wwrite-strings \
        -Wconversion -Wunreachable-code -Wswitch-enum -Wcast-align \
		-Wbad-function-cast -Wstrict-overflow=5 -Wstrict-prototypes -Winline \
		-Wundef -Wnested-externs -Wlogical-op -Wfloat-equal \
		-Wstrict-aliasing=2 -Wredundant-decls -Wold-style-definition -Werror \
		-Wextra -fPIC -fno-omit-frame-pointer -ffloat-store -fno-common \
		-fstrict-aliasing -ggdb3 -std=c99 -O2

PRODFLAGS=-m64 -std=c99 -pedantic -O3 -DNDEBUG -flto -fPIC

dev:
		rm -f ./build/*
		mkdir -p ./build/
		${CC} ${DEVFLAGS} -c src/*.c -shared -o./build/list.o
prod:
		rm -f ./build/*
		mkdir -p ./build/
		${CC} ${PRODFLAGS} -c src/*.c -shared -o ./build/list.o
