CC = gcc

all: thread thread_mutex thread_attr producer-customer
	@echo "Build end..."

thread: src/thread.c
	$(CC) -o bin/thread -pthread src/thread.c

thread_mutex: src/thread_mutex.c
	$(CC) -o bin/thread_mutex -pthread src/thread_mutex.c

thread_attr: src/thread_attr.c
	$(CC) -o bin/thread_attr -pthread src/thread_attr.c

producer-customer: src/producer-customer.c
	$(CC) -o bin/producer-customer -pthread src/producer-customer.c


clean: bin
	@rm bin/thread
	@rm bin/thread_mutex
	@rm bin/thread_attr
	@rm bin/producer-customer
