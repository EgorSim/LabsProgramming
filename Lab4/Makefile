all: buildMain1 buildTest1 runTest1 buildMain2

buildMain1:
	gcc -std=c89 -o N1/Main1/main N1/Main1/src/vector.h N1/Main1/src/main.c N1/Main1/src/vector.c

buildTest1:
	gcc -std=c89 -o N1/Tests1/main1Tests N1/Main1/src/vector.h N1/Tests1/src/main1Tests.c N1/Main1/src/vector.c

runTest1:
	N1/Tests1/main1Tests

buildMain2:
	gcc -std=c89 -o N2/Main2/main N2/Main2/src/main.c