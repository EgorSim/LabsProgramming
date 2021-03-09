all: buildMain runMain buildTests runTests


buildMain:
	gcc -std=c89 -o main src/toBin.h src/main.c src/toBin.c
runMain:
	main
buildTests:
	gcc -std=c89 -o tests/maintests tests/src/toBinTestVersion.h tests/src/maintests.c tests/src/toBinTestVersion.c
runTests:
	tests/maintests