all: buildMain1 buildTest1 runTest1 buildMain2 buildTest2 runTest2

buildMain1:
	gcc -std=c89 -o N1/main1  N1/src/horoscope.h N1/src/horoscope.c N1/src/main1.c

buildTest1:
	gcc -std=c89 -o N1/tests/main1Tests N1/tests/src/horoscopeTests.h N1/tests/src/main1Tests.c N1/tests/src/horoscopeTests.c

runTest1:
	N1/tests/main1Tests

buildMain2:
	gcc -std=c89 -o N2/main2 N2/src/series.h N2/src/main2.c N2/src/series.c -lm

buildTest2:
	gcc -std=c89 -o N2/tests/main2Tests N2/tests/src/seriesTests.h N2/tests/src/main2Tests.c N2/tests/src/seriesTests.c -lm

runTest2:
	N2/tests/main2Tests