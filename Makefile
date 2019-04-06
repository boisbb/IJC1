CFLAGS	= -O2 -std=c11 -Wall -pedantic
PROGS	= steg-decode primes steg-decode-i primes-i

all: $(PROGS)
steg-decode: steg-decode.c ppm.c ppm.h bit_array.h eratosthenes.c error.c error.h
	$(CC) $(CFLAGS) steg-decode.c -o steg-decode -lm
primes: primes.c bit_array.h eratosthenes.c error.c error.h
	$(CC) $(CFLAGS) primes.c -o primes -lm
steg-decode-i: steg-decode.c
	$(CC) $(CFLAGS) steg-decode.c -o steg-decode-i -lm -DUSE_INLINE
primes-i: primes.c
	$(CC) $(CFLAGS) primes.c -o primes-i -lm -DUSE_INLINE
run:
	make
	ulimit -s 20000 && time ./primes
	ulimit -s 20000 && time ./primes-i
clean:
	rm primes primes-i steg-decode steg-decode-i
pack:
	zip xburka00.zip *.c *.h Makefile
