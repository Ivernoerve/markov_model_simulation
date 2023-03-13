MARKOV_SRC=markov.c

SIM_SRC= sim.c  $(MARKOV_SRC)
#SPAMFILTER_SRC=spamfilter.c common.c $(LIST_SRC) $(SET_SRC)
INCLUDE=include


#STATE_SRC:=$(patsubst %.c,src/%.c, $(STATE_SRC))
SIM_SRC:=$(patsubst %.c,src/%.c, $(SIM_SRC))


CFLAGS=-Wall -Wextra -g -Wpedantic
LDFLAGS=-lm -DLOG_LEVEL=0 -DERROR_FATAL

all: sim

sim: $(SIM_SRC) Makefile
	gcc -o $@ $(CFLAGS) $(SIM_SRC) -I$(INCLUDE) $(LDFLAGS)

clean:
	rm -f *~ *.o *.exe sim && rm -rf *.dSYM
