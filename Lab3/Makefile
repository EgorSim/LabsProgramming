all: buildMain buildTests runTests

buildMain:
	gcc -std=c89 -o Main/main Main/src/array3D.h Main/src/main.c Main/src/array3D.c

buildTests:
	gcc -std=c89 -o Tests/mainTests Tests/src/array3DTests.h Tests/src/mainTests.c Tests/src/array3DTests.c

runTests:
	Tests/mainTests