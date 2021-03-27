all: buildMain1 buildTest1 runTest1 buildMain2 buildTest2 runTest2

buildMain1:
	gcc -std=c89 -o N1/Main1/main N1/Main1/src/vector.h N1/Main1/src/main.c N1/Main1/src/vector.c

buildTest1:
	gcc -std=c89 -o N1/Tests1/main1Tests N1/Main1/src/vector.h N1/Tests1/src/main1Tests.c N1/Main1/src/vector.c

runTest1:
	N1/Tests1/main1Tests

buildMain2:
	gcc -std=c89 -o N2/Main2/main N2/Main2/src/vector.h N2/Main2/src/main.c N2/Main2/src/vector.c

buildTest2:
	gcc -std=c89 -o N2/Tests2/main2Tests N2/Main2/src/vector.h N2/Tests2/src/main2Tests.c N2/Main2/src/vector.c

runTest2:
	N2/Tests2/main2Tests
